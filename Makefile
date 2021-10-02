# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2021/10/02 21:59:00 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCSDIR = srcs/
SRCS = main.c \
		ft_puts.c \
		ft_utility.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_split.c \
		ft_atoi.c \
		ft_info.c \
		ft_validate_map.c \
		makesquare2.c \
		helpmakesquare.c
OBJS = $(SRCS:%.c=$(SRCSDIR)%.o)
INCLUDES = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
