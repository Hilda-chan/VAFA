CC=gcc
CFLAGS=-Wall -Werror -std=c99
CPPFLAGS =-O2
LDLIBS=


SRC = calcu.c tinyexpr.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

release: main
	${CC} ${OBJ} -lcsfml-graphics -lcsfml-window -lm -o Calculator

main: ${OBJ}

debug: CPPFLAGS = -g -fsanitize=address
debug: LDLIBS = -lasan
debug: main
	${CC} ${CPPFLAGS} ${OBJ} ${LDLIBS} -lcsfml-graphics -lcsfml-window -lm -o Calculator

clean:
	rm -f Calculator
	${RM} ${OBJ}
	${RM} ${DEP}

-include ${DEP}
