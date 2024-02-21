/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-02-20
 *
 * These are the flags that can be supplied to the linux system call, 'lseek'
 * or in clib for the sys_lseek() function.
 */
#ifndef CLIB_SYS_LSEEK_H
#define CLIB_SYS_LSEEK_H

// whence parameter values
#define LSEEK_START         0
#define LSEEK_CURRENT       1
#define LSEEK_END           2
#define LSEEK_NEXT_DATA     3
#define LSEEK_NEXT_HOLE     4

#endif // CLIB_SYS_LSEEK_H
