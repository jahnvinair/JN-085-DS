#include <stdio.h>

int rec_LS(int arr[], int target, int index, int size) {
    if (index >= size) {
        return -1; // Target not found
    }
    
    if (arr[index] == target) {
        return index;
    }
    
    return rec_LS(arr, target, index + 1, size);
}

int main() {
    int arr[] = {4, 8, 2, 16, 10, 6, 12, 18, 14, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int index = rec_LS(arr, target, 0, size);

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found\n");
    }

    return 0;
}
