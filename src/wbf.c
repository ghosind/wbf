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
#include <stdlib.h>

#include <file.h>
#include <input.h>
#include <vm.h>
#include <wbf.h>

/**
 * print program description and copyright infomation.
 */
void print_program_info() {
  fprintf(stdout, "%s v%d.%d.%d\n", PROGRAM_NAME, MAJOR_VERSION,
      MINOR_VERSION, PATCH_VERSION);
  fprintf(stdout, "Copyright (C) 2018, %s\n\n", PROGRAM_AUTHOR);
  fprintf(stdout, "This program comes with ABSOLUTELY NO WARRANTY.\n");
  fprintf(stdout,
      "This is free software, and you are welcome to redistribute it\n");
  fprintf(stdout, "under certain conditions.\n\n");
  fflush(stdout);
}

/**
 * print program usage.
 */
void print_usage() {
  print_program_info();
}

int main(int argc, char **argv) {
  VM *vm = vm_init(VM_DEFAULT_CS_SIZE, VM_DEFAULT_DS_SIZE);
  
  if (argc == 2) {
    run_with_file(vm, argv[1]);
  } else {
    print_program_info();
    run_with_prompt(vm);
  }

  exit(0);
}
