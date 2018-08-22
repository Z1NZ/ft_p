CC    = gcc -Wall -Wextra -Werror

RM    = rm -f

NAME    = client

SRC    = client.c\
	ft_connect.c\
	ft_looper.c\
	ft_tools_client.c\
	get_file.c\
	put_file.c\

OBJS    = $(SRC:.c=.o)
SRCDIR 	= ./srcs_client/
SRCS	= $(addprefix $(SRCDIR), $(SRC))

NAME1    = serveur

SRC1    = serv.c\
	ft_cd_serv.c\
	ft_creat_serv.c\
	ft_looper.c\
	ft_tools_serv.c\
	ft_tools_serv2.c\
	recpt_file.c\
	send_file.c\
	ft_mini.c\

OBJS1    = $(SRC1:.c=.o)
SRCDIR1 	= ./srcs_serveur/
SRCS1	= $(addprefix $(SRCDIR1), $(SRC1))
all : $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(SRCS) -o $(NAME) libft/libft.a -I include_client
	@$(CC) $(SRCS1) -o $(NAME1) libft/libft.a -I include_serveur
clean:
	@$(RM) $(OBJS) 
	@$(RM) $(OBJS1) 
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME1)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
