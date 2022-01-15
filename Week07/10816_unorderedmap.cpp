#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cards;
int N, M, num;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        cards[num]++;
    }

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &num);
        printf("%d ", cards[num]);
    }

    return 0;
}