#ifndef MATRIZ_H
#define MATRIZ_H

// Função que cria a matriz do campo minado, conforme a dimensão

char **alocarMatriz(int tamanho);
// Função que libera a memória da matriz do campo minado.
void liberarMatriz(char **matriz, int tamanho);

// Função que inicializa as minas na matriz.
void inicializarTabuleiro(char **campo, int tamanho, char valor);

// Função para exibir a matriz do campo minado na tela.
void imprimirTabuleiro(char **campo, int tamanho);

// Função para verificar se a posição escolhida é uma mina.
void posicionarMinas(char **campo, int tamanho, int numMinas);

// Função para contar o número de minas ao redor de uma posição.
int contarMinasVizinhas(char **campo, int tamanho, int linha, int coluna);

void floodFill(char **campo, char **campoVisivel, int tamanho, int linha, int coluna, int *jogadasRestantes);


#endif // MATRIZ_H
