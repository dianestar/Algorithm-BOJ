#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //insertion sort O(N^2)
    int n = 10;
    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        while (j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    printf("Insertion Sort: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}