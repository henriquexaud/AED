#include <stdio.h>
#include <stdbool.h>
#define INFINITY 9999999

// Função para encontrar o mínimo entre dois valores
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Função para encontrar o menor número de horas necessário para ir de C para R
int menorNumeroHoras(int grafo[][1001], int N, int C, int R, int E)
{
    int distancias[N + 1]; // Vetor de distâncias
    bool visitados[N + 1]; // Vetor de visitados
    int i, j;

    // Inicializar as distâncias como INFINITY e os visitados como false
    for (i = 1; i <= N; i++)
    {
        distancias[i] = INFINITY;
        visitados[i] = false;
    }

    // Definir a distância para a cidade inicial como 0
    distancias[C] = 0;

    // Encontrar o menor caminho para todas as cidades
    for (i = 1; i <= N; i++)
    {
        int u = -1;
        // Escolher a cidade não visitada com a menor distância
        for (j = 1; j <= N; j++)
        {
            if (!visitados[j] && (u == -1 || distancias[j] < distancias[u]))
                u = j;
        }

        // Marcar a cidade como visitada
        visitados[u] = true;

        // Atualizar as distâncias
        for (j = 1; j <= N; j++)
        {
            if (grafo[u][j] > 0 && !visitados[j])
            {
                // Verificar se a rota passa pela cidade E
                if (u == E || j == E)
                    continue;
                distancias[j] = min(distancias[j], distancias[u] + grafo[u][j]);
            }
        }
    }

    // Retornar a distância mínima de C a R
    return distancias[R];
}

int main()
{
    int N, M, A, B, C, R, E;

    while (scanf("%d %d", &N, &M) != EOF)
    {
        int grafo[1001][1001] = {0}; // Matriz de adjacência do grafo

        // Ler as rotas
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &A, &B);
            grafo[A][B] = 1;
            grafo[B][A] = 1;
        }

        // Ler as cidades C, R e E
        scanf("%d %d %d", &C, &R, &E);

        // Encontrar o menor número de horas necessário para ir de C para R
        int menorHoras = menorNumeroHoras(grafo, N, C, R, E);

        // Imprimir o resultado
        printf("%d\n", menorHoras);
    }

    return 0;
}