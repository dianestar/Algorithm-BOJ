#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, num, x;
    vector<int> v;

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }
    scanf("%d", &x);

    sort(v.begin(), v.end());

    int left = 0, right = n-1, count = 0, sum;

    while (left < right) {
        sum = v[left] + v[right];
        if (sum == x) {
            count++;
            left++;
            right--;
        }
        else if (sum > x) {
            right--;
        }
        else {
            left++;
        }
    }

    printf("%d", count);

    return 0;
}