#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> arr;
    int t;
    for (int i=0; i<N; i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += arr[i] * (N-i);
    }

    printf("%d", sum);

    return 0;
}