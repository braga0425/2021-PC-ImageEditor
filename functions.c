#include "functions.h"

//void functions

void filtroNegativo(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col) {
    int i, j = 0;
    (void *) imagemaux;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            imagem[i][j].r = 255 - imagem[i][j].r;
            imagem[i][j].g = 255 - imagem[i][j].g;
            imagem[i][j].b = 255 - imagem[i][j].b;
        }
    }
}

void filtroCinza(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col) {
    int i, j, valor;
    (void *) imagemaux;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            valor = 0.2989 * imagem[i][j].r + 0.5870 * imagem[i][j].g + 0.1140 * imagem[i][j].b;
            imagem[i][j].r = valor;
            imagem[i][j].g = valor;
            imagem[i][j].b = valor;
        }
    }
}

void filtroRelevo(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col) {
    int i, j;

    for (i = 1; i < lin - 1; i++) {
        for (j = 0; j < col; j++) {
            imagemaux[i][j].r = imagem[i + 1][j].r - imagem[i - 1][j].r;
            imagemaux[i][j].g = imagem[i + 1][j].b - imagem[i - 1][j].b;
            imagemaux[i][j].b = imagem[i + 1][j].b - imagem[i - 1][j].b;

            if (imagemaux[i][j].r < 0 || imagemaux[i][j].g < 0 || imagemaux[i][j].b < 0) {
                imagemaux[i][j].r = 0;
                imagemaux[i][j].g = 0;
                imagemaux[i][j].b = 0;
            }
        }
    }
    for (i = 1; i < lin - 1; i++) {
        for (j = 0; j < col; j++) {
            imagem[i][j].r = imagemaux[i][j].r + 128;
            imagem[i][j].g = imagemaux[i][j].g + 128;
            imagem[i][j].b = imagemaux[i][j].b + 128;

            if (imagemaux[i][j].r > 255 || imagemaux[i][j].g > 255 || imagemaux[i][j].b > 255) {
                imagemaux[i][j].r = 255;
                imagemaux[i][j].g = 255;
                imagemaux[i][j].b = 255;
            }
        }
    }
}

void filtroEspelhado(FILE *arquivo, pixel **imagem, pixel **imagemaux, int lin, int col) {
    int i, j;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            imagemaux[i][j].r = imagem[i][col - j].r;
            imagemaux[i][j].g = imagem[i][col - j].g;
            imagemaux[i][j].b = imagem[i][col - j].b;
        }
    }
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            imagem[i][j].r = imagemaux[i][j].r;
            imagem[i][j].g = imagemaux[i][j].g;
            imagem[i][j].b = imagemaux[i][j].b;
        }
    }
}

// linked list

nodo *inicializaLista() {
    nodo *lista = (nodo *) malloc(sizeof(nodo));
    lista->proximoNodo = NULL;

    return lista;
}

void insereItem(func filtro, nodo *cabessa) {
    if (cabessa->proximoNodo == NULL) {
        cabessa->filtro = filtro;
        cabessa->proximoNodo = (nodo *) malloc(sizeof(nodo));
        cabessa->proximoNodo->proximoNodo = NULL;
    } else {
        insereItem(filtro, cabessa->proximoNodo);
    }
}

nodo *pegaItem(int n, nodo *cabessa) {
    if (n == 0) {
        return cabessa;
    } else {
        if (cabessa->proximoNodo != NULL)
            return pegaItem(n - 1, cabessa->proximoNodo);
        return NULL;
    }
}