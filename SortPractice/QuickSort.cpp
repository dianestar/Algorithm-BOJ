#include <iostream>
using namespace std;

void quickSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = start;
    int left = start+1;
    int right = end;
    while (left <= right) {
        while (left <= end && arr[left] <= arr[pivot]) { left++; }
        while (right > start && arr[right] >= arr[pivot]) { right--; }
        if (left > right) {
            int temp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = temp;
        }
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    quickSort(arr, start, right-1);
    quickSort(arr, right+1, end);
}

int main() {
    int arr[4] = {2, 1, 4, 3};

    //quick sort O(N*logN)
    int n = 4;
    quickSort(arr, 0, n-1);

    printf("Quick Sort: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}