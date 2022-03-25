#Variables
NAME 	= 	push_swap
CC 		= 	gcc
SRC_DIR =	src/
CFLAGS	=	-Werror -Wall -Wextra -I include/
RM		=	rm -f

#libft
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))


#Sources files
SRC_FILES	=	push_swap.c start.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT_DIR)
			$(CC) $(OBJ) $(LIBFT) -o $(NAME)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
