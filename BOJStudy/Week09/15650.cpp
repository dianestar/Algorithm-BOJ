#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> numbers;
    for (int i=1; i<=N; i++) {
        numbers.push_back(i);
    }

    vector<int> isSelected;
    for (int i=0; i<M; i++) { isSelected.push_back(0); }
    for (int i=0; i<N-M; i++) { isSelected.push_back(1); }
    do {
        for (int i=0; i<N; i++) {
            if (isSelected[i] == 0) {
                printf("%d ", numbers[i]);
            }
        }
        printf("\n");
    } while (next_permutation(isSelected.begin(), isSelected.end()));

    return 0;
}