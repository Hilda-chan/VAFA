#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "dfs.h"

int main(int argc, char** argv)
{
    if(argc != 2)
        err(1,NULL);

    Agraph_t* G;
    Agnode_t* node;
    GVC_t* gvc;
    Agsym_t* attr;
    FILE* fp;
    FILE* dot;
    int i;
    char str[50];

    dot = fopen("dfsTest/dot2.dot","w");
    fp = fopen(argv[1],"r");
    G = agread(fp,0);
    gvc = gvContext(); // CREATE CONTEXT
    Agnode_t* n = agfstnode(G); //FIRST NODE
    attr = agattr(G,AGNODE,"id","0");
    i = 0;

    for(node = n;node;node=agnxtnode(G,node))
    {
        sprintf(str,"%d",i);
        agset(node,"id",str);
        i++;
    }


    dfs(G,gvc,dot);
    system("dot -Tpng dfsTest/dot2.dot -O");
    system("convert -resize 768x576 -delay 100 -loop 1 'dfsTest/dot2.dot.%d.png[0-17]' result.gif");
    system("rm dfsTest/*.png");
    agclose(G);
    fclose(fp);
    fclose(dot);
    system("eog result.gif");

    return 0;
}
