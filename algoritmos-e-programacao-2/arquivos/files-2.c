#include <stdio.h>
#include <stdlib.h>

/*
 * Programa lê e apresenta ao usuário todo o conteúdo de um arquivo armazenado no arquivo “resumo_TCC.txt”.
 A leitura deve ser realizada caractere por caractere.
 */

int main ()
{
    FILE* arquivo;
    char c;
    arquivo = fopen("./resumo_TCC.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir aquivo.\n");
        exit(1);
    }

   while( (c = fgetc(arquivo)) != EOF)
       printf("%c", c);

    fclose(arquivo);
    return 0;
}