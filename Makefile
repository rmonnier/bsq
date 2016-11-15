# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 12:13:13 by rmonnier          #+#    #+#              #
#    Updated: 2016/09/21 17:55:06 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/bsq.c srcs/main.c srcs/ft_atoi.c srcs/get_param.c srcs/max_is_one.c\
	  srcs/bsq_tools.c srcs/convert_and_check_lines.c

OFILES = bsq.o main.o ft_atoi.o get_param.o bsq_tools.o max_is_one.o\
		 convert_and_check_lines.o

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	gcc $(FLAG) -c -I./includes $(SRC)
	gcc $(FLAG) -o $(NAME) $(OFILES)
	chmod 755 $(NAME)
	touch stdin.txt
	chmod 777 stdin.txt

clean:
	/bin/rm -f $(OFILES)
	/bin/rm -f stdin.txt

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
