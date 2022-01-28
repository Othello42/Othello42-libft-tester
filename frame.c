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
		printf(C_BOLD"Legend"C_RESET"\n");
		printf(C_GREEN"[OK]"C_RESET"\tTest checks out.\n");
		printf(C_RED"[KO]"C_RESET"\tTest has failed on basic functionality.\n");
		printf(C_ORANGE"[KO]"C_RESET"\tTest has failed on an edge case.\n");
		printf(C_DGREY"[KO]"C_RESET"\tTest failed to execute.\n");
		printf("\n");
		printf(C_BLUE"[LK]"C_RESET"\tTest contains no leaks.\n");
		printf(C_ORANGE"[LK]"C_RESET"\tFunction leaks at some point.\n");
		printf(C_YELLOW"[CHECK]"C_RESET"\tCheck for possible error. Such as illegal function.\n");
		printf("\n");
		printf("Read "C_BLUE"errorlog.txt"C_RESET" for more information.\n");
		fd = open("errorlog.txt", O_TRUNC | O_CREAT, 0666);
		close(fd);
	}
	if (HEAD == 1)
		printf(C_BOLD"\nMandatory Part - Libc functions"C_RESET"\n");
	if (HEAD == 2)
		printf(C_BOLD"\nMandatory Part - Additional functions"C_RESET"\n");
	if (HEAD == 3)
		printf(C_BOLD"\nBonus Part"C_RESET"\n");
}
