// 2020-09-30 15:10 시작
// https://www.acmicpc.net/problem/11725
// 2020-09-30 18:07 종료
// 트리의 부모 찾기
// 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.
// correct: 11725

// 런타임에러 -> 입력 범위를.. 0을 하나 덜 썼다...
// 시간초과-> cin과 cout을 scanf와 printf로 바꿔서 해결....


// 감상평
// 너무 어렵다!! 
// 2차원 배열 쓰는 법을 익혀두자..
// iostream은 너무 느리다.. 웬만하면 stdio를 쓰자.
// 트리 구현/순회는 좀 익혀둬야 나중에 덜 당황스럽겠다.


// #include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

/*
아이디어 

링크벡터의 내용을 인덱스 1부터 읽어 내려가며 재귀로 연결을 만든다.



아이디어 생각 완료: 16:16 
솔루션
{

2차원 벡터 linkV; // 입력받은 연결이 들어 있음

linkv의 1차원 부분에 0부터 n까지 채워넣기 (인덱스 맞추기 위해 0부터…)



linkv의 2차원 부분에 입력받은 연결을 채워넣기 -> 2, 5면 2에도 5를 넣고 5에도 2를 넣는다.


벡터 트리;
트리에 빈 노드 n+1개 채워둠..
인덱스 1이 노드 1을 의미함

순환(1);

}

노드
{
	인트 부모 인덱스
	벡터<인트> 자식 목록(인덱스로)
	불 연결완료 = false;
}




순환(현재노드의 인덱스)
{
	
	for j in linkV[i] (링크벡터에 있는 인덱스에 대해서,,):  
		if 트리->노드[j]가 false라면:
			j의 부모: i
			연결완료 = true
			i의 자식 목록.push_back[j]
			
			순환(j)
		//if j가 true라면: 다음 j 탐색
			
}

*/

int N; // 노드 개수

// 2차원 벡터. 입력받은 연결이 들어 있다.
vector<int> linkV[100001];
// v[0].push_back(2);
// v[0].push_back(7);
// v[3].push_back(3);
// cout<<v[0][0]<<endl; //2
// cout<<v[0][1]<<endl; //7
// cout<<v[3][0]<<endl; //3


// 노드 클래스
class TreeNode
{
	public:
		// 부모 노드(인덱스)
		int parentIdx;
		bool isLinked = false;
		// vector<int> childrenIdx;
};

// vector<TreeNode> Tree[10001];
// vector<TreeNode> Tree(100001);
TreeNode Tree[100001];




void makeTree(int nowIdx)
{
	vector<int>::iterator iter;
	
	// 현재 노드와 연결이 있는 노드들을 찾는다(인덱스를 찾는다)
	for (iter = linkV[nowIdx].begin(); iter != linkV[nowIdx].end(); ++iter)
	{
		// 아직 연결이 안 된 노드들에 대하여
		if (Tree[(*iter)].isLinked == false)
		{
			// 찾은 노드의 부모노드는 현재 노드
			Tree[*iter].parentIdx = nowIdx;
			// 찾은 노드가 연결이 됐다는 표시를 한다
			Tree[*iter].isLinked = true;
			
			// 현재 노드의 자식 노드로 찾은 노드의 인덱스를 추가한다
			// Tree[nowIdx].childrenIdx.push_back(*iter);
			
			// 찾은 노드에 대해 재귀호출
			makeTree(*iter);
		}
	}
}




int main()
{
	// cin.sync_with_stdio(false);
	
	// cin >> N;
	scanf("%d", &N);
	int tmp1, tmp2;
	// linkv의 2차원 부분에 입력받은 연결을 채워넣기
	for (int i = 0; i < N-1; i++)
	{
		// cin >> tmp1>> tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		linkV[tmp1].push_back(tmp2);
		linkV[tmp2].push_back(tmp1);
	}
	
	makeTree(1);
	
	// 2번 노드부터 부모노드 출력
	for (int i = 0; i < N-1; i++)
	{
		printf("%d\n", Tree[i+2].parentIdx);
	}
}




