#include <iostream>

int main() {
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF) {
        int totalChicken = n;
        int stamp = n;

        while (stamp >= k) {
            int coupon = stamp / k;
            totalChicken += coupon;
            stamp %= k;
            stamp += coupon;
        }

        printf("%d\n", totalChicken);
    }

    return 0;
}