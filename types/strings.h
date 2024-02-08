/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date 2024-02-07
 *
 * This is the implementation of strings and some helper functions
 * for strings.
 */
#ifndef CLIB_STRINGS_H
#define CLIB_STRINGS_H

#include "bool.h"

typedef char* String;

unsigned int str_length(String str);
Bool str_empty(String str);


#endif // CLIB_STRINGS_H
