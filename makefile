SHELL := /bin/bash

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Adjust to libft.a's directory location.
PROJECT = ../libft/
#Adjust to libft source files' location.
SRC_PATH = '"../libft/"'

SCR = main.c\
		test_normal.c\
		test_additional.c\
		test_bonus.c\
		utils.c

MANL_START = 1
MANL_END = 23
MANA_START = 24
MANA_END = 34
BON_START = 35
BON_END = 43
#Adjust to desired function.
TEST = 1

all: libre head linkhead libman libbon manl mana bonus

a: libre head manl mana bonus

l: libre linkhead libman libbon

m: libman head manl mana

b: libbon head bonus

t: libbon libman head test

manl: manlhead
	@NUM=$(MANL_START) ; while [[ $$NUM -le $(MANL_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_normal.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -D SRC_PATH=$(SRC_PATH) -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

mana: manahead
	@NUM=$(MANA_START) ; while [[ $$NUM -le $(MANA_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_additional.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -D SRC_PATH=$(SRC_PATH) -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

bonus: bonhead
	@NUM=$(BON_START) ; while [[ $$NUM -le $(BON_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_bonus.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -D SRC_PATH=$(SRC_PATH) -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

test: 
	@NUM=$(TEST) ; while [[ $$NUM -le $(TEST) ]] ; do \
		$(CC) $(CFLAGS) $(SCR) -L$(PROJECT) -lft -D TEST=$$NUM -D SRC_PATH=$(SRC_PATH) -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

head:
	@$(CC) $(CFLAGS) frame.c -D HEAD=0 -o frame.out && ./frame.out
	@rm frame.out

linkhead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=1 -o frame.out && ./frame.out
	@rm frame.out

manlhead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=2 -o frame.out && ./frame.out
	@rm frame.out

manahead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=3 -o frame.out && ./frame.out
	@rm frame.out

bonhead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=4 -o frame.out && ./frame.out
	@rm frame.out

libre:
	@make fclean -C $(PROJECT)
	@make bonus -C $(PROJECT)
	@make -C $(PROJECT)

libman:
	@make -C $(PROJECT)
	
libbon:
	@make bonus -C $(PROJECT)