NAME 			= push_swap

HEADER			= ./includes/push_swap.h

SRCS			=	main.c operations.c check_arguments.c double_operations.c sort_3_elements.c\
					sort_elements.c sort_algo.c search_function.c check_arguments_str.c free_functions.c\
					sort_small_elements.c

OBJS			= $(SRCS:.c=.o)
%.o:			%.c ${HEADER}
				$(CC) $(CFLAGS) -c -o $@ $<

RM				= rm -f
CFLAGS			= #-Wall -Werror -Wextra
INCLUDES		= ./includes/push_swap.h

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C ./libft
				cp libft/libft.a ./$(NAME)
				gcc $(OBJS) ./libft/libft.a -o ${NAME}

all:			$(NAME)
clean:
				$(MAKE) clean -C ./libft	
				$(RM) $(OBJS)		

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
test:			all
.PHONY:			all clean fclean re
