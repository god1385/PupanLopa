# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <macbook@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 21:19:28 by ctorrek           #+#    #+#              #
#    Updated: 2021/11/04 17:59:51 by ctorrek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH    	= srcs/

LIBFT_PATH   	= libft/

LIBFT_LIB    	= libft.a

HEADERS_FOLDER  = includes/


SRCS_FILES   	= ./srcs/ft_printf.c ./srcs/ft_int.c \
				  ./srcs/ft_hex.c ./srcs/ft_char.c
			
SRCS_OBJS     	= ${SRCS_FILES:.c=.o}

CC          	= gcc
RM          	= rm -f
CFLAGS      	= -Wall -Wextra -Werror

NAME        	= libftprintf.a

LIBFT_OBJS  	= ${LIBFT_PATH}*.o

LIBFTMAKE  		= $(MAKE) -C ${LIBFT_PATH}

all:			${NAME}

${NAME}:   	 	${SRCS_OBJS} pmake
				ar rcs ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
				${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRCS_OBJS}

fclean: 		clean
				${RM} ${NAME} ${LIBFT_PATH} ${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re
