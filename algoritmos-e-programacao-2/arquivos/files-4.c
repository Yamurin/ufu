#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
* Programa que lê um arquivo texto qualquer e imprime o número de caracteres do arquivo.
* Imprima também o número de ocorrências da letra k no arquivo.
*/

#define STR_BUF 1024

int main ()
{
    FILE* arquivo = NULL;
    char pesquisa[STR_BUF];
    char c, k;
    int qtdChar = 0, qtdLetras = 0;

    printf("Endereco do arquivo: ");
    gets(pesquisa);

    setbuf(stdin, NULL);
    printf("Letra a ser pesquisada: ");
    scanf("%c", &k);

    arquivo = fopen(pesquisa, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }

    while ( (c = fgetc(arquivo)) != EOF) {
        qtdLetras++;
        if (c == tolower(k))
            qtdChar++;
    }

    printf("O arquivo tem %d letras. A letra %c aparece %d vezes.\n", qtdLetras, k, qtdChar);

    fclose(arquivo);

    return 0;
}

