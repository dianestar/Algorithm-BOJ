#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;
    for (int i=0; i<N; i++) {
        char str[101];
        scanf("%s", str);

        int alphabet[26] = {0,};
        int isGroupWord = 1;
        for (int i=0; i<strlen(str); i++) {
            if (alphabet[str[i]-'a']==0) {
                alphabet[str[i]-'a'] = 1;
                int tmp=i;
                while (str[i+1]==str[tmp]) {
                    i++;
                }
            }
            else { isGroupWord =0; }
        }

        if (isGroupWord) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}