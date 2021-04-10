# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/04/08 15:17:27 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	checker

SRCS			:= \
main_checker

S				:= \
src/

O				:= \
obj/

H				:= \
checker.h
# push_swap.h

I				:= \
-I lib/libft \
-I .

L				:= \
lib/libft/libft.a

T				= \
$(addprefix $O, $(addsuffix .o, $(SRCS)))

C				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
SANITIZE		:= -g3 -fsanitize=address

R				:= rm -f

$O%.o:			$S%.c $(H)
	$(CC) $(CFLAGS) $I -c $< -o $@

all:
	$(MAKE) -C lib/libft
	make $(NAME)

$(NAME):		$T $L
	$C $^ -o $@

clean:			cleanlib
	$R $T

fclean:			fcleanlib
	$R $T
	$R $(NAME)

cleanlib:
	make --directory=lib/libft clean

fcleanlib:
	make --directory=lib/libft fclean

norme:
	norminette *.c *.h

re:				fclean all

.PHONY: all clean bonus norme re libcomp cleanlib fcleanlib
