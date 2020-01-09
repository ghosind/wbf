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

#include <preprocess.h>

void code_preprocess(char *code) {
  char *ptr = code;
  int inComment = 0;

  while (*code) {
    if (inComment) {
      if (*code == '\n') {
        inComment = 0;
      }
      code++;
      continue;
    }

    switch (*code) {
      case '#':
        inComment = 1;
        code++;
        break;
      case '+':
      case '-':
      case '<':
      case '>':
      case '[':
      case ']':
      case ',':
      case '.':
        *ptr = *code;
        ptr++;
      default:
        code++;
        break;
    }
  }

  *ptr = '\0';
}
