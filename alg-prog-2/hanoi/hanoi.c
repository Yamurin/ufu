#include <stdio.h>

 
    // Tela de início do jogo
    // Mostrar tabuleiro
    // Ações do jogador
    // Mover
    // Verificar se ganhou


#define TORRES 3 
#define BLOCOS 5
enum Torres { a, b, c };

int menu_opcoes();
void print_tabuleiro(int tabuleiro[][TORRES]);

int main()
{
    printf("Iniciando jogo \n");
    int tabuleiro[BLOCOS][TORRES] = {0};
    
     // Popular o tabuleiro inicial
    for(int i = 0; i < BLOCOS; i++)
        tabuleiro[i][a] = i + 1;
        
     print_tabuleiro(tabuleiro);
    
    int *pa = &tabuleiro[0][a];
    int *pb = &tabuleiro[BLOCOS - 1][b];
    int *pc = &tabuleiro[BLOCOS - 1][c];
    
    printf("Mover de A para C quando o jogo esta zerado: \n");
    // funciona, porém entend como tirar magic numbers
    
    int temp = *pa - 1;    
    *pb = *pa;
    *pa = 0;

    pa = &tabuleiro[temp+1][a];
    pb = &tabuleiro[3 - temp][b];
    
    print_tabuleiro(tabuleiro);
    //menu_opcoes();
    // iniciar jogo
    return 0;
}

int menu_opcoes()
{
   printf("MENU de opcoes\n");
   printf("Aperte 1 para mover\n");
   
   int opcao;
   scanf("%d", &opcao);
   
   return opcao;
}

void print_tabuleiro(int tabuleiro[][TORRES])
{
    for (int lin = 0; lin < BLOCOS; lin++)
    {
        for (int col = 0; col < TORRES; col++ )
            printf("%d ", tabuleiro[lin][col]);   
        printf("\n");
    }
        
        
}
 
