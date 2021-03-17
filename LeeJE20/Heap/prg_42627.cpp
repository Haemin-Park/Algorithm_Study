// 2021-03-13 18:12 시작
// https://programmers.co.kr/learn/courses/30/lessons/42627
// 디스크 컨트롤러
// 2021-03-13 18:56 종료
// correct: 42627

/*아이디어 ~18:35까지 생각함
벡터를 첫번째 값(요청시간) 기준으로 정렬하고 시작한다.

priority_queue. pair의 소요시간 기준으로 작은 것이 우선순위가 크게 정렬
1. 두 번째 값이 작으면 우선순위가 높다
2. 두 번쨰 값이 같은 경우, 요청시간이 작은 것이 우선순위가 높다.
=> pair의 크기 비교에 따라, greater<pair<int, int>>로 하고 소요시간을 처음 인자, 요청시간을 두번째 인자로 둔다.

벡터 끝까지 훑을 때까지 time++을 반복한다. : 이터레이터로 진행
while 이터레이터가 end()가 아니면
1. work가 진행중이면 work를 하고 time++
2. work==0인 상태이면 
    1) 벡터[0]이 time과 같아지는 순간까지 벡터를 훑고 큐에 추가
    2) queue 확인하고 안 비었으면 다음 work 채택
        answer += time-요청시점
    3) queue가 비었으면 time++

3. answer /= 벡터.size();

[시간복잡도]


[실수]


[검색(내가 잘 몰랐던 부분)]
- 2차원 벡터 정렬 https://hanyeop.tistory.com/67
- pair의 크기 비교 https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220172825836&proxyReferer=https:%2F%2Fwww.google.com%2F
- 벡터 이터레이터 만드는 방법 https://hyeonstorage.tistory.com/318
- make_pair, pair.first     https://blockdmask.tistory.com/64
- pair는 <utility>에 존재
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> // pair
using namespace std;

int solution(vector<vector<int>> jobs) {
    cout<<"48\n";
    int answer = 0;
    // 벡터를 첫번째 값(요청시간) 기준으로 정렬하고 시작한다.
    sort(jobs.begin(), jobs.end());
    cout<<"52\n";
    // priority_queue. pair의 소요시간 기준으로 작은 것이 우선순위가 크게 정렬
    // 1. 두 번째 값이 작으면 우선순위가 높다
    // 2. 두 번쨰 값이 같은 경우, 요청시간이 작은 것이 우선순위가 높다.
    // => pair의 크기 비교에 따라, greater<pair<int, int>>로 하고 소요시간을 처음 인자, 요청시간을 두번째 인자로 둔다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cout<<"58\n";
    
    
    // 벡터 끝까지 훑을 때까지 time++을 반복한다. : 이터레이터로 진행
    vector<vector<int>>::iterator iter = jobs.begin();
    
    int time = 0, work = 0;
    // while 이터레이터가 end()가 아니면
    // 또는 큐에 뭔가 있으면
    while(iter!=jobs.end() || !pq.empty())
    {
        // 1. work가 진행중이면 work를 하고 time++
        if (work>0)
        {
            work--;
            time++;
        }
        // 2. work==0인 상태이면 
        else
        {
            // 1) 벡터[0]이 time과 같아지는 순간까지 벡터를 훑고 큐에 추가
            while ((*iter)[0] <= time )
            {
                // 소요시간, 도착시간
                pq.push(make_pair((*iter)[1], (*iter)[0]));
                iter++;
            }
            // 2) queue 확인하고 안 비었으면 다음 work 채택
            if (!pq.empty())
            {
                work = pq.top().first;
                // answer += time-요청시점
                answer += time-pq.top().second;
                pq.pop();
            }
            // 3) queue가 비었으면 time++  
            else
            {
                time++;
            }

        }
    }
    // 3. answer /= 벡터.size();
    answer /= jobs.size();
    
    
    return answer;
}

int main()
{
	vector<vector<int> > arr({

	vector<int>( { 1, 9 }),
		
    vector<int>( { 0, 3 }),

    
	vector<int>( { 1, 6 }),
		
	vector<int>( { 1, 8 }),
		
    vector<int>( { 2, 6 }),

	});
	
	// 먼저 첫번째 인자 기준 정렬, 이후 두번째 인자 기준 정렬
	// 의문: 정렬되어 있으면 우선순위큐로 안 해도 되지 않나..
	sort(arr.begin(), arr.end());
	
	// 벡터 끝까지 훑을 때까지 time++을 반복한다. : 이터레이터로 진행
    vector<vector<int>>::iterator iter = arr.begin();
	
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	int time = 0;
	int work = 0;
	int answer = 0;
	while(iter!=arr.end() || !pq.empty())
    {
		cout<<"start"<<'\n';
		//cout<<(*iter)[0] <<", "<<(*iter)[1]<<"\n\n";
		
		// 1. work가 진행중이면 work를 하고 time++
        if (work>0)
        {
			cout<<"1. work 진행"<<endl;
            work--;
            time++;
			
			cout<<"work, time = "<<work<<", "<<time<<"\n\n";
			//continue 써야 하는데 안 써서 밑으로 계속 흘러가서 망항..
			continue;
        }
		
		
		// 1) 벡터[0]이 time과 같아지는 순간까지 벡터를 훑고 큐에 추가
		// 실수: 추가조건- iter != end()
		// iter가 end까지 갔는데 (*iter[0]을 계속 호출해서 세그멘테이션 폴트남)
		// 실수: iter!=arr.end() 조건을 뒤에 줬더니 (*iter) 연산을 먼저 해서 세그멘테이션 폴트
		while (iter != arr.end() && (*iter)[0] <= time)
		{
			cout<<"while:pq 추가, time == "<<time<<'\n';
			cout<<(*iter)[0] <<", "<<(*iter)[1]<<'\n';
			// 소요시간, 도착시간
			pq.push(make_pair((*iter)[1], (*iter)[0]));
			
			
			// cout<<pq.top().first <<", "<<pq.top().second<<"\n\n";
			
			iter++;
			
			if (iter == arr.end())
			{
				cout<<"탈출 iter == arr.end()"<<endl;
				// break;
			}
		}
		
		cout<<"while end"<<"\n\n";
		

		// 2) queue 확인하고 안 비었으면 다음 work 채택
		if (!pq.empty())
		{
			cout<<"02 queue 확인하고 안 비었으면 다음 work 채택"<<"\n";
			cout<<"work 0이어야 함\n";
			cout<<"work, time = "<<work<<", "<<time<<"\n";
			work = pq.top().first;
			// answer += time-요청시점
			answer += time-pq.top().second;
			pq.pop();
			
			cout<<"work 할당: 0이면 안 됨\n";
			cout<<"work, time = "<<work<<", "<<time<<"\n\n";
		}
		// 3) queue가 비었으면 time++  
		else
		{
			cout<<"03 queue가 비었으면 time++  "<<"\n";
			time++;
			cout<<"정답 work가 0이어야 함\n";
			cout<<"work, time = "<<work<<", "<<time<<"\n\n";
		}
		
	}
	
	while(!pq.empty())
	{
		// work = pq.top().first;
		// // answer += time-요청시점
		// answer += time-pq.top().second;
		
		cout<<pq.top().first <<", "<<pq.top().second<<"\n";
		cout<<"ans: "<<time-pq.top().second<<"\n\n";
		pq.pop();
	}
}
