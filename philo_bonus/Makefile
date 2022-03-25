.DEFAULT.GOAL = all

NAME				=	philo_bonus

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
LIBS				=	-pthread

SRCS				=	ft_atoi_bonus.c	\
						ft_checker_args_bonus.c	\
						ft_destroy_semaphores_bonus.c	\
						ft_dinner_bonus.c	\
						ft_get_time_msec_bonus.c	\
						ft_handler_philo_load_bonus.c	\
						ft_handler_table_destroy_bonus.c	\
						ft_handler_table_load_bonus.c	\
						ft_init_semaphores_bonus.c	\
						ft_main_bonus.c	\
						ft_philosophers_bonus.c	\
						ft_put_msg_bonus.c	\
						ft_strlen_bonus.c

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
