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
#include <stdio.h>

#include <error.h>
#include <vm.h>

void vm_inc(VM *vm) {
  *(vm->dp) = *(vm->dp) + 1;
}

void vm_dec(VM *vm) {
  *(vm->dp) = *(vm->dp) - 1;
}

void vm_prev(VM *vm) {
  vm->dp--;
}

void vm_next(VM *vm) {
  vm->dp++;
}

void vm_getc(VM *vm) {
  *(vm->dp) = fgetc(stdin);
}

void vm_putc(VM *vm) {
  fputc(*(vm->dp), stdout);
  fflush(stdout);
}

int vm_start_loop(VM *vm) {
  if (*(vm->dp) != 0) {
    vm->loop_num++;
  } else {
    int n = 1;

    while (n > 0 && *(vm->ip) != '\0') {
      vm->ip++;

      if (*(vm->ip) == '\0') {
        errno = ERR_INVALID_LOOP;
        print_error();
        return VM_STOP;
      } else if (*(vm->ip) == '[') {
        n++;
      } else if (*(vm->ip) == ']') {
        n--;
      }
    }
  }

  return VM_RUNNING;
}

int vm_end_loop(VM *vm) {
  if (vm->loop_num <= 0) {
    errno = ERR_INVALID_LOOP;
    print_error();
    return VM_STOP;
  }

  if (*(vm->dp) != 0) {
    int n = 1;
    while (n > 0) {
      vm->ip--;

      if (*(vm->ip) == '\0') {
        errno = ERR_INVALID_LOOP;
        print_error();
        return VM_STOP;
      } else if (*(vm->ip) == ']') {
        n++;
      } else if (*(vm->ip) == '[') {
        n--;
      }
    }
  } else {
    vm->loop_num--;
  }

  return VM_RUNNING;
}
