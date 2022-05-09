CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -g 
LDFLAGS=`pkg-config  libgvc --cflags` -lcgraph -lgvc
LDLIBS=
EXEC= prog

SRC= rpn.c stack.c 
OBJ= ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

prog:${OBJ}
	${CC} $^ -o cal $(CFLAGS) 


clean:
	${RM} cal
	${RM} *.o
