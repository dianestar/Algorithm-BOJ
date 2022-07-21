#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int durability;
    deque<pair<int, bool>> belt; // {내구도, 로봇여부}
    for (int i=0; i<2*N; i++) {
        scanf("%d", &durability);
        belt.push_back({durability, false});
    }

    int answer = 1;
    while (1) {
        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        belt.push_front(belt.back());
        belt.pop_back();
        // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
        belt[N-1].second = false;

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
        for (auto iter=belt.begin()+N-1; iter>=belt.begin(); iter--) {
            // 2-1. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
            if (iter->second == true && (iter+1)->first > 0 && (iter+1)->second == false) {
                // 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
                (iter+1)->first--;
                (iter+1)->second = true;
                iter->second = false;
            }
        }
        // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
        belt[N-1].second = false;

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (belt.front().first > 0 && belt.front().second == false) {
            // 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
            belt.front().first--;
            belt.front().second = true;
        }

        // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 
        int count = 0;
        for (auto iter=belt.begin(); iter!=belt.end(); iter++) {
            if (iter->first == 0) { count++; }
        }
        if (count >= K) { break; }

        answer++;
    }

    printf("%d\n", answer);

    return 0;
}