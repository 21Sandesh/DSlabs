#include <stdio.h>

int binarysearch(int arr[], int len, int data);

int main()
{
    int arr[10] = {5, 9, 17, 23, 25, 45, 59, 63, 71, 89}, len = 10, pos, data;

    while (1)
    {
        printf("\nEnter Element to be Searched: ");
        scanf("%d", &data);

        pos = binarysearch(arr, len, data);
        if (pos != -1)
        {
            printf("\nElement Found at %d Position!", pos+1);
        }
        else
        {
            printf("\nElement not Found!");
        }
    }
}

int binarysearch(int arr[], int len, int data)
{
    int left = 0, right = len - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (data == arr[mid])
        {
            return mid;
        }
        else
        {
            if (data < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    if (left > right)
    {
        return -1;
    }
}