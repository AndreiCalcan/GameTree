#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    char table[3][3];
    struct node **children;
    int depth;
    char score;
}Node, *PNode;

