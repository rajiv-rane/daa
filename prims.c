#include <stdio.h>
void my_prim(int adj[][10], int N)
{
    int i, j, nv, min, min_cost = 0, u = 0, v = 0;
    int visit[10] = {0}; // Initialize all elements to 0

    visit[0] = 1; // Start from node 0
    nv = 1;

    while (nv < N)
    {
        min = 999;

        for (i = 0; i < N; i++)
        {
            if (visit[i] == 1)
            { // If visited

                for (j = 0; j < N; j++)
                {
                    if (adj[i][j] < min)
                    {
                        min = adj[i][j];
                        adj[i][j] = 999;
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (visit[u] == 1 && visit[v] == 0)
        {
            visit[v] = 1;
            min_cost += min;
            nv++;
            printf("Edge %d - %d : (%d)\n", u, v, min);
        }
    }

    printf("Cost : %d\n", min_cost); // Prints minimum cost
}

int main()
{
    int adj[10][10], N, i, j;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &N);

    printf("Enter the adjacency matrix\n");
    printf("Enter 0 for no connection and weights for connection\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
            {
                adj[i][j] = 999;
            }
        }
    }

    my_prim(adj, N);

    return 0;
}