#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#define TAM 100

typedef struct Livro{
    int id;
    char titulo[TAM];
    char autor[TAM];
    long int byte_offset;
} Livro;

void salvaLivro( Livro* livro, char *arquivo);
void lerbiblioteca(Livro* lista, char *arquivo, int m);

#endif