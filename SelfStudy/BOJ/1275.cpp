#include <iostream>
#include <vector>

using namespace std;

#define TREE_SIZE (1024 * 1024 * 2)

int N, Q, offset;
vector<int> numbers;
vector<long long> tree(TREE_SIZE);

void init() {
    for (offset=1; offset<N; offset*=2);
    for (int i=0; i<N; i++) tree[i+offset] = numbers[i];
    for (int i=offset-1; i>=1; i--) tree[i] = tree[i*2] + tree[i*2+1];
}

long long query(int left, int right) {
    left += offset;
    right += offset;
    long long ret = 0;

    while (left <= right) {
        if (left % 2 == 1) ret += tree[left++];
        if (right % 2 == 0) ret += tree[right--];

        left /= 2;
        right /= 2;
    }

    return ret;
}

void update(int idx, int val) {
    idx += offset;
    tree[idx] = val;

    while (idx) {
        idx /= 2;
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    }
}

int main() {
    scanf("%d %d", &N, &Q);

    int number;
    for (int i=0; i<N; i++) {
        scanf("%d", &number);
        numbers.push_back(number);
    }

    // 인덱스드 트리 초기화
    init();

    int x, y, a, b;
    for (int i=0; i<Q; i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);

        // x~y번째 수의 합 구하기
        if (x <= y) printf("%lld\n", query(x-1, y-1));
        else printf("%lld\n", query(y-1, x-1));

        // a번째 수를 b로 고치기
        update(a-1, b);
    }

    return 0;
}