#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:",i);
        scanf("%d",&arr[i]);
    }

    int min=arr[0];
    int loc;
    for(i=0;i<n;i++)
    {
        if(arr[i]<min){
            min=arr[i];
            loc=i;
        }

    }
    printf("%d is min and found at %d",min,loc);
}