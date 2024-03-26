#include <stdio.h>
#include <stdlib.h>

/*
* Programa que armazena os diálogos entre dois atores para uma peça de teatro.
* Considerando que cada diálogo não passa de 20 caracteres, salve os N diálogos um em cada linha de um arquivo.
*/
#define STR_TAM 20

int main ()
{
    char* dial1 = malloc(STR_TAM);
    char* dial2 = malloc(STR_TAM);
    FILE* arquivo = NULL;
    int n;

    printf("Numero de dialogos: ");
    scanf("%d", &n);

    if (dial1 == NULL || dial2 == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    arquivo = fopen("../dialogos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao ler arquivo.\n");
        exit(1);
    }

    while (n--) {
        setbuf(stdin, NULL);
        printf("Texto do Autor 1: \n");
        fgets(dial1, STR_TAM, stdin);

        for (int i = 0; dial1[i] != '\0'; i++) {
            fputc(dial1[i], arquivo);
        }

        printf("Texto do Autor 2: \n");
        fgets(dial2, STR_TAM, stdin);

        for (int i = 0; dial2[i] != '\0'; i++) {
            fputc(dial2[i], arquivo);
        }
    }

    printf("Arquivo criado com sucesso.\n");
    fclose(arquivo);
    free(dial1);
    free(dial2);

    return 0;
}

