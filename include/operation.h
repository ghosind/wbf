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

#ifndef _OPERATION_H
#define _OPERATION_H

#include <vm.h>

void vm_inc(VM *);
void vm_dec(VM *);
void vm_prev(VM *);
void vm_next(VM *);
void vm_start_loop(VM *);
int vm_end_loop(VM *);
void vm_getc(VM *);
void vm_putc(VM *);

#endif