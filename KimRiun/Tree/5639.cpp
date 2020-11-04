// wrong: 입력 개수가 주어지지 않았을 때, 빈 값에서 엔터를 치면 입력을 종료하는 방법을 모르겠음
// 50 30 24 5 28 45 98 52 60
// 위와 같이 한 행에 공백으로 구분하고 엔터로 입력을 종료했을 시 문제 답 잘 나옴
#include <iostream>
#include <stdio.h>
using namespace std;

int Size;
int arr[10001];

int upperIndex(int start, int end) {
    
    for (int i = 0; i < end; i++) {
        if (arr[start + i + 1] > arr[start]) {
            //printf("arr[%d]: %d\n", start + i + 1, arr[start + i + 1]);
            return start + i + 1;
        }
    }
}

void PostOrder(int start, int end) {

    if (start >= end) return;

    // arr[start]보다 값이 커지는 위치의 인덱스 리턴
    int upperIdx = upperIndex(start, end); 
    //printf("upperIdx: %d\n", upperIdx);

    PostOrder(start + 1, upperIdx);
    PostOrder(upperIdx, end);
    
    //printf("index: %d\n", start);
    cout << arr[start] << endl;
}

int main() {
    int n;

    do {

        cin >> n;
        arr[Size++] = n;
        //cout << n << endl;

    } while (getc(stdin) == ' ');

   // cout << "Size: " << Size << endl;
   // for (int i = 0; i < Size; i++) {
   //     cout << arr[i] << endl;

   //}

    PostOrder(0, Size);

    return 0;
}
