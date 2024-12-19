#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>

// Definição do TAD Log
typedef struct {
    FILE *arquivo;  // Ponteiro para o arquivo de log
} Log;

// Funções para manipulação do log
Log *criarLog(const char *nomeArquivo);  // Cria o log e inicializa o arquivo
void fecharLog(Log *log);  // Fecha o log e libera recursos
void escreverLog(Log *log, const char *mensagem);  // Escreve uma mensagem no log

void registrarCoordenadaNoLog(Log *log, int linha, int coluna);  // Registra uma coordenada jogada

#endif // LOG_H
