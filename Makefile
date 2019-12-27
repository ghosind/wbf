# wbf - A brainfuck interpreter
# Copyright (C) 2018, Chen Su <ghosind@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./dist

SRC = $(wildcard ${DIR_SRC}/*.c)
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC}))

TARGET = wbf

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = gcc
CFLAGS = -Wall -I ${DIR_INC}

${BIN_TARGET}: ${OBJ}
	@if [ ! -d $(DIR_BIN) ]; then mkdir $(DIR_BIN); fi;
	$(CC) $(OBJ)  -o $@ -lreadline

${DIR_OBJ}/%.o: ${DIR_SRC}/%.c
	@if [ ! -d $(DIR_OBJ) ]; then mkdir $(DIR_OBJ); fi;
	$(CC) $(CFLAGS) -c  $< -o $@

.PHONY: clean
clean:
	rm ${DIR_BIN}/*
	rm $(DIR_OBJ)/*.o