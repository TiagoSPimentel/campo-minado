## Jogo Campo Minado:

Este projeto é uma implementação do clássico jogo Campo Minado, onde o jogador deve revelar células de um tabuleiro sem cair em minas escondidas. O jogo é jogado em um tabuleiro de dimensões definidas pelo usuário, com um número aleatório de minas espalhadas. O jogador deve escolher as células de forma estratégica, evitando as minas e revelando o maior número possível de células.



## Funcionalidades:

- Tabuleiro personalizável: O tamanho do tabuleiro e o número de minas podem ser ajustados.
- Mecânica de Flood Fill: Quando o jogador revela uma célula com 0 minas vizinhas, as células vizinhas são automaticamente reveladas.
- Exibição de tabuleiro: O estado atual do tabuleiro pode ser visualizado a qualquer momento.
- Registro de jogadas: Cada jogada é registrada em um arquivo de log, permitindo acompanhamento do progresso do jogo.
- Posicionamento aleatório de minas: As minas são distribuídas aleatoriamente no tabuleiro.


## Estrutura do Projeto:

Arquivos:

- matriz.c / matriz.h: Contém as funções responsáveis pela alocação e manipulação do tabuleiro e das minas.
- log.c / log.h: Responsável pela criação e manipulação de arquivos de log, onde são registradas as jogadas realizadas e o horário de início do jogo.
- main.c: Arquivo principal que inicializa o jogo, interage com o jogador e chama as funções do jogo.


## Compilação:

Para compilar o código, use o seguinte comando:
  ```bash
  gcc main.c matriz.c log.c -o campo_minado
  ```

Para rodar o jogo:
  ```bash
  ./campo_minado
```

## Funções principais:

- alocarMatriz: Aloca memória para o tabuleiro do jogo.
- liberarMatriz: Libera a memória alocada para o tabuleiro.
- inicializarTabuleiro: Inicializa o tabuleiro com um valor específico.
- imprimirTabuleiro: Exibe o estado atual do tabuleiro.
- posicionarMinas: Posiciona as minas aleatoriamente no tabuleiro.
- contarMinasVizinhas: Conta o número de minas vizinhas a uma célula específica.
- floodFill: Revela células adjacentes recursivamente quando uma célula sem minas vizinhas é aberta.
- criarLog: Cria o arquivo de log e registra o horário de início do jogo.
- escreverLog: Escreve mensagens no arquivo de log.
- registrarCoordenadaNoLog: Registra cada jogada realizada no log.


## Tecnologias Utilizadas:

- linguagem: C
- Estruturas de Dados: Matrizes e Estruturas Personalizadas

## Como Jogar:

1.Compile o código utilizando um compilador C.
2.Execute o programa.
3.O jogo exibirá um tabuleiro vazio e você deverá escolher coordenadas para revelar.
4.Evite as minas! Se uma mina for revelada, o jogo termina.
5.Se todas as células livres forem reveladas sem detonar minas, você ganha.


