// 2021-03-12 16:09 시작
// https://www.acmicpc.net/problem/11279
// 최대 힙
// 2021-03-12 16:21 종료
// correct: 11279





/*아이디어
우선순위 큐 STL을 사용해보자.

[실수]
cin>>N을 안 하고 실행해버렸다..
cin할 것을 까먹지 말자.
*/




#include <iostream>
// #include <vector>
#include <queue>
using namespace std;




int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N; //연산 개수
	
	//maxHeap
	priority_queue<int, vector<int>, less<int> > pq;
	
	int input; // 입력받는 순자
	
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>input;
		
		// 0이면 출력
		if (input==0)
		{
			if(pq.empty())
			{
				cout<<0<<'\n';
			}
			else
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else //나머지면 삽입
		{
			pq.push(input);
		}
	}
	return 0;
}

