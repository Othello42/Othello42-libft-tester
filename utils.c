#include "h_colors.h"
#include "h_function_names.h"
#include "h_check_prototypes.h"
#include "h_utils_prototypes.h"
#include "h_function_names.h"
#include "h_os_version.h"

#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h> //system
#include <stdlib.h> //free
#include <string.h> //strcmp, strcpy

/*	=======================================================================  \\
				Utilities for errorlog
\\	=======================================================================  */
int	errorlog_fd(int command)
{
	static int	errorfd = 0;

	if (command == 1)
	{
		if (errorfd == 0)
			errorfd = open("errorlog.txt", O_APPEND | O_RDWR);
	}
	else
		close(errorfd);
	return (errorfd);
}

/*	=======================================================================  \\
				Utilities for leak checks
\\	=======================================================================  */
void	leak_check(void)
{
	int	should;

	should = 0;
	if ((TEST >= 22 && TEST <= 29) || TEST == 35 || TEST == 40 || TEST == 41 || TEST == 43)
		should = 1;	
	if (strcmp(OS, "apple") == 0)
		leak_check_apple(should);
	else
		printf(C_DGREY"[LK]"C_RESET" ");
}

void	leak_check_apple(int should)
{
	int		fd;
	char	buff[99];

	system("leaks test.out | grep leaked | cut -f2 -d: > temp_leaks_libft");
	fd = open("temp_leaks_libft", O_RDONLY);
	read (fd, buff, 99);
	close (fd);
	if (strncmp(buff, " 0 leaks for 0 total leaked bytes.", 34) != 0)
	{
		if (should == 1)
			printf(C_ORANGE"[LK]"C_RESET" ");
		else
			printf(C_RED"[CHEAT]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Function leaks:\n");
		dprintf(fd, "%s\n\n", buff);
	}
	else
		if (should == 1)
			printf(C_BLUE"[LK]"C_RESET" ");
	system("rm temp_leaks_libft");
}

/*	=======================================================================  \\
				Utilities for forbidden functions
\\	=======================================================================  */
const char	*forbidden_functions[];

void	check_forbidden(void)
{
	char	buff[0xF00];
	char	*address;
	int		fd;
	int		i;
	int		start;

	fd = open(PATH FUNCTION, O_RDONLY);
	read(fd, buff, 0xF00);
	close (fd);
	start = util_start_check(buff);
	i = 0;
	while (forbidden_functions[i] != NULL)
	{
		address = &buff[start];
		while (address != NULL)
		{
			address = util_forbidden_strstr(address + 1, i);
			if (address != NULL && strncmp(address - 3, "ft_", 3) != 0)
			{
				printf(C_YELLOW"[CHECK]"C_RESET" ");
				fd = errorlog_fd(1);
				dprintf(fd, NAME"\n");
				dprintf(fd, "Possible illegal function found.\n");
				dprintf(fd, "Found use of %s\n", forbidden_functions[i]);
				write(fd, address - 3, 99);
				dprintf(fd, "\n\n");
				break ;
			}
		}
		i++;
	}
}

int	util_start_check(char *buff)
{
	int	start;

	start = 0;
	if (buff[0] == '/' && buff[1] == '*')
	{
		while (buff[start -2] != '*' || buff[start - 1] != '/')
		start++;
	}
	while (buff[start] != '{' && buff[start] != '\0')
		start++;
	return (start);
}

char	*util_forbidden_strstr(char *buff, int i)
{
	char	*needle;

	needle = strstr(buff, forbidden_functions[i]);
	return (needle);
}
const char	*forbidden_functions[] = {
	"isalpha",
	"isdigit",
	"isalnum",
	"isascii",
	"isprint",
	"strlen",
	"memset",
	"bzero",
	"memcpy",
	"memmove",
	"strlcpy",
	"strlcat",
	"toupper",
	"tolower",
	"strchr",
	"strrchr",
	"strncmp",
	"memchr",
	"memcmp",
	"strnstr",
	"atoi",
	"strdup",
	"strcpy",
	"strncpy",
	"strcat",
	"strncat",
	"strstr",
	"strcmp",
	NULL
};
/*	=======================================================================  \\
				Utilities for list functions
\\	=======================================================================  */

t_list	*util_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (!content)
		list->content = NULL;
	else
		list->content = content;
	list->next = NULL;
	return (list);
}

void	util_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*util_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	util_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = util_lstlast(*lst);
		last->next = new;
	}
}

void	util_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	util_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		util_lstdelone(*lst, del);
		*lst = next;
	}
}

t_list	*util_make_list(int count)
{
	t_list	*lst;
	char	*temp;
	int		i;

	lst = NULL;
	i = 0;
	if (count > 0)
	{
		temp = (char *)calloc(sizeof(char), strlen("Lorem ipsum") + 2);
		strcpy(temp, "Knqdl\037hortl");
		lst = util_lstnew(temp);
		i++;
	}
	while (i < count - 1)
	{
		temp = (char *)calloc(sizeof(char), strlen(" dolor sit amet") + 2);
		strcpy(temp, "\037cnknq\037rhs\037`lds");
		util_lstadd_back(&lst, util_lstnew(temp));
		i++;
	}
	if (count > 2)
	{
		temp = (char *)calloc(sizeof(char), strlen(", consectetur adipiscing elit") + 2);
		strcpy(temp, "+\037bnmrdbsdstq\037`chohrbhmf\037dkhs");
		util_lstadd_back(&lst, util_lstnew(temp));
		i++;
	}
	return (lst);
}

t_list	*util_make_checklist(int count)
{
	t_list	*lst;
	char	*temp;
	int		i;

	lst = NULL;
	i = 0;
	if (count > 0)
	{
		temp = (char *)calloc(sizeof(char), strlen("Lorem ipsum") + 1);
		strcpy(temp, "Lorem ipsum");
		lst = util_lstnew(temp);
		i++;
	}
	while (i < count - 1)
	{
		temp = (char *)calloc(sizeof(char), strlen(" dolor sit amet") + 1);
		strcpy(temp, " dolor sit amet");
		util_lstadd_back(&lst, util_lstnew(temp));
		i++;
	}
	if (count > 2)
	{
		temp = (char *)calloc(sizeof(char), strlen(", consectetur adipiscing elit") + 1);
		strcpy(temp, ", consectetur adipiscing elit");
		util_lstadd_back(&lst, util_lstnew(temp));
		i++;
	}
	return (lst);
}

void	util_iteri(unsigned int i, char *c)
{
	c[0] = c[0] + i;
}

char	util_mapi(unsigned int i, char c)
{
	return (c + i);
}

void	util_free(void *node)
{
	free(node);
	util_free_count(1);
}

int	util_free_count(int i)
{
	static int	free_count = 0;

	free_count = free_count + i;
	if (i == -1)
		free_count = 0;
	return (free_count);
}

void	util_iter(void *str)
{
	int		i;
	char	*string;

	string = str;
	i = 0;
	while (string[i] != '\0')
	{
		string[i] = string[i] + 1;
		i++;
	}
}

void	*util_map(void *str)
{
	int		i;
	char	*string;

	string = str;
	i = 0;
	while (string[i] != '\0')
	{
		string[i] = string[i] + 1;
		i++;
	}
	return (str);
}
