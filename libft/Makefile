CC      	= cc
CFLAGS		= -Wall -Werror -Wextra

RM = rm -rf

NAME = libft.a 
OBJS = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memset.o ft_strchr.o ft_strlen.o ft_strncmp.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strlcpy.o ft_strlcat.o ft_substr.o ft_strjoin.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_itoa.o ft_strtrim.o ft_strdup.o ft_striteri.o ft_strmapi.o ft_memcpy.o ft_memmove.o ft_putnbr_fd.o ft_split.o
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean all fclean re
