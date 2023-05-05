#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "biblioteca.h"

void inserir_livro(FILE *arquivo, IndicePrimario *indice_primario, int *num_livros) {
    Livro livro;
    printf("Digite o autor do livro: ");
    fgets(livro.autor, MAX_AUTOR, stdin);
    printf("Digite o título do livro: ");
    fgets(livro.titulo, MAX_TITULO, stdin);
    livro.id = *num_livros + 1;
    fwrite(&livro, sizeof(Livro), 1, arquivo);
    indice_primario[*num_livros].id = livro.id;
    indice_primario[*num_livros].offset = ftell(arquivo) - sizeof(Livro);
    (*num_livros)++;
}

void buscar_livro(FILE *arquivo, IndicePrimario *indice_primario) {
    int id;
    printf("Digite o id do livro: ");
    scanf("%d", &id);
    //limpar_buffer();
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (indice_primario[i].id == id) {
            Livro livro;
            fseek(arquivo, indice_primario[i].offset, SEEK_SET);
            fread(&livro, sizeof(Livro), 1, arquivo);
            printf("ID: %d, Autor: %s, Título: %s\n", livro.id, livro.autor, livro.titulo);
            return;
        }
    }
    printf("Livro não encontrado.\n");
}

void remover_livro(FILE *arquivo, IndicePrimario *indice_primario, IndiceSecundario *indice_secundario){
    int id;
    printf("Digite o id do livro a ser removido: ");
    scanf("%d", &id);
    //limpar_buffer();
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (indice_primario[i].id == id) {
            indice_primario[i].id = -1;
            int j;
            for (j = 0; j < MAX_LIVROS; j++) {
                if (indice_secundario[j].offset == indice_primario[i].offset) {
                    indice_secundario[j].offset = -1;
                    break;
                }
            }
            fseek(arquivo, indice_primario[i].offset, SEEK_SET);
            fputc('*', arquivo);
            printf("Livro removido com sucesso.\n");
            return;
        }
    }
    printf("Livro não encontrado.\n");
}
void buscar_livros_por_autor(FILE *arquivo, IndiceSecundario *indice_secundario) {
    char autor[MAX_AUTOR];
    printf("Digite o nome do autor: ");
    fgets(autor, MAX_AUTOR, stdin);
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (indice_secundario[i].offset != -1 && strcmp(autor, indice_secundario[i].autor) == 0) {
            Livro livro;
            fseek(arquivo, indice_secundario[i].offset, SEEK_SET);
            fread(&livro, sizeof(Livro), 1, arquivo);
            printf("ID: %d, Autor: %s, Título: %s\n", livro.id, livro.autor, livro.titulo);
        }
    }
}