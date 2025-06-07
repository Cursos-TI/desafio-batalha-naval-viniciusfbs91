#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tamanho_linhas = 10, tamanho_colunas = 15;
    
    printf("BATALHA NAVAL\n");
    
    if(tamanho_linhas > 50 || tamanho_colunas > 50) {
        printf("ERRO: Tamanho máximo permitido é 50x50!\n"); // Na minha tela 1920x1080 maior que isso fica fora de enquadramento
        return 0;
    }
    
    // Verificar se o tabuleiro é grande o suficiente para os navios
    if(tamanho_colunas < 3 && tamanho_linhas < 3) {
        printf("ERRO: O tabuleiro deve ter pelo menos 3 posições em uma direção para caber os navios!\n"); // Adicionado devido a quantidade de naviosminimo  solicitado no exercicio
        return 0;
    }
    
    // Declaração da matriz com tamanho dinâmico
    int tabuleiro[tamanho_linhas][tamanho_colunas];
    int navio1[3] = {3, 3, 3};  // Primeiro navio (horizontal) - tamanho 3
    int navio2[3] = {3, 3, 3};  // Segundo navio (vertical) - tamanho 3
    
    // Coordenadas dos navios (definidas automaticamente)
    int navio1_linha = 0;        // Primeira linha disponível
    int navio1_coluna = 0;       // Primeira coluna disponível
    int navio2_linha = 0;        // Linha para o navio vertical
    int navio2_coluna = 0;       // Coluna para o navio vertical

    if(tamanho_colunas >= 3) {
        navio1_linha = 0;
        navio1_coluna = 0;
    }
    
    if(tamanho_linhas >= 3) {
        if(tamanho_colunas >= 4) {
            // Se tiver espaço, colocar o navio vertical na coluna 3
            navio2_linha = 0;
            navio2_coluna = 3;
        } else if(tamanho_linhas >= 4) {
            // Se não tiver espaço horizontal, colocar na linha 1
            navio2_linha = 1;
            navio2_coluna = 0;
        } else {
            // Tabuleiro muito pequeno, colocar onde couber
            navio2_linha = 0;
            navio2_coluna = (tamanho_colunas > 1) ? 1 : 0;
        }
    }
    
    int i, j;
    
    for(i = 0; i < tamanho_linhas; i++) {
        for(j = 0; j < tamanho_colunas; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
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
                    tabuleiro[navio1_linha][navio1_coluna + i] = navio1[i];
                }
                navio1_posicionado = 1;
            }
        }
    }
    
    
    int navio2_posicionado = 0;
    if(tamanho_linhas >= 3) {
 
        if(navio2_linha + 3 <= tamanho_linhas && navio2_coluna < tamanho_colunas) {
            // Verificar se não há sobreposição
            int pode_posicionar = 1;
            for(i = 0; i < 3; i++) {
                if(tabuleiro[navio2_linha + i][navio2_coluna] != 0) {
                    pode_posicionar = 0;
                    break;
                }
            }
            
            if(pode_posicionar) {
                // Posicionar o navio vertical
                for(i = 0; i < 3; i++) {
                    tabuleiro[navio2_linha + i][navio2_coluna] = navio2[i];
                }
                navio2_posicionado = 1;
            }
        }
    }
    
    printf("   ");  // Espaço para alinhamento pra ficar mais bonito
    for(j = 0; j < tamanho_colunas; j++) {
        if(j + 1 < 10) {
            printf("%2d ", j + 1);  // Números de 1-9 com espaçamento
        } else {
            printf("%d ", j + 1);   // Números >= 10 sem espaço extra
        }
    }
    printf("\n");
    
    // Imprimir o tabuleiro linha por linha
    for(i = 0; i < tamanho_linhas; i++) {
        if(i + 1 < 10) {
            printf("%2d ", i + 1);  // Número da linha com espaçamento
        } else {
            printf("%d ", i + 1);   // Números >= 10 sem espaço extra
        }
        
        for(j = 0; j < tamanho_colunas; j++) {
            printf("%2d ", tabuleiro[i][j]);  // Valor da posição
        }
        printf("\n");  // Nova linha após cada linha do tabuleiro
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
