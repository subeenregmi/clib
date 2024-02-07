/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com> 
 * Date: 2024-02-07
 *
 * These are options/flags that can be set for linux system call, 'open'
 * or in clib for the sys_open() function. These flags are for the 
 * flags and mode parameters. 
 *
 * Note: The mode parameter is mostly ignored if you are not creating a
 * new file.
 */
#ifndef CLIB_FLAGS_OPEN_H
#define CLIB_FLAGS_OPEN_H

// Flags param

// Required (only one needs to be specified)
#define OPEN_READ_ONLY              0
#define OPEN_WRITE_ONLY             1
#define OPEN_READ_WRITE             2

// Optinal (To choose, or (|) the flags together)

// File creation flags
#define OPEN_CREATE_IF_NOT          100
#define OPEN_CLOSE_ON_EXEC          2000000
#define OPEN_DIRECTORY              200000

// File status flags
#define OPEN_APPEND                 2000
#define OPEN_ASYNC                  20000
#define OPEN_DIRECT                 40000


#endif // CLIB_FLAGS_OPEN_H
