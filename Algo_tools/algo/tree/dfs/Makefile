CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -g `pkg-config libgvc --cflags`
LDFLAGS=`pkg-config  libgvc --cflags` -lcgraph -lgvc
LDLIBS=
EXEC= prog

SRC= dfs.c main.c
OBJ= ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

prog:${OBJ}
	${CC} $^ -o prog $(CFLAGS) $(LDFLAGS)


clean:
	${RM} prog
	${RM} *.o
	${RM} *.gif
	${RM} *.png
