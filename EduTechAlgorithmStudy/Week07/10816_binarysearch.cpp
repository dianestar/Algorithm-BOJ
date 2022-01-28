#include <iostream>
#include <algorithm> // sort
using namespace std;

int N, M;
int arr[500000];

int lowerBound(int target) {
    int start = 0;
    int end = N;
    while (end > start) {
        int mid = (start+end)/2;
        if (target <= arr[mid]) { end = mid; }
        else { start = mid+1; }
    }
    return end;
}

int upperBound(int target) {
    int start = 0;
    int end = N;
    while (end > start) {
        int mid = (start+end)/2;
        if (target < arr[mid]) { end = mid; }
        else { start = mid+1; }
    }
    return end;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        int num;
        scanf("%d", &num);
        //printf("%d ", upper_bound(arr, arr+N, num)-lower_bound(arr, arr+N, num));
        printf("%d ", upperBound(num)-lowerBound(num));
    }

    return 0;
}