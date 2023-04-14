#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "biblioteca.h"

void salvaLivro( Livro* livro, char* arquivo){
    FILE* arq = fopen(arquivo, "ab"); //o caracter "b" indica que o arquivo deve ser aberto em modo binário
    if(arq == NULL){
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }

    //escrevendo os campos no arquivo
    
    //id
    fwrite(&(livro->id), sizeof(int), 1, arq);

    //titulo
    fwrite(livro->titulo, sizeof(char), strlen(livro->titulo), arq);
    fwrite("|", sizeof(char), 1, arq);

    //length autor
    int autor_len = strlen(livro->autor);
    fwrite(&autor_len, sizeof(int), 1, arq);

    //autor
    fwrite(livro->autor, sizeof(char), strlen(livro->autor), arq);

    //fim do registro
    fwrite("#", sizeof(char), 1, arq);

    fclose(arq);
}

void lerbiblioteca( Livro* lista, char* arquivo, int n){
    FILE* arq = fopen(arquivo, "rb"); //leitura no modo binário
    if(arq == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    //calculando o tamnaho do aruqivo 
    fseek(arq, 0, SEEK_END); 
        //Reposiciona o ponteiro, nesse caso, no final do arquivo (FILE * fluxo, int deslocamento, int origem);.
    long size = ftell(arq);
         // Retorna a posição do ponteiro.
    rewind(arq); 
        //Reposicionando o ponteiro para o início do arquivo.

    //Lendo todos os registros
    int i = 0;
    while(ftell(arq) < size && i<n){
        
        fread(&(lista[i].id), sizeof(int), 1, arq); 
            // ID;
            //fread(void * dados, size_t tamanho, size_t numero_itens, FILE * fluxo);
        
        int j=0;
        char c = fgetc(arq); 
            //Lê o caractere presente na posição atual do fluxo interno. Após a leitura, a posição atual é avançada para o próximo caractere.
        while (c!='|'){
            lista[i].titulo[j] = c;
            j++;
            c = fgetc(arq);    
        }
        // Titulo

        lista[i].titulo[j] = '\0'; 
            //avançando mais um caracter para pular o delimitador "|" na proxima leitura
        
        int autor_tamanho;
        fread(&autor_tamanho, sizeof(int), 1, arq);
        fread(lista[i].autor, sizeof(char), autor_tamanho, arq);
        // Autor

        c = fgetc(arq);
        // avançar mais um caractere para ignorar o delimitador "#"

        //incrementando o contador
        i++;
        
    }

    fclose(arq);

}
