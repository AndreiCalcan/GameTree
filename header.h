#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 3

typedef struct node
{
    char table[SIZE][SIZE];
    struct node **children;
    int child_nr;
    int depth;
    char score;
} Node, *PNode;