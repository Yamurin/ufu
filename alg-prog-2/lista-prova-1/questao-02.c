/*
    Rayane Reis Mota
    12311BSI233
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cidade {
        int x, y;
        char nome[256];
    } cidade_t;
    
double calcDistancia(cidade_t cidade1, cidade_t cidade2);

int main ()
{
    
    int n; // Quantidade de cidades
    
    printf("Quantas cidades voce quer registrar?: ");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    
    cidade_t *cidades = (cidade_t *) malloc(n * sizeof(cidade_t));
    
    for (int i = 0; i < n; i++)
    {
        printf("Nome da cidade: ");
        fgets(cidades[i].nome, 50, stdin);
        cidades[i].nome[strcspn(cidades[i].nome, "\n")] = 0;
        
        setbuf(stdin, NULL);
        
        printf("Coordenadas de %s (X Y): ", cidades[i].nome);
        scanf("%d %d", &cidades[i].x, &cidades[i].y);
        
        setbuf(stdin, NULL);
    }
    
    double **distancias = (double **) malloc(n * sizeof(double *));
    
    double tempDistancia;
    
    // Cria, preenche e imprime a matriz com as distâncias entre cidades
    for (int lin = 0; lin < n; lin++)
    {
        distancias[lin] = (double *) malloc(n * sizeof(double));
        for (int col = 0; col < n; col++)
        {
            tempDistancia = calcDistancia(cidades[lin], cidades[col]);
            distancias[lin][col] = tempDistancia;
            printf("[%s - %s] %0.2lf \t", cidades[lin].nome , cidades[col].nome, distancias[lin][col]);
        }
        printf("\n");
    }
    
    return 0;
}

// Calcula a distância entre uma cidade e outra usando o teorema de Pitágoras
double calcDistancia(cidade_t cidade1, cidade_t cidade2)
{
    double cat1, cat2, distancia;
    
    cat1 = abs(cidade1.x - cidade2.x);
    cat2 = abs(cidade1.y - cidade2.y);
    
    cat1 *= cat1;
    cat2 *= cat2;
    
    distancia = sqrt(cat1 + cat2);
    
    return distancia;
}