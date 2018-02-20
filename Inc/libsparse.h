/*************************************************************************
Title:    libsparse.h - 
Author:   Nicholas Morrow <nmorrow@crystaldiagnostics.com>
File:     libsparse.h
Software: STM32Fxxx_HAL_Driver, CMSIS-CORE
Hardware: STM32Fxxx
License:  The MIT License (MIT)

DESCRIPTION:


USAGE:

NOTES:

TO-DO:


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

*************************************************************************/
#ifndef INC_LIBSPARSE_H_
#define INC_LIBSPARSE_H_
/**********************    INCLUDE DIRECTIVES    ***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**************    CONSTANTS, MACROS, & DATA STRUCTURES    ***************/
#define SPARSE_COMPILE_WITH_PRINTF 0

typedef enum {
    SPARSE_OK = 0,
    SPARSE_ERROR
} sparse_StatusTypeDef;


typedef struct
{
    char cmd;
    uint8_t num_args;
    char **arg_list;
} sparse_ArgPack;


typedef sparse_StatusTypeDef (*sparse_CallbackPointer)(sparse_ArgPack *a);

typedef struct
{
    uint8_t num_args;
    sparse_CallbackPointer callback_pointer;
} sparse_CallbackTypeDef;

typedef struct
{
    char delimiter;
    char line_end;
    sparse_CallbackTypeDef cmd_table[128];
} sparse_ParserTypeDef;


/***********************    FUNCTION PROTOTYPES    ***********************/
sparse_ParserTypeDef *sparse_New(void);
void sparse_Delete(sparse_ParserTypeDef *s);
sparse_StatusTypeDef sparse_DefaultCallback(sparse_ArgPack *a);
void sparse_InitParser(sparse_ParserTypeDef *parser);
sparse_StatusTypeDef sparse_RegisterCallback(sparse_ParserTypeDef *parser, const char id, const uint8_t num_args, sparse_CallbackPointer callback);
sparse_StatusTypeDef sparse_Exec(sparse_ParserTypeDef *parser, char *cmd_str);
#endif /* INC_LIBSPARSE_H_ */
