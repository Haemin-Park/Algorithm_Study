// 교재 p.689
// 21.5 문제: 요새 (문제 ID ： F O R T R E S S , 난이도: 중)

/*
아이디어

1. 왜 트리인가?
	- 트리는 계층구조이다. 지금 성벽들도 계층구조를 가지므로 트리로 나타낼 수 있다. 가장 바깥이 루트가 되고, 2번째 벽들은 루트의 자식이 되는 꼴이다.
2. 트리를 어떻게 구축할까?
	- 노드가 가지고 있어야 하는 정보
		+ x, y, z : 각각 인트
		+ 부모
		+ 자식들 : 인트 벡터
	- 어떤 노드가 다른 노드와의 거리 안에 포함되면, 그 노드는 다른 노드의 자손이다.
	- 어떤 노드는 다른 노드의 자손들과도 거리 비교를 해서 위치를 찾아야 한다. 이는 재귀적으로 진행된다.
		+ 거리 비교 함수를 만들자. float findDistance(Node, Node);
	- 위치를 찾으면, 삽입을 진행한다.
		1. 삽입할 노드의 자식, 부모를 먼저 설정해야 한다.
3. 탐색을 어떻게 할까?
	- 트리는 순환구조를 이용해야 한다.
	- 각 자식에 대해 가장 깊이가 깊은 것을 찾는다. 깊이는 루트에서부터 노드까지의 간선의 수 이므로, 문제에서의 성벽으로 칠 수 있다.
	- 아래의 과정을 재귀적으로 호출한다.
		1.  각 자식에 대해 가장 깊이가 깊은 것을 찾는다.
		2. 그중 최댓값 2개를 더한다. 이 값을 tmpMax라 하자.
		3. tmpMax와 result를 비교하여 큰 값을 채택
4. 전역변수 설정
	- result
*/


#include<iostream>
#include<vector>
using namespace std;
// 
class Node
{
	public:
		int idx;
		int x;
		int y;
		int z;
		int parent = -1;
		vector<int> children; 
};

int findDistance(Node a, Node b)
{
	return ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y))
}

int C; //테스트 케이스 수
int N; // 성벽의 수
Node wall[100]; // 성벽들

void makeTree(Node a, Node b)
{
	int dist = findDistance(a, b);
	
	// a가 b의 자손이면
	if (dist < b.z)
	{
		// b의 자식들과 a를 비교해서 a가 b의 자식들에 포함되나 확인
		for (int i = 0; i < b.children.size(); i++)
		{
			makeTree(a, b.children[i]);
		}
		
		// 포함 안 되면 a는 b의 자식
		a.parent = b.idx;
		
		// b의 자식 중 a에 포함되는 것이 있는지 확인
		vector<int>::iterator iter;
		for (iter = b.children.begin(); iter != b.children.end(); iter++)
		{
			dist = findDistance(a, *iter);
			if (dist < a.z)
			{
				// a의 자식에 b의 자식 추가
				a.children.push_back(*iter.idx);
				// b의 자식의 부모를 a로 변경
				*iter.parent = a.idx;
				// b의 자식 목록에서 삭제
				b.children.erase(iter);
			}
		}
		
	}


}

void solve()
{
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin<<C;
	for (int i = 0; i < C; i++)
	{
		cin<<N;
		for (int j = 0; j < N; j++)
		{
			cin<<wall[j].x<<wall[j].y<<wall[j].z;
			wall[j].idx = j;
		}
		
		makeTree();
		
		solve();
		
		
		
	}
}
