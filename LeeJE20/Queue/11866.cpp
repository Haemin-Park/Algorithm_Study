// 2020-09-08 17:52 시작
// https://www.acmicpc.net/problem/11866
// 요세푸스 문제
// 2020-09-10 00:51 종료
// correct: 11866

// 감상평: 여사건을 생각해보는 것도 좋겠다.

/*아이디어

꼭 큐로 해야 하나??
그냥 n 크기 배열 만들고..
used = true;
jmp=-1
jmp = (jmp + K ) % N
배열[jmp] = used;

if (!used)
	cout<<배열인덱스+1
else
	배열[jmp]가 used가 아닐때까지 jmp++

-> 이렇게 하면 중간에 이미 빠진 애들을 고려하지 못한다.
처음부터 생각하자.

.. 그냥 책보고 했다
큐에 숫자 넣어두고 점프 수만큼 뒤에 추가한다.
그리고 맨 앞 인간을 제거한다.


*/

#include<iostream>
#include<queue>
using namespace std;
int N; //인간 수
int K; //점프 수

// int jmp = -1;
int used = 1;

// int arr[1000];
// int cout_Count = 0;


int main()
{
	cin.sync_with_stdio(false);
	cin>>N>>K;
	cout<<"<";
	queue<int> q;

	for (int i = 0; i < N ; i++)
	{
		q.push(i+1);
	}
	
	for (int i = 0; i < K-1; i++)
	{
		q.push(q .front());
		q.pop();
	}
	cout<<q.front();
	q.pop();
	
	while(!q.empty())
	{
		for (int i = 0; i < K-1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout<<", "<< q.front();
		q.pop();
		
	}
	cout<<">";
}

