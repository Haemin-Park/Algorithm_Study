// 2021-03-13 16:13 시작
// https://www.acmicpc.net/problem/11286
// 절댓값 힙
// 2021-03-13 16:59 종료
// correct: 11286

/*아이디어
절댓값이 작은 값이 우선순위가 높게 한다.


[시간복잡도]
힙 삽입/삭제 -> nlogn

[실수]


[검색(내가 잘 몰랐던 부분)]
- 우선순위 큐에서 비교 함수 작성
- c++에서의 abs 함수
	- https://blockdmask.tistory.com/335
*/


#include <iostream>
#include <queue>
#include<cstdlib> //abs for int, long int

using namespace std;


class cmp
{
	public:
		bool operator()(int a, int b)
		{
			if (abs(a) < abs (b))
				return false;
			else if (abs(a)==abs(b) && a<=b)
				return false;
			else
				return true;
		}
};


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N; //연산 개수
	
	// 절대값이 작은값..
	// cmp: 비교해서 false가 나오면 우선순위가 높아진다.
	priority_queue<int, vector<int>, cmp > pq;
	
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

