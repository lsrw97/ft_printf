DIRLIB		= ./libft/

SRCS	=	ft_printf.c \
			ft_putnbr_fd_mod.c \
			printconvfromdec.c \
			uIntPutnbr.c		\
			convertX.c	\

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

NAMELFT		= libft.a


all:		${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -I. -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${BONUS_OBJS} ${OBJS}
	cd ${DIRLIB} && make clean

fclean:		clean
	${RM} ${BONUS_OBJS} ${NAME}
	cd ${DIRLIB} && make fclean

re:			fclean all
			cd ${DIRLIB} && ${MAKE} clean

.PHONY:		all clean fclean re
