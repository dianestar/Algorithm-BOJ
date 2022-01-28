#include <iostream>
using namespace std;

int sorted[10];

void merge(int* arr, int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int k = start;

    while (i<=mid && j<=end) {
        if (arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i>mid) {
        for (int l=j; l<=end; l++) {
            sorted[k] = arr[l];
            k++;
        }
    }
    else {
        for (int l=i; l<=mid; l++) {
            sorted[k] = arr[l];
            k++;
        }
    }

    for (int l=start; l<=end; l++) {
        arr[l] = sorted[l];
    }
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //merge sort O(logN)
    mergeSort(arr, 0, 9);

    printf("Merge Sort: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}