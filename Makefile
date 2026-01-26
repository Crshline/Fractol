NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Wextra -Werror 

SRC_DIR	= src/
INC_DIR	= inc/

LIBFT_DIR	= ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

MINILIBX_DIR	= ./minilibx-linux
MINILIBX	= $(MINILIBX_DIR)/libmlx.a

MLX_FLAGS	= -L$(MINILIBX_DIR) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lbsd

SRCS_FILES	= fractol.c exit_windows.c move_windows.c algos.c

SRCS	= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJ	= $(SRCS:.c=.o)

HEADERS	= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MINILIBX_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME) 

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

%.o: %.c	
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

