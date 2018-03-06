/************************************************************************
Title:	  libsparse.c - 
Author:   Nicholas Morrow <nmorrow@crystaldiagnostics.com>
File:     libsparse.c
Software: STM32Fxxx_HAL_Driver, CMSIS-CORE
Hardware: STM32Fxxx
License:  The MIT License (MIT)
Usage:    Refer to the header file libsparse.h for a description of the routines.
    	  See also example test_libsparse.c, if available.
LICENSE:
    Copyright (C) 2018 Pathogen Systems, Inc. dba Crystal Diagnostics

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
************************************************************************/

/**********************    INCLUDE DIRECTIVES    ***********************/

#include "libsparse.h"
/**********************    GLOBAL VARIABLES    ***********************/

/*******************    FUNCTION IMPLEMENTATIONS    ********************/
sparse_StatusTypeDef sparse_DefaultCallback(sparse_ArgPack *a)
{
#if SPARSE_COMPILE_WITH_PRINTF
    printf("Callback for command %c not implemented.\n", a->cmd);
#endif
    return SPARSE_OK;
}

sparse_ParserTypeDef *sparse_New(void)
{
    sparse_ParserTypeDef *s = (sparse_ParserTypeDef *)calloc(1, sizeof(sparse_ParserTypeDef));
    s->delimiter = ',';
    for (uint8_t i = 0; i < 94; i++)
    {
        s->cmd_table[i].callback_pointer = &sparse_DefaultCallback;
    }

    return s;
}

void sparse_Delete(sparse_ParserTypeDef *s)
{
    free(s);
}

void sparse_InitParser(sparse_ParserTypeDef *parser)
{
	return;
}

sparse_StatusTypeDef sparse_RegisterCallback(sparse_ParserTypeDef *parser, const char id, const uint8_t num_args, sparse_CallbackPointer callback)
{
    if (((uint8_t)id < 33) || ((uint8_t)id > 127))
    {
        // Error - Invalid callback ID specified.
        return SPARSE_ERROR;
    }
    if (callback == NULL)
    {
        /* Implement a better way to check if the function address resides in
           a valid segment of memory. */
        return SPARSE_ERROR;
    }
    parser->cmd_table[(uint8_t)(id - 33)].callback_pointer = callback;
    parser->cmd_table[(uint8_t)(id - 33)].num_args = num_args;
    return SPARSE_OK;
}

sparse_StatusTypeDef sparse_Exec(sparse_ParserTypeDef *parser, char *cmd_str)
{
    sparse_ArgPack *a = (sparse_ArgPack *)calloc(1, sizeof(sparse_ArgPack));
    if (a == NULL)
    {
        return SPARSE_ERROR;
    }
    /* If this command accepts arguments, build an argpack and pass to the function
       call.*/
    unsigned int args = parser->cmd_table[((uint8_t)cmd_str[0])].num_args;
    if (args > 0)
    {
        a->cmd = cmd_str[0];

        a->arg_list = (char **)calloc(1, sizeof(char *));
        /* Parse first argument and add to argpack */
        char *token = strtok(cmd_str + 1, &parser->delimiter);
        a->arg_list[a->num_args] = (char *)calloc(strlen(token), sizeof(char));
        strcpy(a->arg_list[a->num_args], token);
        a->num_args++;

        while ((token = strtok(NULL, &parser->delimiter)) != NULL)
        {
            /* Parse remaining arguments and add to argpack */
            a->num_args++;
            a->arg_list = (char **)realloc(a->arg_list, a->num_args * sizeof(char *));
            a->arg_list[(a->num_args) - 1] = (char *)calloc(strlen(token), sizeof(char));
            strcpy(a->arg_list[(a->num_args) - 1], token);
        }
    }
    /* Execute callback function with argpack passed as argument. */
    if (parser->cmd_table[(uint8_t)a->cmd].callback_pointer(a) != SPARSE_OK)
    {
#if SPARSE_COMPILE_WITH_PRINTF
        printf("Error in callback function for command %c.\n", a->cmd);
#endif
    }
    free(a);
    return SPARSE_OK;
}
