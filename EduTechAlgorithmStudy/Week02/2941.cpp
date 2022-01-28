#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    scanf("%s", arr);

    int count = 0;
    for (int i=0; i<strlen(arr); i++) {
        // 이미 count된 알파벳의 이어지는 char에 대해서는 continue
        // 특히 dz=의 경우에는 arr[i]=='d'일 경우 count 후 arr[i]=='z'일 경우와 arr[i]=='='일 경우 두 번 모두 continue
        if (arr[i]=='-' || arr[i]=='=') {
            continue;
        }
        if (i>=1) {
            if ((arr[i]=='j' && arr[i-1]=='l') || (arr[i]=='j' && arr[i-1]=='n')) {
                continue;
            }
            if (i<strlen(arr)-1 && arr[i-1]=='d' && arr[i]=='z' && arr[i+1]=='=') {
                continue;
            }
        }
        count++;
    }

    printf("%d", count);
    
    return 0;
}