#include <stdio.h>

int quicksort(int arr[], int lb, int ub);
void display(int arr[], int len);

int main()
{
    int len;
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
        quicksort(arr, 0,len-1);
        printf("\nSorted Array is: ");
        display(arr, len);
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n\t%d", arr[i]);
    }
}

int quicksort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr,lb,ub);
        quicksort(arr, lb, loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb], temp;
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[lb];
            arr[lb] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}