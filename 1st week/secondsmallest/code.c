#include <stdio.h>
#define SIZE 10

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void secondsmallest(int arr[], int size) {
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }

    sortArray(arr, size);
    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > smallest) {
            printf("The second smallest element is: %d\n", arr[i]);
            return;
        }
    }

    printf("No second smallest element found.\n");
}

int main() {
    int arr[SIZE], size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    secondsmallest(arr, size);

    return 0;
}
