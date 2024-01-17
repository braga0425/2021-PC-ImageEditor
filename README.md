# Image Editor in C

This repository contains a simple C program for image editing in PPM (Portable Pixel Map) format. The program allows applying different color filters to the image, such as Negative, Gray, Relief, and Mirrored.

## File Structure

**main.c**: The main file containing the main function that manages the program execution. It reads a PPM image, applies filters chosen by the user, and saves the resulting image.

**functions.c**: Contains the implementations of the filter functions (Negative, Gray, Relief, Mirrored) and the logic for manipulating a linked list of filters to be applied.

**functions.h**: The header file with data structure definitions (pixel, node) and function prototypes.

**image.ppm**: An example PPM image to be used in the program.

**Makefile**: File responsible for automating the compilation process. It facilitates the generation of objects and the creation of the final executable.

## Compilation and Execution

To compile the program automatically using the Makefile, simply execute the following command in the terminal:

```bash
make
```

This will compile the source files and generate the executable named main. To run the program:

```bash
./main
```

The program will prompt for the input file name (image.ppm), the output file name, and the choice of the filter to be applied.

## Final Notes

The program uses the standard file manipulation library (stdio.h) and mathematical operations library (math.h). The data structure used is a linked list to store the filters to be applied.

Available filters include Negative, Gray, Relief, and Mirrored. The code includes basic error handling for file opening.

This program is a simple educational project and can be used as a foundation for more complex image processing projects in C. Feel free to explore, modify, and expand the code as needed.

The use of the Makefile is optional but recommended to simplify the compilation process.

# [PT-BR] Editor de Imagens em C

Este repositório contém um programa simples em C para edição de imagens em formato PPM (Portable Pixel Map). O programa permite aplicar diferentes filtros de cor à imagem, como Negativo, Cinza, Relevo e Espelhado.

## Estrutura de Arquivos

**main.c**: O arquivo principal contendo a função main que gerencia a execução do programa. Ele lê uma imagem PPM, aplica filtros escolhidos pelo usuário e salva a imagem resultante.

**functions.c**: Contém as implementações das funções dos filtros (Negativo, Cinza, Relevo, Espelhado) e a lógica para manipular uma lista encadeada de filtros a serem aplicados.

**functions.h**: O arquivo de cabeçalho com as definições das estruturas de dados (pixel, nodo) e protótipos de função.

**imagem.ppm**: Um exemplo de imagem PPM para ser usado no programa.

**Makefile**: Arquivo responsável pela automação do processo de compilação. Facilita a geração dos objetos e a criação do executável final.

## Compilação e Execução

Para compilar o programa automaticamente usando o Makefile, basta executar o seguinte comando no terminal:

```bash
make
```

Isso irá compilar os arquivos fonte e gerar o executável chamado main. Para executar o programa:

```bash
./main
```

O programa solicitará o nome do arquivo de entrada (imagem.ppm), o nome do arquivo de saída e a escolha do filtro a ser aplicado.

## Observações Finais

O programa utiliza a biblioteca padrão de manipulação de arquivos (stdio.h) e operações matemáticas (math.h). A estrutura de dados utilizada é uma lista encadeada (linked list) para armazenar os filtros a serem aplicados.

Os filtros disponíveis são: Negativo, Cinza, Relevo e Espelhado. O código inclui tratamento de erros básico para a abertura de arquivos.

Este programa é um projeto simples com fins educacionais e pode ser utilizado como base para projetos mais complexos de processamento de imagens em C. Sinta-se à vontade para explorar, modificar e expandir o código conforme suas necessidades.

O uso do Makefile é opcional, mas é recomendado para simplificar o processo de compilação.
