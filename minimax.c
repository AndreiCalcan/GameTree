#include "header.h"

void copy_table(char old_table[SIZE][SIZE], char new_table[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            new_table[i][j] = old_table[i][j];
        }
    }
}

PNode *get_moves(Node *node, int *child_nr, char curr_player)
{
    node->children = (Node *)malloc(sizeof(Node) * 9);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (node->table[i][j] == 0)
            {
                Node *new = (Node *)malloc(sizeof(Node));
                copy_table(node->table, new->table);
                new->table[i][j] = curr_player;
                node->children[(*child_nr)++] = new;
                new->depth = node->depth + 1;
                new->child_nr = 0;
                new->children = NULL;
            }
        }
    }
}