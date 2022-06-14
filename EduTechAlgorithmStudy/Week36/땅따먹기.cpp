#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(int a, int b, int c) {
    return max(max(a, b), c);
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    int row = land.size();
    for (int i=1; i<row; i++) {
        land[i][0] += getMax(land[i-1][1], land[i-1][2], land[i-1][3]);
        land[i][1] += getMax(land[i-1][0], land[i-1][2], land[i-1][3]);
        land[i][2] += getMax(land[i-1][0], land[i-1][1], land[i-1][3]);
        land[i][3] += getMax(land[i-1][0], land[i-1][1], land[i-1][2]);
    }
    
    for (int i=0; i<4; i++) {
        answer = max(answer, land[row-1][i]);
    }
    
    return answer;
}

int main() {
    vector<vector<int>> land = {{1,2,3,5}, {5,6,7,8}, {4,3,2,1}};
    printf("%d\n", solution(land));
    
    return 0;
}