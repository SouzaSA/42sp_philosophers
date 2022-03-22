.DEFAULT.GOAL = all

NAME				=	philo_bonus

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g
LIBS				=	-l pthread

SRCS				=	ft_atoi.c	\
						ft_checker_args.c	\
						ft_destroy_semaphores.c	\
						ft_dinner.c	\
						ft_get_time_msec.c	\
						ft_handler_philo_load.c	\
						ft_handler_table_destroy.c	\
						ft_handler_table_load.c	\
						ft_init_semaphores.c	\
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
