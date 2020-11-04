// 11279.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//자연수면 힙에 넣고, 0이면 가장 큰 값 출력, 배열에서 제거
//배열이 비어있다면 0 출력

#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void insertheap(int num) {
    heap.push_back(num); //리프 노드에 변수 삽입
    int idx = heap.size() - 1; //리프 노드 위치
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) { //삽입한 값이 부모노드보다 크면
        swap(heap[idx], heap[(idx - 1) / 2]); 
        idx = (idx - 1) / 2; //부모와 노드 위치 스왑

    }
}
void deleteheap() {
    printf("%d\n", heap[0]); //삭제되기 전 값 출력
    heap[0] = heap.back(); //루트값에 리프 노드 삽입
    heap.pop_back(); //리프 노드 제거
    
    int here = 0;
    while (true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        if (left >= heap.size()) break; //리프에 도달할 경우 break
        
        int next = here;
        if (heap[next] < heap[left]) next = left; //left가 더 크면 자식으로 내려감
        if (right < heap.size() && heap[next] < heap[right]) //right가 더 클 경우
            next = right; 
        if (next == here) break;//바뀌지 않고 그대로일 경우 break
        swap(heap[here], heap[next]); //위치 스왑
        here = next;
    }
}
int main()
{
    int a; //입력 개수
    cin >> a;
    for (int i = 0; i < a; i++) {
        int b;
        scanf("%d", &b);
        if (b == 0) { 
            if (heap.empty()) printf( "0\n");
            else deleteheap(); }
        else if (b > 0) insertheap(b);
    }
}
