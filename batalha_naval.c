#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define ALT_HAB 3
#define LARG_HAB 5
#define CENTRO_LINHA 1
#define CENTRO_COL 2

void criarHabilidades(int cone[][LARG_HAB], int cruz[][LARG_HAB], int octaedro[][LARG_HAB]) {
    for (int i = 0; i < ALT_HAB; i++) {
        for (int j = 0; j < LARG_HAB; j++) {
            // Cone: expandindo de cima para baixo
            cone[i][j] = (j >= CENTRO_COL - i && j <= CENTRO_COL + i) ? 1 : 0;

            // Cruz: linha central + coluna central
            cruz[i][j] = (i == CENTRO_LINHA || j == CENTRO_COL) ? 1 : 0;

            // Octaedro: formato de losango no centro
            octaedro[i][j] = (abs(i - CENTRO_LINHA) + abs(j - CENTRO_COL) <= 2) ? 1 : 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[][TAM_TAB], int habilidade[][LARG_HAB], int origemX, int origemY) {
    for (int i = 0; i < ALT_HAB; i++) {
        for (int j = 0; j < LARG_HAB; j++) {
            int linha = origemX + i - CENTRO_LINHA;
            int coluna = origemY + j - CENTRO_COL;
            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[][TAM_TAB], char linha[]) {
    printf("   ");
    for (int l = 0; l < TAM_TAB; l++) {
        printf("%3c", linha[l]);
    }
    printf("\n");

    for (int i = 0; i < TAM_TAB; i++) {
        printf("%3d", i + 1);
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%3d", tabuleiro[i][j]); // Exibe 0, 3, 5
        }
        printf("\n");
    }
}

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // Inserindo navios
    tabuleiro[1][2] = 3; tabuleiro[2][2] = 3; tabuleiro[3][2] = 3;
    tabuleiro[6][4] = 3; tabuleiro[6][5] = 3; tabuleiro[6][6] = 3;
    tabuleiro[2][6] = 3; tabuleiro[3][7] = 3; tabuleiro[4][8] = 3;
    tabuleiro[6][0] = 3; tabuleiro[7][1] = 3; tabuleiro[8][2] = 3;

    int cone[ALT_HAB][LARG_HAB], cruz[ALT_HAB][LARG_HAB], octaedro[ALT_HAB][LARG_HAB];
    criarHabilidades(cone, cruz, octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 5);       // Cruz em (6,5)
    aplicarHabilidade(tabuleiro, octaedro, 4, 7);   // Octaedro em (4,7)

    imprimirTabuleiro(tabuleiro, linha);

    return 0;
}