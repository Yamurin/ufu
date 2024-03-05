
#include <stdio.h>
#include <stdlib.h>

void incp(double *x, int a)
{
    *x += a;
}

int main()
{
    double x;
    scanf("%lf", &x);
    if(x < 0)
        incp(&x, 10);
    else
        incp(&x, -20);
        
    printf("%lf \n", x);
    return 0;
}
