// 2020-08-31 00:01 시작
// https://www.acmicpc.net/problem/1149
// RGB 거리
// 2020-08-31 01:56 종료
// correct: 1149

/*
감상평: 돌 놓기 문제랑 똑같아서 아이디어가 바로 생각나 쉽게 접근 가능했다.
*/


/* 아이디어

//완전 탐색을 해야겠다...! -> 이걸 완전탐색이라고 부를 수 있나???
돌 놓기 문제랑 비슷하지 않을까??

r이 올 수 있는 경우는.. 앞이 g, b인 경우!

현재, 앞번째..가 있다고 하자.

현재r = min(앞번째가 g인 경우중 최소, 앞번째가 b인 경우중 최소) + r 비용

결국엔, 각 경우가 r일때의 최소 비용, g일때의 최소 비용, b일 때의 최소 비용을 구해야 한다.
-> (n+1)*3 배열에 넣자. 집 번호랑 인덱스랑 같게 하려고 n+1로 하였다.

*/


#include<iostream>
//#include<stdio.h>
#include<algorithm> // min 쓸 때 사용
using namespace std;


int N; // 집 개수
int cost[1001][3]; // 문제에서 주어지는 비용. 집 번호랑 인덱스랑 같게 하려고 로우가 1000+1이다. 컬럼 0 = R, 1 = G, 2 = B
int result[1001][3]; // N번 집까지의 코스트 합. 컬럼 0 = R, 1 = G, 2 = B


int main()
{
	cin.sync_with_stdio(false);
	//cout << endl << "1149 start!!! yeah~~~~" << endl;

	cin >> N;

	for (int houseNum = 1; houseNum < N + 1; houseNum++)
	{
		for (int colorCost = 0; colorCost < 3; colorCost++)
		{
			cin >> cost[houseNum][colorCost];
		}
	}


	// 초기값 작성: 1번 집 정보 작성
	for (int color = 0; color < 3; color++)
	{
		result[1][color] = cost[1][color];
	}

	// 2번 집부터 정보 작성
	for (int house = 2; house < N + 1; house++)
	{
		int beforeR = result[house - 1][0];
		int beforeG = result[house - 1][1];
		int beforeB = result[house - 1][2];

		// 현재 집을 빨간 색으로 칠할 경우
		result[house][0] = min(beforeG, beforeB) + cost[house][0];
		// 현재집 초록
		result[house][1] = min(beforeR, beforeB) + cost[house][1];
		// 현재집 파랑
		result[house][2] = min(beforeG, beforeR) + cost[house][2];
	}


	int resultCost = -1;
	resultCost = min({ result[N][0] , result[N][1], result[N][2] });

	cout << resultCost;
}

