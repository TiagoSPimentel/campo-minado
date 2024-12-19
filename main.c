#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "matriz.h"  // Supondo que a manipulação da matriz está aqui
#include <time.h>

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

int main() {
    int tamanho, numMinas, nivel, linha, coluna, jogadasRestantes;
    char **campo, **campoVisivel;

    // Cria o log
    Log *log = criarLog("log.txt");

    printf("\n\n--------------------- CAMPO MINADO <3 ---------------------\n");
    printf("Qual Nivel de dificuldade? \n(1) facil, (2) medio, (3) dificil: ");
    scanf("%d", &nivel);

    // Define o tamanho do tabuleiro e o número de minas com base no nível escolhido
    if (nivel == FACIL) {
        tamanho = 10;
        numMinas = tamanho * tamanho * 0.15;
    } else if (nivel == MEDIO) {
        tamanho = 20;
        numMinas = tamanho * tamanho * 0.15;
    } else if (nivel == DIFICIL) {
        tamanho = 30;
        numMinas = tamanho * tamanho * 0.15;
    } else {
        printf("Nivel invalido!\n");
        return 1;
    }

    // Aloca dinamicamente as matrizes para o campo e o campo visível
    campo = alocarMatriz(tamanho);
    campoVisivel = alocarMatriz(tamanho);

    // Inicializa o tabuleiro
    inicializarTabuleiro(campo, tamanho, '0');
    inicializarTabuleiro(campoVisivel, tamanho, 'x');

    // Posiciona as minas aleatoriamente
    posicionarMinas(campo, tamanho, numMinas);

    jogadasRestantes = (tamanho * tamanho) - numMinas;

    
    
    // Loop: continua até que o jogador perca ou ganhe
    while (jogadasRestantes > 0) {
        imprimirTabuleiro(campoVisivel, tamanho);  // Mostra a matriz visível no terminal
        printf("\nQuais coordenadas (x,y)?(0-%d): ", tamanho - 1);
        scanf("%d %d", &linha, &coluna);  // Lê as coordenadas

        // Verifica se a coordenada é válida
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho) {
            printf("Coordenada invalida! Tente novamente.\n");
            continue;  // Pede uma nova jogada
        }

        // Registra a jogada no log
        registrarCoordenadaNoLog(log, linha, coluna);

        // Verifica se o jogador atingiu uma mina
        if (campo[linha][coluna] == '*') {
            printf("\nBoooomm! GAME OVER!\n");
            imprimirTabuleiro(campo, tamanho);  // Mostra a matriz completa com as minas
            break;
        } else if (campo[linha][coluna] == '0') {
            floodFill(campo, campoVisivel, tamanho, linha, coluna, &jogadasRestantes);
        } else {
            // Conta o número de minas vizinhas e atualiza o campo visível
            int minasVizinhas = contarMinasVizinhas(campo, tamanho, linha, coluna);
            campoVisivel[linha][coluna] = minasVizinhas + '0';
            jogadasRestantes--;  // Decrementa o número de jogadas restantes
        }

    }

    // Verifica se o jogador venceu
    if (jogadasRestantes == 0) {
        printf("\nParabens, voce e fera!\n");
        imprimirTabuleiro(campo, tamanho);  // Mostra o campo completo
    }

    // Fecha o log
    fecharLog(log);

    // Libera a memória alocada dinamicamente para os tabuleiros
    liberarMatriz(campo, tamanho);
    liberarMatriz(campoVisivel, tamanho);

    return 0;
}
