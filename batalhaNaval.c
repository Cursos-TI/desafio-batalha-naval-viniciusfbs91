#include <stdio.h>

int main() {
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

    int tabuleiro[tamanho_linhas][tamanho_colunas];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for(i = 0; i < tamanho_linhas; i++) {
        for(j = 0; j < tamanho_colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1 - horizontal
    int navio1_linha = 0, navio1_coluna = 0;
    if(navio1_coluna + 3 <= tamanho_colunas) {
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
        }
    }

    // Navio 2 - vertical
    int navio2_linha = 0, navio2_coluna = 3;
    if(navio2_linha + 3 <= tamanho_linhas) {
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
        }
    }

    // Navio 3 - diagonal principal
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

    // Navio 4 - diagonal secundária
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

    // MATRIZES DE HABILIDADES
    int habilidade_tam = 5;
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Cone
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Soma das distâncias até o centro deve ser <= 2
            int distancia_linha = i < 2 ? 2 - i : i - 2;
            int distancia_coluna = j < 2 ? 2 - j : j - 2;
            if(distancia_linha + distancia_coluna <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Pontos de origem das habilidades no tabuleiro
    int origem_cone_linha = 0, origem_cone_coluna = 2;
    int origem_cruz_linha = 5, origem_cruz_coluna = 5;
    int origem_octaedro_linha = 7, origem_octaedro_coluna = 2;

    // Aplicar as habilidades no tabuleiro
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int linha, coluna;

            if(cone[i][j] == 1) {
                linha = origem_cone_linha + i;
                coluna = origem_cone_coluna + j - 2;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if(tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }

            if(cruz[i][j] == 1) {
                linha = origem_cruz_linha + i - 2;
                coluna = origem_cruz_coluna + j - 2;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if(tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }

            if(octaedro[i][j] == 1) {
                linha = origem_octaedro_linha + i - 2;
                coluna = origem_octaedro_coluna + j - 2;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if(tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }

    // Cabeçalho das colunas
    printf("   ");
    for(j = 0; j < tamanho_colunas; j++) {
        if(j + 1 < 10) {
            printf("%2d ", j + 1);
        } else {
            printf("%d ", j + 1);
        }
    }
    printf("\n");

    // Imprimir o tabuleiro
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

    return 0;
}
