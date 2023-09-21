#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000

void print_arr(int *arr, int i, int j) {
    while (i <= j) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void quick_sort(int *arr, int start, int end) {
    if (start == end) {
        return;
    }

    int pivot = arr[start];
    int i = start + 1;
    int j = end;
    while (i < j) {
        while (i < j && arr[i] < pivot) {
            i++;
        }

        while (i < j && arr[j] >= pivot) {
            j--;
        }

        if (i != j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    if (arr[i] >= pivot) {
        i--;
    }

    int temp = arr[i];
    arr[i] = arr[start];
    arr[start] = temp;

    if (i != start) {
        quick_sort(arr, start, i - 1);
    }

    if (i != end) {
        quick_sort(arr, i + 1, end);
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    quick_sort(arr, 0, n-1);

    print_arr(arr, 0, n-1);
    return 0;
}