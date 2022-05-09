CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99
CPPFLAGS =-O2
LDLIBS=


SRC = Vigenere.c Tools.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

release: main
	${CC} ${OBJ} -lcsfml-graphics -lcsfml-window -o Vigenere

main: ${OBJ}

debug: CPPFLAGS = -g -fsanitize=address
debug: LDLIBS = -lasan
debug: main
	${CC} ${CPPFLAGS} ${OBJ} -lasan -o main

graphic: LDLIBS = -lasan -lcsfml_graphics -lcsfml-window -o main
graphic: main
	${CC} ${CPPFLAGS} ${OBJ} ${LDLIBS} -o main

clean:
	rm -f Vigenere
	${RM} ${OBJ}
	${RM} ${DEP}

-include ${DEP}
