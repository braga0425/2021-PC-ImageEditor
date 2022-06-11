#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    int r, g, b;
} pixel;

typedef void (*func)(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col);

// linked list

typedef struct nodo {
    func filtro;
    struct nodo *proximoNodo;
} nodo;

nodo *inicializaLista();

void insereItem(func filtro, nodo *cabessa);

nodo *pegaItem(int n, nodo *cabessa);


// void functions

void filtroNegativo(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col);

void filtroCinza(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col);

void filtroRelevo(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col);

void filtroEspelhado(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col);