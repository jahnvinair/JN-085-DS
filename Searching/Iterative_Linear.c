#include <stdio.h>

int iter_LS(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {4, 8, 2, 16, 10, 6, 12, 18, 14, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int index = iter_LS(arr, size, target);

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found\n");
    }

    return 0;
}
