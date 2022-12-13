#include <stdio.h>

int bubblesort(int arr[], int len);
void display(int arr[], int len);

int main()
{
    int len,pass;
    while (1)
    {
        printf("\nEnter Number of Elements in Array: ");
        scanf("%d", &len);
        int arr[len];
        for(int i=0;i<len;i++)
        {
            printf("Enter %d Element: ",i+1);
            scanf("%d",&arr[i]);
        }
        pass = bubblesort(arr, len);
        printf("\nSorted Array is: ");
        display(arr, len);
        printf("\nArray was Sorted in %d Pass\n",pass);
    }
}

int bubblesort(int arr[], int len)
{
    int temp,i;
    int swapflag = 0;
    for (i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapflag = 1;
            }
        }
        if (swapflag == 0)
        {
            break;
        }
    }
    return i;
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n\t%d", arr[i]);
    }
}