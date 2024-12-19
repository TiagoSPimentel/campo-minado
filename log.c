#include "log.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Função para criar o arquivo de log e inicializar o TAD Log
Log *criarLog(const char *nomeArquivo) {
    Log *log = (Log *)malloc(sizeof(Log));  // Aloca memória para o TAD Log
    if (log == NULL) {
        printf("Erro ao alocar memória para o log!\n");
        exit(1);
    }

    // Abre o arquivo de log em modo de escrita (cria ou sobrescreve)
    log->arquivo = fopen(nomeArquivo, "w");
    if (log->arquivo == NULL) {
        printf("Erro ao criar o arquivo de log!\n");
        free(log);
        exit(1);
    }

    // Registra a data e hora de início do jogo
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(log->arquivo, "Jogo iniciado em: %d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    return log;
}

// Função para fechar o arquivo de log e liberar recursos
void fecharLog(Log *log) {
    if (log != NULL) {
        if (log->arquivo != NULL) {
            fclose(log->arquivo);  // Fecha o arquivo
        }
        free(log);  // Libera a memória alocada para o TAD
    }
}

// Função para escrever uma mensagem no arquivo de log
void escreverLog(Log *log, const char *mensagem) {
    if (log != NULL && log->arquivo != NULL) {
        fprintf(log->arquivo, "%s\n", mensagem);  // Escreve a mensagem no arquivo de log
        fflush(log->arquivo);  // Garante que a escrita seja realizada imediatamente
    }
}

// Função para registrar a coordenada jogada pelo jogador no log
void registrarCoordenadaNoLog(Log *log, int linha, int coluna) {
    if (log != NULL && log->arquivo != NULL) {
        fprintf(log->arquivo, "Jogada na coordenada: (%d, %d)\n", linha, coluna);
    }
}
