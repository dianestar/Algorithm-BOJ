#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int N, totalCount;
map<int, pair<int, int>> likes; // 학생 번호: {추천 횟수, 게시 시점}
vector<int> answers;

void checkMap() {
    int target;
    int minLikes = INT_MAX;
    int minDate = INT_MAX;

    for (auto iter=likes.begin(); iter!=likes.end(); iter++) {
        if (iter->second.first == 0) continue;

        // 비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 그 자리에 새롭게 추천받은 학생의 사진을 게시한다.
        // 이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
        if (iter->second.first < minLikes || iter->second.first == minLikes && iter->second.second < minDate) {
            target = iter->first;
            minLikes = iter->second.first;
            minDate = iter->second.second;
        }
    }

    // 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
    likes.erase(target);
}

int main() {
    scanf("%d %d", &N, &totalCount);

    int id;
    // worst case 복잡도 1,000 * 20 = 20,000 OK
    for (int i=0; i<totalCount; i++) { // 총 추천 횟수는 1,000번 이하
        scanf("%d", &id);
    
        // checkMap은 likes 맵을 한 번 순회하는 함수, likes 맵의 최대 크기는 사진틀의 개수인 N (1 <= N <= 20)
        if (likes.size() >= N && likes[id].first == 0) checkMap();

        // 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
        if (likes[id].first == 0) likes[id] = {1, i};

        // 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
        else likes[id].first++;
    }

    for (auto iter=likes.begin(); iter!=likes.end(); iter++) {
        if (iter->second.first != 0) answers.push_back(iter->first);
    }
    sort(answers.begin(), answers.end());

    // 사진틀에 사진이 게재된 최종 후보의 학생 번호를 증가하는 순서대로 출력한다.
    // 사진틀 개수보다 추천된 후보 수가 적을 수도 있음에 주의!
    for (int i=0; i<answers.size(); i++) {
        printf("%d ", answers[i]);
    }

    return 0;
}