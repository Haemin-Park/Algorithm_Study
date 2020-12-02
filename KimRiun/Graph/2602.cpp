/* 무방향 그래프 2차원 배열
깊이 탐색 이용
1번과 연결된 노드들은 connect 배열에 1로 표시
 */


#include <iostream>
#include <stack>
using namespace std;


int n, d, answer = 0; // 노드 개수
int matrix[101][101];
bool connect[101];

void dfs(int v) {
	if (connect[v] == 1) {
		return;
	}

	connect[v] = 1;

	for (int i = 2; i <= n; i++) {
		
		if (matrix[v][i] == 1) {
			dfs(i);
			
		}
	}

	return;
}


int main(void) {

	cin >> n >> d;


	int num1, num2;

	for (int i = 0; i < d; i++) {
		cin >> num1 >> num2;
		matrix[num1][num2] = 1;
		matrix[num2][num1] = 1;

	}

	

	for (int i = 1; i <= n; i++) {
		if (matrix[1][i] == 1) {
			dfs(i);
		}

	}



	for (int i = 1; i <= n; i++) {
		if (connect[i] == 1)
			answer++;
	}

	
	cout << answer;

	return 0;

}
