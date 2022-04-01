.DEFAULT.GOAL = all

NAME				=	philo_bonus

CC					=	cc -g #-fsanitize=thread -g3
CFLAGS				=	-Wall -Wextra -Werror
LIBS				=	-pthread

SRCS				=	ft_atoi_bonus.c	\
						ft_checker_args_bonus.c	\
						ft_clean_exit.c	\
						ft_destroy_semaphores_bonus.c	\
						ft_dinner_bonus.c	\
						ft_get_keep_dinning.c	\
						ft_get_last_meal_time_bonus.c	\
						ft_get_num_meals_bonus.c	\
						ft_get_time_msec_bonus.c	\
						ft_handler_philo_load_bonus.c	\
						ft_handler_table_destroy_bonus.c	\
						ft_handler_table_load_bonus.c	\
						ft_init_semaphores_bonus.c	\
						ft_main_bonus.c	\
						ft_msleep_bonus.c	\
						ft_philosophers_bonus.c	\
						ft_put_msg_bonus.c	\
						ft_set_keep_dinning.c	\
						ft_set_last_meal_bonus.c	\
						ft_set_last_meal_time_bonus.c	\
						ft_strlen_bonus.c

RM					=	@rm -rf

OBJS				=	$(SRCS:.c=.o)

.c.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all:				${NAME}

san:				${OBJS}
					${CC} ${SAN} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
