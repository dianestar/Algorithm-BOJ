#include <iostream>
using namespace std;

int main() {
    int arr[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

    //heap sort O(N*logN)
    int n = 9;

    // create min heap !
    for (int i=1; i<n; i++) {
        int node = i;
        do {
            int root = (node-1)/2;
            if (arr[root] < arr[node]) {
                int temp = arr[root];
                arr[root] = arr[node];
                arr[node] = temp;
            }
            node = root;
        } while (node != 0);
    }

    for (int i=n-1; i>=0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int root = 0;
        int node = 1;
        do {
            node = 2*root+1;
            if (node<i-1 && arr[node] < arr[node+1]) {
                node++;
            }
            if (node<i && arr[root] < arr[node]) {
                temp = arr[root];
                arr[root] = arr[node];
                arr[node] = temp;
            }
            root = node;
        } while (node < i);
    }


    printf("Heap Sort: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}