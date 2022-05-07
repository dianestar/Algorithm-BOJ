#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    vector<int> answers;
    for (int i=0; i<T; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        vector<int> aList(A);
        vector<int> bList(B);
        for (int j=0; j<A; j++) {
            scanf("%d", &aList[j]);
        }
        for (int j=0; j<B; j++) {
            scanf("%d", &bList[j]);
        }

        sort(aList.begin(), aList.end());
        sort(bList.begin(), bList.end());

        int answer = 0;
        for (int j=0; j<A; j++) {
            for (int k=0; k<B; k++) {
                if (bList[k] >= aList[j]) { break; }
                else { answer++; }
            }
        }
        answers.push_back(answer);
    }

    for (int i=0; i<T; i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}