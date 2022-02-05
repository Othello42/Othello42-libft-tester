void	primary_tests(void);
void	secundary_tests(void);

void	error(int sig);
void	error_prot(int sig);

int		errorlog_fd(int command);

void	leak_check(void);
void	leak_check_apple(int should);

void	check_forbidden(void);

int		util_start_check(char *buff);
char	*util_forbidden_strstr(char *buff, int i);

t_list	*util_lstnew(void *content);
void	util_lstadd_front(t_list **lst, t_list *new);
t_list	*util_lstlast(t_list *lst);
void	util_lstdelone(t_list *lst, void (*del)(void *));
void	util_lstadd_back(t_list **lst, t_list *new);
void	util_lstclear(t_list **lst, void (*del) (void *));
t_list	*util_make_list(int count);
t_list	*util_make_checklist(int count);

void	util_iteri(unsigned int i, char *c);
char	util_mapi(unsigned int i, char c);
void	util_iter(void *str);
void	*util_map(void *str);
void	util_free(void *node);
int		util_free_count(int i);
