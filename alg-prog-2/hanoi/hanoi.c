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
    printf(" 3 ) Mover de B para A\n");
    printf(" 4 ) Mover de B para C\n");
    printf(" 5 ) Mover de C para A\n");
    printf(" 6 ) Mover de C para B\n");
    
    printf(" 7 ) Desistir do jogo\n");
    
    printf(" -> ");
}

void moveBloco(int orig, int dest, int **ptrOr, int **ptrDs)
{
    // Vê se aposição é válida
    if (*ptrDs != NULL && **ptrOr > **ptrDs)
    {
        printf("INVALIDO\n");
        return;
    }
    
    // Índices auxiliares
    int i = 0;
    int j = BLOCOS - 1;
     
    // Define o bloco atualmente no topo da pilha de origem
    while(mat[j][dest] != 0) { j--;}
    *ptrDs = &mat[j][dest];
    
    // Move o bloco da origem para o destino. Reseta o bloco de origem
    **ptrDs = **ptrOr;
    **ptrOr = 0;
    
    // Define o bloco atualmente no topo da pilha de destino
    while(mat[i][orig] == 0 && i < BLOCOS) { i++; }
    *ptrOr = &mat[i][orig];
    
    return; 
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
        switch (userEscolha)
        {
            case (1): // A > B
                moveBloco(a, b, &pa, &pb);
                break;
                
            case (2): // A > C
                moveBloco(a, c, &pa, &pc);
                break;
                
            case (3): // B > A
                moveBloco(b, a, &pb, &pa);

                break;
                
            case (4): // B > C
                moveBloco(b, c, &pb, &pc);
                break;
                
            case (5): // C > A
                moveBloco(c, a, &pc, &pa);
                break;
                
            case (6): // C > B
                moveBloco(c, b, &pc, &pb);
                break;
                
            case (7):
                exit(1);
        }
    }
    return 0;
}
