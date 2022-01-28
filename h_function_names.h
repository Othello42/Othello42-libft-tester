#define PATH "../libft/"

/* MANDATORY - Libc */
#if (TEST == 1)
#  define NAME "ft_isalpha"
#  define FUNCTION "ft_isalpha.c" 
#  define CHECK check_ft_isalpha
# elif (TEST == 2)
#  define NAME "ft_isdigit"
#  define FUNCTION "ft_isdigit.c" 
#  define CHECK check_ft_isdigit
# elif (TEST == 3)
#  define NAME "ft_isalnum"
#  define FUNCTION "ft_isalnum.c" 
#  define CHECK check_ft_isalnum
# elif (TEST == 4)
#  define NAME "ft_isascii"
#  define FUNCTION "ft_isascii.c" 
#  define CHECK check_ft_isascii
# elif (TEST == 5)
#  define NAME "ft_isprint"
#  define FUNCTION "ft_isprint.c" 
#  define CHECK check_ft_isprint
# elif (TEST == 6)
#  define NAME "ft_strlen"
#  define FUNCTION "ft_strlen.c" 
#  define CHECK check_ft_strlen
# elif (TEST == 7)
#  define NAME "ft_memset"
#  define FUNCTION "ft_memset.c" 
#  define CHECK check_ft_memset
# elif (TEST == 8)
#  define NAME "ft_bzero"
#  define FUNCTION "ft_bzero.c" 
#  define CHECK check_ft_bzero
# elif (TEST == 9)
#  define NAME "ft_memcpy"
#  define FUNCTION "ft_memcpy.c" 
#  define CHECK check_ft_memcpy
# elif (TEST == 10)
#  define NAME "ft_memmove"
#  define FUNCTION "ft_memmove.c" 
#  define CHECK check_ft_memmove
# elif (TEST == 11)
#  define NAME "ft_strlcpy"
#  define FUNCTION "ft_strlcpy.c" 
#  define CHECK check_ft_strlcpy
# elif (TEST == 12)
#  define NAME "ft_strlcat"
#  define FUNCTION "ft_strlcat.c" 
#  define CHECK check_ft_strlcat
# elif (TEST == 13)
#  define NAME "ft_toupper"
#  define FUNCTION "ft_toupper.c" 
#  define CHECK check_ft_toupper
# elif (TEST == 14)
#  define NAME "ft_tolower"
#  define FUNCTION "ft_tolower.c" 
#  define CHECK check_ft_tolower
# elif (TEST == 15)
#  define NAME "ft_strchr"
#  define FUNCTION "ft_strchr.c" 
#  define CHECK check_ft_strchr
# elif (TEST == 16)
#  define NAME "ft_strrchr"
#  define FUNCTION "ft_strrchr.c" 
#  define CHECK check_ft_strrchr
# elif (TEST == 17)
#  define NAME "ft_strncmp"
#  define FUNCTION "ft_strncmp.c" 
#  define CHECK check_ft_strncmp
# elif (TEST == 18)
#  define NAME "ft_memchr"
#  define FUNCTION "ft_memchr.c" 
#  define CHECK check_ft_memchr
# elif (TEST == 19)
#  define NAME "ft_memcmp"
#  define FUNCTION "ft_memcmp.c" 
#  define CHECK check_ft_memcmp
# elif (TEST == 20)
#  define NAME "ft_strnstr"
#  define FUNCTION "ft_strnstr.c" 
#  define CHECK check_ft_strnstr
# elif (TEST == 21)
#  define NAME "ft_atoi\t"
#  define FUNCTION "ft_atoi.c" 
#  define CHECK check_ft_atoi
# elif (TEST == 22)
#  define NAME "ft_calloc"
#  define FUNCTION "ft_calloc.c" 
#  define CHECK check_ft_calloc
# elif (TEST == 23)
#  define NAME "ft_strdup"
#  define FUNCTION "ft_strdup.c" 
#  define CHECK check_ft_strdup
/* MANDATORY - Additional */
# elif (TEST == 24)
#  define NAME "ft_substr"
#  define FUNCTION "ft_substr.c" 
#  define CHECK check_ft_substr
# elif (TEST == 25)
#  define NAME "ft_strjoin"
#  define FUNCTION "ft_strjoin.c" 
#  define CHECK check_ft_strjoin
# elif (TEST == 26)
#  define NAME "ft_strtrim"
#  define FUNCTION "ft_strtrim.c" 
#  define CHECK check_ft_strtrim
# elif (TEST == 27)
#  define NAME "ft_split"
#  define FUNCTION "ft_split.c" 
#  define CHECK check_ft_split
# elif (TEST == 28)
#  define NAME "ft_itoa\t"
#  define FUNCTION "ft_itoa.c" 
#  define CHECK check_ft_itoa
# elif (TEST == 29)
#  define NAME "ft_strmapi"
#  define FUNCTION "ft_strmapi.c" 
#  define CHECK check_ft_strmapi
# elif (TEST == 30)
#  define NAME "ft_striteri"
#  define FUNCTION "ft_striteri.c" 
#  define CHECK check_ft_striteri
# elif (TEST == 31)
#  define NAME "ft_putchar_fd"
#  define FUNCTION "ft_putchar_fd.c" 
#  define CHECK check_ft_putchar_fd
# elif (TEST == 32)
#  define NAME "ft_putstr_fd"
#  define FUNCTION "ft_putstr_fd.c" 
#  define CHECK check_ft_putstr_fd
# elif (TEST == 33)
#  define NAME "ft_putendl_fd"
#  define FUNCTION "ft_putendl_fd.c" 
#  define CHECK check_ft_putendl_fd
# elif (TEST == 34)
#  define NAME "ft_putnbr_fd"
#  define FUNCTION "ft_putnbr_fd.c" 
#  define CHECK check_ft_putnbr_fd
/* BONUS */
# elif (TEST == 35)
#  define NAME "ft_lstnew"
#  define FUNCTION "ft_lstnew"
#  define CHECK check_ft_lstnew
# elif (TEST == 36)
#  define NAME "ft_lstadd_front"
#  define FUNCTION "ft_lstadd_front" 
#  define CHECK check_ft_lstadd_front
# elif (TEST == 37)
#  define NAME "ft_lstsize"
#  define FUNCTION "ft_lstsize" 
#  define CHECK check_ft_lstsize
# elif (TEST == 38)
#  define NAME "ft_lstlast"
#  define FUNCTION "ft_lstlast" 
#  define CHECK check_ft_lstlast
# elif (TEST == 39)
#  define NAME "ft_lstadd_back"
#  define FUNCTION "ft_lstadd_back" 
#  define CHECK check_ft_lstadd_back
# elif (TEST == 40)
#  define NAME "ft_lstdelone"
#  define FUNCTION "ft_lstdelone" 
#  define CHECK check_ft_lstdelone
# elif (TEST == 41)
#  define NAME "ft_lstclear"
#  define FUNCTION "ft_lstclear" 
#  define CHECK check_ft_lstclear
# elif (TEST == 42)
#  define NAME "ft_lstiter"
#  define FUNCTION "ft_lstiter" 
#  define CHECK check_ft_lstiter
# elif (TEST == 43)
#  define NAME "ft_lstmap"
#  define FUNCTION "ft_lstmap" 
#  define CHECK check_ft_lstmap
#endif
