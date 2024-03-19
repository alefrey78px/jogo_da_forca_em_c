#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


char palavra[20];
char dica[50];
char palavra_secreta[20];
char letra;
int chances = 7;
int tamanho_palavra;

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


void sorteia_palavra() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com uma semente diferente

    int numero = rand() % 10; // Gera um número aleatório entre 0 e 9

    struct PalavraDica pd = banco_palavras[numero];

    strcpy(palavra, pd.palavra);
    strcpy(dica, pd.dica);

    tamanho_palavra = strlen(palavra);

    for (int i = 0; i < tamanho_palavra; i++) {
        palavra_secreta[i] = '-';
    }

    palavra_secreta[tamanho_palavra] = '\0'; // Adiciona o caractere nulo de terminação
}


void pede_chute() {
    printf("\nChute uma letra: ");
    scanf(" %c", &letra);
}


void verifica_chute() {
    int letraEncontrada = 0;

    for (int i = 0; i < strlen(palavra); i++) {

        if (palavra[i] == letra) {
            palavra_secreta[i] = letra;
            letraEncontrada = 1;
        }

    }

    if (!letraEncontrada)
        chances = chances - 1;
}


bool venceu() {
    return strcmp(palavra, palavra_secreta) == 0;
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

    printf("\nA palavra e': %s", palavra_secreta);
    printf("\nA palavra tem %d letras", tamanho_palavra);
    printf("\nDica: %s", dica);
    printf("\nChances restantes: %d", chances);

}



// Inicio do programa principal.
void main() {

    sorteia_palavra();

    while (chances > 0) {

        exibe();

        pede_chute();

        verifica_chute();

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

