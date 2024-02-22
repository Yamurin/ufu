#include <stdio.h>
#include <stdlib.h>

#define TORRES 3 
#define BLOCOS 5

enum Torres { a, b, c };
int tabuleiro[BLOCOS][TORRES] = {0};

void printContinuar (void)
{
    printf("\nContinuar...");
    setbuf(stdin, NULL);
    getchar();
    
    return;
}

void printTabuleiro (void)
{
    printf("\nA\tB\tC\n-----------------\n");
    for (int i = 0; i < BLOCOS; i++)
        {
            for (int j = 0; j < TORRES; j++)
                printf("%d \t", tabuleiro[i][j]);
            printf("\n");
        }
    printContinuar();
    
    return;
}

void printMenu (void)
{
    printf("\nEscolha a proxima jogada:\n");
    printf("1 ) Mover A > B \t\t 3 ) Mover B > A \t\t 5 ) Mover C > A\n");
    printf("2 ) Mover A > C \t\t 4 ) Mover B > C \t\t 6 ) Mover C > B\n");
    printf("7 ) Desistir do jogo\n");
    printf("-> ");
    
    return;
}

// Movimenta um bloco de cada vez, se um movimento válido 
void moverBloco(int orig, int dest, int **ptrOr, int **ptrDs)
{
    // Verifica se o movimento é válido.
    if (*ptrOr == NULL) {
        printf("MOVIMENTO INVALIDO: Voce nao pode mover blocos de uma torre vazia.\n");
        printContinuar();
        return;
    } else if (*ptrDs != NULL && **ptrDs != 0 && **ptrOr > **ptrDs) {
        printf("MOVIMENTO INVALIDO: Voce nao pode colocar um bloco em cima de outro com diametro menor. Tente novamente.\n");
        printContinuar();
        return;
    }
    
    int i = 0;
    int j = BLOCOS - 1;
     
    // Define o bloco no topo da pilha de destino (procurando de baixo para cima).
    while(tabuleiro[j][dest] != 0) 
        j--;
    *ptrDs = &tabuleiro[j][dest];
    
    // Move o bloco da origem para o destino. Reseta o bloco de origem.
    **ptrDs = **ptrOr;
    **ptrOr = 0;
    
    // Define o novo bloco no topo da pilha de origem (procurando de cima para baixo). 
    // Se a pilha estiver vazia, o ponteiro que indica o bloco do topo será NULL.
    while(tabuleiro[i][orig] == 0 && i <= BLOCOS) 
        i++; 
    
    if (i > BLOCOS && tabuleiro[i][orig] == 0)
        *ptrOr = NULL;
    else
        *ptrOr = &tabuleiro[i][orig];
        
     return;
}
            
int main()
{
    printf("Iniciando jogo...\n");
    
    // Preencher o tabuleiro inicial
    for(int i = 0; i < BLOCOS; i++)
        tabuleiro[i][a] = i + 1;
        
    int *pa = &tabuleiro[0][a];
    int *pb = NULL;
    int *pc = NULL;
    int userEscolha ;
   
   // Jogar até transpor todos os blocos para a última torre ou desistir
    while(tabuleiro[0][c] != 1)
    {
        printTabuleiro();
        printMenu();
        scanf("%d", &userEscolha);
        
        switch (userEscolha)
        {
            case (1):   // Mover A > B
                moverBloco(a, b, &pa, &pb);
                break;
                
            case (2):   // Mover  A > C
                moverBloco(a, c, &pa, &pc);
                break;
                
            case (3):   // Mover  B > A
                moverBloco(b, a, &pb, &pa);
                break;
                
            case (4):   // Mover  B > C
                moverBloco(b, c, &pb, &pc);
                break;
                
            case (5):   // Mover  C > A
                moverBloco(c, a, &pc, &pa);
                break;
                
            case (6):   // Mover  C > B
                moverBloco(c, b, &pc, &pb);
                break;
                
            case (7):   // Desistir
                printf("\nSaindo do jogo...\n");
                exit(1);
        }
    }
    
    printTabuleiro();
    printf("PARABENS! Voce ganhou!\n");
    return 0;
}