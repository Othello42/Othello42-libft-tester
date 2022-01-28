#include "h_colors.h"
#include "h_check_prototypes.h"
#include "h_utils_prototypes.h"
#include "h_function_names.h"

#include "libft.h"

#include <stdio.h> //printf
#include <stdlib.h> //free, system
#include <string.h> //strcmp
#include <fcntl.h> //open
#include <unistd.h> //close, read

//TEST == 24
void	check_ft_substr(void)
{
	check_ft_substr_2("Lorem ipsum", 0, 11, "Lorem ipsum");
	check_ft_substr_2("Lorem ipsum", 0, 10, "Lorem ipsu");
	check_ft_substr_2("Lorem ipsum", 0, 0, "");
	check_ft_substr_2("Lorem ipsum", 0, 42000, "Lorem ipsum");
	check_ft_substr_2("Lorem ipsum", 5, 11, " ipsum");
	check_ft_substr_2("Lorem ipsum", 1, 11, "orem ipsum");
	check_ft_substr_2("Lorem ipsum", 0, 11, "Lorem ipsum");
	check_ft_substr_2("", 0, 0, "");
	check_ft_substr_2("", 10, 0, "");
	check_ft_substr_2("", 0, 10, "");
	check_ft_substr_2("", 10, 10, "");
	printf("\n\t\t");
	// check_prot_ft_substr();
}

