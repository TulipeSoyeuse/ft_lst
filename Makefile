# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:10:00 by rdupeux           #+#    #+#              #
#    Updated: 2024/01/26 14:35:29 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
OBJS_DEBUG	= $(SRCS:.c=_debug.o)

# Compiler, Linker Defines
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME		= liblst.a
NAME_DEBUG	= liblst_debug.a
# Link all Object Files with external Libraries into Binaries
all: $(NAME)

re: fclean all

debug: $(NAME_DEBUG)

%_debug.o : %.c
	cc -g3 $(CFLAGS) -c $< -o $@	

$(NAME_DEBUG): $(OBJS_DEBUG)
	ar -rcs $@ $^

$(NAME): $(OBJS)
	ar -rcs $@ $^

clean:
	rm -f $(OBJS) $(OBJS_DEBUG)

fclean: clean
	rm -f $(NAME) a.out core $(name) $(NAME_DEBUG)

.PHONY: all clean fclean re
