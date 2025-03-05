#include <stdio.h>

int main() {
    int size, count = 0;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    int arr[size], freq[size];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array
    }
    
    for (int i = 0; i < size; i++) {
        int duplicateCount = 1;
        if (freq[i] == -1) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    duplicateCount++;
                    freq[j] = 0; // Mark as counted
                }
            }
            if (duplicateCount > 1) {
                count += duplicateCount - 1;
            }
        }
    }
    
    printf("Total number of duplicate elements: %d\n", count);
    
    return 0;
}
