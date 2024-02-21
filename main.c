#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


char palavra[20];
char dica[50];
char palavraSecreta[20];
char letra;
int chances = 7;
int tamanhoPalavra;

struct PalavraDica {
    char palavra[20];
    char dica[50];
};


struct PalavraDica banco_palavras[] = {
        {"abacaxi",    "fruta tropical"},
        {"pera",       "fruta comum"},
        {"morango",    "fruta vermelha"},
        {"casa",       "lugar onde se mora"},
        {"escola",     "local de estudo"},
        {"caderno",    "item de papelaria"},
        {"lapis",      "ferramenta de escrita"},
        {"giz",        "usado para escrever no quadro"},
        {"aula",       "período de instrução"},
        {"professora", "ensina na escola"}
};


void sorteiaPalavra() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com uma semente diferente

    int numero = rand() % 10; // Gera um número aleatório entre 0 e 9

    struct PalavraDica pd = banco_palavras[numero];

    strcpy(palavra, pd.palavra);
    strcpy(dica, pd.dica);

    tamanhoPalavra = strlen(palavra);

    for (int i = 0; i < tamanhoPalavra; i++) {
        palavraSecreta[i] = '-';
    }

    palavraSecreta[tamanhoPalavra] = '\0'; // Adiciona o caractere nulo de terminação
}


void pedeChute() {
    printf("\nChute uma letra: ");
    scanf(" %c", &letra);
}


void verificaChute() {
    int letraEncontrada = 0;

    for (int i = 0; i < strlen(palavra); i++) {

        if (palavra[i] == letra) {
            palavraSecreta[i] = letra;
            letraEncontrada = 1;
        }

    }

    if (!letraEncontrada)
        chances = chances - 1;
}


bool venceu() {
    return strcmp(palavra, palavraSecreta) == 0;
}


void exibe() {
    printf("\nJogo Da Forca\n");
    printf("\n|==========|\n"
           "|          +  \n");

    if (chances == 6) {
        printf("|        (```) \n"
               "|             \n"
               "|             \n"
               "|             \n"
               "|               \n");
    }
    if (chances == 5) {
        printf("|        (```) \n"
               "|          |  \n"
               "|             \n"
               "|             \n"
               "|               \n");
    }
    if (chances == 4) {
        printf("|        (```) \n"
               "|          |  \n"
               "|         /   \n"
               "|             \n"
               "|               \n");
    }
    if (chances == 3) {
        printf("|        (```) \n"
               "|          |  \n"
               "|         / \\ \n"
               "|             \n"
               "|               \n");
    }
    if (chances == 2) {
        printf("|        (```) \n"
               "|          |  \n"
               "|         / \\ \n"
               "|          |  \n"
               "|               \n");
    }
    if (chances == 1) {
        printf("|        (```) \n"
               "|          |  \n"
               "|         / \\ \n"
               "|          |  \n"
               "|         /     \n");
    }
    if (chances == 0) {
        printf("|        (```) \n"
               "|          |  \n"
               "|         / \\ \n"
               "|          |  \n"
               "|         / \\  \n");
    }

    printf("|\n"
           "|________________________\n");

    printf("\nA palavra e': %s", palavraSecreta);
    printf("\nA palavra tem %d letras", tamanhoPalavra);
    printf("\nDica: %s", dica);
    printf("\nChances restantes: %d", chances);

}


void main() {

    sorteiaPalavra();

    while (chances > 0) {

        exibe();

        pedeChute();

        verificaChute();

        if (venceu()) {
            exibe();
            printf("\nParabens! Voce acertou a palavra secreta!\n");
            break;
        }

        if (chances == 0) {
            exibe();
            printf("\nPerdeu!, a palavra era: %s\n", palavra);
        }

    }

}
