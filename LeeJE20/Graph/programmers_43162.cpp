// https://programmers.co.kr/learn/courses/30/lessons/43162

// 2021.01.25 15:11 시작
// 네트워크
// 2021.01.25 16:02 끝
// correct: 43162


/* 아이디어
깊이 우선 탐색이다!
깊이 우선 탐색을 하면서, 컴포넌트 개수를 찾는 문제이다.

방문 안 된 정점이 없을때가지 dfs를 계속한다.
dfs가 실행되는 횟수가 컴포넌트의 개수이다.

*/

#include<iostream>
#include <vector>
using namespace std;



void dfs(const vector<vector<int>> &computers, vector<int> &visited, int here, int n)
{
	// cout<<"dfs: "<<here<<" 방문 중"<<endl;
	for (int i = 0; i < n; i++)
	{
		// 연결된 애 찾기
		int there;
		// cout<<i<<" 와 연결 여부: "<<computers[here][i]<<endl;
		if(computers[here][i])
		{
			there = i;
			// cout<<there<<" 방문 여부 : "<<visited[there]<<endl;
			// 방문 안 했다면 방문하기
			if (!visited[there])
			{
				// cout<<"dfs: "<<there<<" 방문"<<endl;
				visited[there] = 1;
				dfs(computers, visited, there, n);
			}
		}		
		

	}
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
	vector<int> visited(n, 0);
	
	for (int i = 0; i < n; i++)
	{
		// cout<<"solution에서의 "<<i<<" 방문 여부 : "<<visited[i]<<endl;
		if (!visited[i])
		{
			// cout<<"solution: "<<i<<" 방문"<<endl;
			visited[i] = 1;
			// cout<<"solution: "<<i<<" 방문 했다고 표시"<<endl;
			dfs(computers, visited, i, n);
			answer++;
		}

	}
	
    return answer;
}

int main()
{
	vector<vector<int>> computers;
	vector<int> v1 = {1, 1, 0};
	vector<int> v2 = {1, 1, 1};
	vector<int> v3 = {0, 1, 1};
	computers.push_back(v1);
	computers.push_back(v2);
	computers.push_back(v3);
	
	// cout<<"start"<<endl;
	// cout<<solution(3, computers);
}
