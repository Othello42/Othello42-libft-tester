#include "h_colors.h"
#include "h_check_prototypes.h"
#include "h_utils_prototypes.h"
#include "h_function_names.h"

#include "libft.h"

#include <string.h> //strcpy
#include <stdlib.h> //calloc

#include <stdio.h> //printf

//TEST == 35
void	check_ft_lstnew(void)
{
	check_ft_lstnew_2("Lorem ipsum");
	check_ft_lstnew_2("");
	check_ft_lstnew_3();
}

void	check_ft_lstnew_2(char *str)
{
	t_list	*list;
	int		fd;

	list = ft_lstnew(str);
	if ((strcmp(str, list->content) != 0) || str != list->content || list->next != NULL)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Adding string '%s' to new linked list node.\n", str);
		dprintf(fd, "\t\t\tAddress\t\tlist->next\tString\n");
		dprintf(fd, "expected:\t%p\t0x0\t\t\t%s\n", str, str);
		dprintf(fd, "ft_lstnew:\t%p\t%p\t\t\t%s\n", list->content, list->next, list->content);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(list);
}

void	check_ft_lstnew_3(void)
{
	t_list	*list;
	int		fd;

	list = ft_lstnew(NULL);
	if (list->content != NULL || list->next != NULL)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Adding empty string to new linked list node.\n");
		dprintf(fd, "\t\t\tAddress\tlist->next\tString\n");
		dprintf(fd, "expected:\t0x0\t\t0x0\t\t\t(null)\n");
		dprintf(fd, "ft_lstnew:\t%p\t\t%p\t\t\t%s\n", list->content, list->next, list->content);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free (list);
}

//TEST == 36
void	check_ft_lstadd_front(void)
{
	t_list	*lst;

	lst = NULL;
	check_ft_lstadd_front_2(lst);
	check_ft_lstadd_front_3(lst);
}

void	check_ft_lstadd_front_2(t_list *lst)
{
	t_list	*new;
	int		fd;

	new = util_lstnew(NULL);
	ft_lstadd_front(&lst, new);
	if (new != lst || new->content != lst->content || new->next != lst->next)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Creating new list nodes and adding '%s' in front of it.\n", new->content);
		dprintf(fd, "\tnode\t\t\tcontent\tnext\tstring\n");
		dprintf(fd, "1:\t%p\t%p\t\t%p\t\t%s\n", lst, lst->content, lst->next, lst->content);
		dprintf(fd, "2:\t%p\t%p\t\t%p\t\t%s\n", new, new->content, new->next, new->content);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(new);
}

void	check_ft_lstadd_front_3(t_list *lst)
{
	t_list	*new1;
	t_list	*new2;
	int		fd;

	new1 = util_lstnew("Lorem ipsum");
	new2 = util_lstnew(" dolor sit amet");
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new1);
	if (lst != new1 || lst->content != new1->content || lst->next != new1->next\
	|| lst->next != new2 || lst->next->content != new2->content || lst->next->next != new2->next)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Creating new list nodes and adding '%s' and '%s' in front of it.\n", new1->content, new2->content);
		dprintf(fd, "\t\tExpected\n");
		dprintf(fd, "\tnode\t\t\tcontent\t\t\tnext\t\t\t\tstring\n");
		dprintf(fd, "1:\t%p\t%p\t\t%p\t\t%s\n", new1, new1->content, new1->next, new1->content);
		dprintf(fd, "2:\t%p\t%p\t\t%p\t\t\t\t%s\n", new2, new2->content, new2->next, new2->content);
		dprintf(fd, "\t\tResult\n");
		dprintf(fd, "\tnode\t\t\tcontent\t\t\tnext\t\t\t\tstring\n");
		dprintf(fd, "1:\t%p\t%p\t\t%p\t\t%s\n", lst, lst->content, lst->next, lst->content);
		dprintf(fd, "2:\t%p\t%p\t\t%p\t\t\t\t%s\n", lst->next, lst->next->content, lst->next->next, lst->next->content);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	free(lst->next);
	free(lst);
}

//TEST == 37
void	check_ft_lstsize(void)
{
	check_ft_lstsize_2(0);
	check_ft_lstsize_2(1);
	check_ft_lstsize_2(42);
}

