#include<stdio.h>

int insertionsort(int arr[],int len);
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
        pass = insertionsort(arr, len);
        printf("\nSorted Array is: ");
        display(arr, len);
        printf("\nArray was Sorted in %d Pass\n",pass);
    }
}

int insertionsort(int arr[],int len)
{
    int temp,i,j;
    
    for(i=1;i <len; i++)
    {
        temp=arr[i];
        j = i-1;
        while(j>=0 &&arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n\t%d", arr[i]);
    }
}