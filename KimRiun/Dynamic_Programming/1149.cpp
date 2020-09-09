// RGB거리
// 동적계획법1 https://www.acmicpc.net/problem/1149
/* 어떤 문제와 같을까? 행렬의 최단경로 문제
첫번째 행부터 마지막 행까지 최단경로 합 구하기. (행:집 번호, 열: RGB 비용)
규칙: i번째 행의 열은 i-1번째 행의 열과 같지 않아야 한다.*/
#include <iostream>
using namespace std;

int house[1000][3]; // row: 허용 가능한 집 개수, col: RGB 각각의 비용
int n; // 집 개수 입력
int cache[1000][3]; // 누적테이블. Memorization



// 둘 중에 작은 수를 반환하는 함수
int min(int a, int b) {
	return a < b ? a : b;
}

// 규칙에 따라 색을 칠할 경우 최소 비용 구하는 함수
void minCost() {
	
	// cache 첫번째 행을 house의 첫번째 행으로 초기화
	for (int i = 0; i < 3; i++)
		cache[0][i] = house[0][i];

	// Memorization 으로 누적 비용 구하기
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {

			// 현재 열과 중복되지 않은 이전 행의 열 중에서 최소 누적값을 구함
			int minValue = min(cache[i - 1][(j + 1) % 3], cache[i - 1][(j + 2) % 3]); 
			
			// 누적테이블을 갱신
			cache[i][j] = house[i][j] + minValue; 
			
		}

	}
	
	// 최소 비용 출력
	int result = min(cache[n-1][0], cache[n-1][1]);
	result = min(result, cache[n-1][2]); 
	
	cout << result;
	
}

int main() {
	
	// n과 RGB 비용 입력
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}

	// 규칙에 따라 색을 칠할 경우 최소 비용 출력
	minCost();
	
	
	return 0;
}

// correct: 1149
