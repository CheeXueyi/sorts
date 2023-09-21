#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

void print_arr(int *arr, int i, int j) {
    while (i <= j) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        int swaps = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
        if (swaps == 0) {
            break;
        }
    }

    print_arr(arr, 0, n-1);

    return 0;
}