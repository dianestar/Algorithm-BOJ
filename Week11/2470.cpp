#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N;
    scanf("%d", &N);

    int num;
    vector<int> v;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int tempSum;
    int bestSum = 2000000000;
    int tempX = 0, tempY = N-1;
    int bestX, bestY;

    while (tempX < tempY) {
        tempSum = v[tempX] + v[tempY];

        if (abs(tempSum) < bestSum) {
            bestSum = abs(tempSum);
            bestX = tempX;
            bestY = tempY;
        }

        if (tempSum < 0) {
            tempX++;
        }
        else {
            tempY--;
        }
    }

    printf("%d %d", v[bestX], v[bestY]);

    return 0;
}