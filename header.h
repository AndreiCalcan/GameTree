#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 3

typedef struct node{
    char table[SIZE][SIZE];
    struct node **children;
    int depth;
    char score;
}Node, *PNode;

void printGame(char game[SIZE][SIZE]);