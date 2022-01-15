#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //bubble sort O(N^2)
    int n = 10;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Bubble Sort: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}