#include<stdio.h>
 int main()
 {
     int n;
     printf("Enter the size of array:");
     scanf("%d",&n);
    
     int arr[n];
     printf("Enter the elements of array:");
     for(int i=0;i<n;i++)
     {
       
     }
      int min,max= arr[0];
     for(int i=0;i<n;i++)
     {
         
         if(arr[i]<min)
         {
             min = arr[i];
         }
          
         if(arr[i]>max)
         {
             max = arr[i];
         }
     }
     printf("The min number in array is:%d\n", min);
     printf("The max number in array is:%d",max);
     
     return 0;
 }