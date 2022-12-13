#include <stdio.h>

int selectionsort(int arr[], int len);
void display(int arr[], int len);

int main()
{
    int len, pass;
    while (1)
    {
        printf("\nEnter Number of Elements in Array: ");
        scanf("%d", &len);
        int arr[len];
        for (int i = 0; i < len; i++)
        {
            printf("Enter %d Element: ", i + 1);
            scanf("%d", &arr[i]);
        }
        pass = selectionsort(arr, len);
        printf("\nSorted Array is: ");
        display(arr, len);
        printf("\nArray was Sorted in %d Pass\n", pass);
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n\t%d", arr[i]);
    }
}

int selectionsort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}