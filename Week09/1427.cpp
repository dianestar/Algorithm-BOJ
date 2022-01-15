#include <iostream>
#include <cstring>
using namespace std;

void quickSort(char* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= arr[pivot]) { left++; }
        while (right > start && arr[right] >= arr[pivot]) { right--; }
        if (left <= right) {
            //idx sequence: pivot left(bigger) right(smaller)
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    //idx sequence: pivot right(smaller) left(bigger)
    int temp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = temp;

    quickSort(arr, start, right-1); // range smaller than pivot
    quickSort(arr, right+1, end); // range bigger than pivot
}

int main() {
    char input[11]; // 0 < N <= 1000000000
    scanf("%s", input);

    int endIdx = strlen(input)-1;
    quickSort(input, 0, endIdx);

    for (int i=endIdx; i>=0; i--) {
        printf("%d", input[i]-'0');
    }

    return 0;
}