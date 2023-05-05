#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    FILE *arquivo = fopen("livros.txt", "r+");
    if (arquivo == NULL) {
        arquivo = fopen("livros.txt", "w+");
    }
    IndicePrimario indice_primario[MAX_LIVROS];
    IndiceSecundario indice_secundario[MAX_LIVROS];
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        indice_primario[i].id = -1;
        indice_primario[i].offset = -1;
        indice_secundario[i].offset = -1;
    }
    int num_livros = 0;
    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.id != -1) {
            indice_primario[num_livros].id = livro.id;
            indice_primario[num_livros].offset = ftell(arquivo) - sizeof(Livro);
            strcpy(indice_secundario[num_livros].autor, livro.autor);
            indice_secundario[num_livros].offset = indice_primario[num_livros].offset;
            num_livros++;
        }
    }
    int opcao;
    do {
        printf("\nOpções:\n");
        printf("1. Inserir um livro\n");
        printf("2. Buscar um livro por ID\n");
        printf("3. Remover um livro por ID\n");
        printf("4. Buscar livros por autor\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        //limpar_buffer();
        switch (opcao) {
            case 1:
                inserir_livro(arquivo, indice_primario, &num_livros);
                strcpy(indice_secundario[num_livros-1].autor, livro.autor);
                indice_secundario[num_livros-1].offset = indice_primario[num_livros-1].offset;
                break;
            case 2:
                buscar_livro(arquivo, indice_primario);
                break;
            case 3:
                remover_livro(arquivo, indice_primario, indice_secundario);
                break;
            case 4:
                buscar_livros_por_autor(arquivo, indice_secundario);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 5);
    
    fclose(arquivo);
    return 0;
}




