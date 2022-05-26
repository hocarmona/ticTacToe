//
//  main.c
//  ticTacToe
//
//  Created by Hector Carmona on 10/18/21.
//

#include <stdio.h>
char table[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void board(void);
void clearScreen(void);
void gameStatus(void);
void check(char);
int status = 1;
int player = 1;
int main() {
    board();
    while (status == 1) {
        int coordinate;
        char sign;
        if (player == 1) {
            printf("Player 1 turn, Select a number: ");
            scanf("%d", &coordinate);
            sign = 'X';
            player = 2;
        }else{
            printf("Player 2 turn, Select a number: ");
            scanf("%d", &coordinate);
            sign = 'O';
            player = 1;
        }
        if (table[coordinate] != 'X' && table[coordinate] != 'O' && coordinate >= 1 && coordinate <= 9) {
            table[coordinate] = sign;
        }else{
            if (player == 1) {
                player = 2;
            }else{
                player = 1;
            }
        }
        printf("TIC TAC TOE");
        board();
        gameStatus();
    }
    if (status == 0) {
        if (player == 1) {
            printf("Player 2 WINS!!");
        }else{
            printf("Player 1 WINS!!");
        }
    }else{
        printf("It's a Draw\n");
    }
    printf("\nGAME OVER\n");
    
    return 0;
}
void board(void){
    clearScreen();
    printf("\n%c | %c | %c\n", table[1], table[2], table[3]);
    printf("__ ___ ___\n");
    printf("%c | %c | %c\n", table[4], table[5], table[6]);
    printf("__ ___ ___\n");
    printf("%c | %c | %c\n\n", table[7], table[8], table[9]);
}
void clearScreen(){
    for(int i= 0; i < 50; i++)
        printf(" \n");
}
void gameStatus(){
    if (table[1] == table[2] && table[2] == table[3]) {
        status = 0;
    }else if(table[4] == table[5] && table[5] == table[6]){
        status = 0;
    }else if(table[7] == table[8] && table[8] == table[9]){
        status = 0;
    }else if(table[1] == table[4] && table[4] == table[7]){
        status = 0;
    }else if(table[2] == table[5] && table[5] == table[8]){
        status = 0;
    }else if(table[3] == table[6] && table[6] == table[9]){
        status = 0;
    }else if(table[1] == table[5] && table[5] == table[9]){
        status = 0;
    }else if(table[3] == table[5] && table[5] == table[7]){
        status = 0;
    }else if (table[1] != '1' && table[2] != '2' && table[3] != '3' &&table[4] != '4' && table[5] != '5' && table[6] != '6' && table[7] != '7' && table[8] != '8' && table[9] != '9')
        status = -1;
}

