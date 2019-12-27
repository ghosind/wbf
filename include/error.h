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

#ifndef _ERROR_H
#define _ERROR_H

#define ERR_VM_INIT_ERROR          0x00000001   // allocate vm error
#define ERR_VM_MEM_INIT_ERROR      0x00000002   // allocate memory error
#define ERR_VM_UNKNOWN_INSTRUCTION 0x00000003   // unknown instruction
#define ERR_VM_OVERFLOW            0x00000004   // overflow
#define ERR_VM_LOOP                0x00000005
#define ERR_TOO_LONG_CODE          0x00000006
#define ERR_INVALID_LOOP           0x00000007

void print_error(void);

#endif
