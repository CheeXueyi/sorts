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

void merge(int *arr, int i, int m, int j) {
    int *temp = malloc((j - i + 1) * sizeof(int));
    int ite1 = i;
    int ite2 = m;
    int iteTemp = 0;
    while (ite1 < m || ite2 <= j) {
        if (ite1 == m) {
            temp[iteTemp] = arr[ite2];
            ite2++;
        } else if (ite2 > j) {
            temp[iteTemp] = arr[ite1];
            ite1++;
        } else if (arr[ite1] <= arr[ite2]){
            temp[iteTemp] = arr[ite1];
            ite1++;
        } else if (arr[ite1 > arr[ite2]]) {
            temp[iteTemp] = arr[ite2];
            ite2++;
        }
        iteTemp++;
    }

    for (int k = 0; k < (j - i + 1); k++) {
        arr[i+k] = temp[k];
    }
}

void mergeSort(int *arr, int i, int j) {
    if (i == j) {
        return; 
    }
    int mid = (i + j)/2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, j);
    merge(arr, i, mid + 1, j);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}