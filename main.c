#include "header.h"

int main()
{
    PNode startingNode = (PNode)malloc(sizeof(Node));
    startingNode->children = NULL;
    startingNode->depth = 0;
    startingNode->child_nr = 0;
    int countx = 0, counto = 0;
    printf("Introduceti tabla de X/O\nLegenda:\nX -> 1\nO -> 2\ngol -> 0\n");
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
            else if(startingNode->table[i][j] != 0){
                printf("Input invalid.\n");
                free(startingNode);
                return 0;
            }
        }
    }
    if (countx - counto != 0 && countx - counto != 1)
    {
        printf("Input not valid. The cake is a lie.\n");
        goto free;
    }
    printGame(startingNode->table);
    startingNode = alfa_beta(startingNode, countx - counto + 1, CHAR_MIN, CHAR_MAX);
    // startingNode = minimax(startingNode, countx - counto + 1);
    if(startingNode->score == 1){
        printf("Jucatorul care urmeaza sa mute castiga.\n");
    }else if(startingNode->score == 0){
        printf("Jocul se termina in remiza.\n");
    }else if(startingNode->score == -1){
        printf("Jucatorul care urmeaza sa mute pierde.\n");
    }
    //printf("%d\n", startingNode->score);
    for (int i = 0; i < startingNode->child_nr; i++)
    {
        if (startingNode->children[i]->score == startingNode->score)
        {
            printf("O posibila mutare optima este:\n");
            printGame(startingNode->children[i]->table);
            break;
        }
    }
free:
    freeTree(startingNode);
    return 0;
}