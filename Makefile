# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/29 14:04:21 by jle-quer          #+#    #+#              #
#    Updated: 2016/03/29 14:20:48 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	op_stack.c \
			parse_error.c \
			parse_opt.c \
			parse_stack.c \
			print_stack.c \
			sort_stack.c \
			main.c

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

LIB = ./Libft/libft.a

OBJET = $(SRC_NAME:.c=.o)

all: $(NAME)
	@echo "Make In Progress"
	@echo "Make Done."

$(NAME): $(LIB) $(OBJET)
	@gcc $(FLAGS) $(OBJET) -L./Libft/ -lft -o $(NAME)

$(LIB):
	make proper -C ./Libft/

%.o: %.c
	@gcc $(FLAGS) -I./Libft/INCLUDES -c $<

clean:
	@echo "Clean In Progress"
	@rm -f $(OBJET)
	@echo "Clean Done."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

proper:
	@make
	@make clean
