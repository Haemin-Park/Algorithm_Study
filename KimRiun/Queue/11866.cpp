//요페푸스 문제 0
// N명의 사람이 원을 이루면서 앉아있고 순서대로 K번째 사람을 제거한다. 모두 제거할 때까지 반복한다.
// https://www.acmicpc.net/problem/11866
#include <iostream>
#include <queue>
using namespace std;



int main() {
	
	
	int n, k;
	queue<int> q;
	bool first = 1;

	// 입력: n명, k번째
	cin >> n >> k;
	

	//// 요세푸스 
	/* 포인터를 k씩 옮기는 것이 아닌, 사람을 움직인다. 
	k-1번 앞 사람을 뒤로 옮긴 뒤, 맨 앞 사람을 제거한다. 이를 2명이 남을 때까지 반복한다.
	남은 2명 중 k가 홀수면 마찬가지로 맨 앞 사람을 제거하고, 짝수면 두번째 사람을 제거한다.*/

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	if (q.size() == 1) {
		cout << q.front();
	}
	else if (q.size() == 2) {
		
		if (k % 2 == 0) { // 짝수면 두번째 사람이 제거되므로 순서 바꿈
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();
		cout << ", " << q.front();

		
	}
	else {
		
		while (q.size() > 2) {

			for (int i = 0; i < k - 1; i++) {
				q.push(q.front());
				q.pop();
			}

			if (first) { cout << q.front();	first = 0; }
			else cout << ", " << q.front();

			q.pop();
		}

		if (k % 2 == 0) { // 짝수면 두번째 사람이 제거되므로 순서 바꿈
			q.push(q.front());
			q.pop();
		}

		cout << ", " << q.front();
		q.pop();
		cout << ", " << q.front();

	}
	cout << ">";

	return 0;
}