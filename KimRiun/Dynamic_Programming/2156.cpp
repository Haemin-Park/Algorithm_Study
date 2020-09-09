// 포도주 시식
// 3잔을 연속으로 마시지 않으면서 최대로 마실 수 있는 포도주의 양 구하기
// 동적계획법1 https://www.acmicpc.net/problem/2156

#include <iostream>
using namespace std;


int n; // 포도주 잔 개수. 1<= n <=10000
int glass[10001]; // 포도주 양
int cache[10001]; // 누적값

// 3개 중 최대값 찾기
int max(int a, int b, int c) {
	int temp = a > b ? a : b;
	temp = temp > c ? temp : c;
	return temp;
}

void maxWine() {
	
	/* i번째를 마실 경우와 마시지 않을 경우로 나눈다. 둘 중 최대값을 택한다.

		[i-3]		[i-2]		[i-1]		[i]
	(1)		 	  O		  X		 O  
	(2)			  X		  O		 O  => (1),(2) 중 뭐가 더 클지는 비교해봐야 함
	(3)			  X		  X		 O  => 항상 (1),(2)보다 작다. 탈락

	(4)			  O		  O		 X  => 마실 경우와 비교해봐야 함
	(5)			  O		  X		 X  => 항상 (4)보다 작다. 탈락
	(6)			  X		  O		 X  => 항상 (4)보다 작다. 탈락

	이 중 최대값을 선택한다.
	(1): cache[i-2] + glass[i]
	(2): cache[i-3] + glass[i-1] + glass[i]
	(4): cache[i-1]
	

	*/


	//cache의 1, 2번째 자리는 초기화
	cache[1] = glass[1];

	if (n > 1) {
		cache[2] = glass[1] + glass[2];
		
		for (int i = 3; i <= n; i++) {
			/* 3가지 중 최대값 구하기 */
			cache[i] = max(cache[i - 2] + glass[i], cache[i - 3] + glass[i - 1] + glass[i], cache[i - 1]);
			
		}/*i-3까지 인덱스를 고려해야 하므로 i=3부터 시작하도록 한다.*/
	}

	cout << cache[n];
}


int main() {

	// 포도주 잔 개수와 양 입력
	cin >> n;
	for (int i = 1; i <= n; i++) // 0번째 자리는 누적값 계산에서 인덱스 편의를 위해 비어둠
		cin >> glass[i];

	
	// 규칙에 따라 최대로 마실 수 있는 포도주 양 출력
	maxWine(); 
	
	
	return 0;
}

// correct: 2156
