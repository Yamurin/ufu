#include <stdio.h>
#include <stdlib.h>

#define STR_BUF 1024
// Protótipo de funções
int printMenu(void);
int sum_bin ();     // dois vetores
int main ()
{
    // 1- Selecionar operação
    // 2- Inserir numero(s)
    // 3 Realizar operação
    // 4 Imprimir inteiro

    switch (printMenu())
    {
        case 1:
            printf("Iniciando soma\n");
            //printf("Digite os números separados por '+' sem espaços\n");
    }

    sum_bin();
    /*//// Binário para decimal
    int num[5] = {0, 1, 1, 0, 1}; // 9
    int dec = 0;

    for (int i = 0; i < 5; i++) {
        int base = 1;
        int pow = 5 - 1 - i;
        if (num[i] == 0)
            continue;
        else
            while (pow--)
                base *= 2;
        dec += base;
    }
    printf("%d\n", dec);*/

    return 0;
}

int sum_bin ()     // dois vetores
{
    int bin1[4] = {0, 1, 0, 1};
    int bin2[4] = {0, 1, 1 ,1};
    int* result = calloc (4 , sizeof(int));     // Guarda o número binário de soma total
    int  carry = 0;             // Quando 1 + 1 = 0 com um "carry" de 1 para o proximo digito, é o "sobe um"

    for (int i = 4 - 1; i >= 0; i--) {
        // if carry = i > n, realocar
        int auxResult = bin1[i] + bin2[i] + carry;

        if (auxResult <= 1) {
            result[i] = auxResult;
            carry = 0;
        } else {
            result[i] = auxResult % 2;          // Soma o 'carry' ao dígito, mas sem sobrescrever o valor da soma desse mesmo dígito com o próximo
            carry = 1;
        }
    }

    for(int i = 0; i < 4; i++)
        printf("%d", result[i]);

    return 0;

}

// Retorna a quantidade de digitos do vetor alocado, parametro: vetor para alocar a string &ptr
// nesse caso, bin[binLen - 1] vai ser o sinal
int get_binary (int *bin)
{
    char binStr[STR_BUF];
    bin = NULL;
    int binLen= 0;                              // Número de dígitos da entrada

    fgets(binStr, STR_BUF, stdin);

    // Converte a string digitada para números em um vetor dinâmico
    for (int i = 0; binStr[i] != '\0' && binStr[i] != '\n'; i++) {
        binLen++;
        bin = realloc(bin, sizeof(int) + binLen);

        if (bin == NULL) {
            printf("Falha ao alocar memória. Reinicie o programa.\n");
            exit(1);
        }

        bin[i] = binStr[i] == '1' ? 1 : 0;
    }

    return binLen;
}

int printMenu (void)
{
    printf("Selecione a operação: ");
    printf("1. Soma \n");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
}
