# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2021/10/08 01:55:06 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCSDIR = srcs/
SRCS = main.c \
		validate/is_valid_input.c \
		validate/is_valid_chars.c \
		validate/is_valid_map_height.c \
		validate/is_valid_map_structure.c \
		validate/is_valid_coordinate.c \
		validate/header_len.c \
		free.c \
		solve.c \
		put_map.c \
		read.c \
		load_map_data.c \
		apply_square_on_map.c \
		search_square.c \
		utils/ft_atoi.c \
		utils/ft_is_printable.c \
		utils/ft_puts.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c
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


########################################33

TESTER = tester_bsq

.PHONY: test

test: all
ifneq ($(shell echo ${TESTER}), $(shell ls | grep ${TESTER}))
	git clone https://github.com/mfunyu/tester_bsq.git
endif
	cd tester_bsq && ./test.sh
