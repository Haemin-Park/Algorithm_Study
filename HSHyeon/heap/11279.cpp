// 11279.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//자연수면 힙에 넣고, 0이면 가장 큰 값 출력, 배열에서 제거
//배열이 비어있다면 0 출력

#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void insertheap(int num) {
    heap.push_back(num);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;

    }
}
void deleteheap() {
    printf("%d\n", heap[0]);
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while (true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        if (left >= heap.size()) break;
        int next = here;
        if (heap[next] < heap[left]) next = left;
        if (right < heap.size() && heap[next] < heap[right])
            next = right;
        if (next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}
int main()
{
    int a;
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
