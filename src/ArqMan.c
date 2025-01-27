#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Header.h"
#include "VGlobais.h"

#define MAX_JOGADORES 10
#define TAM_NOME 30

void exibirNomeJogador(char nome[])
{
    telaXY(48, 3);
    printf("PLAYER: %s", nome);
}

void exibirScoreJogador(int score)
{
    telaXY(2, 10);
    printf("Ultima pontuacao: %d", score);
}

void gravarJogadorBinario(Player jogador)
{
    FILE *arq = fopen("arq//Arquivo.dat", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Grava o jogador como um único registro
    fwrite(&jogador, sizeof(Player), 1, arq);

    fclose(arq);
}

void lerUltimoNomeArquivoBinario()
{
    FILE *arq = fopen("arq//Arquivo.dat", "rb");
    if (arq == NULL)
    {
        printf("Ocorreu um problema ao abrir o arquivo\n");
    }

    Player jogador;
    fseek(arq, -sizeof(Player), SEEK_END); // Move o cursor para o último registro
    fread(&jogador, sizeof(Player), 1, arq); // Lê o último registro
    exibirNomeJogador(jogador.nome);// Exibe o nome e o score do jogador na tela
    fclose(arq);
}

Player buscaNomeArquivoBinario() {
    FILE *arq = fopen("arq//arquivo.dat", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    Player jogador;
    fseek(arq, -sizeof(Player), SEEK_END); // Posiciona o cursor no final do arquivo
    fread(&jogador, sizeof(Player), 1, arq); // Lê o último registro do arquivo
    fclose(arq);
    return jogador;
}

void chamaScore(int score){
    Player jogador = buscaNomeArquivoBinario();
    gravarScoreJogadorArquivoBinario(jogador.nome, score);
}

void gravarScoreJogadorArquivoBinario(const char *nomeJogador, int novoScore) {
    FILE *arq = fopen("arq//arquivo.dat", "r+b"); // Abre o arquivo para leitura e escrita binária

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Player jogador;

    while (fread(&jogador, sizeof(jogador), 1, arq) == 1) {
        if (strcmp(jogador.nome, nomeJogador) == 0) {
            // Atualiza o score do jogador
            jogador.score = novoScore;
            // Move o cursor para a posição correta para escrever o novo score
            fseek(arq, -sizeof(jogador), SEEK_CUR);
            // Escreve o novo score no arquivo
            fwrite(&jogador, sizeof(jogador), 1, arq);
            break; // Sai do loop após atualizar o score
        }
    }

    fclose(arq);
}

void exibirRanking() {
    FILE *arq = fopen("arq//Arquivo.dat", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Array de jogadores no ranking
    Player ranking[MAX_JOGADORES];
    for (int i = 0; i < MAX_JOGADORES; i++) {
        ranking[i].score = -1; // Inicializa os scores como -1 para indicar valores inválidos
    }


    Player jogador;
    int linha = 0; // Índice para percorrer o ranking

    // Inicializa o menor score como o maior valor possível para que qualquer score seja menor
    int menorScore = 0;

    // Lê os jogadores do arquivo e encontra os maiores scores
    while (fread(&jogador, sizeof(jogador), 1, arq) == 1 && linha < MAX_JOGADORES) {
        if (jogador.score >= 0) { // Verifica se o score do jogador é válido
            if (jogador.score < menorScore) {
                menorScore = jogador.score; // Atualiza o menor score atual no ranking
            }
            // Insere o jogador no ranking
            ranking[linha] = jogador;
            linha++;
        }
    }

    // Retorna o cursor para o início do arquivo
    fseek(arq, 0, SEEK_SET);

    // Lê novamente os jogadores do arquivo e atualiza o ranking com os jogadores válidos e com os maiores scores
    linha = 0; // Reinicializa o índice para percorrer o ranking
    while (fread(&jogador, sizeof(jogador), 1, arq) == 1 && linha < MAX_JOGADORES) {
        if (jogador.score >= 0 && jogador.score > menorScore) { // Verifica se o score do jogador é válido e maior que o menor score atual no ranking
            ranking[linha] = jogador;
            linha++;
        }
    }

    fclose(arq);

    // Ordena o ranking por score (bubble sort)
    for (int i = 0; i < MAX_JOGADORES - 1; i++) {
        for (int j = 0; j < MAX_JOGADORES - i - 1; j++) {
            if (ranking[j].score < ranking[j + 1].score) {
                Player temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }

    // Exibe o ranking na tela
    telaXY(6, 5);
        printf("Ranking:\n");
    telaXY(65, 5);
        printf("Score:\n");

    for (int i = 0; i < MAX_JOGADORES; i++) {
        telaXY(6, 7 + i);
        if (ranking[i].score >= 0) { // Verifica se o jogador é válido
            printf("%d. %-*s", i + 1, TAM_NOME, ranking[i].nome);
            telaXY(70, 7 + i);
            printf("%d\n", ranking[i].score); // Exibe o score ao lado do nome
        }
    }

    getch();
}

void ranking()
{
    limpaTela();
    exibirRanking();
}

// Função para obter os dados do usuário
void dadosUser()
{
    Player jogador;
    printf("Digite o nome do Player: ");
    fflush(stdin);// Limpa o buffer de entrada para remover caracteres indesejados
    fgets(jogador.nome, sizeof(jogador.nome), stdin); 
    jogador.score = 0;
    gravarJogadorBinario(jogador);

}

void creditos() {
    system("cls");
    FILE *arq = fopen("arq//Creditos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de créditos.\n");
        return;
    }
    char c;
    while ((c = fgetc(arq)) != EOF)
    {
        printf("%c", c);
    }
    fclose(arq);
    getch();
}

//Fim do código