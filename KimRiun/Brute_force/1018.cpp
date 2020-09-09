// 체스판 다시 칠하기 문제 
/* N*M 크기의 격자 보드에서 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
 8*8 크기는 아무데서나 골라도 된다. 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.*/
/* 1. n과 m 그리고 보드 격자 모양을 입력받는다.
   2. 왼쪽위 끝 색이 검은색 패턴인 8x8 사각형을 이동하며 최소 개수를 찾는다.
   3. 왼쪽위 끝 색이 흰색 패턴인 8x8 사각형을 이동하며 최소 개수를 찾는다.
   4. 둘 중 더 작은 값을 출력한다.*/

#include <iostream>
using namespace std;

int n, m; // 체스판 크기


int count(char** b, int color) {
	int count = 0;
	int min = 0;
	bool first = 1;
	
	// black
	if (color == 1) { 
		for (int i = 0; i <= n-8; i++) {
			for (int j = 0; j <= m-8; j++) {	
				// 8x8씩 이동하며 검사
				for (int ii = 0; ii < 8; ii++) {
					for (int jj = 0; jj < 8; jj++) {
						// (짝수,짝수) 또는 (홀수, 홀수)마다 검은색 패턴 반복
						if ( ((i+ii)% 2 == 0 && (j+jj)% 2 == 0) || (((i+ii) % 2 == 1 && (j+jj) % 2 == 1)) ) {
							if (b[i + ii][j + jj] != 'B') count++; // black 검사					
						}
						else
							if (b[i + ii][j + jj] != 'W') count++; // white 검사
						
					}
				}
				
				if (first) {
					min = count;
					first = 0;
				}
				if (min > count) min = count; // 이전보다 값이 작으면 최소값 변경
				count = 0;
			}
		}
		
		return min;
	}
	// white
	else { 		
		for (int i = 0; i <= n - 8; i++) {
			for (int j = 0; j <= m - 8; j++) {
				// 8x8씩 이동하며 검사
				for (int ii = 0; ii < 8; ii++) {
					for (int jj = 0; jj < 8; jj++) {
						// (짝수,짝수) 또는 (홀수, 홀수)마다 흰색 패턴 반복
						if (((i + ii) % 2 == 0 && (j + jj) % 2 == 0) || (((i + ii) % 2 == 1 && (j + jj) % 2 == 1))) {
							if (b[i + ii][j + jj] != 'W')	count++; // white 검사					
						}
						else
							if (b[i + ii][j + jj] != 'B')	count++; // black 검사
						
					}
				}
				if (first) {
					min = count;	
					first = 0;
				}
				if (min > count) min = count; // 이전보다 값이 작으면 최소값 변경
				count = 0;
			}
		}
		
		return min;
	}

}



int main() {
	// n x m 크기의 체스판
	cin >> n >> m;

	// n x m 크기의 2차원 배열 동적할당 
	char** board = new char*[n];
	for (int i = 0; i < n; i++)
		board[i] = new char[m];

	// 체스판 모양 입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];


	
	//// 체스판에서 새로 칠해야할 칸의 최소 수
	// 왼쪽위 색이 black으로 칠해진다면
	int black=0;
	black = count(board, 1);
	
	// 왼쪽위 색이 white로 칠해진다면
	int white=0;
	white = count(board, 2);
	
	// 두 경우 중 더 작은 칸의 갯수 출력
	if (white < black)
		cout << white;
	else
		cout << black;

	return 0;
	
}

// correct: 1018
