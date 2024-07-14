CC      	= cc
CFLAGS		= -Wall -Werror -Wextra

RM = rm -rf

NAME = fractol
SRCS = test.c f_utils.c f_utils_two.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp libft/libft.a .
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) libft.a -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all
