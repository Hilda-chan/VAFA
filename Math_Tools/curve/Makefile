CC=gcc
CFLAGS=-Wall -std=c99
CPPFLAGS =-O2
LDLIBS=


SRC = graph.c tinyexpr.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

release: main
	${CC} ${OBJ} -lcsfml-graphics -lcsfml-window -lm -o Graph

main: ${OBJ}

debug: CPPFLAGS = -g -fsanitize=address
debug: LDLIBS = -lasan
debug: main
	${CC} ${CPPFLAGS} ${OBJ} -lcsfml-graphics -lcsfml-window -lm -o Graph

clean:
	rm -f Graph
	${RM} ${OBJ}
	${RM} ${DEP}

-include ${DEP}
