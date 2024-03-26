#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QUOTES 5
#define STR_BUF 50
int main ()
{
    FILE* file = NULL;
    char fileName[STR_BUF];

    printf("Nome do arquivo: ");
    gets(fileName);

    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Falha ao escrever arquivo.\n");
        exit(1);
    }

    // Gravar cada frase.
    for (int i = 0; i < QUOTES; i++) {
        char buffer[STR_BUF];
        int bufferSize = 0;

        printf("Frase %d: ", i);
        fgets(buffer, sizeof buffer, stdin);

        // Converter caracteres.
        while (buffer[bufferSize] != '\0') {
            buffer[bufferSize] = toupper(buffer[bufferSize]);
            bufferSize++;
        }

        // Gravar caracteres.
        for (int k = 0; k < bufferSize; k++)
            fputc(buffer[k], file);
    }

    fclose(file);
    printf("Arquivo gravado com sucesso.\nAbrindo arquivo...\n");
    fopen(fileName, "r");
    fclose(file);

    return 0;
}
