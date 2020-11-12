/*요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다.
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include<queue>
using namespace std;

int main()
{
	int N, K;
	queue<int>qu;
	
	cin >> N >> K;	
	for (int i = 1; i <= N; i++) { qu.push(i); } //숫자 넣기
	
	cout << "<";

	while (!qu.empty()) {
		for (int i = 1; i <= K; i++) {
			int tmp = qu.front();
			if (i == K) {
				qu.pop();

				cout << tmp;
				if (!qu.empty()) cout << ", ";
			}
			else { //k번째 숫자가 아니라면 임시 변수 tmp에 저장된 값을 pop한 다음, 다시 push해줘서 큐의 뒤로 보낸다
				qu.pop();
				qu.push(tmp);
			}
		}
	}
	cout << ">";
	}
 
