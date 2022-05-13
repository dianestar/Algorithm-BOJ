#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    int move = 0;
    int line, flat;
    vector<stack<int>> guitar(7);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &line, &flat);

        while (!guitar[line].empty() && guitar[line].top() > flat) {
            guitar[line].pop();
            move++;
        }

        if (!guitar[line].empty() && guitar[line].top() == flat) {
            continue;
        }

        guitar[line].push(flat);
        move++;   
    }

    printf("%d", move);

    return 0;
}