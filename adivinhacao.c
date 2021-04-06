#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 5

int main() {

    printf ("*************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("**************************************\n");

    int numerosecreto = 42;
    /* int idade = 25;
    int tamanhodocalcado;
    tamanhodocalcado = 39; 

    printf("O número %d é o secreto. Não conte para ninguém!\n", numerosecreto); */

/*     int qtdtentativas = 5; */

    int chute;

    for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {

        printf("Tentativa %d de %d\n", i, NUMERO_DE_TENTATIVAS);
        printf("Qual é o seu chute? ");
        
        scanf("%d", &chute);
        printf("Seu chute foi %d\n\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            i--;

            continue;
        }

        /* printf("%d %d\n", numerosecreto, chute); */
        
        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;
        int menor = chute < numerosecreto;

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
    }

    printf("Fim de jogo!");    
}
