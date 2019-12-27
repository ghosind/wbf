/**
 * wbf - A brainfuck interpreter
 * Copyright (C) 2018, Chen Su <ghosind@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VM_H
#define _VM_H


#define VM_RUNNING 1
#define VM_STOP    0

#define VM_RESERVED_SIZE    0x400
#define VM_DEFAULT_CS_SIZE  0x400
#define VM_DEFAULT_DS_SIZE  0x400

/**
 * VM memory size = code segment size + data segment size + reserved size * 3.
 * Default code segment and data segment size are 1 Kilobytes, and default
 * memory size is 7 Kilobytes.
 * 
 * VM structure:
 * |---------------|
 * |   Reserved    |
 * |---------------|
 * | Code Segment  |
 * |---------------|
 * |   Reserved    |
 * |---------------|
 * | Data Segment  |
 * |---------------|
 * |   Reserved    |
 * |---------------|
 */
typedef struct {
    char *mem;      // vm memory
    char *cs;       // code segments pointer
    char *ds;       // data segments pointer
    char *ip;       // instruction pointer
    char *dp;       // data pointer
    int mem_size;
    int cs_size;
    int ds_size;
    int loop_num;
} VM;

/**
 * init virtual machine
 */
VM *vm_init(int , int );

void vm_reset(VM *);

int vm_run(VM *);

#endif
