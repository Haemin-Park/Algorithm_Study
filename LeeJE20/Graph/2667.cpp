// 2020-12-02 19:54 시작
// https://www.acmicpc.net/problem/2667
// 단지번호붙이기
// 2020-11-04 21:17 종료
// correct: 2667


/*
느낀점

1. 행렬 입력받을때 %d로 입력받으니 한 줄이 통째로 큰 수로 입력받아졌다. 
	문자열로 하나하나 입력받아야 한다.

2. 문자열로 하나하나 입력받을 때 개행 부분은 따로 잡아먹게 해야 한다.

3. 분리된 두 개 이상의 부분 그래프가 있을 때, 
	부분 그래프의 개수와 각 그래프에 속한 노드의 개수를 구하는 문제이다.

4. 각 노드에 적절한 이름을 붙이는 것이 좋겠다. 
	여기서는 row*N +column으로 하여 행렬의 각 원소들이 고유한 이름을 가질 수 있도록 하였다.
*/


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

// 지도의 크기
int N;

int map[25][25];
vector<int> myGraph[625];
int visited[625];


int groupCount = 0; // 단지 수
int houseCount = 0; // 한 단지 내의 집 수

vector<int> resultCount; // 한 단지 내의 집 수 모음. 얘를 정렬한 뒤 결과 출력


int getName(int i, int j)
{
	return i * N + j;
}


// n: 현재 노드 번호
void dfs(int n)
{
	visited[n] = 1;
	houseCount++;
	for (int i = 0; i < myGraph[n].size(); ++i)
	{
		int link = myGraph[n][i];
		if (visited[link] == 0)
		{
			dfs(link);
		}
	}
}


int main()
{
	scanf("%d", &N);

	//printf("%d", N);

	// 개행 잡아먹기
	char d;
	d = getchar();

	// 지도 채우기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			char data;

			data = getchar();

			int isHouse = 0;
			if (data == '1')
				isHouse = 1;
			map[i][j] = isHouse;

		}
		// 개행 잡아먹기
		d = getchar();
	}

	//// 지도 출력
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		printf("%2d", map[i][j]);

	//	}
	//	printf("\n");
	//}


	// 그래프 구축
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
				continue;

			// data가 1인 경우만 아래 진행

			// 노드 이름
			int name = getName(i, j);

			// 자기 자신과 연결 -> 한 집이 한 단지를 이루는 경우
			myGraph[name].push_back(name);

			// 제일 마지막 노드
			if (j == N - 1 && i == N - 1)
			{

			}

			// 제일 오른쪽
			else if (j == N - 1)
			{
				// 아래쪽에 집 있으면
				if (map[i + 1][j] == 1)
				{
					int other = getName(i + 1, j);
					myGraph[name].push_back(other);
					myGraph[other].push_back(name);
				}
			}

			// 제일 아래쪽
			else if (i == N - 1)
			{
				// 오른쪽에 집 있으면
				if (map[i][j + 1] == 1)
				{
					int other = getName(i, j + 1);
					myGraph[name].push_back(other);
					myGraph[other].push_back(name);
				}
			}

			else // 일반적인 경우
			{
				// 아래쪽에 집 있으면
				if (map[i + 1][j] == 1)
				{
					int other = getName(i + 1, j);
					myGraph[name].push_back(other);
					myGraph[other].push_back(name);
				}
				// 오른쪽에 집 있으면
				if (map[i][j + 1] == 1)
				{
					int other = getName(i, j + 1);
					myGraph[name].push_back(other);
					myGraph[other].push_back(name);
				}
			}

		}
	}



	//// 그래프 출력
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		// 노드 이름
	//		int name = getName(i, j);
	//		printf("%3d: ", name);
	//		for (int k = 0; k < myGraph[name].size(); k++)
	//		{
	//			printf("%3d ", myGraph[name][k]);
	//		}
	//		printf("\n");

	//	}
	//}


	// 단지, 집 개수 구하기
	for (int i = 0; i < N * N ; i++)
	{
		// 노드에 연결이 있을 경우
		if (!myGraph[i].empty())
		{
			//printf("%3d 연결 있음\n", i);
			// 아직 방문하지 않은 경우
			if (visited[i] == 0)
			{
				//printf("~~~~~~~~~~~~~~~~~~~~새로운 단지: %3d\n",i);
				houseCount = 0;
				groupCount++;
				dfs(i);
				resultCount.push_back(houseCount);
				houseCount = 0;
			}
		}
	}

	// 벡터 정렬
	sort(resultCount.begin(), resultCount.end());

	//// 사람이 보기 좋게 결과 출력
	//printf("groupCount: %d\n", groupCount);
	//printf("resultCount: ");
	//for (int i = 0; i < resultCount.size(); i++)
	//{
	//	printf("%3d", resultCount[i]);
	//}


	// 문제 요구조건에 맞게 결과 출력
	printf("%d\n", groupCount);
	for (int i = 0; i < resultCount.size(); i++)
	{
		printf("%d\n", resultCount[i]);
	}
}