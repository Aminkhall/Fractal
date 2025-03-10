NAME 	=	fractol
CC 		=	cc

HEADER 	=	fractol.h

CFLAGS 	= 	-Wall -Wextra -Werror -Imlx

SRC 	=	events.c \
			init_function.c \
			main.c \
			math_utils.c \
			render_function.c \
			string_utils.c \

OBJ 	= 	${SRC:.c=.o}

all: ${NAME}

${NAME} : ${OBJ}
	@ ${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o : %.c $(HEADER)
	@ ${CC} ${CFLAGS} -c $< -o $@
	
clean :
	@rm -f ${OBJ}

re: fclean all

fclean : clean
	@rm -f ${NAME}
	
.PHONY: all clean fclean re