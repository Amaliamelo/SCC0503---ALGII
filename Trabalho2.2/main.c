#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


int main() {
    char input[100];
    printf("Entre com a entrada: ");
    fgets(input, 100, stdin);
    
    char id[10], titulo[50], autor[50];
    if (sscanf(input, "ADD id='%9[^']' titulo='%49[^']' autor='%49[^']'", id, titulo, autor) != 3) {
        printf("Entrada inválida!\n");
        return 1;
    }

    FILE *arquivo = fopen("livros.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "%s %s %s\n", id, titulo, autor);
    fclose(arquivo);

    printf("Entrada inserida com sucesso!\n");
    return 0;
}





