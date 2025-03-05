#include <stdio.h>
#define SIZE 10

void secondlargest(int arr[], int size) {
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }
    
    int largest = arr[0], secondLargest = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    if (secondLargest == largest) {
        printf("No second largest element found.\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }
}

int main() {
    int arr[SIZE], size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    secondlargest(arr, size);
    
    return 0;
}
