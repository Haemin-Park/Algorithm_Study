/* 대칭적인 2차원 행렬 이용
우선 쭉 읽어가면서 간선으로 연결되면 1로 표현
1번과 연결된 노드들의 행을 읽어가며 1번에도 1로 표시
1번 행에 1로 표신된 개수 출력
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
