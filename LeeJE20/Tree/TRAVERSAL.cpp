// www.algospot.com/judge/problem/read/TRAVERSAL
// 교재 p.686
// 21.3 문제: 트리 순회 순서 변경 (문제 ID: TR A V ER SA L, 난이도: 하)
// correct: TRAVERSAL


/*
책 보고 힌트 얻고 풀었음.
 아이디어: preOrder는 루트 먼저니까 inorder에서 preOrder 값을 찾으면 왼쪽 서브트리, 오른쪽 서브트리로 나눌 수 있다.
 이를 이용하여 재귀적으로 왼쪽, 오른쪽, 가운데 순으로 보면서 출력
 
- 자신의 접근 되새겨보기
	하나도 모르겠어서 그냥 책을 봤다.
- 자신이 왜 이 풀이를 떠올리지 못했는지 살펴보기
	1. divide and conquer가 잘 안 되었다.
	2. preOrder, inOrder의 특징을 잘 되새겨 봤어야 했다.
	3. 트리니까 재귀적으로 뭔가를 할 수 있다는 걸 느껴야 했다.
	4. 재귀적으로 할 수 있다는 것은 작은 비슷한 문제로 쪼갤 수 있다는 뜻이다.
 
*/



#include <stdio.h>
#include <iostream>
using namespace std;


int C; // 테스트 케이스 수 
int N; // 트리에 포함된 노드의 수

int preOrder[100];
int inOrder[100];
int postOrder[100];

// preOrder 훑는 인덱스
int preIndex = 0;
// first는 해당하는 처음 인덱스
// last는 해당되는 마지막 인덱스 +1
void printPostOrder(int first, int last)
{
	// 기저: 비었으면 리턴
	if ( (last - first) == 0)
	{
		// cout<<"리턴"<<endl;
		return;
	}
	
	// 프리에서 차례대로 하나씩 빼옴
	int now = preOrder[preIndex++];
	
	// now를 inOrder에서 몇 번쨰 인덱스인지 찾음
	int inOrderIdx;
	
	for (int i = first; i < last; i++)
	{
		if (inOrder[i] == now)
		{
			inOrderIdx = i;
			break;
		}
	}
	
	// 포스트 오더에 맞게 출력 
	
	// 왼쪽 서브트리
	printPostOrder(first, inOrderIdx);
	// 오른쪽 서브트리
	printPostOrder(inOrderIdx+1, last);
	// 빼온거 출력
	printf("%d ", now);
}


int main()
{
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		scanf("%d", &N);
		
		// cout<<"프리"<<endl;
		for (int j = 0; j<N; j++)
		{
			scanf("%d", &preOrder[j]);
		}
		// cout<<"인"<<endl;
		for (int j = 0; j<N; j++)
		{
			scanf("%d", &inOrder[j]);
		}
		// preOrder 훑는거 초기화
		preIndex = 0;
		printPostOrder(0, N);
		printf("\n");
	}
	// cout<<"끝"<<endl;
	
}
