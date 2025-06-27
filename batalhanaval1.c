#include <stdio.h>
int main () {

    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro [10][10] = {0};

    tabuleiro[1][2] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;  

    tabuleiro[6][4] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[6][6] = 3;  


    for (int l = 0; l < 10; l++) {
        printf (" %c ", linha[l]);
        }
        printf ("\n");

    for (int i = 0; i <10; i++) {
        for (int j = 0; j < 10; j++) {
            
        printf (" %d ", tabuleiro [i][j]);
        }
        printf("\n");
    }   



    return 0;
}