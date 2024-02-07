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
#define OPEN_ENSURE_CREATE          200

// File status flags
#define OPEN_APPEND                 2000
#define OPEN_ASYNC                  20000
#define OPEN_DIRECT                 40000
#define OPEN_DSYNC                  10000
#define OPEN_LARGE_FILE             100000
#define OPEN_NO_UPDATE_ACCESS_TIME  1000000
#define OPEN_C_TTY                  400
#define OPEN_NO_SLINKS              400000
#define OPEN_NON_BLOCKING           4000
#define OPEN_TRUNCATED              1000

// Mode param
// User permissions
#define OPEN_USER_RWX               700
#define OPEN_USER_R                 400
#define OPEN_USER_W                 200
#define OPEN_USER_X                 100

// Group permissions
#define OPEN_GROUP_RWX              70
#define OPEN_GROUP_R                40
#define OPEN_GROUP_W                20
#define OPEN_GROUP_X                10

// Others permissions
#define OPEN_OTHERS_RWX             7
#define OPEN_OTHERS_R               4
#define OPEN_OTHERS_W               2
#define OPEN_OTHERS_X               1

#endif // CLIB_FLAGS_OPEN_H
