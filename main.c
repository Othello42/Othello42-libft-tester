#include "h_colors.h"
#include "h_function_names.h"
#include "h_check_prototypes.h"
#include "h_utils_prototypes.h"
#include "h_os_version.h"

#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h> //system
#include <string.h> //strcmp

void	check_forbidden(void);

int	main(void)
{
	int	fd;

	printf(C_BOLD NAME C_RESET"\t");
	if (TEST >= 1 && TEST <= 34)
		fd = open(PATH FUNCTION, O_RDONLY);
	else if (TEST >= 35 && TEST <= 43)
	{
		fd = open(PATH FUNCTION"_bonus.c", O_RDONLY);
		if (fd == -1)
		{
			fd = open(PATH FUNCTION".c", O_RDONLY);
			if (fd > 0)
				printf("File name should be: "C_YELLOW NAME"_bonus.c"C_RESET"\n\t\t");
		}
	}
	if (fd == -1)
		printf(C_RED"[FILE NOT FOUND]"C_RESET" ");
	else
		CHECK();
	close(fd);
	leak_check();
	check_forbidden();
	errorlog_fd(0);
	printf("\n");
}
