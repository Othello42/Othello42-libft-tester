#include "h_colors.h"
#include "h_check_prototypes.h"
#include "h_utils_prototypes.h"
#include "h_function_names.h"
#include "h_os_version.h"

#include "libft.h"

#include <stdio.h> //printf

#include <ctype.h> //isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower
#include <string.h> //strlen, memset, memcpy, memmove, strchr, strrchr, strncmp, memchr, memcmp, strdup
					//strlcpy, strlcat, strnstr (not found in linux)
#include <strings.h> //bzero
#include <stdlib.h> //atoi, calloc


/* ====================================||==================================== *\
||																			  ||
||								   TEST == 1								  ||
||								   ft_isalpha								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_isalpha_2(int low, int high);
static int	util_ft_check_isalpha(int c);

void	check_ft_isalpha(void)
{
	check_ft_isalpha_2(32, 126);
	check_ft_isalpha_2(0, 127);
	check_ft_isalpha_2(128, 255);
	check_ft_isalpha_2(-384, -1);
}

static void	check_ft_isalpha_2(int low, int high)
{
	int	comp;
	int	check;
	int	fd;

	fd = 0;
	check = 0;
	while (low <= high)
	{
		comp = util_ft_check_isalpha(low);
		if ((ft_isalpha(low) != comp))
		{
			if (check == 0)
			{
				check = 1;
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");

			}
			if (fd == 0)
				fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "isalpha returns:\t%i\n", isalpha(low));
			dprintf(fd, "ft_isalpha returns:\t%i\n", ft_isalpha(low));
			dprintf(fd, "\n\n");
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	util_ft_check_isalpha(int c)
{
	int	ret;

	ret = isalpha(c);
	if (strcmp(OS, "linux") == 0 && ret == 1024)
		ret = 1;
	if (strcmp(OS, "windows 64bit") == 0 && (ret == 1 || ret == 2))
		ret = 1;
	return (ret);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 2								  ||
||								   ft_isdigit								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_isdigit_2(int low, int high);
static int	util_ft_check_isdigit(int c);

void	check_ft_isdigit(void)
{
	check_ft_isdigit_2(32, 126);
	check_ft_isdigit_2(0, 127);
	check_ft_isdigit_2(128, 255);
	check_ft_isdigit_2(-384, -1);
}

static void	check_ft_isdigit_2(int low, int high)
{
	int	comp;
	int	check;
	int	fd;

	check = 0;
	fd = 0;
	while (low <= high)
	{
		comp = util_ft_check_isdigit(low);
		if (ft_isdigit(low) != comp)
		{
			if (check == 0)
			{
				check = 1;
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");

			}
			if (fd == 0)
				fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "isdigit returns:\t%i\n", isdigit(low));
			dprintf(fd, "ft_isdigit returns:\t%i\n", ft_isdigit(low));
			dprintf(fd, "\n\n");
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	util_ft_check_isdigit(int c)
{
	int	ret;

	ret = isdigit(c);
	if (strcmp(OS, "linux") == 0 && ret == 2048)
		ret = 1;
	return (ret);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 3								  ||
||								   ft_isalnum								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_isalnum_2(int low, int high);
static int	util_ft_check_isalnum(int c);

void	check_ft_isalnum(void)
{
	check_ft_isalnum_2(32, 126);
	check_ft_isalnum_2(0, 127);
	check_ft_isalnum_2(128, 255);
	check_ft_isalnum_2(-384, -1);
}

static void	check_ft_isalnum_2(int low, int high)
{
	int	comp;
	int	check;
	int	fd;

	check = 0;
	fd = 0;
	while (low <= high)
	{
		comp = util_ft_check_isalnum(low);
		if (ft_isalnum(low) != comp)
		{
			if (check == 0)
			{
				check = 1;
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");

			}
			if (fd == 0)
				fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "isalnum returns:\t%i\n", isalnum(low));
			dprintf(fd, "ft_isalnum returns:\t%i\n", ft_isalnum(low));
			dprintf(fd, "\n\n");
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	util_ft_check_isalnum(int c)
{
	int	ret;

	ret = isalnum(c);
	if (strcmp(OS, "linux") == 0 && ret == 8)
		ret = 1;
	if (strcmp(OS, "windows 64bit") == 0 && (ret == 1 || ret == 2 || ret == 4))
		ret = 1;
	return (ret);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 4								  ||
||								   ft_isascii								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_isascii_2(int low, int high);

void	check_ft_isascii(void)
{
	check_ft_isascii_2(0, 127);
	check_ft_isascii_2(128, 255);
	check_ft_isascii_2(-384, -1);
}

static void	check_ft_isascii_2(int low, int high)
{
	int	check;
	int	fd;

	check = 0;
	fd = 0;
	while (low <= high)
	{
		if (isascii(low) != ft_isascii(low))
		{
			if (check == 0)
			{
				check = 1;
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");

			}
			if (fd == 0)
				fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "isascii returns:\t%i\n", isascii(low));
			dprintf(fd, "ft_isascii returns:\t%i\n", ft_isascii(low));
			dprintf(fd, "\n\n");
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}
/* ====================================||==================================== *\
||																			  ||
||								   TEST == 5								  ||
||								   ft_isprint								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_isprint_2(int low, int high);
// static int	util_ft_check_isprint(int c);

void	check_ft_isprint(void)
{
	check_ft_isprint_2(0, 127);
	check_ft_isprint_2(128, 255);
	check_ft_isprint_2(-384, -1);
}

static void	check_ft_isprint_2(int low, int high)
{
	int	check;
	int	fd;

	check = 0;
	fd = 0;
	while (low <= high)
	{
		if ((isprint(low) != 0 && ft_isprint(low) == 0) || (isprint(low) == 0 && ft_isprint(low) != 0))
		{
			if (check == 0)
			{
				check = 1;
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");

			}
			if (fd == 0)
				fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "isprint returns:\t%i\n", isprint(low));
			dprintf(fd, "ft_isprint returns:\t%i\n", ft_isprint(low));
			dprintf(fd, "\n\n");
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

// static int	util_ft_check_isprint(int c)
// {
// 	int	ret;

// 	ret = isprint(c);
// 	if (strcmp(OS, "linux") == 0 && ret == 16384)
// 		ret = 1;
// 	if (strcmp(OS, "windows 64bit") == 0 && (ret == 1 || ret == 2 || ret == 4 || ret == 16 || ret == 64))
// 		ret = 1;
// 	return (ret);
// }

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 6								  ||
||								   ft_strlen								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strlen_2(const char *s);

void	check_ft_strlen(void)
{
	check_ft_strlen_2("Lorem");
	check_ft_strlen_2("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	check_ft_strlen_2("Lorem\nipsum");
	check_ft_strlen_2("1234567890");
	check_ft_strlen_2("123456789\0");
	check_ft_strlen_2("!@#$%^&*\\()");
	check_ft_strlen_2("");
	check_ft_strlen_2("\0");
	check_ft_strlen_2("z\31m");
	check_ft_strlen_2("\127\127\127");
	check_ft_strlen_2("Lorem\200ipsum");
	printf("\n\t\t");
	check_ft_strlen_2("\n\n\f\r\t");
	check_ft_strlen_2("   ");
}

static void	check_ft_strlen_2(const char *s)
{
	int fd;

	if (strlen(s) != ft_strlen(s))
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Counting characters from string \"%s\"\n", s);
		dprintf(fd, "strlen returns:\t%li\n", strlen(s));
		dprintf(fd, "ft_strlen returns:\t%li\n", ft_strlen(s));
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 7								  ||
||								   ft_memset								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_memset_2(char *b, int c, size_t len);

void	check_ft_memset(void)
{
	check_ft_memset_2("Lorem ipsum", 'a', 5);
	check_ft_memset_2("Lorem ipsum", 0, 5);
	check_ft_memset_2("Lorem ipsum", 'a', 0);
	check_ft_memset_2("", 'a', 5);
}

static void	check_ft_memset_2(char *b, int c, size_t len)
{
	char	b1[99];
	char	b2[99];
	int		fd;

	strcpy(b1, b);
	strcpy(b2, b);
	if (strcmp(memset(&b1, c, len), ft_memset(&b2, c, len)) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Setting the first %li characters from the string to '%c'\n", len, c);
		dprintf(fd, "memset returns:\t%s\n", b1);
		dprintf(fd, "ft_memset returns:\t%s\n", b2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 8								  ||
||								    ft_bzero									  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_bzero_2(char *b, size_t len);

void	check_ft_bzero(void)
{
	check_ft_bzero_2("Lorem ipsum", 5);
	check_ft_bzero_2("Lorem ipsum", 0);
	check_ft_bzero_2("", 5);
}

static void	check_ft_bzero_2(char *b, size_t len)
{
	char	b1[99];
	char	b2[99];
	size_t	i;
	int		fd;

	strcpy(b1, b);
	strcpy(b2, b);
	bzero(b1, len);
	ft_bzero(b2, len);
	i = 0;
	while (i < strlen(b))
	{
		if (b1[i] != b2[i])
		{
			printf(C_RED"[KO]"C_RESET" ");
			fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "Setting the first %li characters from the string '%s'to '0'\n", len, b);
			dprintf(fd, "bzero returns:\t\t");
			i = 0;
			while (i < strlen(b))
			{
				if (b1[i] == 0)
					dprintf(fd, "0");
				else
					dprintf(fd, "%c", b1[i]);
				i++;
			}
			dprintf(fd, "\n");
			dprintf(fd, "ft_bzero returns:\t");
			i = 0;
			while (i < strlen(b))
			{
				if (b2[i] == 0)
					dprintf(fd, "0");
				else
					dprintf(fd, "%c", b2[i]);
				i++;
			}
			dprintf(fd, "\n");
			dprintf(fd, "\n\n");

			return ;
		}
		i++;
	}
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 9								  ||
||								   ft_memcpy								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_memcpy_2(char *dst, char *src, size_t n);
static void	check_ft_memcpy_3(char *dst1, char *dst2, char *src, size_t n);

void	check_ft_memcpy(void)
{
	check_ft_memcpy_2("Lorem ipsum", "1234567890", 1);
	check_ft_memcpy_2("Lorem ipsum", "1234567890", 7);
	check_ft_memcpy_2("Lorem ipsum", "1234567890", 23);
	check_ft_memcpy_2("Lorem ipsum", "1234567890", 0);
	check_ft_memcpy_2("Lorem ipsum", "", 7);
	check_ft_memcpy_2("Lorem ipsum", "", 23);
	check_ft_memcpy_2("Lorem ipsum", "", 0);
	check_ft_memcpy_2("Lorem ipsum", NULL, 0);
	check_ft_memcpy_2("", "1234567890", 7);
	check_ft_memcpy_2("", "1234567890", 23);
	check_ft_memcpy_2("", "1234567890", 0);
	printf("\n\t\t");
	check_ft_memcpy_2("", "", 7);
	check_ft_memcpy_2("", "", 23);
	check_ft_memcpy_2("", "", 0);
	ft_memcpy(NULL, "1234567890", 0);
	ft_memcpy(NULL, NULL, 7);
	ft_memcpy(NULL, NULL, 0);
	ft_memcpy(((void *)0), ((void *)0), 0);
}

static void	check_ft_memcpy_2(char *dst, char *src, size_t n)
{
	char	*dst1;
	char	*dst2;
	char	*src1;

	dst1 = NULL;
	dst2 = NULL;
	src1 = NULL;
	if (dst != NULL)
	{
		dst1 = (char *)ft_calloc(sizeof(char), 42);
		dst2 = (char *)ft_calloc(sizeof(char), 42);
		memcpy(dst1, dst, strlen(dst));
		memcpy(dst2, dst, strlen(dst));
	}
	if (src != NULL)
	{
		src1 = (char *)ft_calloc(sizeof(char), 42);
		memcpy(src1, src, strlen(src));
		src1[21] = '!';
		src1[22] = '!';
		src1[23] = '!';
	}
	check_ft_memcpy_3(dst1, dst2, src1, n);
	free(dst1);
	free(dst2);
	free(src1);
}

static void	check_ft_memcpy_3(char *dst1, char *dst2, char *src, size_t n)
{
	int	fd;
	int	i;
	int	check;

	memcpy(dst1, src, n);
	memcpy(dst2, src, n);
	i = 0;
	check = 0;
	while (i < 41)
	{
		if (dst1[i] != dst2[i])
		{
			check = -1;
			break ;
		}
		i++;
	}
	if (check == -1)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Setting the first %li characters from the string to '%s' to string '%s'\n", n, src, dst1);
		dprintf(fd, "%14s returns:\t'%s%s'\n", "memcpy", dst1, &dst1[i]);
		dprintf(fd, "%14s returns:\t'%s%s'\n", "ft_memcpy", dst2, &dst2[i]);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 10								  ||
||								   ft_memmove								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_memmove_2(void *dest, const void *src, size_t n);
static void	check_ft_memmove_3(void *dest, int pos, size_t n);

void	check_ft_memmove(void)
{
	check_ft_memmove_2("0123456789", "Lorem Ipsum", 7);
	check_ft_memmove_2("0123456789", "Lorem Ipsum", 0);
	check_ft_memmove_2("0123456789", "Lorem Ipsum", 11);
	check_ft_memmove_2("0123456789", "Lorem Ipsum", 42);
	check_ft_memmove_2("", "Lorem Ipsum", 7);
	check_ft_memmove_2("0123465789", "", 7);
	check_ft_memmove_2("", "", 7);
	check_ft_memmove_3("Lorem Ipsum", 1, 7);
	check_ft_memmove_3("Lorem Ipsum", 0, 7);
	check_ft_memmove_3("Lorem Ipsum", -1, 7);
}

static void	check_ft_memmove_2(void *dest, const void *src, size_t n)
{
	char	copy1[99];
	char	copy2[99];
	int		fd;

	bzero(copy1, 99);
	bzero(copy2, 99);
	strcpy(copy1, dest);
	strcpy(copy2, dest);
	memmove(copy1, src, n);
	ft_memmove(copy2, src, n);
	if (strcmp(copy1, copy2) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Moving %li bytes of memory from string from string %s to string %s.\n", n, (char *)src, (char *)dest);
		dprintf(fd, "memmove returns:\t%s\n", copy1);
		dprintf(fd, "ft_memmove returns:\t%s\n", copy2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

static void	check_ft_memmove_3(void *dest, int pos, size_t n)
{
	char	copy1[99];
	char	copy2[99];
	int		fd;

	strcpy(copy1, dest);
	strcpy(copy2, dest);
	if (pos >= 0)
	{
		memmove(copy1, &copy1[pos], n);
		ft_memmove(copy2, &copy2[pos], n);
	}
	else if (pos < 0)
	{
		memmove(&copy1[pos *-1], copy1, n);
		ft_memmove(&copy2[pos *-1], copy2, n);
	}
	if (strcmp(copy1, copy2) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Moving %li bytes of memory from string from %s forward by %i bytes.\n", n, (char *)dest, pos);
		dprintf(fd, "memmove returns:\t%s\n", copy1);
		dprintf(fd, "ft_memmove returns:\t%s\n", copy2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 11								  ||
||								   ft_strlcpy								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strlcpy_2(char *dst, const char *src, size_t dstsize);

void	check_ft_strlcpy(void)
{
	if (strcmp(OS, "apple") == 0)
	{
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 6);
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 11);
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 12);
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 27);
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 42);
		check_ft_strlcpy_2("qwertyuiop", "Lorem ipsum dolor sit amet", 0);
		check_ft_strlcpy_2("Lorem ipsum dolor sit amet", "qwertyuiop", 7);
		check_ft_strlcpy_2("", "Lorem ipsum dolor sit amet", 12);
		check_ft_strlcpy_2("qwertyuiop", "", 12);
		check_ft_strlcpy_2("", "", 12);
	}
	else
		printf(C_RED"function not found in linux"C_RESET" ");	
}

static void	check_ft_strlcpy_2(char *dst, const char *src, size_t dstsize)
{
	char	copy1[99];
	char	copy2[99];
	size_t	ret1;
	size_t	ret2;
	int		fd;

	bzero(copy1, 99);
	bzero(copy2, 99);
	strcpy(copy1, dst);
	strcpy(copy2, dst);
	ret1 = strlcpy(copy1, src, dstsize);
	ret2 = ft_strlcpy(copy2, src, dstsize);
	if (strcmp(copy1, copy2) != 0 || ret1 != ret2)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Copying the first %li bytes from '%s' to '%s'.\n", dstsize, src, dst);
		dprintf(fd, "   strlcpy:\t%s\n", copy1);
		dprintf(fd, "\treturn:\t%li\n", ret1);
		dprintf(fd, "ft_strlcpy:\t%s\n", copy2);
		dprintf(fd, " ft_return:\t%li\n", ret2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 12								  ||
||								   ft_strlcat								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strlcat_2(char *dst, const char *src, size_t dstsize);

void	check_ft_strlcat(void)
{
	if (strcmp(OS, "apple") == 0)
	{
		check_ft_strlcat_2("Lorem ipsum", " dolor sit amet", 27);
		check_ft_strlcat_2("Lorem", " ipsum dolor sit amet", 12);
		check_ft_strlcat_2("Lorem ipsum", " dolor sit amet", 11);
		check_ft_strlcat_2("Lorem ipsum", " dolor sit amet", 0);
		check_ft_strlcat_2("Lorem ipsum", " dolor sit amet", 99);
		check_ft_strlcat_2("", "Lorem ipsum dolor sit amet", 42);
		check_ft_strlcat_2("Lorem ipsum dolor sit amet", "", 42);
		check_ft_strlcat_2("", "", 42);
	}
	else
		printf(C_RED"function not found in linux"C_RESET" "); //windows
}

static void	check_ft_strlcat_2(char *dst, const char *src, size_t dstsize)
{
	char	copy1[99];
	char	copy2[99];
	size_t	ret1;
	size_t	ret2;
	int		fd;

	bzero(copy1, 99);
	bzero(copy2, 99);
	strcpy(copy1, dst);
	strcpy(copy2, dst);
	ret1 = strlcat(copy1, src, dstsize);
	ret2 = ft_strlcat(copy2, src, dstsize);
	if (strcmp(copy1, copy2) != 0 || ret1 != ret2)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Copying the first %li bytes from '%s' to '%s'.\n", dstsize, src, dst);
		dprintf(fd, "   strlcat:\t%s\n", copy1);
		dprintf(fd, "\treturn:\t%li\n", ret1);
		dprintf(fd, "ft_strlcat:\t%s\n", copy2);
		dprintf(fd, " ft_return:\t%li\n", ret2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 13								  ||
||								   ft_toupper								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_toupper_2(int low, int high);
static int	util_ft_check_toupper(int c);

void	check_ft_toupper(void)
{
	check_ft_toupper_2(0, 127);
	check_ft_toupper_2(128, 255);
	check_ft_toupper_2(-384, -1);
}

static void	check_ft_toupper_2(int low, int high)
{
	int	comp;
	int	check;
	int	fd;

	check = 0;
	while (low <= high)
	{
		comp = util_ft_check_toupper(low);
		if (ft_toupper(low) != comp)
		{
			printf("%i = %i\n", comp, ft_toupper(low));
			if (check == 0)
			{
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");
				fd = errorlog_fd(1);
			}
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "toupper returns:\t%i\n", comp);
			dprintf(fd, "ft_toupper returns:\t%i\n", ft_toupper(low));
			dprintf(fd, "\n\n");
			check = 1;
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	util_ft_check_toupper(int c)
{
	int	ret;

	ret = toupper(c);
	if (strcmp(OS, "linux") == 0 && c < 0)
		ret = c;
	return (ret);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 14								  ||
||								   ft_tolower								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_tolower_2(int low, int high);
static int	util_ft_check_tolower(int c);

void	check_ft_tolower(void)
{
	check_ft_tolower_2(0, 127);
	check_ft_tolower_2(128, 255);
	check_ft_tolower_2(-384, -1);
}

static void	check_ft_tolower_2(int low, int high)
{
	int	comp;
	int	check;
	int	fd;

	check = 0;
	while (low <= high)
	{
		comp = util_ft_check_tolower(low);
		if (ft_tolower(low) != comp)
		{
			if (check == 0)
			{
				if (low >=0 && low <= 127)
					printf(C_RED"[KO]"C_RESET" ");
				else
					printf(C_ORANGE"[KO]"C_RESET" ");
				fd = errorlog_fd(1);
			}
			dprintf(fd, NAME"\n");
			dprintf(fd, "input value of '%i' for character '%c'\n", low, low);
			dprintf(fd, "tolower returns:\t%i\n", tolower(low));
			dprintf(fd, "ft_tolower returns:\t%i\n", ft_tolower(low));
			dprintf(fd, "\n\n");
			check = 1;
		}
		low++;
	}
	if (check == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	util_ft_check_tolower(int c)
{
	int	ret;

	ret = tolower(c);
	if (strcmp(OS, "linux") == 0 && c < 0)
		ret = c;
	return (ret);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 15								  ||
||								   ft_strchr								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strchr_2(const char *s, int c);

void	check_ft_strchr(void)
{
	check_ft_strchr_2("Lorem ipsum", 'L');
	check_ft_strchr_2("Lorem ipsum", 'e');
	check_ft_strchr_2("Lorem ipsum dolor sit", ' ');
	check_ft_strchr_2("Lorem ipsum dolor sit", 't');
	check_ft_strchr_2("Lorem ipsum", 'q');
	check_ft_strchr_2("", '\0');
	check_ft_strchr_2("Lorem ipsum", 'o' + 128);
	check_ft_strchr_2("Lorem ipsum", 'o' + 256);
	check_ft_strchr_2("Lorem ipsum", 'o' + 7897);

}

static void	check_ft_strchr_2(const char *s, int c)
{
	char	*ft;
	char	*check;
	int		fd;

	ft = ft_strchr(s, c);
	check = strchr(s, c);
	if (ft != check)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Looking for the first occurence of character '%c' in string '%s'\n", c, s);
		dprintf(fd, "strchr returns:\t\taddress %p\tfor string '%s'\n", check, check);
		dprintf(fd, "ft_strchr returns:\taddress %p\tfor string '%s'\n", ft, ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 16								  ||
||								   ft_strrchr								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strrchr_2(const char *s, int c);

void	check_ft_strrchr(void)
{
	check_ft_strrchr_2("Lorem ipsum", 'L');
	check_ft_strrchr_2("Lorem ipsum", 'e');
	check_ft_strrchr_2("Lorem ipsum dolor sit", ' ');
	check_ft_strrchr_2("Lorem ipsum dolor sit", 't');
	check_ft_strrchr_2("Lorem ipsum", 'q');
	check_ft_strrchr_2("", '\0');
	check_ft_strrchr_2("Lorem ipsum", 'o' + 128);
	check_ft_strrchr_2("Lorem ipsum", 'o' + 256);
	check_ft_strrchr_2("Lorem ipsum", 'o' + 7897);

}

static void	check_ft_strrchr_2(const char *s, int c)
{
	char	*ft;
	char	*check;
	int		fd;

	ft = ft_strrchr(s, c);
	check = strrchr(s, c);
	if (ft != check)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Looking for the last occurence of character '%c' in string '%s'\n", c, s);
		dprintf(fd, "strrchr returns:\t\taddress %p\tfor string '%s'\n", check, check);
		dprintf(fd, "ft_strrchr returns:\taddress %p\tfor string '%s'\n", ft, ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 17								  ||
||								   ft_strncmp								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strncmp_2(const char *s1, const char *s2, size_t n);

void	check_ft_strncmp(void)
{
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 10);
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 0);
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 1);
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 6);
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 7);
	check_ft_strncmp_2("Lorem ipsum", "Lorem Ipsum", 8);
	check_ft_strncmp_2("Lorem ipsum", "L0rem ipsum", 7);
	check_ft_strncmp_2("Lorem ipsum", "Lorem \200psum", 7);
	check_ft_strncmp_2("Lorem ipsum", "", 7);
	check_ft_strncmp_2("", "Lorem ipsum", 7);
	check_ft_strncmp_2("", "", 7);
}

static void	check_ft_strncmp_2(const char *s1, const char *s2, size_t n)
{
	int	ft;
	int	check;
	int fd;

	check = strncmp(s1, s2, n);
	ft = ft_strncmp(s1, s2, n);
	if (check != ft)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Comparing the first %li characters from string '%s' with string '%s'\n", n, s1, s2);
		dprintf(fd, "strncmp returns:\t\t%i\n", check);
		dprintf(fd, "ft_strncmp returns:\t\t%i\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 18								  ||
||								   ft_memchr								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_memchr_2(const char *s, int c, size_t n);

void	check_ft_memchr(void)
{
	check_ft_memchr_2("Lorem ipsum", 'L', 10);
	check_ft_memchr_2("Lorem ipsum", 'L', 0);
	check_ft_memchr_2("Lorem ipsum", 'L', 1);
	check_ft_memchr_2("Lorem ipsum", 'L', 42);
	check_ft_memchr_2("Lorem ipsum", 'e', 42);
	check_ft_memchr_2("Lorem ipsum dolor sit", ' ', 42);
	check_ft_memchr_2("Lorem ipsum dolor sit", 't', 42);
	check_ft_memchr_2("Lorem ipsum", 'q', 42);
	check_ft_memchr_2("", '\0', 42);
	check_ft_memchr_2("Lorem ipsum", 'o' + 128, 42);
	check_ft_memchr_2("Lorem ipsum", 'o' + 256, 42);
	printf("\n\t\t");
	check_ft_memchr_2("Lorem ipsum", 'o' + 7897, 42);

}

static void	check_ft_memchr_2(const char *s, int c, size_t n)
{
	char	*ft;
	char	*check;
	int		fd;

	ft = ft_memchr(s, c, n);
	check = memchr(s, c, n);
	if (ft != check)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Looking for the first occurence of character '%c' in the first %li bytes of string '%s'\n", c, n, s);
		dprintf(fd, "memchr returns:\t\taddress %p\tfor string '%s'\n", check, check);
		dprintf(fd, "ft_memchr returns:\taddress %p\tfor string '%s'\n", ft, ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 19								  ||
||								   ft_memcmp								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_memcmp_2(const char *s1, const char *s2, size_t n);
static int	utils_ft_memcmp(const char *s1, const char *s2, size_t n);

void	check_ft_memcmp(void)
{
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 10);
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 0);
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 1);
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 6);
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 7);
	check_ft_memcmp_2("Lorem ipsum", "Lorem Ipsum", 8);
	check_ft_memcmp_2("Lorem ipsum", "L0rem ipsum", 7);
	check_ft_memcmp_2("Lorem ipsum", "Lorem \200psum", 7);
	check_ft_memcmp_2("Lorem ipsum", "", 7);
	check_ft_memcmp_2("", "Lorem ipsum", 7);
	check_ft_memcmp_2("", "", 7);
}

static void	check_ft_memcmp_2(const char *s1, const char *s2, size_t n)
{
	int	ft;
	int	check;
	int fd;

	check = utils_ft_memcmp(s1, s2, n);
	ft = ft_memcmp(s1, s2, n);
	if (check != ft)
	{
			printf(C_RED"[KO]"C_RESET" ");
			fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "Comparing the first %li characters from string '%s' with string '%s'\n", n, s1, s2);
			dprintf(fd, "memcmp returns:\t\t%i\n", check);
			dprintf(fd, "ft_memcmp returns:\t%i\n", ft);
			dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

static int	utils_ft_memcmp(const char *s1, const char *s2, size_t n)
{
	if (strcmp(OS, "linux") == 0)
		return (strncmp(s1, s2, n));
	if (strcmp(OS, "windows 64bit") == 0)
		return (strncmp(s1, s2, n));
	return (memcmp(s1, s2, n));
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 20								  ||
||								   ft_strnstr								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strnstr_2(const char *haystack, const char *needle, size_t len);

void	check_ft_strnstr(void)
{
	if (strcmp(OS, "apple") == 0)
	{
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolor", 42);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolar", 42);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolor", 7);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolor", 17);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolor", 16);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "dolor", 0);
		check_ft_strnstr_2("Lorem ipsum dolor ipsum", "ipsum", 42);
		check_ft_strnstr_2("LLorem ipsum", "Lorem", 42);
		check_ft_strnstr_2("LLLorem ipsum", "Lorem", 42);
		check_ft_strnstr_2("Lorem ipsum dolor sit amet", "", 42);
		check_ft_strnstr_2("", "dolor", 42);
		printf("\n\t\t");
		check_ft_strnstr_2("", "", 42);
	}
	else
		printf(C_RED"function not found in linux"C_RESET" ");
}

static void	check_ft_strnstr_2(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*needle1;
	char	*needle2;
	int		fd;

	hay = (char *)calloc(1, strlen(haystack) + 1);
	strcpy(hay, haystack);
	needle1 = strnstr(hay, needle, len);
	needle2 = ft_strnstr(hay, needle, len);
	if (needle1 != needle2)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Finding first occurence of needle '%s' withinin the first %li bytes of haystack '%s'.\n", needle, len, haystack);
		dprintf(fd, "strnstr returns:\t\t%p\tfor string '%s'\n", needle1, needle1);
		dprintf(fd, "ft_strnstr returns:\t\t%p\tfor string '%s'\n", needle2, needle2);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(hay);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 21								  ||
||									ft_atoi									  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_atoi_2(const char *str);
static void	check_ft_atoi_3(const char *str);

void	check_ft_atoi(void)
{
	check_ft_atoi_2("1234");
	check_ft_atoi_2("0");
	check_ft_atoi_2("1");
	check_ft_atoi_2("100");
	check_ft_atoi_2("-2147483648");
	check_ft_atoi_2("2147483647");
	check_ft_atoi_2("");
	check_ft_atoi_2("\t 1234");
	check_ft_atoi_2("\t\v\n\f\r 1234");
	check_ft_atoi_2("+-1234");
	check_ft_atoi_2("-+1234");
	printf("\n\t\t");
	check_ft_atoi_2("1234d23498");
	check_ft_atoi_2("1234-8976");
	check_ft_atoi_2("1234+9856");
	check_ft_atoi_3("-9999999999");
	check_ft_atoi_3("9999999999");
	check_ft_atoi_3("-9223372036854775808");
	check_ft_atoi_3("9223372036854775807");
	check_ft_atoi_3("-9223372036854775809");
	check_ft_atoi_3("9223372036854775808");
}

static void	check_ft_atoi_2(const char *str)
{
	int	i;
	int	check;
	int	fd;

	check = atoi(str);
	i = ft_atoi(str);
	if (check != i)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Converting string '%s' into integer.\n", str);
		dprintf(fd, "atoi returns:\t\t%i\n", check);
		dprintf(fd, "ft_atoi returns:\t%i\n", i);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

static void	check_ft_atoi_3(const char *str)
{
	int	i;
	int	check;
	int	fd;

	check = atoi(str);
	i = ft_atoi(str);
	if (check != i)
	{
		printf(C_ORANGE"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Converting edge-case string '%s' into integer.\n", str);
		dprintf(fd, "atoi returns:\t\t%i\n", check);
		dprintf(fd, "ft_atoi returns:\t%i\n", i);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 22								  ||
||								   ft_calloc								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_calloc_2(size_t count, size_t size);

void	check_ft_calloc(void)
{
	check_ft_calloc_2(1, 1);
	check_ft_calloc_2(42, 42);
	check_ft_calloc_2(0xfff, 0xfff);
	check_ft_calloc_2(0, 42);
	check_ft_calloc_2(42, 0);
}

static void	check_ft_calloc_2(size_t count, size_t size)
{
	char	*mem1;
	char	*mem2;
	size_t	i;
	int		fd;

	mem1 = (char *)malloc(count * size);
	i = 0;
	while (i <= count * size)
	{
		mem1[i] = 42;
		i++;
	}
	free(mem1);
	mem2 = (char *)ft_calloc(count, size);
	if (mem1 != mem2)
		printf(C_DGREY"[TF]"C_RESET" ");
	else
	{
		i = 0;
		while (i < count * size)
		{
			if (mem2[i] != 0)
			{
				if (mem2[i] == 42)
				{
					printf(C_RED"[KO]"C_RESET" ");
					fd = errorlog_fd(1);
					dprintf(fd, NAME"\n");
					dprintf(fd, "Allocating %li * %li bytes of memory and setting to zero.\n", count, size);
					dprintf(fd, "Byte #%li should be set to 0.\n", i);
					dprintf(fd, "Byte #%li has been  set to %i.\n", i, mem2[i]);
					dprintf(fd, "\n\n");
					break ;
				}
				else
				{
					printf(C_ORANGE"[KO]"C_RESET" ");
					fd = errorlog_fd(1);
					dprintf(fd, NAME"\n");
					dprintf(fd, "Allocating %li * %li bytes of memory and setting to zero.\n", count, size);
					dprintf(fd, "Byte #%li has been set to %i for undefined reasons. Test expected 42 as failure.\n", i, mem2[i]);
					dprintf(fd, "\n\n");
					break ;
				}	
			}
			i++;
		}
		if (i == count * size)
		{
			if (mem2[i] == 42)
				printf(C_GREEN"[OK]"C_RESET" ");
			else if (mem2[i] == 0)
			{
				printf(C_ORANGE"[KO]"C_RESET" ");
				fd = errorlog_fd(1);
				dprintf(fd, NAME"\n");
				dprintf(fd, "Allocating %li * %li bytes of memory and setting to zero.\n", count, size);
				dprintf(fd, "Byte #%li has been set to 0.\n", i);
				dprintf(fd, "Allocated memory appears to be to large.\n");
				dprintf(fd, "\n\n");
			}
		}
	}
	free(mem2);
}

/* ====================================||==================================== *\
||																			  ||
||								   TEST == 23								  ||
||								   ft_strdup								  ||
||																			  ||
\* ================libft===============||==============©Othello============== */

static void	check_ft_strdup_2(const char *s);

void	check_ft_strdup(void)
{
	check_ft_strdup_2("Lorem ipsum");
	check_ft_strdup_2("Lorem ipsum\0dolor sit amet");
	check_ft_strdup_2("");
}

static void	check_ft_strdup_2(const char *s)
{
	char	*check;
	char	*ft;
	int		fd;

	check = strdup(s);
	ft = ft_strdup(s);
	if (strcmp(check, ft) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Duplicating string \"%s\".\n", s);
		dprintf(fd, "strdup returns:\t\t%s\n", check);
		dprintf(fd, "ft_strdup returns:\t%s\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(check);
	free(ft);
}
