#include<stdio.h>
#include<stdlib.h>
#include "biblioteca.h"

int main() {
    int n, m;
    char s[9] = "save";

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        Livro* livro = (Livro*) malloc(sizeof(Livro));
        scanf("%d", &livro->id);
        scanf("  %[^\n\r]", livro->titulo); // é um tipo Registro que contem um TipoChave Chave sendo TipoChave um int.
        scanf("  %[^\n\r]", livro->autor);
        salvaLivro(livro, s);
        free(livro);
    }

    scanf("%d", &m);

    int pula = n - m;    // quantas posições pular para ler os ultimos registros

    Livro lista[n];
    lerbiblioteca(lista, s, n);

    //Mostrar biblioteca
    for(int i = pula; i < n; i++) {
        printf("Id: %d\n", lista[i].id);
        printf("Titulo: %s\n", lista[i].titulo);
        printf("Autor: %s\n", lista[i].autor);
        printf("Byte offset: %ld\n", lista[i].byteOffset);
        if(i!=(n-1)){
            printf("\n");
        }
    }
    return 0;
}