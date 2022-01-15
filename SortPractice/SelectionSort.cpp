#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //selection sort O(N^2)
    int n = 10;
    for (int i=0; i<n; i++) {
        int minIdx = i;
        for (int j=i; j<n; j++) {
            if (arr[j] < arr[minIdx]) { minIdx = j; }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    printf("Selection Sort: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}