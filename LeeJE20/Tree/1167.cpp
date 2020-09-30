// 2020-09-30 18:08 시작
// https://www.acmicpc.net/problem/1167
// 2020-09-30 21:05 종료

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

// wrong: 1167.cpp

/*
아이디어

아이디어 완료-  18:30

1. 트리 구축
2. 각 리프까지 가는 경로 탐색
3. 제일 큰거 리턴


트리 구축 -> 아까 했던 것(11721)처럼 한다.


트리노드
{
	인트 부모노드 인덱스;
	
	
	// 인덱스가 같은 위치면, 그 자식노드의 가중치가 그만큼이라는 뜻
	벡터 자식노드 인덱스;
	벡터 자식노드 간선 가중치;
	

}


// 교재의 height 구하는 함수 활용
searh()
{
	// if 자식노드가 없으면 0이 리턴된다 
	int h = 0;
	
	for (각 자식노드에 대해)
		h = max(h, search(h) + 그 노드까지 가는 가중치)
	)
	
	return h;
	

}

*/







// v[0].push_back(2);
// v[0].push_back(7);
// v[3].push_back(3);
// cout<<v[0][0]<<endl; //2
// cout<<v[0][1]<<endl; //7
// cout<<v[3][0]<<endl; //3



// 연결 정보를 저장하는 클래스
class linkInfo
{
	public:
		int nodeNum;
		int weight;
};



// 노드 클래스
class TreeNode
{
	public:
		// 부모 노드(인덱스)
		int parentIdx;
		bool isLinked = false;
		vector<int> childrenIdx;
		vector<int> weight;
};

// vector<TreeNode> Tree[10001];
vector<TreeNode> Tree(100001);

int N; // 노드 개수

// 2차원 벡터. 입력받은 연결과 웨이트가 들어 있다.
vector<linkInfo> linkV[100001];


void makeTree(int nowIdx)
{
	// vector<int>::iterator iter = linkV[nowIdx].begin();
	
	
	// 현재 노드와 연결이 있는 노드들을 찾는다(인덱스를 찾는다)
	for (int i = 0; i< linkV[nowIdx].size(); ++i)
	{
		linkInfo childInfo = linkV[nowIdx][i];
		// 아직 연결이 안 된 노드들에 대하여
		if (Tree[childInfo.nodeNum].isLinked == false)
		{
			// 찾은 노드의 부모노드는 현재 노드
			Tree[childInfo.nodeNum].parentIdx = nowIdx;
			// 찾은 노드가 연결이 됐다는 표시를 한다
			Tree[childInfo.nodeNum].isLinked = true;
			
			// 현재 노드의 자식 노드로 찾은 노드의 인덱스를 추가한다
			Tree[nowIdx].childrenIdx.push_back(childInfo.nodeNum);
			
			// 현재 노드의 웨이트 벡터에 추가한 자식 노드의 웨이트 추가 
			Tree[nowIdx].weight.push_back(childInfo.weight);
			
			// 찾은 노드에 대해 재귀호출
			makeTree(childInfo.nodeNum);
		}
	}
}


int search(TreeNode N)
{
	int h = 0;
	int size = N.childrenIdx.size();
	for (int i = 0; i < size; i++)
	{
		h = max(h, search(Tree[N.childrenIdx[i]])+ N.weight[i]);
	}
	return h;
}

int main()
{
	// cin.sync_with_stdio(false);
	
	// cin >> N;
	scanf("%d", &N);
	int baseNode, linkedNode, weight;
	// linkv의 2차원 부분에 입력받은 연결을 채워넣기
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &baseNode);
		while(true)
		{
			scanf("%d", &linkedNode);
			if (linkedNode == -1) break;
			scanf("%d", &weight);
			
			
			
			linkInfo tmp;
			tmp.nodeNum = linkedNode;
			tmp.weight = weight;
			linkV[baseNode].push_back(tmp);
		}
	}
	
	makeTree(1);
	
	
	int anwser = search(Tree[1]);
	
	printf("%d", anwser);

}
