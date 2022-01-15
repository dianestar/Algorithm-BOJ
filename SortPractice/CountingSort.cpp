#include <iostream>
using namespace std;

int main() {
    int temp;
    int count[6] = {0, };
    int arr[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
                    3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
                    3, 1, 4, 3, 5, 1, 2, 1, 1, 1};

    for (int i=0; i<30; i++) {
        count[arr[i]]++;
    }

    for (int i=1; i<=5; i++) {
        while (count[i] != 0) {
            printf("%d ", i);
            count[i]--;
        }
    }

    return 0;
}