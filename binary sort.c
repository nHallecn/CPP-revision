#include <stdio.h>

int main() {
   	int target, size;
    int found = 0;
    
    printf("-------Binary Sort---------\n");
    printf("Enter the size of your array: ");
    scanf("%d",&size);
    
    int array[size];
    int low = 0;
    int high = size - 1;
    
    printf("Enter the elements of your array in sorted order\n");
    
    for(int i=0;i<size;i++){
    	printf("Enter element %d: ",i+1);
    	scanf("%d",&array[i]);
	}
	
	printf("\n Enter the element you want to find: ");
	scanf("%d",&target);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target) {
            printf("Element %d found at index: %d",target, mid);
            found = 1;
            break;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    return 0;
}