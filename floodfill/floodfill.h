#ifndef FLOODFILL_H
#define FLOODFILL_H

#ifndef LINAHS_IMAGEM
#define LINHAS_IMAGEM 20
#define COLUNAS_IMAGEM 20
#endif

char** ler_imagem(FILE*, int*, int*);
void floodfill(char**, int, int);
void imprimir_imagem(char **);

#endif
