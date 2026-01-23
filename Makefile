NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Wextra -Werror 

SRC_DIR	= src/
INC_DIR	= inc/
LIBFT_DIR	= ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

SRCS_FILES	= 

SRCS	= $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJ	= $(SRCS:.c=.o)

HEADERS	= -I $(INC_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) 

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c	
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

