
#include <stdio.h>
#include <stdlib.h>

void maxMin (double *vet, int n)
{
    double max = 0, min = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(vet[i] > max) 
            max = vet[i];
        if(vet[i] < min) 
            min = vet[i];
    }
    
    printf("%lf %lf\n", max, min);
}

int main()
{
    int n;
    scanf("%d", &n);
    double *vet = (double *) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        scanf("%lf", &vet[i]);
        
    maxMin(vet, n);
    return 0;
}
