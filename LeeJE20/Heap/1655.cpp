// 2021-03-12 17:02 시작
// https://www.acmicpc.net/problem/1655
// 가운데를 말해요
// 2021-03-12 17:18 종료
// correct: 1655


/*아이디어
교재랑 똑같은 문제다.
제일 작은 수 - 최대힙 - 중간값 - 최소힙
모양이 되게 하자.


조건1: 최대힙 개수 == 최소힙 개수
조건2: 최대힙의 top < 최소힙의 top

중앙값: 최대힙의 top

예)
최대힙n/2개: 1 2 3 / 최소힙: 4 5 6
최대힙(n+1/2)개: 1 2 3 / 최소힙: 4 5



[시간복잡도]
힙에 넣고 빼고... O(nlogn)

[실수]
	1) priority_queue를 선언해야하는데 queue를 선언헀다...
	2) #include<algorithm>을 한 상황에서 변수 이름을 min, max로 지었다..
	3) while문에서 빈 힙에서 top을 하여 오류 났다...
[검색(내가 잘 몰랐던 부분)]


*/


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N; // 입력 개수
	int input; // 입력
	
	
	cin >> N;
	
	
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int> maxHeap;
	int tmp;
	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (i%2==0)
		{
			maxHeap.push(input);
		}
		else
		{
			minHeap.push(input);
		}
		// 빈 힙에서 top을 하여 오류 났다...
		while(!minHeap.empty() && maxHeap.top() > minHeap.top() )
		{
			tmp = maxHeap.top();
			maxHeap.pop();
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(tmp);
		}
		
		cout<<maxHeap.top()<<'\n';
	}
	
	
	return 0;
}

