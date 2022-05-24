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

Node *get_moves(Node *node, char curr_player)
{
    node->children = (Node **)malloc(sizeof(Node *) * 9);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (node->table[i][j] == 0)
            {
                Node *new = (Node *)malloc(sizeof(Node));
                copy_table(node->table, new->table);
                new->table[i][j] = curr_player;
                node->children[(node->child_nr)++] = new;
                new->depth = node->depth + 1;
                new->child_nr = 0;
                new->children = NULL;
            }
        }
    }

    return node;
}

Node *minimax(Node *node, char main_player)
{
    char winner = findWinner(node->table);
    if (winner == main_player)
        node->score = 1;
    else if (winner > 0)
        node->score = -1;
    else if (winner == 0)
        node->score = 0;

    if (winner != -1)
        return node;

    char curr_player;
    char parity = node->depth % 2;
    if (parity == 0)
        curr_player = main_player;
    else
        curr_player = 3 - main_player;

    node = get_moves(node, curr_player);

    if (parity == 0)
    {
        char max = CHAR_MIN;
        for (int i = 0; i < node->child_nr; i++)
        {
            node->children[i] = minimax(node->children[i], main_player);
            if (node->children[i]->score > max)
                max = node->children[i]->score;
        }
        node->score = max;
    }
    else
    {
        char min = CHAR_MAX;
        for (int i = 0; i < node->child_nr; i++)
        {
            node->children[i] = minimax(node->children[i], main_player);
            if (node->children[i]->score < min)
                min = node->children[i]->score;
        }
        node->score = min;
    }

    return node;
}

Node *alfa_beta(Node *node, char main_player, char alfa, char beta)
{
    char winner = findWinner(node->table);
    if (winner == main_player)
        node->score = 1;
    else if (winner > 0)
        node->score = -1;
    else if (winner == 0)
        node->score = 0;

    if (winner != -1)
        return node;

    char curr_player;
    char parity = node->depth % 2;
    if (parity == 0)
        curr_player = main_player;
    else
        curr_player = 3 - main_player;

    node = get_moves(node, curr_player);

    if (parity == 0)
    {
        char max = CHAR_MIN;
        for (int i = 0; i < node->child_nr; i++)
        {
            if (max > beta)
                break;
            node->children[i] = alfa_beta(node->children[i], main_player, max, beta);
            if (node->children[i]->score > max)
                max = node->children[i]->score;
        }
        node->score = max;
    }
    else
    {
        char min = CHAR_MAX;
        for (int i = 0; i < node->child_nr; i++)
        {
            if (min < alfa)
                break;
            node->children[i] = alfa_beta(node->children[i], main_player, alfa, min);
            if (node->children[i]->score < min)
                min = node->children[i]->score;
        }
        node->score = min;
    }

    return node;
}