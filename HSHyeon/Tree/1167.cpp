// 1167.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*트리가 입력으로 주어진다. 
먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)
둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 
(정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 
예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 
정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 
주어지는 거리는 모두 10,000 이하의 자연수이다.*/

/*첫째 줄에 트리의 지름을 출력한다.*/
//트리의 지름 구하기
//루트노드에서 리프노드까지의 최장거리가 아마 최장거리

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX 100001 

vector<pair<int,int> > v[MAX];
int N;
int length,current;
bool checked[MAX];
/*
typedef struct treetype {
	int node, cost;

}treetype;*/


void dfs(int node,int cost) {
	if (checked[node])return;
	checked[node] = true;

	if (length < cost) { //만약 최장거리보다 cost가 크다면
		length = cost;
		current = node;
	}
	for (int i = 0; i < v[node].size(); i++)
		dfs(v[node][i].first, cost + v[node][i].second); 
	//pair first, second로 구분
}


int main()
{
	cin >> N; //정점 번호
	for (int i = 0; i < N; i++) {
		int node;
		cin >> node;
		while (1) {
			int node2,cost;
			
			cin >> node2;
			if (node2 == -1)break;
			cin >> cost; //왠지 같이 입력받음 안되네

			v[node].push_back(make_pair(node2, cost));
			v[node2].push_back(make_pair(node, cost));
		}
	}
	dfs(1, 0);

	cout << length;
}

