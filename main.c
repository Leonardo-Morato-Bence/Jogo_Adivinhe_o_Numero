#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("================================\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("================================\n\n");

    printf("O número secreto está entre 0 e 99\n\n");

    srand(time(0));

    int numeroSecreto = rand()%100;
    int chute;
    int tentativas = 1;
    int numeroDeTentativas;
    double pontos = 1000;

    int dificuldade;
    printf("Escolha o nível de dificuldade\n");
    printf("(1)Fácil (2)Médio (3)Difícil\n\n");
    printf("Dificuldade desejada: ");
    scanf("%d", &dificuldade);

    switch(dificuldade)
    {
        case 1:
            numeroDeTentativas = 20;
            break;

        case 2:
            numeroDeTentativas = 10;
            break;

        default:
            numeroDeTentativas = 5;
            break;

    }

    for(int i = 1; i <= numeroDeTentativas; i++)
    {
        printf("Tentativa %d de %d \n", tentativas, numeroDeTentativas);
        printf("------------\n");
        printf("Qual é o seu chute?\n");
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if(chute<0)
        {
            printf("Números negativos não são validos\n");
            continue;
        }

        if(chute == numeroSecreto)
        {
            printf("Você Acertou!!!\n");
            break;
        }
        else if(chute > numeroSecreto)
            {
                printf("Chute maior que o número secreto\n");
            }

        else
            {
                printf("Chute menor que o número secreto\n");
            }
        tentativas++;
        pontos -= abs(chute - numeroSecreto)/(double)2;

        printf("\n");
    }

    printf("\n");
    printf("************\n");
    printf("FIM DE JOGO!\n");
    printf("************\n");

    printf("\nVocê utilizou %d tentativas\n", tentativas-1);
    printf("Total de pontos: %.1f\n", pontos);

    if(chute == numeroSecreto)
        {
            printf("\n\n");

            printf("Parabéns por ganhar o jogo, aqui está a sua recompensa :)\n\n");

            printf("               *************************** \n");
            printf("               *         o888888,        * \n");
            printf("               *       o8888888888.      * \n");
            printf("               *      8'- -:8888b        * \n");
            printf("               *     8' 8888             * \n");
            printf("               *    d8.-=. ,==-.:888b    * \n");
            printf("               *    >8 `~` :`~' d8888    * \n");
            printf("               *    88,88888             * \n");
            printf("               *    88b. `-~ ':88888     * \n");
            printf("               *    888b ~==~ .:88888    * \n");
            printf("               *    88888o--:':::8888    * \n");
            printf("               *    `88888| :::' 8888b   * \n");
            printf("               *    8888^^' 8888b        * \n");
            printf("               *   d888,%888b.           * \n");
            printf("               *  d88% 8888--'-.         * \n");
            printf("               * /88:.__ , _--' --- -    * \n");
            printf("               *     '''::===..-' = --.  * \n");
            printf("               *************************** \n");
            printf("                        Mona Lisa          \n");
        }
    else
        {
            printf("VOCÊ PERDEU!\n");
        }

    scanf("%d");

    return 0;
}
