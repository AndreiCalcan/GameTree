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

void printGame(char game[SIZE][SIZE]);
char findWinner(char game[SIZE][SIZE]);
Node *get_moves(Node *node, char curr_player);
void copy_table(char old_table[SIZE][SIZE], char new_table[SIZE][SIZE]);
Node *minimax(Node *node, char curr_player);