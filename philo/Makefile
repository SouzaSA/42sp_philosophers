# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 14:48:03 by sde-alva          #+#    #+#              #
#    Updated: 2022/03/25 14:41:19 by sde-alva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		:=	all

NAME				=	philo

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
LIBS				=	-l pthread

SRCS				=	ft_atoi.c	\
						ft_checker_args.c	\
						ft_destroy_forks_mutex.c	\
						ft_destroy_philo_threads.c	\
						ft_dinner.c	\
						ft_get_time_msec.c	\
						ft_handler_philo_load.c	\
						ft_handler_table_destroy.c	\
						ft_handler_table_load.c	\
						ft_main.c	\
						ft_philosophers.c	\
						ft_put_msg.c	\
						ft_strlen.c

RM					=	@rm -rf

OBJS				=	$(SRCS:.c=.o)

.c.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all:				${NAME}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all bonus san clean fclean re

