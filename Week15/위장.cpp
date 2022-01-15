#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m; //{의상의 종류, 개수} 저장
    
    for (int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]]++;
    }
    
    for (auto iter=m.begin(); iter!=m.end(); iter++) {
        answer *= (iter->second + 1); //해당 종류의 의상 중 하나를 고르거나(iter->second) 해당 종류의 의상은 고르지 않는(+1) 경우의 수
    }
    answer -= 1; //어떤 종류의 의상도 고르지 않는 하나의 경우 빼주기 cf) 스파이는 하루에 최소 한 개의 의상은 입는다
    
    return answer;
}

int main() {
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    printf("%d", solution(clothes));
    return 0;
}