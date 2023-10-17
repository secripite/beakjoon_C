#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_
{
    char name[15];
    int level;
    int end;
    struct tree_ *child = (tree_*)malloc(sizeof(tree_));
}tree;

tree new_node(char *Str,int level){
    tree *node = (tree *)malloc(sizeof(tree));
    strcpy(node->name, Str);
    return node;
}
