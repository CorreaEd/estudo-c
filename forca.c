#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("*************************\n");
    printf("*     Jogo de Forca     *\n");
    printf("*************************\n\n");
}
void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    (chutesdados)++;
}
void desenhaforca() { 

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
        (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
        (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), 
        (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        int achou = jachutou(palavrasecreta[i]);

        if(achou) {
                printf("%c ", palavrasecreta[i]);
        } else {
                printf("_ ");
        }            
    }
    printf("\n");
}
void adicionapalavra() {

    char quer;
    
    printf("Voce deseja adicionar uma nova palabra no jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;

        f= fopen("palavras.txt", "r+");
        if(f == 0) {
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}
void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }
    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int randomico = rand() % qtdpalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }
    fclose(f);
}
int acertou() {
    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;    
}
int chuteserrados() {
        int erros = 0;
    
    for(int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {

                existe = 1;
                break;
            }    
        }
                
        if(!existe) erros++;

    }
    return erros;
}
int enforcou() {

    return chuteserrados() >= 5;
}
int jachutou(char letra) {
    int achou = 0;

    for(int j = 0; j < chutesdados; j++) {
       if(chutes[j] == letra) {
            achou = 1;
            break;
        }              
    }

    return achou;
}
int main() {
    escolhepalavra();
    abertura();

    do {
        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
    if(acertou()) {
        printf("__________________,__,_________________________\n");
        printf("_________________/ \\/ \\,'| ____________________\n");
        printf("________________,'    '  ,' |,|________________\n");
        printf("_______________,'           ' |,'|_____________\n");
        printf("______________,'                 ;'| __________\n");
        printf("_____________,'                    '' |________\n");
        printf("____________,'                        ;-,______\n");
        printf("___________(___                        /_______\n");
        printf("_________,'    `.  ___               ,'________\n");
        printf("________:       ,`'   `-.           /__________\n");
        printf("________|-._ o /         \\         /___________\n");
        printf("_______(    `-(           )       /____________\n");
        printf("______,'`.     \\      o  /      ,'_____________\n");
        printf("_____/    `     `.      ,'     /_______________\n");
        printf("____(             `````       /________________\n");
        printf("_____`._                     /_________________\n");
        printf("________`--.______        ''`._________________\n");
        printf("___________\\__,__,`---._   '`;_________________\n");
        printf("________________))`-^--')`,-'__________________\n");
        printf("______________,',_____,'  |____________________\n");
        printf("______________\\_          `).__________________\n");
        printf("________________`.      _,'  `_________________\n");
        printf("________________/`-._,-'      \\________________\n");
        printf("\nParabéns, você ganhou!\n\n");
    } else {
        printf("_________________________________________\n");
        printf("_______________,.-------.,_______________\n");
        printf("__________,;~'             '~;,__________\n");
        printf("________,;                     ;,________\n");
        printf("_______;                         ;_______\n");
        printf("______,'                         ',______\n");
        printf("_____,;                           ;,_____\n");
        printf("_____; ;      .           .      ; ;_____\n");
        printf("_____| ;   ______       ______   ; |_____\n");
        printf("_____|  `/~''   ~'' . ''~     ''~\\'|_____\n");
        printf("_____|  ~  ,-~~~^~, | ,~^~~~-,  ~  |_____\n");
        printf("______|   |        }:{        |   |______\n");
        printf("______|   l       / | \\       !   |______\n");
        printf("______.~  (__,.--' .^. '--.,__)  ~.______\n");
        printf("______|     ---;' / | \\ `;---     |______\n");
        printf("_______\\__.       \\/^\\/       .__/_______\n");
        printf("________V| \\                 / |V________\n");
        printf("_________| |T~\\___!___!___/~T| |_________\n");
        printf("_________| |`IIII_I_I_I_IIII'| |_________\n");
        printf("_________|  \\,III I I I III,/  |_________\n");
        printf("__________\\   `~~~~~~~~~~'    /__________\n");
        printf("____________\\   .       .   /____________\n");
        printf("______________\\.    ^    ./______________\n");
        printf("________________^~~~^~~~^________________\n");
        printf("_________________________________________\n");
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era ***%s***\n\n", palavrasecreta);        
    }
adicionapalavra();
}