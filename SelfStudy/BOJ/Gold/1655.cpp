#include <iostream>
#include <queue>

using namespace std;

vector<int> answers;

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<int> maxHeap; // 중간값보다 작거나 같은 값들 모음
	priority_queue<int, vector<int>, greater<int>> minHeap; // 중간값보다 큰 값들 모음
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		// cf. 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
		// maxHeap.size()는 minHeap.size()와 같거나 1만큼 큼
		if (maxHeap.size() > minHeap.size()) minHeap.push(num);
		else maxHeap.push(num);

		
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			/* 아래 코드를 if문 밖으로 뺄 경우 queue가 비어 있는 경우 에러 발생 */
			int maxTop = maxHeap.top();
			int minTop = minHeap.top();
			/*                                                                  */

			/* maxHeap과 minHeap의 유지 조건을 충족하기 위해
		   maxHeap에 minHeap에 있는 값 보다 큰 값이 들어가 있는 경우 swap */
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		printf("%d\n", maxHeap.top());
	} 

	return 0;
}