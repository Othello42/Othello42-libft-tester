# Othello42-libft-tester



## Setting up
Tester is setup to run in a directory NEXT to your libft directory.
Here it looks for the makefile and the libft.a file
Adjust PROJECT if it is elsewhere.

Tester is setup to look for .c files in your libft directory.
[FILE NOT FOUND] errors could be caused by bad PATH directions.
Adjust PATH in h_function_names.h to where your source files are.



## Running:
Test everything:	make
Test mandatory:		make m
Test bonus:		make b
Test specific:		Adjust TEST (number can be found in h_function_names.h)
			make test