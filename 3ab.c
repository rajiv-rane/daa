// AIM: Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using
// Floyd's algorithm.

#include <stdio.h>
#define INF 999

int min(int a, int b)
{
    return (a < b) ? a : b;
}
void floyd(int p[][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
void main()
{
    int a[10][10], n, i, j;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    floyd(a, n);
    printf("\nShortest path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

// AIM: Design and implement C/C++ Program to find the transitive closure using Warshall's
// algorithm

#include <stdio.h>
void warshall(int[10][10], int);
void main()
{
    int a[10][10], i, j, n;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("The adjacency matirx is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    warshall(a, n);
}
void warshall(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (j = 1; j <= n; j++)
        {
            for (i = 1; i <= n; i++)
            {
                if ((p[i][j] == 0) && (p[i][k] == 1) && (p[k][j] == 1))
                {
                    p[i][j] = 1;
                }
            }
        }
    }
    printf("\nThe path matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}