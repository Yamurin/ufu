#include <stdio.h>

#define TORRES 3 
#define BLOCOS 5
enum Torres { a, b, c };

int main()
{
    printf("Iniciando jogo \n");
    int mat[BLOCOS][TORRES] = {0};
    
     // Popular o tabuleiro inicial
    for(int i = 0; i < BLOCOS; i++)
        mat[i][a] = i + 1;
    
    /*
        1 0 0
        2 0 0
        3 0 0
        4 0 0
        5 0 0
    */
    
    int *pa = &mat[0][a];
    int *pb = NULL;
    int *pc = NULL;
    int i, temp;
    
    while (1)
    {
        printf("Opcao: \n");
        printf("1.A para B \n2.A para C\n3.B para A\n4.B para C\n");
        scanf("%d", &i);
        
        switch (i)
        {
            case 1:
                
                // como acessar pb?
                *pb = *pa;
                temp = *pa; 
                *pa = 0;
                pa = &mat[temp][a];
                break;
                
            case 2:
                temp = BLOCOS - (*pa);
                pc = &mat[temp][c];
                *pc = *pa;
                temp = *pa;  // Calcula qual o indice do ultimo bloco, depois de tirar o de cima
                *pa = 0;
                pa = &mat[temp][a];
                break;
        }
        
         for(int i = 0; i < BLOCOS; i++)
         {
             for(int j = 0; j < TORRES; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
         }  
    }
    
    
    return 0;
    
}
 
