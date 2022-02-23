#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> waiting_queue;
    for (int i=0; i<truck_weights.size(); i++) {
        waiting_queue.push(truck_weights[i]);
    }
    
    queue<int> current_bridge;
    int current_weight = 0;
    while (!waiting_queue.empty()) {
        if (current_weight+waiting_queue.front() <= weight) {
            current_weight += waiting_queue.front();
            current_bridge.push(waiting_queue.front());
            waiting_queue.pop();
        }
        else {
            current_bridge.push(0);
        }
        
        answer++;
        
        if (current_bridge.size() >= bridge_length) {
            current_weight -= current_bridge.front();
            current_bridge.pop();
        }
    }
    
    answer += bridge_length;
    
    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    printf("%d", solution(bridge_length, weight, truck_weights));

    return 0;
}