void	check_ft_lstsize_2(int count)
{
	t_list	*lst;
	int		fd;

	lst = NULL;
	if (count > 0)
		lst = util_make_checklist(count);
	if (ft_lstsize(lst) != count)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Count the number of nodes in the list.\n");
		dprintf(fd, "expected:\t%i\n", count);
		dprintf(fd, "ft_lstsize:\t%i\n", ft_lstsize(lst));
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	util_lstclear(&lst, free);
}

//TEST == 38
void	check_ft_lstlast(void)
{
	check_ft_lstlast_2(0);
	check_ft_lstlast_2(1);
	check_ft_lstlast_2(42);
}

void	check_ft_lstlast_2(int count)
{
	t_list	*lst;
	t_list	*ft_lst;
	t_list	*util_lst;
	int		fd;

	lst = NULL;
	if (count > 0)
		lst = util_make_checklist(count);
	ft_lst = ft_lstlast(lst);
	util_lst = util_lstlast(lst);
	if (ft_lst != util_lst)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Returns the last adress of the list.\n");
		if (lst != NULL)
		{
			dprintf(fd, "expected:\t%p\t%s\n", util_lst, util_lst->content);
			dprintf(fd, "ft_lstlast:\t%p\t%s\n", ft_lst, ft_lst->content);
		}
		else
		{
			dprintf(fd, "expected:\t%p\n", util_lst);
			dprintf(fd, "ft_lstlast:\t%p\n", ft_lst);
		}
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	util_lstclear(&lst, free);
}

//TEST == 39
void	check_ft_lstadd_back(void)
{
	check_ft_lstadd_back_2(0);
	check_ft_lstadd_back_2(1);
	check_ft_lstadd_back_2(42);
}

void	check_ft_lstadd_back_2(int count)
{
	t_list	*lst;
	t_list	*new;
	t_list	*temp;
	int		i;
	int		fd;

	lst = NULL;
	i = 0;
	while (i < count)
	{
		util_lstadd_front(&lst, util_lstnew("Lorem ipsum"));
		i++;
	}
	new = util_lstnew(" dolor sit amet");
	ft_lstadd_back(&lst, new);
	temp = util_lstlast(lst);
	if (new != temp)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Returns the last adress of the list.\n");
		dprintf(fd, "expected:\t\t%p\t%s\n", temp, temp->content);
		dprintf(fd, "ft_lstadd_back:\t%p\t%s\n", new, new->content);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
	i++;
	while (i > 0)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
		i--;
	}
}

//TEST == 40
void	check_ft_lstdelone(void)
{
	check_ft_lstdelone_2();
}

void	check_ft_lstdelone_2(void)
{
	t_list	*lst;
	char	*content;
	int		count;
	int		fd;

	content = (char *)calloc(sizeof(char), strlen("Lorem ipsum"));
	lst = util_lstnew(content);
	ft_lstdelone(lst, util_free);
	count = util_free_count(0);
	if (count != 1)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Clears content of a node using passed function and frees the node.\n");
		dprintf(fd, "Times function should be called:\t1\n");
		dprintf(fd, "Times ft_lstdelone called the function:\t%i\n", count);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

//TEST == 41
void	check_ft_lstclear(void)
{
	check_ft_lstclear_2(0);
	check_ft_lstclear_2(1);
	check_ft_lstclear_2(42);
}

void	check_ft_lstclear_2(int count)
{
	t_list	*lst;
	char	*temp;
	int		free_count;
	int		i;
	int		fd;

	util_free_count(-1);
	i = 0;
	lst = NULL;
	if (count > 0)
	{
		temp = (char *)calloc(sizeof(char), strlen(" dolor sit amet"));
		strcpy(temp, " dolor sit amet");
		lst = util_lstnew(temp);
		i++;
	}
	while (i < count)
	{
		temp = (char *)calloc(sizeof(char), strlen("Lorem ipsum"));
		strcpy(temp, "Lorem ipsum");
		util_lstadd_front(&lst, util_lstnew(temp));
		i++;
	}
	ft_lstclear(&lst, util_free);
	free_count = util_free_count(0);
	if (free_count != count)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Clears content of a list using passed function and frees the list.\n");
		dprintf(fd, "Times function should be called:\t\t%i\n", count);
		dprintf(fd, "Times ft_lstclear called the function:\t%i\n", free_count);
		dprintf(fd, "\n\n");
	}
	else
		printf(C_GREEN"[OK]"C_RESET" ");
}

