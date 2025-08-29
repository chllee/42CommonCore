# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chllee <chllee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 14:37:09 by chllee            #+#    #+#              #
#    Updated: 2025/06/25 19:22:40 by chllee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -I libft

NAME	:= libft.a
HEADER	:= libftprintf.h

SRCS	:= ft_phex.c ft_pfpercent.c ft_pfputadd.c ft_pfputchar.c \
		ft_pfputdec.c ft_pfputptr.c ft_pfputstr.c ft_pfputunsint.c \
		ft_uphex.c ft_printf.c
		
OBJS	:= $(SRCS:.c=.o)

L_DIR	:= libft
LIBFT	:= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(L_DIR)
	cp $(L_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(L_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(L_DIR) fclean
	rm -f $(NAME)

re: fclean all
