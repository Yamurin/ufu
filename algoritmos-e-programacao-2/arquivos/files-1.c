#include <stdio.h>
#include <stdlib.h>

//Programa que aloca um vetor de 1000 posições para armazenar um texto no arquivo “resumo_TCC.txt”.

int main ()
{

    FILE* arquivo;
    arquivo = fopen("resumo_TCC.txt", "w");

    char* texto = NULL;
    texto = malloc(1000);

    if (arquivo == NULL || texto == NULL) {
        printf("Erro ao criar aquivo.\n");
        exit(1);
    }

    printf("Escreva o text: \n");
    fgets(texto, 1000, stdin);

    for (int i = 0; i < 1000; i++)
        fputc(texto[i], arquivo);
    fclose(arquivo);

    printf("Arquivo criado com sucesso.\n");
    free(texto);
}
