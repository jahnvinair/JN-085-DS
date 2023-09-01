#include <stdio.h>

int rec_BS(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; // Target not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return rec_BS(arr, target, mid + 1, right);
    } else {
        return rec_BS(arr, target, left, mid - 1);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int index = rec_BS(arr, target, 0, size - 1);

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found\n");
    }

    return 0;
}
