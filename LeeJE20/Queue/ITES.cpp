// https://www.algospot.com/judge/problem/read/ITES
// 외계 신호 분석
// correct: ITES

// 21.03.08

#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

/* 아이디어
O(n^2)밖에 생각이 안 나서 책 슬쩍 보고 아이디어를 얻었다.

연속된 수의 합이 K인 경우의 수를 구하는 문제.

연속된 수를 큐에 넣고, 큐의 합이 K를 넘으면 pop을 한다.
count는 큐에 들어 있는 숫자들의 합이다.

count==K여도 pop을 한다.


[시간복잡도 분석]
for 문이 N번 돈다.
while문은 head가 증가하는 부분-> 최대 N번 실행될 수 있다.
O(2N) -> O(N)이 된다.


[느낀점]
	부분수열의 합 문제다.
	head, tail로 나누어 생각하면 좋을 것 같다.
	


실수1:
	전역변수를 사용하면 다시 반복되는 부분이 있을 때 초기화를 잘 해줘야 하는데, 초기화를 안 해줬다...
	
	발전 방향: 전역변수를 사용할 때는 초기화를 다시 해야 할 수도 있음을 유념한다.
	
실수2:
	전역변수를 사용하고, 그 전역변수를 함수에서 사용할 때 파라미터로 받아 썼다.
	그 때 &를 안 붙여서 또 call by value로 해서 전역변수가 업데이트 되지 않았다.
	이전에 한 실수를 다시 반복하였다... 전역변수 쓸 때는 신경 쓰자.
	
	발전 방향: 파라미터로 받아 쓰지 말든가, &를 잘 붙이도록 해야 한다.
	
실수3:
	unsigned int는 총 32비트라서 2^32까지 표현할 수 있다고 생각하였다.
	실제로는 0을 포함하므로 2^32-1까지 표현 가능하다.
	
	발전 방향: 타입의 범위 제한을 좀 알고 있어야겠다. 맨날 검색한다...
	
[검색한 부분(내가 잘 모르는 부분)]
	int 범위:
		인트는 4바이트이므로 -2^16~2^16-1까지 가능하다.
	power 함수 쓰는 법:
		#include <cmath>를 하고, power(2, 32) 처럼 쓴다.
		float임에 유념하자.
	
책 코드에서 배울 점:
	1. unsigned int는 그냥 unsigned라고 써도 된다.
	2. 1028u 처럼 상수 뒤에 u를 붙이면 unsigned int가 된다.
	3. % 2^32 처럼 모듈 연산이 필요할 때, 변수의 최대 크기를 활용하면 모듈 연산을 직접 하지 않아도 간접적으로 할 수 있다.
	
*/




// 전역변수로 하면 초기화를 다시 해줘야 한다!!! 으악!
//queue<int> q;


int getNextNum(long &Ai)
{
	int ret =  (int) ((Ai % 10000) +1);
	Ai = (Ai * 214013 + 2531011) % (long) pow(2, 32);
	
	return ret;

}

// 책: unsigned 로 하면 %2^32 연산을 안 해도 된다!
int nextInt(unsigned int & seed)
{
	int ret = (int) (seed%10000+1);
	seed = ((seed*214013u) + 2531011u);
	return ret;
}

void solve()
{
	queue<int> q;
	int K, N, now, result, count;
	cin>>K>>N;
	result = 0;
	count = 0;
	
	long Ai = 1983;
	
	for (int i = 0; i < N; i++)
	{

		// now = nextInt();
		// cout<<now<<endl;
		now = getNextNum(Ai);
		// cout<<now<<endl<<endl;
		
		q.push(now);
		count+= now;

		// 최대 N번 실행된다.
		// count가 K보다 크면 큐 앞의 수를 빼준다.
		while (count >= K && !q.empty())
		{
			if (count== K)
			{
				result++;
			}
			int out = q.front();
			q.pop();
			
			count -= out;
		}
		
		// 책에선 이렇게 했다
		// while (count > K)
		// {
		// 	count -= q.front();
		// 	q.pop();
		// }
		// if (count == K)
		// {
		// 	result++;
		// }
		
	}
	
	cout<<result<<"\n";
	
	
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// 테스트 케이스 개수
	int C;
	cin>>C;
	
	for (int i = 0; i < C; i++)
	{
		solve();
	}
	
	return 0;
}
