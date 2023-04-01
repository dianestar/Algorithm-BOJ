#include <iostream>
#include <vector>
using namespace std;

#define TREE_SIZE (1024 * 1024 * 2 + 1)

int N, M, K, offset;
vector<long long> numbers;
vector<long long> tree(TREE_SIZE, 0);

void init() {
    for (offset=1; offset<N; offset*=2);
    
    for (int i=0; i<N; i++) tree[i + offset] = numbers[i];
    for (int i=offset-1; i>=1; i--) tree[i] = tree[i*2] + tree[i*2+1];
}

void update(int idx, long long val) {
    idx += offset;
    tree[idx] = val;
    
    while (idx) {
        idx /= 2;
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    }
}

long long query(int left, int right) {
    left += offset;
    right += offset;
    long long ret = 0;
    
    while (left <= right) {
        // 왼쪽 끝 범위가 홀수일 경우
        if (left % 2 == 1) ret += tree[left++];
        // 오른쪽 끝 범위가 짝수일 경우
        if (right % 2 == 0) ret += tree[right--];

        left /= 2;
        right /= 2;
    }

    return ret;   
}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    long long number;
    for (int i=0; i<N; i++) {
        scanf("%lld", &number);
        numbers.push_back(number);
    }

    // 인덱스드 트리 구성
    init();

    long long a, b, c;
    for (int i=0; i<M+K; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == 1) {
            // b번째 수를 c로 바꾸기
            update(b-1, c);
        }
        else {
            // b번째 수부터 c번째 수까지의 합을 구하여 출력하기
            printf("%lld\n", query(b-1, c-1));
        }
    }

    return 0;
}