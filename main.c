#include "functions.h"


int main(int argc, char **argv) {

    pixel **imagem;
    pixel **imagemaux;

    nodo *lista = inicializaLista();

    printf("****************************************\n");
    printf("**** Bem-vindo ao Editor de Imagens ****\n");
    printf("****************************************\n\n");

    char nome_arq[50], code[3], saida[50];
    int lin, col, max, opc;
    int i, j;
    FILE *arquivo;

    begin:

    printf("\nDigite o nome do arquivo que deseja aplicar o filtro (com a extensão do arquivo): ");
    scanf("%s", nome_arq);

    if ((arquivo = fopen(nome_arq, "r")) == NULL) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        exit(1);
    }

    fscanf(arquivo, "%s", code);
    fscanf(arquivo, "%d", &col);
    fscanf(arquivo, "%d", &lin);
    fscanf(arquivo, "%d", &max); 

    imagem = malloc(lin * sizeof(*imagem));
    for (i = 0; i < lin; i++) {
        imagem[i] = malloc(col * sizeof(*imagem[i]));
    }

    imagemaux = malloc(lin * sizeof(*imagemaux));
    for (i = 0; i < lin; i++) {
        imagemaux[i] = malloc(col * sizeof(*imagemaux[i]));
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            fscanf(arquivo, "%d%d%d", &imagem[i][j].r, &imagem[i][j].g, &imagem[i][j].b);
        }
    }
    fclose(arquivo);

    printf("\nDigite o nome de saída (sem a extensão): ");
    scanf("%s", saida);

    strcat(saida, ".ppm");

    arquivo = fopen(saida, "w");

    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d %d\n", col, lin);
    fprintf(arquivo, "%d\n", max);

    do {
        printf("\nQual filtro de cor você deseja aplicar?\n");
        printf("(0) Sair - (1) Negativo - (2) Cinza - (3) Relevo - (4) Espelhado\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if ((opc > 4) || (opc < 0)) {
            printf("\nEscolha um número inteiro entre 0 e 4.\n\n");
            continue;
        }

        if (opc == 0)
            break;

        switch (opc) {

            case 1:
                printf("\nFiltro Negativo Escolhido\n");

                insereItem(filtroNegativo, lista);

                break;

            case 2:
                printf("\nFiltro Cinza Escolhido\n");

                insereItem(filtroCinza, lista);

                break;

            case 3:
                printf("\nFiltro Relevo Escolhido\n");

                insereItem(filtroRelevo, lista);

                break;

            case 4:
                printf("\nFiltro Espelhado Escolhido\n");

                insereItem(filtroEspelhado, lista);

                break;
        }
    } while (1);

    for (nodo *n = lista; n->proximoNodo != NULL; n = n->proximoNodo) {
        n->filtro(arquivo, imagem, imagemaux, lin, col);
    }

    for (nodo *n = lista; n->proximoNodo != NULL; n = n->proximoNodo) {
        free(n);
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            fprintf(arquivo, "%d %d %d\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
        }
    }

    fclose(arquivo);

    printf("\nA imagem foi editada com sucesso!\n\n");

    for (i = 0; i < lin; i++) {
        free(imagem[i]);
    }
    free(imagem);

    for (i = 0; i < lin; i++) {
        free(imagemaux[i]);
    }
    free(imagemaux);

    printf("Deseja editar outra imagem?\n");
    printf("(0) Não - (1) Sim\n");
    printf("Escolha: ");
    scanf("%d", &opc);

    if (opc) {
        goto begin;
    }

    return 0;
}