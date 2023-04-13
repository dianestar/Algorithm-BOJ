#include <string>
#include <vector>

using namespace std;

#define MAX_EMOTICONS 7

int usersLen, emoticonsLen, totalCount, totalMoney;
vector<int> percentages(MAX_EMOTICONS); // 이모티콘 할인율

void purchaseEmoticons(vector<vector<int>> users, vector<int> emoticons) {
    int tempCount = 0;
    int tempMoney = 0;
    
    vector<int> discounted;
    for (int i=0; i<emoticonsLen; i++) {
        discounted.push_back(emoticons[i] * (100 - percentages[i]) / 100);
    }
    
    for (int i=0; i<usersLen; i++) {
        int payment = 0;
        
        // 비율(users[i][0])% 이상의 할인이 있는 이모티콘을 모두 구매
        for (int j=0; j<emoticonsLen; j++) {
            if (percentages[j] >= users[i][0]) payment += discounted[j];
        }
        
        // 가격(users[i][1])이상의 돈을 이모티콘 구매에 사용한다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입
        if (payment >= users[i][1]) tempCount++;
        else tempMoney += payment; 
    }
    
    // 목표 1. 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것
    if (tempCount > totalCount) {
        totalCount = tempCount;
        totalMoney = tempMoney;
    }
    // 목표 2. 이모티콘 판매액을 최대한 늘리는 것
    else if (tempCount == totalCount && tempMoney > totalMoney) {
        totalMoney = tempMoney;
    }
}

void setPercentages(int cnt, vector<vector<int>> users, vector<int> emoticons) {
    if (cnt == emoticonsLen) {
        purchaseEmoticons(users, emoticons);
        return;
    }
    
    // 할인율은 10%, 20%, 30%, 40% 중 하나로 설정
    for (int i=1; i<=4; i++) {
        percentages[cnt] = i * 10;
        setPercentages(cnt + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    usersLen = users.size();
    emoticonsLen = emoticons.size();
    
    // 중복순열로 할인율 설정 후 이모티콘 구입 및 이모티콘 플러스 가입 진행
    // 중복순열 경우의 수 * 최대 users 길이 * 최대 emoticons 길이 = 4^7 * 100 * 7 = 11,468,800
    setPercentages(0, users, emoticons);
    
    // 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액을 1차원 정수 배열에 담아 return
    vector<int> answer = {totalCount, totalMoney};
    return answer;
}