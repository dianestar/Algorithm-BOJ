#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_IDX 16

int L, C;
char ch;
vector<char> characters;
vector<int> isSelected(MAX_IDX);

void dfs(int index, int total, int vowel, int consonant) {
    if (total == L) {
        // 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
        if (vowel >= 1 && consonant >= 2) {
            for (int i=0; i<C; i++) {
                if (isSelected[i]) printf("%c", characters[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i=index; i<C; i++) {
        if (isSelected[i]) continue;

        isSelected[i] = 1;
        if (characters[i] == 'a' || characters[i] == 'e' || characters[i] == 'i' || characters[i] == 'o' || characters[i] == 'u') dfs(i, total + 1, vowel + 1, consonant);
        else dfs(i, total + 1, vowel, consonant + 1);
        isSelected[i] = 0;
    }
}

int main() {
    scanf("%d %d", &L, &C);

    for (int i=0; i<C; i++) {
        scanf(" %c", &ch);
        characters.push_back(ch);
    }

    // 암호는 서로 다른 L개의 알파벳 소문자들로 구성 + 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열
    // -> 알파벳 순서로 정렬 후에 조합으로 L개 선택
    sort(characters.begin(), characters.end());
    dfs(0, 0, 0, 0);

    return 0;
}