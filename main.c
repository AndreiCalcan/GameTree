#include "header.h"

int main()
{
    PNode startingNode = (PNode)malloc(sizeof(Node));
    startingNode->children = NULL;
    startingNode->depth = 0;
    startingNode->child_nr = 0;
    int countx = 0, counto = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%hhd", &startingNode->table[i][j]);
            if (startingNode->table[i][j] == 1)
            {
                countx++;
            }
            else if (startingNode->table[i][j] == 2)
            {
                counto++;
            }
        }
    }
    if (countx - counto != 0 && countx - counto != 1)
    {
        printf("Input not valid. The cake is a lie.\n");
        goto free;
    }
    printGame(startingNode->table);
    startingNode = minimax(startingNode, countx - counto + 1);
    printf("%d\n", startingNode->score);
    for (int i = 0; i < startingNode->child_nr; i++)
    {
        if (startingNode->children[i]->score == startingNode->score)
        {
            printGame(startingNode->children[i]->table);
            break;
        }
    }
free:
    return 0;
}