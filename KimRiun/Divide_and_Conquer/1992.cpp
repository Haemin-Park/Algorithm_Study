// 쿼드트리 QuadTree : 자식 노드가 4개인 트리 구조
// 흑백영상 압축하기
// https://www.acmicpc.net/problem/1992

#include <iostream>
using namespace std;

#define MAX_SIZE 64

char image[MAX_SIZE][MAX_SIZE]; // 최대 크기 64x64
int n; // 영상의 한 변의 길이


// 쿼드트리 구조를 가진 흑백영상을 압축하는 함수
void compress(int y, int x, int size) {
	
	/*(y, x) : 시작 좌표
	  (dy, dx) : 현재 좌표*/
	
	for (int dy = y; dy < y + size; dy++) {
		for (int dx = x; dx < x + size; dx++) {
			
			// 전부 같은 색이 아니라면
			if (image[dy][dx] != image[y][x]) {

				int half = size / 2;
				
				cout << "(";
				compress(y, x, half); // 왼쪽위
				compress(y, x + half, half); // 오른쪽위
				compress(y + half, x, half); // 왼쪽아래
				compress(y + half, x + half, half); // 오른쪽아래
				cout << ")";

				/* NOTE! return 없으면 한 번 1/4하면서 재귀했는데 이후에 (y,x)와 색이 다른 칸에서 또다시 같은 재귀를 반복함. */
				return; 
			}
			

		}
	}

	// 전부 같은 색일 때 검사
	cout << image[y][x];
	
}

int main() {
	// 영상의 한 변의 길이 n 입력
	cin >> n;
	
	// 영상 모양 입력 ('0':흰색 또는 '1':검은색 으로 구성된 형태)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> image[i][j];
		}
		
	}
	
	//// 영상 압축 및 출력
	compress(0, 0, n);


	return 0;
}

// correct: 1992
