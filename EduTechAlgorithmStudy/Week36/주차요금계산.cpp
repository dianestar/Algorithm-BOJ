#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

int convertTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return 60 * hour + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    unordered_map<string, string> inCars; // {차량변호, 입차시간}
    map<string, int> totalTimes; // {차량번호, 누적주차시간} 
    for (int i=0; i<records.size(); i++) {
        string time = records[i].substr(0, 5);
        string id = records[i].substr(6, 4);
        string direction = records[i].substr(11);
        
        if (direction == "IN") {
            inCars[id] = time;
        }
        
        else {
            int outTime = convertTime(time);
            int inTime = convertTime(inCars[id]);
            totalTimes[id] += (outTime - inTime);
            inCars[id] = "out"; // 출차 완료 표시
        }
    }
    
    // 어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
    int outTime = convertTime("23:59");
    for (auto iter=inCars.begin(); iter!=inCars.end(); iter++) {
        if (iter->second != "out") {
            int inTime = convertTime(iter->second);
            totalTimes[iter->first] += (outTime - inTime);
        }
    }
    
    // 00:00부터 23:59까지의 입/출차 내역을 바탕으로 차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산합니다.
    for (auto iter=totalTimes.begin(); iter!=totalTimes.end(); iter++) {
        // 누적 주차 시간이 기본 시간이하라면, 기본 요금을 청구합니다.
        if (iter->second <= defaultTime) {
            answer.push_back(defaultFee);
        }
        // 누적 주차 시간이 기본 시간을 초과하면, 기본 요금에 더해서, 초과한 시간에 대해서 단위 시간 마다 단위 요금을 청구합니다.
        // 초과한 시간이 단위 시간으로 나누어 떨어지지 않으면, 올림합니다.
        else {
            answer.push_back(defaultFee + ceil((double)(iter->second - defaultTime) / unitTime) * unitFee);
        }
        
    }
    
    return answer;
}

int main() {
    vector<vector<int>> fees = {
        {180, 5000, 10, 600},
        {120, 0, 60, 591},
        {1, 461, 1, 10}
    };
    vector<vector<string>> records = {
        {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"},
        {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"},
        {"00:00 1234 IN"}
    };

    for (int i=0; i<fees.size(); i++) {
        vector<int> answer = solution(fees[i], records[i]);

        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}