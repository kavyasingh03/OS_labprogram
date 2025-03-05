#include <stdio.h>

int main() {
    int arr[100], size, pos;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return 1;
    }
    
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
