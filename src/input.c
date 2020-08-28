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

#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <error.h>
#include <input.h>
#include <preprocess.h>
#include <vm.h>

static int keep_running = 1;
sigjmp_buf ctrlc_buf;

int is_not_blank(char *str) {
  while (*str && isblank(*str)) {
    str++;
  }

  return *str && !isblank(*str);
}

void int_handler(int signo) {
  if (signo != SIGINT) {
    return;
  }

  if (keep_running) {
    keep_running = 0;
    fprintf(stdout, "\nPress CTRL-C again to exit.\n> ");
    fflush(stdout);
  } else {
    exit(0);
  }
}

void input_prompt(VM *vm) {
  if (signal(SIGINT, int_handler) == SIG_ERR) {
    fprintf(stderr, "Failed to regsiter interrupt.");
  }

  while (1) {
    while (sigsetjmp(ctrlc_buf, 1) != 0) {}

    // read input
    char *buffer = readline("> ");
    keep_running = 1;

    if (!buffer) {
      break;
    }

    if (is_not_blank(buffer)) {
      add_history(buffer);
    }

    code_preprocess(buffer);

    size_t len = strnlen(buffer, vm->cs_size);

    if (len > vm->cs_size) {
      errno = ERR_TOO_LONG_CODE;
      print_error();
    } else if (len > 0) {
      snprintf(vm->cs, len + 1, "%s", buffer);

      vm_run(vm);
      vm_reset(vm);

      fprintf(stdout, "\n");
    }

    free(buffer);
  }
}

void run_with_prompt(VM *vm) {
  input_prompt(vm);
}
