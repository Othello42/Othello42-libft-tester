SHELL := /bin/bash

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PROJECT = ../libft/

LIB = $(PROJECT)libft.a

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
TEST = 1

all: lib a

a: lib head manl mana lib_b bonus

m: lib head manl mana

manl: manlhead
	@NUM=$(MANL_START) ; while [[ $$NUM -le $(MANL_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_normal.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

mana: manahead
	@NUM=$(MANA_START) ; while [[ $$NUM -le $(MANA_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_additional.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

b: lib_b head bonus

bonus: bonhead
	@NUM=$(BON_START) ; while [[ $$NUM -le $(BON_END) ]] ; do \
		$(CC) $(CFLAGS) main.c test_bonus.c utils.c -L$(PROJECT) -lft -D TEST=$$NUM -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done

head:
	@$(CC) $(CFLAGS) frame.c -D HEAD=0 -o frame.out && ./frame.out
	@rm frame.out

manlhead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=1 -o frame.out && ./frame.out
	@rm frame.out

manahead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=2 -o frame.out && ./frame.out
	@rm frame.out

bonhead:
	@$(CC) $(CFLAGS) frame.c -D HEAD=3 -o frame.out && ./frame.out
	@rm frame.out

lib:
	make -C $(PROJECT)
	
lib_b:
	make bonus -C $(PROJECT)

test: lib head t

t: 
	@NUM=$(TEST) ; while [[ $$NUM -le $(TEST) ]] ; do \
		$(CC) $(CFLAGS) $(SCR) -L$(PROJECT) -lft -D TEST=$$NUM -o test.out && ./test.out; \
		((NUM = NUM + 1)) ; \
    done