//TEST == 42
void	check_ft_lstiter(void)
{
	check_ft_lstiter_2(0);
	check_ft_lstiter_2(1);
	check_ft_lstiter_2(2);
	check_ft_lstiter_2(42);
	check_ft_lstiter_prot();
}

void	check_ft_lstiter_2(int count)
{
	t_list	*lst;
	t_list	*check;

	lst = util_make_list(count);
	check = util_make_checklist(count);
	ft_lstiter(lst, util_iter);
	if (check_ft_lstiter_3(lst, check) == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
	util_lstclear(&check, free);
	util_lstclear(&lst, free);
}

int	check_ft_lstiter_3(t_list *lst, t_list *check)
{
	int	node;
	int	fd;

	node = 1;
	while (lst != NULL)
	{
		if (strcmp(lst->content, check->content) != 0)
		{
			printf(C_RED"[KO]"C_RESET" ");
			fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "Iterates content of linked list and places result in new list.\n");
			dprintf(fd, "Expected content:\t\t'%s'\n", check->content);
			dprintf(fd, "List content at node %i:\t'%s'\n", node, lst->content);
			dprintf(fd, "\n\n");
			return (1);
		}
		node ++;
		check = check->next;
		lst = lst->next;
	}
	return (0);
}

void	check_ft_lstiter_prot(void)
{
	signal(SIGSEGV, error_prot);
	ft_lstiter(NULL, util_iter);
	printf(C_BLUE"[PROT]"C_RESET" ");
}

//TEST == 43
void	check_ft_lstmap(void)
{
	check_ft_lstmap_2(0);
	check_ft_lstmap_2(1);
	check_ft_lstmap_2(2);
	check_ft_lstmap_2(3);
	check_ft_lstmap_2(42);
	check_ft_lstmap_prot();
}

t_list	*ft_lstmap_2(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	char	*newstr;

	if (!lst)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		newstr = (char *)ft_calloc(sizeof(char), ft_strlen(lst->content) + 1);
		if (newstr == NULL)
		{
			util_lstclear(&newlist, del);
			return (NULL);
		}
		ft_strlcpy(newstr, lst->content, ft_strlen(lst->content) + 1);
		newnode = util_lstnew((*f)(newstr));
		if (newnode == NULL)
		{
			util_lstclear(&newlist, del);
			return (NULL);
		}
		util_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

void	check_ft_lstmap_2(int count)
{
	t_list	*lst;
	t_list	*check;
	t_list	*newlst;
	int		fd;

	lst = util_make_list(count);
	check = util_make_checklist(count);
	newlst = ft_lstmap_2(lst, util_map, util_free);
	if (lst == newlst && count != 0)
	{
		printf(C_RED"[KO]"C_RESET" ");
		fd = errorlog_fd(1);
		dprintf(fd, NAME"\n");
		dprintf(fd, "Iterates content of linked list and places result in new list.\n");
		dprintf(fd, "Old list Address:\t%p\n", lst);
		dprintf(fd, "New list Address:\t%p\n", newlst);
		dprintf(fd, "Either old list has been freed, or no new list has been created.\n");
		dprintf(fd, "\n\n");
	}
	else if (check_ft_lstmap_3(lst, newlst, check) == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
	util_lstclear(&lst, free);
	util_lstclear(&newlst, free);
	util_lstclear(&check, free);
}

int check_ft_lstmap_3(t_list *lst, t_list *newlst, t_list *check)
{
	int	node;
	int	fd;

	node = 1;
	while (newlst != NULL)
	{
		if (strcmp(newlst->content, check->content) != 0)
		{
			printf(C_RED"[KO]"C_RESET" ");
			fd = errorlog_fd(1);
			dprintf(fd, NAME"\n");
			dprintf(fd, "Iterates content of linked list and places result in new list.\n");
			dprintf(fd, "Old list content at node %i:\t%s\n", node, lst->content);
			dprintf(fd, "Expected content:\t\t\t%s\n", check->content);
			dprintf(fd, "New list content at node %i:\t%s\n", node, newlst->content);
			dprintf(fd, "\n\n");
			return (1);
		}
		node++;
		lst = lst->next;
		check = check->next;
		newlst = newlst->next;
	}
	return (0);
}

void	check_ft_lstmap_prot(void)
{
	signal(SIGSEGV, error_prot);
	ft_lstmap(NULL, util_map, util_free);
	printf(C_BLUE"[PROT]"C_RESET" ");
}
