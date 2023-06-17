#include<stdio.h>
 int main(){
     int n,temp;

     printf("Enter the size of array:");
     scanf("%d",&n);
          int arr[n];
     printf("Enter the elements of array:");
     for(int i=0;i<n;i++)
     {
         scanf("%d",&arr[i]);
         
     }
     
     for(int i=0;i<n/2;i++)
    {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] =temp;
    }
    printf("Reverse array is:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
     return 0;
 }