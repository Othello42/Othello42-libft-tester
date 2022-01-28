void	check_ft_lstiter_2(int count)
{
	t_list	*lst;
	t_list	*temp;
	int		fd;

	lst = util_make_list(count);

	ft_lstiter(lst, util_iter);
	temp = lst;
	fd = 0;
	while (temp != NULL)
	{
		if (strcmp(temp->content, "Mpsfn!jqtvn") != 0)
		{
			if (strcmp(temp->content, "!epmps!tju!bnfu") != 0)
			{
				printf(C_RED"[KO]"C_RESET" ");
				fd = errorlog_fd(1);
				dprintf(fd, NAME"\n");
				dprintf(fd, "Iterates each content of a linked list using passed function.\n");
				if (temp->next == NULL)
				{
					dprintf(fd, "Input:\t\t\t\t\t dolor sit amet\n");
					dprintf(fd, "Expected content:\t\t'!epmps!tju!bnfu'\n");
				}
				else
				{
					dprintf(fd, "Input:\t\t\t\t\tLorem ipsum\n");
					dprintf(fd, "Expected content:\t\t'Mpsfn!jqtvn'\n");
				}
				// dprintf(fd, "Expected content:\t\t'Lorem ipsum'\n");
				dprintf(fd, "ft_lstiter's content:\t'%s'\n", temp->content);
				dprintf(fd, "\n\n");
				break ;
			}
		}
		temp = temp->next;
	}
	if (fd == 0)
		printf(C_GREEN"[OK]"C_RESET" ");
	ft_lstclear(&lst, free);
}