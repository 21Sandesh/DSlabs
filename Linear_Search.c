#include <stdio.h>

int main()
{
    int arr[8] = {15, 5, 20, 35, 2, 42, 67, 17}, search, pos,len=8;
    while (1)
    {
        printf("\nEnter the Element to be Searched: ");
        scanf("%d", &search);

        pos = linearsearch(arr, search, len);
        if (pos != -1)
        {
            printf("\nElement Found at %d Position",pos+1);
        }
    }
}

int linearsearch(int arr[], int data, int len)
{
    int i;
    for (i=0; i<len; i++)
    {
        if (arr[i] == data)
        {
            printf("\nElement Found!");
            return i;
            break;
        }
    }
    if (i == len)
    {
        printf("Element not Found!");
        return -1;
    }
}