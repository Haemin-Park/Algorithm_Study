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

=> 03.17 개선: time 계산을 좀 더 빠르게 진행
while 이터레이터가 end()가 아님, 또는 q가 비어있지 않다면
1) 벡터[0]이 time과 같아지는 순간까지 벡터를 훑고 큐에 추가
2) queue 확인하고 안 비었으면 다음 work 채택
    answer += time-요청시점 + 소요시간(work)
	time +=work
3) queue가 비었으면 time = 다음 job의 도착시간

[시간복잡도]
안쪽 while문: 총 n번 수행 (모든 job을 큐에 넣어야 함)
바깥쪽 while문: 총 n번 수행 (모든 job을 수행해야함)
큐에 삽입/삭제: 한번에 logN인데 이런 연산을 n번함 => 2nlogn (2는 삽입도 하고 삭제도 하기 때문)

//else: O(디스크가 놀고 있는 시간)
//결론: 2nlogn +디스크가 놀고 있는 시간=> O(디스크가 놀고 있는 시간+nlogn)
결론: O(nlogn)




[실수]
// 실수: 추가조건- iter != end()
// iter가 end까지 갔는데 (*iter[0]을 계속 호출해서 세그멘테이션 폴트남)
// 실수: iter!=jobs.end() 조건을 뒤에 줬더니 (*iter) 연산을 먼저 해서 세그멘테이션 폴트

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
    
    int answer = 0;
    // 벡터를 첫번째 값(요청시간) 기준으로 정렬하고 시작한다.
    sort(jobs.begin(), jobs.end());
    
    // priority_queue. pair의 소요시간 기준으로 작은 것이 우선순위가 크게 정렬
    // 1. 두 번째 값이 작으면 우선순위가 높다
    // 2. 두 번쨰 값이 같은 경우, 요청시간이 작은 것이 우선순위가 높다.
    // => pair의 크기 비교에 따라, greater<pair<int, int>>로 하고 소요시간을 처음 인자, 요청시간을 두번째 인자로 둔다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    
    
    // 벡터 끝까지 훑을 때까지 time++을 반복한다. : 이터레이터로 진행
    vector<vector<int>>::iterator iter = jobs.begin();
    
    int time = 0, work = 0;
    // while 이터레이터가 end()가 아니면
    // 또는 큐에 뭔가 있으면
	
	
	// 바깥while
    while(iter!=jobs.end() || !pq.empty())
    {
        // // 1. work가 진행중이면 work를 하고 time++
        // if (work>0)
        // {
        //     work--;
        //     time++;
        // }
        // // 2. work==0인 상태이면 
        // else
        // {
		
		
		// 21.03.17 개선사항
		// work를 받자마자 수행하는 과정을 추가하여 윗 부분의 if~else를 날려버리자
		
            // 1) 벡터[0]이 time과 같아지는 순간까지 벡터를 훑고 큐에 추가
		// 실수: 추가조건- iter != end()
		// iter가 end까지 갔는데 (*iter[0]을 계속 호출해서 세그멘테이션 폴트남)
		// 실수: iter!=jobs.end() 조건을 뒤에 줬더니 (*iter) 연산을 먼저 해서 세그멘테이션 폴트
		
		// a: 이번 while문에서 q에 들어가는 job의 개수
		//log(a!) -> nlog(n)
		while (iter != jobs.end() && (*iter)[0] <= time)
		{
                // 소요시간, 도착시간
                pq.push(make_pair((*iter)[1], (*iter)[0]));
                iter++;
        }
		// 2) queue 확인하고 안 비었으면 다음 work 채택
		if (!pq.empty())
		{
			work = pq.top().first;
			// answer += time-요청시점+ 수행시간
			answer += time-pq.top().second+ work;
			pq.pop(); // log(a)
			time += work;
		}
		// 3) queue가 비었으면 time++  
		else
		{
			// time++;
			// 21.03.17 개선사항
			// 도착시간 순으로 jobs가 정렬되어 있으므로 
			// 바로 다음 job의 도착시간으로 jump
			time += ((*iter)[0]-time);
		}

        // }
    }
    // 3. answer /= 벡터.size();
    answer /= jobs.size();
    
    
    return answer;
}
