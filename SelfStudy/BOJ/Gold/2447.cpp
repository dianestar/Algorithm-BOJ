#include <iostream>

using namespace std;

void drawPattern(int n, int r, int c) {
    int divided = n / 3;

    if (divided == 0) cout << '*';
    else if (r / divided % 3 == 1 && c / divided % 3== 1) cout << ' ';
    else drawPattern(divided, r, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            drawPattern(N, i, j);
        }
        cout << "\n";
    }

    return 0;
}