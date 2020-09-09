/* Z문제
2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다.
예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.*/
// https://www.acmicpc.net/problem/1074

#include <iostream>
using namespace std;

int n, r, c; // 2^n x 2^n 크기 2차원 배열, (r, c) 방문 순서를 알고자 함
int Count;


// 쿼드트리 구조로 (r, c)가 몇 번째인지 탐색하는 함수
void QuadTree_Z(int y, int x, int size) {

	/* (y, x)를 시작점으로 size x size 크기의 2차원 배열을 4등분으로 나누었을 때,
	(r, c)가 속하는 사분면을 다시 4등분하며 재귀적으로 반복한다.
	모든 사분면을 다 탐색하지 않고 오직 (r, c)가 속하는 사분면만 탐색하므로써 비용을 줄일 수 있다.
	예를 들어, 오른쪽 아래에 속하면 오른쪽 아래를 다시 4등분하고 시작점은 오른쪽 아래 첫 좌표이다.*/

	if (y == r && x == c) { // 기저 사례 : 시작점이 (r, c)의 위치와 같다.
		cout << Count << endl;
		return;
	}
	else { // (r, c)가 몇 사분면에 속하는지 조사

		int half = size / 2;
		int quarter = half * half; // 4등분된 조각 하나의 크기

		if (r < y + half && c < x + half) { // 왼쪽위
			QuadTree_Z(y, x, half);
		}
		else if (r < y + half && c >= x + half) { //오른쪽위
			Count += quarter; // 왼쪽위 칸 개수 더함
			QuadTree_Z(y, x + half, half);
		}
		else if (r >= y + half && c < x + half) { //왼쪽아래
			Count += quarter * 2; // 왼쪽위 와 오른쪽위 칸 개수 더함
			QuadTree_Z(y + half, x, half);
		}
		else if (r >= y + half && c >= x + half) { //오른쪽아래
			Count += quarter * 3; // 왼쪽위, 오른쪽위, 왼쪽아래 칸 개수 더함
			QuadTree_Z(y + half, x + half, half);
		}
	}


}

int main() {
	// n, r, c 입력
	cin >> n >> r >> c;

	// 2의 거듭제곱 계산: 2^n
	int size = 1;
	for (int i = 0; i < n; i++) {
		size *= 2;
	}  // NOTE! size = size << n; 로 for문 대신 << 연산자로도 가능


	//// z모양으로 (r, c)가 몇 번째인지 탐색
	QuadTree_Z(0, 0, size);

	return 0;
}

// correct: 1017
