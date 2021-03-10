// 2021-01-22 16:46 시작
// https://www.acmicpc.net/problem/2263
// 트리의 순회

// 2021-01-22 18:17 종료
// correct: 2263


/*
아이디어
교재의 TRAVERSAL과 유사하다!

프리: 루트-왼쪽-오른쪽
인: 왼쪽-루트-오른쪽
포스트: 왼쪽-오른쪽-루트

뒤집으면

프리: 오른쪽-왼쪽-루트 => 일종의 포스트 오더
인: 오른쪽-루트-왼쪽 => 일종의 인오더
포스트: 루트-오른쪽-왼쪽 => 일종의 프리오더

뒤집은 포스트를 훑어간다.
뒤집은 인에서 그 숫자를 찾고, 왼쪽 서브트리(뒤집기 전의 오른쪽)와 오른쪽 서브트리(뒤집기 전의 왼쪽)으로 나눈다.
왼쪽, 오른쪽에 대해 재귀
루트를 결과 array에 저장


마지막: array 출력
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int pre[100000];
int in[100000];
int post[100000];

// pre 저장하는 인덱스
int preIdx;

// post 훑어가는 인덱스
int postIdx;

// last: 인덱스 이하
// first: 인덱스 초과
void findPre(int last, int first)
{
	if ( (last - first) == -1)
	{
		// cout<<"리턴"<<endl;
		return;
	}
	
	//뒤집은 포스트를 훑어간다.
	int now = post[postIdx--];
	
	
	// 뒤집은 인에서 찾는다.
	int nowIdx;
	for (int i = last; i >= first; i--)
	{
		if (in[i]==now)
		{
			nowIdx = i;
			break;
		}
	}
	// 왼쪽 재귀 (뒤집기 전 오른쪽)
	findPre(last, nowIdx+1);
	
	findPre(nowIdx-1, first);
	
	// preOrder 거꾸로 써내려 감
	pre[preIdx--] = now;
	// cout<<"now: "<<now<<endl;
	
}


int main()
{
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	
	// 인덱스 초기화
	preIdx = n-1;
	postIdx = n-1;
	
	
	// preOrder 찾기
	findPre(n-1, 0);
	
	// 출력 
	for (int i = 0; i < n; i++)
	{
		printf("%d ", pre[i]);
	}
	
}
