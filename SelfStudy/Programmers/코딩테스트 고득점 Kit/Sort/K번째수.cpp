#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int idx=0; idx<commands.size(); idx++) {
        int i = commands[idx][0] - 1;
        int j = commands[idx][1];
        vector<int> temp = {array.begin()+i, array.begin()+j}; // 배열 자르기
        sort(temp.begin(), temp.end()); // 정렬하기
        
        int k = commands[idx][2] - 1;
        answer.push_back(temp[k]); // K.번째 있는 수 구하기
    }
    
    return answer;
}

int main() {
    vector<int> array = {1,5,2,6,3,7,4};
    vector<vector<int>> commands = {{2,5,3}, {4,4,1}, {1,7,3}};

    vector<int> answer = solution(array, commands);

    for (int idx=0; idx<answer.size(); idx++) {
        printf("%d ", answer[idx]);
    }

    return 0;
}