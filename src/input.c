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

#include <stdio.h>
#include <string.h>

#include <input.h>
#include <preprocess.h>
#include <vm.h>

void input_prompt(VM *vm) {
    // TODO
    char buffer[INPUT_BUFFER_SIZE];

    do {
        fprintf(stdout, "\n> ");
        int n = fscanf(stdin, "%s", buffer);
        fflush(stdin);

        if (n > 0) {
            code_preprocess(buffer);

            strcpy(vm->cs, buffer);
            
            vm_run(vm);

            vm_reset(vm);
        }
    } while (buffer[0] != EOF);
}

void run_with_prompt(VM *vm) {
    input_prompt(vm);
}