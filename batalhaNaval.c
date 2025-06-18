#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Matriz tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 1;
    int colunaHorizontal = 4;

    int linhaVertical = 4;
    int colunaVertical = 7;

    // Validação: Verifica se o navio horizontal cabe no tabuleiro
    if (colunaHorizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
            }
        }
    }

    // Validação: Verifica se o navio vertical cabe no tabuleiro
    if (linhaVertical + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            }
        }
    }

 // Exibição do tabuleiro 
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%-2d", i + 1);  // Número da linha (1 a 10)
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
