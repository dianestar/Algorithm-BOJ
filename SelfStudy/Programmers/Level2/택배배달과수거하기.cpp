#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<int> stDeliveries;
    stack<int> stPickups;
    for (int i=0; i<n; i++) {
        for (int j=0; j<deliveries[i]; j++) stDeliveries.push(i+1);
        for (int j=0; j<pickups[i]; j++) stPickups.push(i+1);
    }
    
    while (1) {
        if (stDeliveries.empty() && stPickups.empty()) break;
        
        int deliveryDist = 0;
        if (!stDeliveries.empty()) {
            deliveryDist = stDeliveries.top();
            
            for (int i=0; i<cap; i++) {
                if (stDeliveries.empty()) break;
                stDeliveries.pop();
            }
        }
        
        int pickupDist = 0;
        if (!stPickups.empty()) {
            pickupDist = stPickups.top();
            
            for (int i=0; i<cap; i++) {
                if (stPickups.empty()) break;
                stPickups.pop();
            }
        }
        
        answer += 2 * max(deliveryDist, pickupDist);
    }
    
    return answer;
}