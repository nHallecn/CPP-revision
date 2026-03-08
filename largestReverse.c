#include <stdio.h>
#include <stdlib.h>

void findMax(int arr[], int size){
    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("The maximum element in the array is: %d\n", max);
}

void reverseArray(int arr[], int size){
    printf("The reversed array is: ");

    for(int i = size - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){

    int size;

    // Input validation
    do{
        printf("Enter the size of the array (1 - 10): ");
        scanf("%d", &size);
    }while(size > 10 || size <= 0);

    int *arr = (int *)malloc(size * sizeof(int));  // Allocate memory dynamically

    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    findMax(arr, size);
    reverseArray(arr, size);

    free(arr);  // Free allocated memory
    return 0;
}