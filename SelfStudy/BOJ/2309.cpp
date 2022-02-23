#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heightList;
    int height, sum = 0;

    // 입력
    for (int i=0; i<9; i++) {
        scanf("%d", &height);
        heightList.push_back(height);
        sum += height;
    }

    // 일곱 난쟁이 찾기
    // cf) 일곱 난쟁이의 키의 합이 100
    for (int i=0; i<8; i++) {
        for (int j=i+1; j<9; j++) {
            if (sum - (heightList[i] + heightList[j]) == 100) {
                heightList.erase(heightList.begin() + i);
                heightList.erase(heightList.begin() + j - 1);
                break;
            }
        }
        if (heightList.size() == 7) {
            break;
        }
    }

    // cf) 일곱 난쟁이의 키를 오름차순으로 출력한다.
    sort(heightList.begin(), heightList.end());
    for (int i=0; i<heightList.size(); i++) {
        printf("%d\n", heightList[i]);
    }

    return 0;
}