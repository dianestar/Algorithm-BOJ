#include <iostream>
#include <vector>
using namespace std;

vector<int> id(31, 0);

int main() {
    int n;
    for (int i=0; i<28; i++) {
        scanf("%d", &n);
        id[n] = 1;
    }

    for (int i=1; i<=30; i++) {
        if (!id[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}