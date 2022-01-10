SRC =	./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c  \
		lst.c mif_manager.c mif_to_img.c put_pixel.c put_square.c \

CC = gcc

HEADER = mif_manager.h ./get_next_line/get_next_line.h

OBJ = $(SRC:.c=.o)

NAME = mif_manager.a

RM = rm -f

LIBC = ar -rc

CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(CC) ${CFLAGS} -I. -o $@ -c $?

${NAME} : $(OBJ)
	${LIBC} ${NAME} ${OBJ}

all :	${NAME} 
	make bonus

clean :
	${RM} ${OBJ}

fclean :	clean
	${RM} ${NAME}

re :	fclean all
