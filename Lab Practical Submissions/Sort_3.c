#include <stdio.h>

// Bubble Sort
void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the elements
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    int bubble_sorted[n];
    for (int i = 0; i < n; i++) {
        bubble_sorted[i] = arr[i];
    }
    bubble_sort(bubble_sorted, n);

    printf("Bubble Sort Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bubble_sorted[i]);
    }
    printf("\n");

    // Selection Sort
    int selection_sorted[n];
    for (int i = 0; i < n; i++) {
        selection_sorted[i] = arr[i];
    }
    selection_sort(selection_sorted, n);

    printf("Selection Sort Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selection_sorted[i]);
    }
    printf("\n");

    // Insertion Sort
    int insertion_sorted[n];
    for (int i = 0; i < n; i++) {
        insertion_sorted[i] = arr[i];
    }
    insertion_sort(insertion_sorted, n);

    printf("Insertion Sort Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", insertion_sorted[i]);
    }
    printf("\n");

    return 0;
}
