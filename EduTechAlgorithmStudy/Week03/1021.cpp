#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    deque<int> dq;
    for (int i=1; i<=N; i++) {
        dq.push_back(i);
    }

    int num;
    int idx;
    int count=0;
    for (int i=0; i<M; i++) {
        scanf("%d", &num);

        for (int j=0; j<dq.size(); j++) {
            if (dq[j]==num) {
                idx=j;
                break;
            }
        }
        
        if (idx<(dq.size()-idx)) {
            while (1) {
                if (dq.front()==num) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }   
        }
        else {
            while (1) {
                if (dq.front()==num) {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}