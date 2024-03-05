
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto 
{
    double x, y;
} ponto_t;

void imprime_ponto (ponto_t ponto1, ponto_t ponto2)
{
    ponto_t res;
    
    res.x = ponto1.x + ponto2.x;
    res.y = ponto1.y + ponto2.y;
    printf("A soma eh (%0.1lf, %0.1lf)\n", res.x, res.y);
}

int main()
{
    ponto_t ponto1, ponto2;
    int n;
    printf("ponto 1: ");
    scanf("%lf %lf", &ponto1.x, &ponto1.y);
    printf("ponto 2: ");
    scanf("%lf %lf", &ponto2.x, &ponto2.y);
    
    imprime_ponto(ponto1, ponto2);
    
    return 0;
}
