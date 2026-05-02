NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft
RM			= rm -f
AR			= ar rcs

SRCS		= ft_printf.c ft_print_utils.c ft_utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
