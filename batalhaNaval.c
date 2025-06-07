#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tamanho_linhas = 10, tamanho_colunas = 10;

    printf("BATALHA NAVAL\n");

    if(tamanho_linhas > 50 || tamanho_colunas > 50) {
        printf("ERRO: Tamanho máximo permitido é 50x50!\n");
        return 0;
    }

    if(tamanho_colunas < 3 && tamanho_linhas < 3) {
        printf("ERRO: O tabuleiro deve ter pelo menos 3 posições em uma direção para caber os navios!\n");
        return 0;
    }

    // Declaração da matriz com tamanho fixo 10x10
    int tabuleiro[tamanho_linhas][tamanho_colunas];

    // Coordenadas dos navios (definidas automaticamente)
    int navio1_linha = 0;
    int navio1_coluna = 0;
    int navio2_linha = 0;
    int navio2_coluna = 0;

    if(tamanho_colunas >= 3) {
        navio1_linha = 0;
        navio1_coluna = 0;
    }

    if(tamanho_linhas >= 3) {
        if(tamanho_colunas >= 4) {
            navio2_linha = 0;
            navio2_coluna = 3;
        } else if(tamanho_linhas >= 4) {
            navio2_linha = 1;
            navio2_coluna = 0;
        } else {
            navio2_linha = 0;
            navio2_coluna = (tamanho_colunas > 1) ? 1 : 0;
        }
    }

    int i, j;

    for(i = 0; i < tamanho_linhas; i++) {
        for(j = 0; j < tamanho_colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navio1_posicionado = 0;
    if(tamanho_colunas >= 3) {
        if(navio1_coluna + 3 <= tamanho_colunas && navio1_linha < tamanho_linhas) {
            int pode_posicionar = 1;
            for(i = 0; i < 3; i++) {
                if(tabuleiro[navio1_linha][navio1_coluna + i] != 0) {
                    pode_posicionar = 0;
                    break;
                }
            }
            if(pode_posicionar) {
                for(i = 0; i < 3; i++) {
                    tabuleiro[navio1_linha][navio1_coluna + i] = 3;
                }
                navio1_posicionado = 1;
            }
        }
    }

    int navio2_posicionado = 0;
    if(tamanho_linhas >= 3) {
        if(navio2_linha + 3 <= tamanho_linhas && navio2_coluna < tamanho_colunas) {
            int pode_posicionar = 1;
            for(i = 0; i < 3; i++) {
                if(tabuleiro[navio2_linha + i][navio2_coluna] != 0) {
                    pode_posicionar = 0;
                    break;
                }
            }
            if(pode_posicionar) {
                for(i = 0; i < 3; i++) {
                    tabuleiro[navio2_linha + i][navio2_coluna] = 3;
                }
                navio2_posicionado = 1;
            }
        }
    }

    // === NAVIO DIAGONAL 1 === (posição: (2,2), (3,3), (4,4))
    int navio3_linha = 2, navio3_coluna = 2;
    int pode_posicionar_diag1 = 1;
    for(i = 0; i < 3; i++) {
        if(tabuleiro[navio3_linha + i][navio3_coluna + i] != 0) {
            pode_posicionar_diag1 = 0;
            break;
        }
    }
    if(pode_posicionar_diag1) {
        for(i = 0; i < 3; i++) {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    }

    // === NAVIO DIAGONAL 2 === (posição: (2,7), (3,6), (4,5))
    int navio4_linha = 2, navio4_coluna = 7;
    int pode_posicionar_diag2 = 1;
    for(i = 0; i < 3; i++) {
        if(tabuleiro[navio4_linha + i][navio4_coluna - i] != 0) {
            pode_posicionar_diag2 = 0;
            break;
        }
    }
    if(pode_posicionar_diag2) {
        for(i = 0; i < 3; i++) {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    }

    printf("   ");
    for(j = 0; j < tamanho_colunas; j++) {
        if(j + 1 < 10) {
            printf("%2d ", j + 1);
        } else {
            printf("%d ", j + 1);
        }
    }
    printf("\n");

    for(i = 0; i < tamanho_linhas; i++) {
        if(i + 1 < 10) {
            printf("%2d ", i + 1);
        } else {
            printf("%d ", i + 1);
        }

        for(j = 0; j < tamanho_colunas; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
