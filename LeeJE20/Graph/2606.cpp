//https://www.acmicpc.net/problem/2606
// 바이러스
// 2020.12.02 19:06
// 끝 19:49

// correct:2606

// 감상평: 기본적인 그래프..
// 너비우선탐색으로도 나중에 해보면 좋을듯.



#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

vector<int> myGraph[101];

int visited[101] = { 0 };


int pcNum;
int linkNum;
int link1;
int link2;

int pcCount = 0;

// n: 현재 노드 번호
void dfs(int n)
{
	visited[n] = 1;
	pcCount++;
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
	scanf("%d %d", &pcNum, &linkNum);

	// 그래프 구축
	for (int i = 0; i < linkNum; i++)
	{
		scanf("%d %d", &link1, &link2);
		myGraph[link1].push_back(link2);
		myGraph[link2].push_back(link1);
	}

	// 노드 1로부터 출발
	dfs(1);

	// 1번 컴퓨터 제외하기 위해 -1
	printf("%d", (pcCount - 1));


}


