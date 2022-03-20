#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    unordered_map<int, int> m;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        m[num] = 1;
    }

    int M;
    scanf("%d", &M);
    
    vector<int> answers;
    for (int i=0; i<M; i++) {
        scanf("%d", &num);
        answers.push_back(m[num]);
    }

    for (int i=0; i<M; i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}