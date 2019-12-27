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
#include <string.h>

#include <error.h>
#include <file.h>
#include <preprocess.h>
#include <vm.h>

int read_file(VM *vm, char *path) {
  FILE *file = fopen(path, "r");
  char buffer[FILE_BUFFER_SIZE];

  while (!feof(file)) {
    fread(buffer, sizeof(char), FILE_SIZE_PEER_READ, file);
  }

  // pre-process code
  code_preprocess(buffer);

  int len = strlen(buffer);

  // code length must less than code segment size
  if (len > vm->cs_size) {
    errno = ERR_TOO_LONG_CODE;   
    return -1;
  }

  // copy code to vm
  strcpy(vm->cs, buffer);

  return 0;
}

void run_with_file(VM *vm, char *path) {
  if (read_file(vm, path) == 0) {
    vm_run(vm);
  }
}