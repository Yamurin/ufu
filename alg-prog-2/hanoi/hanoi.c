#include <stdio.h>
#include <stdlib.h>

#define TORRES 3 
#define BLOCOS 3

enum Torres { a, b, c };
int mat[BLOCOS][TORRES] = {0};

// Mensagem 
void printContinuar (void)
{
    printf("\nContinuar...");
    setbuf(stdin, NULL);
    getchar();
}

// Apresenta toda a matriz na tela.
void printMatriz (void)
{
    printf("\nA\tB\tC\n------------------\n");
    for (int i = 0; i < BLOCOS; i++)
        {
            for (int j = 0; j < TORRES; j++)
                printf("%d \t", mat[i][j]);
            printf("\n");
        }
    printContinuar();
    return; 
}

// Apresenta as opções na tela.
void printMenu (void)
{
    printf("\nEscolha a próxima jogada\n");
    
    printf(" 1 ) Mover A > B \t\t 2 ) Mover A > C\n");
    printf(" 3 ) Mover B > A \t\t 4 ) Mover B > C\n");
    printf(" 5 ) Mover C > A \t\t 6 ) Mover C > B\n");
    printf(" 7 ) Desistir do jogo\n");
    printf(" -> ");
}

void moveBloco(int orig, int dest, int **ptrOr, int **ptrDs)
{
    // todo paontar pra null quando vazio
    // Verifica se o movimento é válido.
    if (*ptrOr == NULL) {
        printf("MOVIMENTO INVALIDO: Voce nao pode mover blocos de uma torre vazia.\n");
        printContinuar();
        return;
    } else if (*ptrDs != NULL && **ptrDs != 0 && **ptrOr > **ptrDs) {
        printf("orig %d : dest %d\n", **ptrOr, **ptrDs);
        printf("MOVIMENTO INVALIDO: Voce nao pode colocar um bloco em cima de outro com diametro menor. Tente novamente.\n");
        printContinuar();
        return;
    }
    
    int i = 0;
    int j = BLOCOS - 1;
     
    // Define o bloco atualmente no topo da pilha de origem.
    while(mat[j][dest] != 0) 
        j--;
    *ptrDs = &mat[j][dest];
    
    // Move o bloco da origem para o destino. Reseta o bloco de origem.
    **ptrDs = **ptrOr;
    **ptrOr = 0;
    
    // Define o bloco atualmente no topo da pilha de destino.
    while(mat[i][orig] == 0 && i <= BLOCOS) 
        i++; 
    *ptrOr = &mat[i][orig];
    
    return; 
}
            
int main()
{
    printf("Iniciando jogo...\n");
    
     // Preencher o tabuleiro inicial
    for(int i = 0; i < BLOCOS; i++)
        mat[i][a] = i + 1;
        
    int *pa = &mat[0][a];
    int *pb = NULL;
    int *pc = NULL;
    int userEscolha ;
   
    while(mat[0][c] != 1)
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
                printf("\nSaindo do jogo...\n");
                getchar();
                exit(1);
        }
    }
    
    printf("Parabens! Voce ganhou!\n");
    return 0;
}
