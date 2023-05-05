#define MAX_AUTOR 50
#define MAX_TITULO 100
#define MAX_LIVROS 1000

typedef struct {
    int id;
    char autor[MAX_AUTOR];
    char titulo[MAX_TITULO];
} Livro;

typedef struct {
    int id;
    int offset;
} IndicePrimario;

typedef struct {
    char autor[MAX_AUTOR];
    int offset;
} IndiceSecundario;

/*void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}*/

void inserir_livro(FILE *arquivo, IndicePrimario *indice_primario, int *num_livros);
void buscar_livro(FILE *arquivo, IndicePrimario *indice_primario);
void remover_livro(FILE *arquivo, IndicePrimario *indice_primario, IndiceSecundario *indice_secundario);
void buscar_livros_por_autor(FILE *arquivo, IndiceSecundario *indice_secundario);