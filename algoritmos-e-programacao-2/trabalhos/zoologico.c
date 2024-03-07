#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Biblioteca para impressão caracteres do PT-BR

#define TAM_STRING 256

typedef struct {
    char* codigo;
    char* nome;
    char* especie;
    float peso;
    float altura;
} info_animal;

// Assegurar que uma determinada alocação de memória foi bem sucedida.
void confereMalloc (void *ptr)
{
    if(ptr == NULL)
    {
        printf("Erro ao alocar memória. Reinicie o programa.\n");
        exit(1);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Quantidades iniciais de setores, jaulas e animais.
    int qtd_setor, qtd_jaula, qtd_animal;

    printf("Setores - jaulas em cada setor - animais em cada jaula\n");
    scanf("%d %d %d", &qtd_setor, &qtd_jaula, &qtd_animal);

    // Inicializar zoológico
    info_animal*** zoo;
    zoo = (info_animal ***) malloc (qtd_setor * sizeof(info_animal **));
    confereMalloc(zoo);
    printf("Inicializando zoo... \n\n");

    for (int i_setor = 0; i_setor < qtd_setor; i_setor++)                           // Alocação de setores.
    {
        zoo[i_setor] = (info_animal **) malloc (qtd_jaula * sizeof (info_animal *));

        for (int i_jaula = 0; i_jaula < qtd_jaula; i_jaula++)                       // Alocação de jaulas.
        {
            zoo[i_setor][i_jaula] = (info_animal *) malloc (qtd_animal * sizeof (info_animal));
            printf("A %d° jaula do setor %d foi alocada com espaço para %d animais.\n", i_jaula + 1, i_setor + 1, qtd_animal);

            for (int i_animal = 0; i_animal < qtd_animal; i_animal++)               // Alocação e preenchimento de animais.
            {
                setbuf(stdin, NULL);
                info_animal* tmp_animal = &zoo[i_setor][i_jaula][i_animal];         // Variável temporária para editar o animal atual.

                printf("\nInsira os dados do %dº animal da jaula %d: \n", i_animal + 1, i_jaula + 1);

                printf("Código: ");
                tmp_animal->codigo = malloc(TAM_STRING);
                confereMalloc(tmp_animal->codigo);
                scanf("%s", tmp_animal->codigo);

                printf("Nome: ");
                tmp_animal->nome = malloc(TAM_STRING);
                confereMalloc(tmp_animal->nome);
                scanf("%s", tmp_animal->nome);

                printf("Espécie: ");
                tmp_animal->especie = malloc(TAM_STRING);
                confereMalloc(tmp_animal->especie);
                scanf("%s", tmp_animal->especie);

                printf("Peso: ");
                scanf("%f", &tmp_animal->peso);

                printf("Altura: ");
                scanf("%f", &tmp_animal->altura);

                printf("\n\"%s\" adicionado à %dº Jaula do Setor %d.\n", zoo[i_setor][i_jaula][i_animal].nome, i_jaula + 1, i_setor + 1);
            }
        }
        printf("\n");
    }

    // Inicializar vetor de nomes de setores.
     char **nomes_setor = (char **) malloc (qtd_setor * sizeof(char *));
    return 0;
}
