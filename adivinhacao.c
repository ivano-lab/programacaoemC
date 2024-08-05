#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TENT 3

int main() {
    printf("************************************\n");
    printf("* Bem-Vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");
    
    int nivel;
    
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int totaldetentativas;
    if(nivel == 1) {
        totaldetentativas = 20;
    } else if (nivel == 2) {
        totaldetentativas = 15;
    } else {
        totaldetentativas = 6;
    }
    
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;    
    double pontos = 1000;
    int chute;
    int acertou = 0;
    
    for(int i = 1; i <= totaldetentativas; i++) {
        printf("Qual é o seu %dº chute? ", i);
        scanf("%d", &chute);
        if (chute < 0) {
            printf("Não são permitidos números negativos!\n");
            i--;
            continue;
        }
        printf("Seu chute foi %d\n", chute);

        if(chute == numerosecreto) {
            printf("Parabéns! Você acertou!\n");
            acertou = 1;
            break;
        } else {
            printf("Você errou!\n");
            if (chute > numerosecreto) {
                printf("Seu chute foi maior do que o número secreto\n");
            } else {
                printf("Seu chute foi menor do que o número secreto\n");
            }
            
            double pontosperdidos = (double)abs(chute - numerosecreto) / 2.0;
            pontos -= pontosperdidos;
        }    
    }
    
    if (acertou) {
        printf("Parabéns! Você acertou!\n");
    } else {
        printf("Você perdeu! O número secreto era %d. Tente novamente!\n", numerosecreto);
    }
    printf("Você fez %.2f pontos\n", pontos);
    printf("Fim de jogo!\n");

    return 0;
}
