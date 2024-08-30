# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 16:44:07 by ajacinto          #+#    #+#              #
#    Updated: 2024/07/24 16:44:13 by ajacinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	init.c \
	validate_args.c \
	rules.c \
	push_swap_utils.c \
	rotate.c \
	swap.c \
	push.c \
	reverse_rotate.c \
	ordering.c \
	push_swap_utils1.c \

MAKEFLAGS += -silent

OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

${LIBFT}:
	@make -s -C ${LIBFT_DIR}

clean:
	@make clean -s -C ${LIBFT_DIR}
	${RM} ${OBJS}

fclean: clean
	@make fclean -s -C ${LIBFT_DIR}
	${RM} ${NAME}

re: fclean all
