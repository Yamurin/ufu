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

// Transpõe um bloco da pilha de origem para a pilha de destino, informados pelo usuário
void moverBloco(int orig, int dest, int *ptrOr, int *ptrDs)
{
    // Define o bloco atualmente no topo da pilha de origem
    int i = 0;
    while(mat[i][orig] == 0)
        i++;
    ptrOr = &mat[i][orig];
    *ptrOr = mat[i][orig];
    
     // Define o bloco atualmente no topo da pilha de destino
    i = BLOCOS - 1;
    while(mat[i][dest] != 0)
        i--;
    ptrDs = &mat[i][dest];
    
    //TODO Erros Handling

    // Mover bloco da origem para o destino
    *ptrDs = *ptrOr;
    *ptrOr = 0;  
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
    int userEscolha;
   
    while(mat[0][c] != 5)
    {
        printMatriz();
        
        printMenu();
        scanf("%d", &userEscolha);
        
        switch (userEscolha)
        {
            case (1):
                moverBloco(a, b, pa, pb);
                break;
            case (2):
                moverBloco(a, c, pa, pc);
                break;
            case (3):
                moverBloco(b, c, pb, pc);
                break;
            case (4):
                moverBloco(b, a, pb, pa);
                break;
            case (5):
                moverBloco(c, a, pc, pa);
                break;
            case (6):
                moverBloco(c, b, pc, pb);
                break;
            case (7):
                exit(1);
        }
        
        printf("\n");
        setbuf(stdin, NULL);
    }
    return 0;
}
