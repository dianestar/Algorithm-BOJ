#include <iostream>
#include <vector>
using namespace std;

int checkStr(string str, int i, int j, bool chance) {
    while (i < j) {
        if (str[i] == str[j]) {
            i++;
            j--;
            continue;
        }

        // 그 자체로 회문은 아닌 경우 + 한 문자 삭제할 수 있는 기회 있는 경우
        if (chance) {
            // 유사회문인 경우
            if (checkStr(str, i+1, j, false) == 0 || checkStr(str, i, j-1, false) == 0) {
                return 1;
            }
            // 회문도 유사회문도 아닌경우
            return 2;
        }

        // 그 자체로 회문은 아닌 경우 + 한 문자 삭제할 수 있는 기회 없는 경우
        // 회문도 유사회문도 아닌 경우
        return 2;
    }

    // 회문인 경우
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        char ch[100001];
        scanf("%s", ch);
        string str = ch;
        int endIdx = str.size()-1;
        printf("%d\n", checkStr(str, 0, endIdx, true));
    }

    return 0;
}