#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string str;
	map<string, bool> record;
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "ENTER") {
			count += record.size();
			record.clear();
		}
		else {
			record[str] = true;
		}
	}
	count += record.size();

	cout << count;

	return 0;
}