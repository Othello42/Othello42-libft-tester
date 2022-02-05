#include "h_colors.h"

#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close

int	main(void)
{
	int	fd;

	if (HEAD == 0)
	{
		printf("\n\t"C_HEADER" Othello's libft Tester "C_RESET"\n\n");
		printf(C_BOLD"\n\tLegend"C_RESET"\n");
		printf(C_GREEN"[OK]"C_RESET"\tTest checks out.\n");
		printf(C_RED"[KO]"C_RESET"\tTest has failed on basic functionality.\n");
		printf(C_ORANGE"[KO]"C_RESET"\tTest has failed on an edge case.\n");
		printf(C_DGREY"[KO]"C_RESET"\tTest failed to execute.\n");
		printf("\n");
		printf(C_BLUE"[PR"C_ORANGE"OT]"C_RESET"\tFunctions "C_BLUE"is"C_RESET"/"C_ORANGE"isn't"C_RESET" protected.\n");
		printf(C_ORANGE"[L"C_BLUE"K]"C_RESET"\tFunction "C_ORANGE"does"C_RESET"/"C_BLUE"doesn't"C_RESET" contain leaks at some point.\n");
		printf(C_YELLOW"[CHECK]"C_RESET"\tCheck for possible error. Such as illegal function.\n");
		printf("\n");
		printf("Read "C_BLUE"errorlog.txt"C_RESET" for more information.\n");
		fd = open("errorlog.txt", O_TRUNC | O_CREAT, 0666);
		close(fd);
	}
	if (HEAD == 1)
		printf(C_BOLD"\n\n\tMakefile relink."C_RESET"\n");
	if (HEAD == 2)
		printf(C_BOLD"\n\n\tMandatory Part - Libc functions"C_RESET"\n");
	if (HEAD == 3)
		printf(C_BOLD"\n\n\tMandatory Part - Additional functions"C_RESET"\n");
	if (HEAD == 4)
		printf(C_BOLD"\n\n\tBonus Part"C_RESET"\n");
}
