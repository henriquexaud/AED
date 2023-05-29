#include <stdio.h>
#include <string.h>

int prefixIndex = 0;
int findIndex(char str[], int start, int end, char value);

void printPostOrder(char in[], char pre[], int inStart, int inEnd)
{
    if (inStart > inEnd)
        return;

    // Encontra o índice do valor atual na ordem infixa
    int inIndex = findIndex(in, inStart, inEnd, pre[prefixIndex++]);

    // Constrói a subárvore esquerda
    printPostOrder(in, pre, inStart, inIndex - 1);

    // Constrói a subárvore direita
    printPostOrder(in, pre, inIndex + 1, inEnd);

    // Imprime o valor do nó
    printf("%c", in[inIndex]);
}

int findIndex(char str[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
    {
        if (str[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    int c;
    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {
        int n;
        char in[52], pre[52];
        scanf("%d %s %s", &n, pre, in);

        prefixIndex = 0;
        printPostOrder(in, pre, 0, n - 1);

        printf("\n");
    }
    return 0;
}