#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf ("*************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("**************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    double pontos = 1000;
    int tentativas = 1;
    int qtdtentativas;
    int acertou = 0;
    int chute;
    int nivel;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil   (2) Médio   (3) Difícil\n\n");
    printf("Escolha:    ");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1:
            qtdtentativas = 20;
            break;
        case 2:
            qtdtentativas = 15;
            break;
        default:
            qtdtentativas = 6;
            break;    
    }
    
    /*  if (nivel == 1) {
            qtdtentativas = 20;
        }
        else if (nivel == 2) {
            qtdtentativas = 15;
        }
        else {
            qtdtentativas = 6;
        } */

    for(int i = 1; i <= qtdtentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Você é um bom adivinha!\n\n");
            break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o número secreto!\n\n");
        } 
        else {
            printf("Seu chute foi menor que o número secreto!\n\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de jogo!");

    if(acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente novamente\n\n");
    }
}