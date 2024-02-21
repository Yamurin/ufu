#include <stdio.h>
#include <stdlib.h>

#define TORRES 3 
#define BLOCOS 5

enum Torres { a, b, c };
int mat[BLOCOS][TORRES] = {0};

void printMatriz (void)
{
    for (int i = 0; i < BLOCOS; i++)
        {
            for (int j = 0; j < TORRES; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
        
    getchar();
    setbuf(stdin, NULL);
    
    return; 
}
void printMenu (void)
{
    printf("\nEscolha a próxima jogada\n");
    
    printf(" 1 ) Mover de A para B\n");
    printf(" 2 ) Mover de A para C\n");
    printf(" 3 ) Mover de B para C\n");
    printf(" 4 ) Mover de B para A\n");
    printf(" 5 ) Mover de C para A\n");
    printf(" 6 ) Mover de C para B\n");
    
    printf(" 7 ) Desistir do jogo\n");
    
    printf(" -> ");
}

int main()
{
    printf("Iniciando jogo \n");
    
     // Preencher o tabuleiro inicial
    for(int i = 0; i < BLOCOS; i++)
        mat[i][a] = i + 1;
        
    int *pa = &mat[0][a];
    int *pb = NULL;
    int *pc = NULL;
    int userEscolha ;
   
    while(mat[0][c] != 5)
    {
        printMatriz();
        printMenu();
        
        scanf("%d", &userEscolha);

        int i = 0;
        int j = BLOCOS - 1;
            
        switch (userEscolha)
        {
            case (1): // A > B
                while(mat[j][b] != 0) { j--;}
                pb = &mat[j][b];
                *pb = *pa;
                *pa = 0;
                while(mat[i][a] == 0) { i++; }
                pa = &mat[i][a];
                break;
                
            case (2): // A > C
               while(mat[j][c] != 0) { j--;}
                pc = &mat[j][c];
                *pc = *pa;
                *pa = 0;
                while(mat[i][a] == 0) { i++; }
                pa = &mat[i][a];
                break;
                
            case (3): // B > A
                while(mat[j][a] != 0) { j--;}
                pa = &mat[j][a];
                *pa = *pb;
                *pb = 0;
                while(mat[i][b] == 0) { i++; }
                pa = &mat[i][b];
                break;
                
            case (4): // B > C
               while(mat[j][c] != 0) { j--;}
                pc = &mat[j][c];
                *pc = *pb;
                *pb = 0;
                while(mat[i][b] == 0) { i++; }
                pa = &mat[i][b];
                break;
                
            case (5): // C > A
                while(mat[j][a] != 0) { j--;}
                pa = &mat[j][a];
                *pa = *pc;
                *pc = 0;
                while(mat[i][c] == 0) { i++; }
                pa = &mat[i][c];
                break;
                
            case (6): // C > B
                while(mat[j][b] != 0) { j--;}
                pb = &mat[j][b];
                *pb = *pc;
                *pc = 0;
                while(mat[i][c] == 0) { i++; }
                pc = &mat[i][c];
                break;
            case (7):
                exit(1);
        }
    }
    return 0;
}
