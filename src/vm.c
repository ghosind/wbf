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

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <error.h>
#include <operation.h>
#include <vm.h>

VM *vm_init(int cs_size, int ds_size) {
  int vm_size = cs_size + ds_size + VM_RESERVED_SIZE * 3;

  VM *vm = (VM *) malloc(sizeof(VM));
  if (!vm) {
    errno = ERR_VM_INIT_ERROR;
    print_error();
    return NULL;
  }

  vm->mem = (char *) malloc(vm_size);
  if (!vm->mem) {
    errno = ERR_VM_MEM_INIT_ERROR;
    print_error();
    return NULL;
  }

  memset(vm->mem, 0, vm_size);

  vm->ds = vm->dp = vm->mem + VM_RESERVED_SIZE;
  vm->cs = vm->ip = vm->ds + ds_size + VM_RESERVED_SIZE;

  vm->mem_size = vm_size;
  vm->cs_size = cs_size;
  vm->ds_size = ds_size;

  vm->loop_num = 0;

  return vm;
}

void vm_reset(VM *vm) {
  // set memory to 0
  memset(vm->mem, 0, vm->mem_size);

  vm->ip = vm->cs;
  vm->dp = vm->ds;

  vm->loop_num = 0;
}

int vm_run(VM *vm) {
  int running = VM_RUNNING;

  while (*(vm->ip) && running) {
    switch (*(vm->ip)) {
      case '+':
        vm_inc(vm);
        break;
      case '-':
        vm_dec(vm);
        break;
      case '>':
        vm_next(vm);
        break;
      case '<':
        vm_prev(vm);
        break;
      case '[':
        running = vm_start_loop(vm);
        break;
      case ']':
        running = vm_end_loop(vm);
        break;
      case ',':
        vm_getc(vm);
        break;
      case '.':
        vm_putc(vm);
        break;
      default:
        errno = ERR_VM_UNKNOWN_INSTRUCTION;
        print_error();
        running = VM_STOP;
        break;
    }

    vm->ip++;

    if (vm->ip > vm->mem + vm->mem_size) {
      errno = ERR_VM_OVERFLOW;
      print_error();
    }
  }

  return running;
}