void	check_ft_substr_2(char const *s, unsigned int start, size_t len, char const *check)
{
	char	*ft;
	int		fd;

	ft = ft_substr(s, start, len);
	if (strcmp(ft, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Creating a substring from string '%s' starting at byte %i with a maximum length of %li\n", s, start, len);
		dprintf(fd, "Expected return:\t%s\n", check);
		dprintf(fd, "ft_substr returns:\t%s\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(ft);
}

// void	check_prot_ft_substr(void)
// {
// 	if (ft_substr(NULL, 1, 1) != NULL)
// 		printf("not prot\n");
// 	else
// 		printf("prot\n");
// }


//TEST == 25
void	check_ft_strjoin(void)
{
	check_ft_strjoin_2("lorem ipsum", "dolor sit amet", "lorem ipsumdolor sit amet");
	check_ft_strjoin_2("\0orem ipsum", "dolor sit amet", "dolor sit amet");
	check_ft_strjoin_2("lorem ipsum", "\0olor sit amet", "lorem ipsum");
	check_ft_strjoin_2("\0orem ipsum", "\0olor sit amet", "");
	check_ft_strjoin_2("", "dolor sit amet", "dolor sit amet");
	check_ft_strjoin_2("lorem ipsum", "", "lorem ipsum");
}

void	check_ft_strjoin_2(char const *s1, char const *s2, char const *check)
{
	char	*ft;
	int		fd;

	ft = ft_strjoin(s1, s2);
	if (strcmp(ft, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Creating a new string combining strings '%s' and '%s'.\n", s1, s2);
		dprintf(fd, "Expected return:\t%s\n", check);
		dprintf(fd, "ft_strjoin returns:\t%s\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(ft);
}

//TEST == 26
void	check_ft_strtrim(void)
{
	check_ft_strtrim_2("123Lorem123ipsum123", "123", "Lorem123ipsum");
	check_ft_strtrim_2("  \t \t \n   \n\n\n\t", " \n\t", "");
	check_ft_strtrim_2("  \t \t \n   \n\n\n\tLorem  \t \t \n   \n\n\n\t", " \n\t", "Lorem");
	check_ft_strtrim_2("   xxxLorem", " x", "Lorem");
	check_ft_strtrim_2("Lorem   xxx", " x", "Lorem");
	check_ft_strtrim_2("   xxxLorem   xxx", " x", "Lorem");
	check_ft_strtrim_2("   xxx   xxx", " x", "");
	check_ft_strtrim_2("", "123", "");
	check_ft_strtrim_2("123", "", "123");
	check_ft_strtrim_2("", "", "");
}

void	check_ft_strtrim_2(const char *s1, char const *set, char const *check)
{
	char	*ft;
	int		fd;

	ft = ft_strtrim(s1, set);
	if (strcmp(ft, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Trimming characters '%s' from the beginning and end of string '%s'.\n", set, s1);
		dprintf(fd, "Expected return:\t%s\n", check);
		dprintf(fd, "ft_strtrim returns:\t%s\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(ft);
}

//TEST == 27
void	check_ft_split(void)
{
	check_ft_split_2("Lorem ipsum", ' ');
	check_ft_split_2("Loremipsum", ' ');
	check_ft_split_2("Lorem    ipsum", ' ');
	check_ft_split_2("    Lorem ipsum", ' ');
	check_ft_split_2("Lorem ipsum    ", ' ');
	check_ft_split_2("    ", ' ');
	check_ft_split_2("", ' ');
}

void	check_ft_split_2(char const *s, char c)
{
	char	**ft;
	int		fd;
	int		i;
	int		j;
	int		k;

	ft = ft_split(s, c);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			if (k != 0)
				j++;
			k = 0;
		}
		else if (s[i] != ft[j][k])
		{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Using delimiter '%c' splitting string '%s'.\n", c, s);
		dprintf(fd, "Expected return:\t%s\n", &s[i]);
		dprintf(fd, "ft_split returns:\t%s\n", ft[j]);
		dprintf(fd, "\n\n");
		break;
		}
		else
		{
			k++;
			i++;
		}
	}
		printf(C_GREEN"[OK]"C_RESET" ");
	i = 0;
	while (i <= j)
	{
		free(ft[i]);
		i++;
	}
	free(ft);
}

//TEST == 28
void	check_ft_itoa(void)
{
	check_ft_itoa_2(42, "42");
	check_ft_itoa_2(1, "1");
	check_ft_itoa_2(0, "0");
	check_ft_itoa_2(-1, "-1");
	check_ft_itoa_2(4242, "4242");
	check_ft_itoa_2(1234567890, "1234567890");
	check_ft_itoa_2(101, "101");
	check_ft_itoa_2(-4242, "-4242");
	check_ft_itoa_2(-2147483648, "-2147483648");
	check_ft_itoa_2(2147483647, "2147483647");
}

void	check_ft_itoa_2(int n, char *check)
{
	char	*ft;
	int		fd;

	ft = ft_itoa(n);
	if (strcmp(ft, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Turning interger %i into a character string.\n", n);
		dprintf(fd, "Expected return:\t%s\n", check);
		dprintf(fd, "ft_itoa returns:\t%s\n", ft);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(ft);
}

//TEST == 29
void	check_ft_strmapi(void)
{
	check_ft_strmapi_2("aaaaaaaaaaaaaaaaaaaaaaaaaa", "abcdefghijklmnopqrstuvwxyz");
	check_ft_strmapi_2("Lorem ipsum", "Lpthq%ow{~w");
	check_ft_strmapi_2("Lnpbi\033ciklc", "Lorem ipsum");
	check_ft_strmapi_2("0123465789", "02468;;>@B");
	check_ft_strmapi_2("", "");
}

void	check_ft_strmapi_2(const char *s, const char *check)
{
	char	*str;
	int		fd;

	str = ft_strmapi(s, util_mapi);
	if (strcmp(str, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Changing string \"%s\" using provided function.\n", s);
		dprintf(fd, "Expected return:\t%s\n", check);
		dprintf(fd, "ft_strmapi returns:\t%s\n", str);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(str);
}

//TEST == 30
void	check_ft_striteri(void)
{
	check_ft_striteri_2("Lnpbi\033ciklc", "Lorem ipsum", util_iteri);
	check_ft_striteri_2("", "", util_iteri);
}

void	check_ft_striteri_2(char *s, char *check, void (*f)(unsigned int, char*))
{
	char	*str;
	int		fd;

	str = (char *)calloc(4, 4);
	strcpy(str, s);
	ft_striteri(str, f);
	if (strcmp(str, check) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Changing string \"%s\" using provided function.\n", s);
		dprintf(fd, "Expected return:\t\t%s\n", check);
		dprintf(fd, "ft_striteri returns:\t%s\n", str);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(str);
}

//TEST == 31
void	check_ft_putchar_fd(void)
{
	check_ft_putchar_fd_2(32, 126);
	check_ft_putchar_fd_2(0, 127);
	check_ft_putchar_fd_2(128, 255);
	check_ft_putchar_fd_2(-384, -1);
}

void	check_ft_putchar_fd_2(int low, int high)
{
	int	check;
	int	error;

	check = 1;
	error = 0;
	while (low <= high)
	{
		check = check * check_ft_putchar_fd_3(low);
		if (check == 0 && error == 0)
		{
			printf(C_RED"[KO]"C_RESET" ");
			error = 1;
			check = 1;
		}
		low++;
	}
	if (error == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
}

int	check_ft_putchar_fd_3(char c)
{
	int		fd;
	char	buff[99];
	size_t	len;

	fd = open("temp.txt", O_TRUNC | O_CREAT | O_RDWR, 0700);
	ft_putchar_fd(c, fd);
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	len = read(fd, buff, 99);
	close (fd);
	system("rm temp.txt");
	if (!(len == 1 && buff[0] == c))
	{
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Printing character '%c' to fd.\n", c);
		dprintf(fd, "Expected return:\t\t%c with a length of 1.\n", c);
		dprintf(fd, "ft_putchar_fd returns:\t%s with a length of %li.\n", buff, len);
		dprintf(fd, "\n\n");
		return (0);
	}
	return (1);
}

//TEST == 32
void	check_ft_putstr_fd(void)
{
	check_ft_putstr_fd_2("Lorem ipsum dolor sit amet.");
	check_ft_putstr_fd_2("c");
	check_ft_putstr_fd_2("string \x01 of \x63 non \x0a ascii \x12 chars\x1d");
	check_ft_putstr_fd_2("よくやった");
	check_ft_putstr_fd_2("");
}

void	check_ft_putstr_fd_2(char *s)
{
	int		fd;
	char	buff[99];
	size_t	len;

	bzero(buff, 99);
	fd = open("temp.txt", O_TRUNC | O_CREAT | O_RDWR, 0700);
	ft_putstr_fd(s, fd);
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	len = read(fd, buff, 99);
	close (fd);
	system("rm temp.txt");
	if (len != strlen(s) || strcmp(s, buff) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Printing string \"%s\" to fd\n", s);
		dprintf(fd, "Expected return:\t\t%s with a length of %li.\n", s, strlen(s));
		dprintf(fd, "ft_putstr_fd returns:\t%s with a length of %li.\n", buff, strlen(buff));
		dprintf(fd, "\n\n");		
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

//TEST == 33
void	check_ft_putendl_fd(void)
{
	check_ft_putendl_fd_2("Lorem ipsum dolor sit amet.");
	check_ft_putendl_fd_2("c");
	check_ft_putendl_fd_2("string \x01 of \x63 non \x0a ascii \x12 chars\x1d");
	check_ft_putendl_fd_2("よくやった");
	check_ft_putendl_fd_2("");
}

void	check_ft_putendl_fd_2(char *s)
{
	int		fd;
	char	buff[99];
	char	check[100];
	size_t	len;

	bzero(buff, 99);
	bzero(check, 100);
	memcpy(check, s, strlen(s));
	check[strlen(s)] = '\n';
	fd = open("temp.txt", O_TRUNC | O_CREAT | O_RDWR, 0700);
	ft_putendl_fd(s, fd);
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	len = read(fd, buff, 99);
	close (fd);
	system("rm temp.txt");
	if (len != strlen(check) || strcmp(check, buff) != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Printing string \"%s\" to fd\n", s);
		dprintf(fd, "Expected return:\t\t%s with a length of %li.\n", s, strlen(s));
		dprintf(fd, "ft_putendl_fd returns:\t%s with a length of %li.\n", buff, strlen(buff));
		dprintf(fd, "\n\n");		
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

//TEST == 34
void	check_ft_putnbr_fd(void)
{
	check_ft_putnbr_fd_2(42, "42");
	check_ft_putnbr_fd_2(1, "1");
	check_ft_putnbr_fd_2(0, "0");
	check_ft_putnbr_fd_2(-1, "-1");
	check_ft_putnbr_fd_2(4242, "4242");
	check_ft_putnbr_fd_2(1234567890, "1234567890");
	check_ft_putnbr_fd_2(101, "101");
	check_ft_putnbr_fd_2(-4242, "-4242");
	check_ft_putnbr_fd_2(-2147483648, "-2147483648");
	check_ft_putnbr_fd_2(2147483647, "2147483647");
}

void	check_ft_putnbr_fd_2(int n, char *check)
{
	char	buff[12];
	int		fd;
	size_t	len;

	bzero(buff, 12);
	fd = open("temp.txt", O_TRUNC | O_CREAT | O_RDWR, 0700);
	ft_putnbr_fd(n, fd);
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	len = read(fd, buff, 99);
	close (fd);	
	system("rm temp.txt");
	if (strcmp(buff, check) != 0 || len != strlen(buff))
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Printing number \"%i\" to fd\n", n);
		dprintf(fd, "Expected return:\t\t%s with a length of %li.\n", check, strlen(check));
		dprintf(fd, "ft_putnbr_fd returns:\t%s with a length of %li.\n", buff, strlen(buff));
		dprintf(fd, "\n\n");		
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}
