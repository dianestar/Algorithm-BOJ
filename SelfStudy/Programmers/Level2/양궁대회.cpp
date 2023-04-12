#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 11

int N, maxDiff;
vector<int> apeach(MAX_LEN);
vector<int> arrows(MAX_LEN);
vector<int> answer = {-1};

void calculateScore() {
    vector<int> ryan(MAX_LEN);
    for (int i=0; i<N; i++) {
        ryan[arrows[i]]++;
    }

    int ryanScore = 0;
    int apeachScore = 0;
    for (int i=0; i<=10; i++) {
        if (ryan[i] > apeach[i]) ryanScore += i;
        else if (apeach[i]) apeachScore += i;
    }

    int diff = ryanScore - apeachScore;
    if (diff > maxDiff) {
        maxDiff = diff;
        reverse(ryan.begin(), ryan.end());
        answer = ryan;
    }
}

void dfs(int cnt, int idx) {
    if (cnt == N) {
        calculateScore();
        return;
    }
    
    for (int i=idx; i<=10; i++) {
        arrows[cnt] = i;
        dfs(cnt + 1, i);
    }
}

vector<int> solution(int n, vector<int> info) {    
    N = n;
    for (int i=0; i<=10; i++) {
        apeach[i] = info[10 - i];
    }
    
    // 중복조합 11H10 = 184,756
    // 브루트포스 가능!
    dfs(0, 0);

    return answer;
}

int main() {
    vector<int> n = {5, 1, 9, 10};
    vector<vector<int>> info = {
        {2,1,1,1,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,2,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,3,4,3}
    };

    for (int i=0; i<n.size(); i++) {
        maxDiff = 0;
        arrows.clear();
        answer = {-1};

        vector<int> answer = solution(n[i], info[i]);
        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}