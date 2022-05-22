#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string car;
    queue<string> in;
    for (int i=0; i<N; i++) {
        cin >> car;
        in.push(car);
    }
    
    vector<string> out;
    for (int i=0; i<N; i++) {
        cin >> car;
        out.push_back(car);
    }

    int idx = 0;
    int answer = 0;
    unordered_map<string, int> finished;
    while (!in.empty() && idx < N) {
        if (in.front() == out[idx]) {
            finished[out[idx]] = 1;
            in.pop();
            idx++;
        }
        else {
            if (finished[in.front()]) {
                in.pop();
            }
            else {
                finished[out[idx]] = 1;
                idx++;
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}