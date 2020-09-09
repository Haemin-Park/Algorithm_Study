#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321;
string board[50]; //입력받을 판

//Brute-force: 무차별적으로 대입해본다
//문제에서 힌트 주었다: (0,0)이 w or b인 경우밖에 없다

string whiteBoard[8] = { //(0,0)이 white인 경우
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

string blackBoard[8] = { //(0,0)이 black인 경우
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

int white(int y, int x) {
	int cnt = 0;

	for (int i = y; i<y+8; i++) {
		for (int j = x; j<x+8; j++) {
			if (whiteBoard[i-y][j-x] != board[i][j]) //문자열 비교
				cnt++;
		}
	}

	return cnt;
}

int black(int y, int x) {
	int cnt = 0;

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (blackBoard[i - y][j - x] != board[i][j]) //문자열 비교
				cnt++;
		}
	}

	return cnt;
}

int main() {
	int m, n;
	cin >> n >> m;

	//문자열로 입력받을 것임->입력받을 배열은 1차원으로 생각해도 된다
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int answer = INF;

	//직접 다 계산해본다(n,m이 최대 50까지이기 때문에 가능)
	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			answer = min(answer, min(white(i, j), black(i, j))); //최솟값 찾기
		}
	}

	cout << answer;
}
