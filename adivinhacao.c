#include <stdio.h>

int main() {

    printf ("*************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("**************************************\n");

    int numerosecreto = 42;

    int chute;
   
    int tentativas = 1;
   
    int pontos = 1000;

    while(1) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");

            continue;
        }
        
        int acertou = (chute == numerosecreto);
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

        int pontosperdidos = (chute - numerosecreto) / 2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!");
    printf("Você acertou em %d tentativas!\n", tentativas);
    printf("Total de pontos: %d\n", pontos);
}
