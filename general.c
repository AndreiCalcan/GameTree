#include "header.h"

void printGame(char game[3][3]){
    printf("- - - - -\n");
    for(int i = 0; i < 3; i++){
        printf("| ");
        for(int j = 0; j < 3; j++){
           if(game[i][j] == 1){
               printf("X ");
           }else{
               printf("O ");
           }
        }
        printf("|\n");
    }
    printf("- - - - -\n");
}