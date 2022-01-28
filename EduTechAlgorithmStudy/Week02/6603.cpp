#include <stdio.h>

int k;
int numList[13];
int printYes[13]; // Yes:1 , No:0

void lotto(int n, int level) {
    if (level==6) {
        for (int i=0; i<k; i++) {
            if (printYes[i]) {
                printf("%d ", numList[i]);
            }
        }
        printf("\n");

        return;
    }

    for (int i=n; i<k; i++) {
        printYes[i] = 1;
        lotto(i+1, level+1);
        printYes[i] = 0;
    }
}

int main() {
    while (1) {
        scanf("%d", &k);

        if (k==0) { break; }

        for (int i=0; i<k; i++) {
            scanf("%d", &numList[i]);
        }

        lotto(0, 0);
        printf("\n");
    }

    return 0;
}