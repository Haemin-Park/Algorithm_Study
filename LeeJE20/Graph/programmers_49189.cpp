// https://programmers.co.kr/learn/courses/30/lessons/49189
// 가장 먼 노드
// 2021.01.31 23:13시작
// 2021.02.05 20:35 종료

// 후기
// 길이를 저장해두지 않고 찾을 수 있는 방법이 있으면 좋을듯


/* 아이디어
너비우선으로 한다.
current, next가 있을때 next의 길이는 current+1이다.

정답 개수를 어떻게 count할까??
길이를 계산 할때마다 업데이트 한다. -> 방법 잘 모르겠,,

max를 구해두고, 길이 벡터에서 max와 같은 것의 개수 카운트

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


// 그래프 구축
vector<vector<int>> init(vector<vector<int>> &edge, int n)
{
	vector<vector<int>> graph(n+1); // n+1개의 원소를 가짐
	
	for (int i = 0; i < edge.size(); i++)
	{
		// cout<<edge[i][0]<<", "<<edge[i][1]<<"\n";
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}
	
	
	
	
	// for (int i = 0; i < graph.size(); i++)
	// {
	// 	sort(graph[i].begin(), graph[i].end());
		
	// 	cout<< i<<": ";
	// 	for (int j = 0; j < graph[i].size(); j++)
	// 	{
	// 		cout<< graph[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	
	
	
	return graph;
	
}
     

void bfs(queue<int> & q, const vector<vector<int>> &graph, vector<int> &found, vector<int> &length, int & max)
{
	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int there = graph[now][i];
			if (!found[there])
			{
				found[there] = true;
				q.push(there);
				length[there] = length[now]+1;
				
				// 깊이 우선이기 때문에 나중에 방문하는 노드일수록 길이가 길다
				if (max < length[there])
					max = length[there];

			}
		}
	}
}


int solution(int n, vector<vector<int>> edge)
{
	vector<vector<int>> graph = init(edge, n);
	
	queue<int> q;
	vector<int> found(n+1, false);
	vector<int> length(n+1, 0);
	int max = -1;
	
	// 처음 노드 설정
	q.push(1);
	found[1] = true;
	
	// 탐색
	bfs(q, graph, found, length, max);
	
	int answer = 0;
	for (int i = 0; i < length.size(); i++)
	{
		if (length[i]==max)
			answer++;
	}


	return answer;
}


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	
	// 간선 정보
	vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}; 
	// 노드 개수
	int n = 6;
	
	int answer = solution(n, edge);
	cout<<answer;
}
