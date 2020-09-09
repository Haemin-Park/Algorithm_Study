#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, tmp;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";

	while (!q.empty()) {
		for (int i = 1; i <= k; i++) {
			
			tmp = q.front();
			
			q.pop();

			if (i == k) {
				cout << tmp;
				if (!q.empty()) cout << ", ";
			}
			else
				q.push(tmp);
		
		}
	}
	cout << ">";
}