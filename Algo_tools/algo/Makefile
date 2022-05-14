CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -g `pkg-config libgvc --cflags`
LDFLAGS=`pkg-config  libgvc --cflags` -lcgraph -lgvc
LDLIBS=
EXEC= prog

SRC= graph/dfs/Gdfs.c graph/bfs/Gbfs.c tree/dfs/Tdfs.c tree/bfs/Tbfs.c \
tree/treeCheck/isTree/IsTree.c queue/queue.c general.c
OBJ= ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

prog:${OBJ}
	${CC} $^ -o prog $(CFLAGS) $(LDFLAGS)


clean:
	${RM} prog
	${RM} *.o
	${RM} graph/bfs/*.o
	${RM} graph/dfs/*.o
	${RM} tree/bfs/*.o
	${RM} tree/dfs/*.o
	${RM} tree/treeCheck/isTree/*.o
	${RM} queue/*.o
	${RM} result/*.png
