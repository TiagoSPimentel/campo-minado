#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3


char **alocarMatriz(int tamanho) {
    char **matriz = (char **)malloc(tamanho * sizeof(char *));  // Alocação do vetor de ponteiros
    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (char *)malloc(tamanho * sizeof(char));     // Alocação de cada linha da matriz
    }
    return matriz;  
}

//liberara memória da matriz alocada dinamicamente
void liberarMatriz(char **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]); 
    }
    free(matriz);
}


void inicializarTabuleiro(char **campo, int tamanho, char valor) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            campo[i][j] = valor;  // atribui o valor em cada posição da matriz
        }
    }
}

//para imprimir o tabuleiro
void imprimirTabuleiro(char **campo, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", campo[i][j]);  // imprime os elementos da linha
        }
        printf("\n");  // passa para proxima linha quando termina a anterior
    }
}

// para posicionar as minas de forma aleatória
void posicionarMinas(char **campo, int tamanho, int numMinas) {
    srand(time(NULL));  
    int minasColocadas = 0;
    
    // coloca minas até atingir o número especificado
    while (minasColocadas < numMinas) {
        int linha = rand() % tamanho;    
        int coluna = rand() % tamanho;   
        
        // verifica se já há uma mina na posição; se não, coloca uma mina
        if (campo[linha][coluna] != '*') {
            campo[linha][coluna] = '*';  
            minasColocadas++;            
        }
    }
}

//conta o número de minas vizinhas a uma célula específica
int contarMinasVizinhas(char **campo, int tamanho, int linha, int coluna) {
    int contagem = 0;
    
    // Loop pelas 8 células vizinhas (de -1 até +1 na linha e na coluna)
    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
            
            // Ignora a célula atual (linha, coluna)
            if (i == linha && j == coluna) continue;
            
            // Verifica se a célula (i, j) está dentro dos limites do tabuleiro
            if (i >= 0 && i < tamanho && j >= 0 && j < tamanho) {
                
                // Conta a mina se houver uma nesta posição
                if (campo[i][j] == '*') {
                    contagem++;
                }
            }
        }
    }
    return contagem;  // Retorna o número de minas vizinhas
}

void floodFill(char **campo, char **campoVisivel, int tamanho, int linha, int coluna, int *jogadasRestantes) {
    // Verifica se a célula está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho) {
        return;
    }

    // Se a célula já foi aberta ou é uma mina, não faz nada
    if (campoVisivel[linha][coluna] != 'x') {
        return;
    }

    // Revela a célula no campo visível
    int minasVizinhas = contarMinasVizinhas(campo, tamanho, linha, coluna);
    campoVisivel[linha][coluna] = minasVizinhas + '0';
    (*jogadasRestantes)--;

    // Se a célula não tem minas vizinhas (é um 0), então faz a recursão nas células vizinhas
    if (minasVizinhas == 0) {
        floodFill(campo, campoVisivel, tamanho, linha - 1, coluna, jogadasRestantes);  // Cima
        floodFill(campo, campoVisivel, tamanho, linha + 1, coluna, jogadasRestantes);  // Baixo
        floodFill(campo, campoVisivel, tamanho, linha, coluna - 1, jogadasRestantes);  // Esquerda
        floodFill(campo, campoVisivel, tamanho, linha, coluna + 1, jogadasRestantes);  // Direita
        floodFill(campo, campoVisivel, tamanho, linha - 1, coluna - 1, jogadasRestantes); // Cima-esquerda
        floodFill(campo, campoVisivel, tamanho, linha - 1, coluna + 1, jogadasRestantes); // Cima-direita
        floodFill(campo, campoVisivel, tamanho, linha + 1, coluna - 1, jogadasRestantes); // Baixo-esquerda
        floodFill(campo, campoVisivel, tamanho, linha + 1, coluna + 1, jogadasRestantes); // Baixo-direita
    }
}