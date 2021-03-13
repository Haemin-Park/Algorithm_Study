// 2021-03-13 17:23 시작
// https://programmers.co.kr/learn/courses/30/lessons/42626
// 더 맵게
// 2021-03-13 17:56 종료
// correct: 42626


/*아이디어
1. 전부 min 힙에 넣는다 (make heap 함수가 있을 듯)
아래 내용을 heap.top<K 인 조건에서 반복
2. heap에서 2번 pop한 값으로 새 스코빌 지수 계산
3. 새 스코빌 지수 push


[시간복잡도]
n/2 = k라 할때
시간복잡도는 최대 klogk이다.
따라서 O(nlogn)

[실수]
- 문제 대충 읽어서 while pq.size() 조건을 처음에 안 줬다.
    대책: 1) 문제를 읽는다 2) 제한사항을 읽는다 3) 입출력 예시를 읽는다
        문제만 읽고 풀지 말고 뒷 내용도 잘 보자.

[검색(내가 잘 몰랐던 부분)]
- 우선순위큐를 기존 벡터를 이용해 만들 수도 있다.
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
    반성: 생성자 공부를 잘 하자... 모르면 생성자 검색해보자.


- 벡터
    fornt(), pop_back() 연산


*/


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {

    
    
    int answer = 0;
    
    // 우선순위 큐로 풀기
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto& s: scoville)
    {
        pq.push(s);
    }
    
    // 문제 대충 읽어서 pq.size() 조건을 처음에 안 줬다.
    while(pq.size() > 1 && pq.top()<K)
    {
        
        int tmp = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        pq.push(tmp+tmp2*2);
        answer++;
    }
    if (pq.top()<K) return -1;
    
    
//     // 벡터로 풀기
//     make_heap(scoville.begin(), scoville.end(), greater<int>());
//     while(scoville.size() > 1 && scoville.front()<K)
//     {
//         int tmp = scoville.front();
//         pop_heap(scoville.begin(), scoville.end(), greater<int>());
//         scoville.pop_back();
        
//         int tmp2 = scoville.front();
//         pop_heap(scoville.begin(), scoville.end(), greater<int>());
//         scoville.pop_back();
        
//         scoville.push_back(tmp+tmp2*2);
//         push_heap(scoville.begin(), scoville.end(), greater<int>());
//         answer++;
//     }
//     if (scoville.front()<K) return -1;
    
    
    return answer;
}
