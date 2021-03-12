// 2021-03-12 16:30 시작
// https://www.acmicpc.net/problem/1927
// 최소 힙
// 2021-03-12 16:31 종료
// correct: 1927





/*아이디어
우선순위 큐 STL을 사용해보자.
최대 힙과 반대로만 하면 되겠다.
11279 문제의 코드 복사해서 쓰고 큐 객체 생성 부분만 바꾸자.

[실수]


[시간복잡도]
힙의 삽입/삭제가 계속 이루어짐
O(NlogN)
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
	
	// //maxHeap
	// priority_queue<int, vector<int>, less<int> > pq;
	//minHeap
	priority_queue<int, vector<int>, greater<int> > pq;
	
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

