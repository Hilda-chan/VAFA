CC=gcc
CFLAGS=-Wall -std=c99
CPPFLAGS =-O2
LDLIBS=


SRC = Ui.c Math_Tools/calculator/tinyexpr.c Algo_tools/algo/graph/dfs/Gdfs.c Algo_tools/algo/graph/bfs/Gbfs.c Algo_tools/algo/tree/dfs/Tdfs.c Algo_tools/algo/tree/bfs/Tbfs.c Algo_tools/algo/tree/treeCheck/isTree/IsTree.c Algo_tools/algo/queue/queue.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

release: main
	${CC} ${OBJ} -lcsfml-graphics -lcsfml-window -lm -lssl -lcrypto -lcgraph -lgvc -o Vafa

main: ${OBJ}

debug: CPPFLAGS = -g -fsanitize=address
debug: LDLIBS = -lasan
debug: main
	${CC} ${CPPFLAGS} ${OBJ} -lcsfml-graphics -lcsfml-window -lm -lssl -lcrypto -lcgraph -lgvc -o Vafa

clean:
	rm -f Vafa
	${RM} ${OBJ}
	${RM} ${DEP}

-include ${DEP}
