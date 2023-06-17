#include<stdio.h>

int main() {
    int n, temp;
    int even = 0, odd = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even += arr[i];
        }
        else {
            odd += arr[i];
        }
    }
    
    printf("Sum of even elements: %d\n", even);
    printf("Sum of odd elements: %d\n", odd);
    
    return 0;
}
