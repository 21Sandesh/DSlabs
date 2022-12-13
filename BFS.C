#include <stdio.h>
#include <malloc.h>
#define n 5
int a[n][n];
int visited[n] = {0, 0, 0, 0, 0};
int arr[n];
int f = -1, r = -1;
void enqueue(int x)
{
    if (r == n - 1)
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        r = f = 0;
        arr[r] = x;
    }
    else
    {
        r++;
        arr[r] = x;
    }
}
int dequeue()
{
    int a;
    if (f == -1)
    {
        printf("Queueu is empty \n");
    }
    else
    {
        a = arr[f];
        f++;
    }
    return a;
}
int main()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter 1 if %d having node with %d else 0 : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int s = 1;
    printf("%d ", s);
    visited[s] = 1;
    enqueue(s);
    for (i = 1; i <= n; i++)
    {
        int u = dequeue();
        for (j = 1; j <= n; j++)
        {
            if (a[u][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    return 0;
}