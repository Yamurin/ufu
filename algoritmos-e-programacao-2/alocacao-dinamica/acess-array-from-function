#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int numero;
    char *string;
} animal_t;

// Altera o valor de um elemento do vetor  
// Argument: endereço do vetor a ser alterado
void editVetor (animal_t **vetorPtr, int i)
{
    printf("\nInsira o valor: ");
    int aux;
    scanf("%d", &aux);
    
    /*
        https://stackoverflow.com/questions/1706502/arrow-operator-with-arrays
        Why I have to use fooArray[0].foo instead of fooArray[0]->foo.
    */
    
    (*vetorPtr)[i].numero = aux;
    printf("[!] Valor de vetor[%d] ao final da funcao: %d\n", i, (*vetorPtr)[i].numero);
    
    printf("Adicionar string: ");
    setbuf(stdin, NULL);
    (*vetorPtr)[i].string = malloc(256);
    fgets((*vetorPtr)[i].string, 255, stdin);
    return;
}

int main()
{
    animal_t* vetor;
    int lin = 2, col = 3;
    vetor = calloc(lin * col, sizeof(animal_t));     // Vetor com 15 animais
    // Editar valor do vetor por meio de função
    
    printf("Indice do elemento a ser substituido: ");
    int i;
    scanf("%d", &i);
    
    printf("[!] vetor antes da funcao: \n");
    for(int i = 0; i < lin * col; i ++)
        printf("[%d]: %d %s \n", i, vetor[i].numero, vetor[i].string);
    
    editVetor(&vetor, i);
    
    printf("[!] vetor depois da funcao: \n");
    for(int i = 0; i < lin * col; i ++)
        printf("[%d]: %d %s \n", i, vetor[i].numero, vetor[i].string);
    return 0;
}
