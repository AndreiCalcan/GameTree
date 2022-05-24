#include "header.h"

void printGame(char game[SIZE][SIZE]){
    printf("- - - - -\n");
    for(int i = 0; i < SIZE; i++){
        printf("| ");
        for(int j = 0; j < SIZE; j++){
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

char findWinner(char game[SIZE][SIZE]){
    int x_h,o_h, x_v,o_v;
    int xwon = 10, owon = 10;
    for(int i = 0; i < SIZE; i++){
        x_h = 0;
        o_h = 0;
        x_v = 0;
        o_v = 0;
        for(int j = 0; j < SIZE; j++){
            if(game[i][j] == 1){
                x_h++;
            }else if(game[i][j] == 2){
                o_h++;
            }
            if(game[j][i] == 1){
                x_v++;
            }else if(game[j][i] == 2){
                o_v++;
            }
        }
        if(x_h == 3 || x_v == 3){
            xwon = 1;
            owon = 0;
            break;
        }
        if(o_h == 3 || o_v == 3){
            owon = 1;
            xwon = 0;
            break;
        }
    }
    if(xwon != 1 && owon != 1){
        x_h = 0;
        o_h = 0;
        x_v = 0;
        o_v = 0;
        for(int i = 0; i < SIZE; i++){
            if(game[i][i] == 1){
                x_h++;
            }else if(game[i][i] == 2){
                o_h++;
            }
            if(game[i][SIZE - i - 1] == 1){
                x_v++;
            }else if(game[i][SIZE -i - 1] == 2){
                o_v++;
            }
        }
        if(x_h == 3 || x_v == 3){
            xwon = 1;
            owon = 0;
        }
        if(o_h == 3 || o_v == 3){
            owon = 1;
            xwon = 0;
        }
    }
    if(xwon == 1){
        return 1;
    }else if(owon == 1){
        return 2;
    }
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(game[i][j] != 0){
                count++;
            }
        }
    }
    if(count == 9){
        return 0;
    }else{
        return -1;
    }
}