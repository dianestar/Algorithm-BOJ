#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int tree;
    int maxH = 0;
    int minH = 0;
    vector<int> trees;
    for (int i=0; i<N; i++) {
        scanf("%d", &tree);
        trees.push_back(tree);
        if (tree > maxH) {
            maxH = tree;
        }
    }

    int answer;
    int midH;
    while (minH <= maxH) {
        midH = (minH + maxH) / 2;

        long long sum = 0;
        for (int i=0; i<N; i++) {
            if (trees[i] > midH) {
                sum += trees[i] - midH;
            }
        }

        if (sum >= M) {
            answer = midH;
            minH = midH + 1;
        }
        else {
            maxH = midH - 1;   
        }
    }

    printf("%d", answer);

    return 0;
}