#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found
}

int binary_search(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Key found at index mid
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the list of integers (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    int linear_result = linear_search(arr, n, key);
    if (linear_result != -1) {
        printf("Linear search: Key %d found at index %d\n", key, linear_result);
    } else {
        printf("Linear search: Key %d not found\n", key);
    }

    int binary_result = binary_search(arr, 0, n - 1, key);
    if (binary_result != -1) {
        printf("Binary search: Key %d found at index %d\n", key, binary_result);
    } else {
        printf("Binary search: Key %d not found\n", key);
    }

    return 0;
}
