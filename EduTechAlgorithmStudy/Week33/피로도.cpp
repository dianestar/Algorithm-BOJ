#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    // dungeons의 세로(행) 길이(즉, 던전의 개수)는 1 이상 8 이하입니다.
    // 8! = 40320 브루트포스 OK
    int answer = -1;
    
    int len = dungeons.size();
    vector<int> index;
    for (int i=0; i<len; i++) { index.push_back(i); }
    
    do {
        int current = k;
        int count = 0;
        for (int i=0; i<len; i++) {
            if (current < dungeons[index[i]][0]) { continue; }
            current -= dungeons[index[i]][1];
            count++;
        }
        answer = max(answer, count);
    } while (next_permutation(index.begin(), index.end()));
    
    return answer;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
    printf("%d", solution(k, dungeons));
    return 0;
}