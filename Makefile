# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:10:00 by rdupeux           #+#    #+#              #
#    Updated: 2024/01/01 17:55:58 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

# Compiler, Linker Defines
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME	= liblst.a

# Link all Object Files with external Libraries into Binaries
all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out core $(name) $(DEBUG)

.PHONY: all clean fclean re
