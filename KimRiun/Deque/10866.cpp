// 덱 구현
// 문제: https://www.acmicpc.net/problem/10866
#include <iostream>
#include <string>
using namespace std;

#define MAX 10000

int arr[MAX];
int Count;
int head;
int tail = 1;


/* head는 항상 첫번째 원소 인덱스의 바로 앞 인덱스를 가리킨다.
   tail은 항상 마지막 원소 인덱스의 바로 다음 인덱스 가리킨다.
*/

// head에 x넣고 다시 head를 한칸 앞으로 보냄 
void push_front(int x) {
	
	if (head < 0) {
		head = MAX - 1;
	}
	arr[head] = x;
	head--;
	Count++;

}

// tail에 x넣고 다시 tail을 한칸 뒤로 보냄
void push_back(int x) {
	if (tail > MAX-1) {
		tail = 0;
	}
	arr[tail] = x;
	tail++;
	Count++;
}

// head를 뒤로 한칸 보내 첫번째 원소를 출력
void pop_front() {
	if (Count == 0) cout << "-1" << endl;
	else {
		if (head == MAX - 1) {
			head = 0;
		}
		else head++;
		cout << arr[head]<<endl; 
		
		Count--;
	}
	
}

// tail를 앞으로 한칸 보내 마지막 원소를 출력
void pop_back() {
	if (Count == 0) cout << "-1" << endl;
	else {
		if (tail == 0) {
			tail = MAX - 1;
		}
		else tail--;
		cout << arr[tail]<<endl;
		
		Count--;
	}
}

void size() {
	
	cout<< Count <<endl;
}

// 비었으면 1, 원소가 있으면 0 출력
void empty() {
	if (Count == 0) cout << "1" << endl;
	else cout << "0" << endl;
}

// 첫번째 원소 출력
void front() {
	if (Count == 0) cout << "-1" << endl;
	else {
		
		if (head == MAX - 1) {
			cout << arr[0] << endl;
		}
		else cout << arr[head + 1] << endl;

		
	}
}

//마지막 원소 출력
void back() {
	if (Count == 0) cout << "-1" << endl;
	else {

		if (tail == 0) {
			arr[MAX - 1];
		}
		else cout << arr[tail - 1] << endl;
		


	}

}

// 모든 원소 출력(문제에는 없는 함수...)
void printArr() {
	cout << "**arr출력**" << endl;
	if (Count == 0) cout << "수행 후 size = 0" << endl;
	else {
	
		for (int i = 1; i <= Count; i++) {
			int temp = head + i;
			if (temp > MAX - 1) {
				temp = temp - MAX;
			}
			cout << "[" << temp << "]";
			cout << arr[temp] << "  ";
		}
		cout << endl;
	}
}


int main() {
	int n; // 명령 개수
	cin >> n;


	for (int i = 0; i < n; i++) {
		string ins; //instruction
		cin >> ins;
		if (ins == "push_front") {
			int x;
			cin >> x;
			push_front(x);
		}
		else if (ins == "push_back") {
			int y;
			cin >> y;
			push_back(y);
		}
		else if (ins == "pop_front") {
			pop_front();
		}
		else if (ins == "pop_back") {
			pop_back();
		}
		else if (ins == "size") {
			size();
		}
		else if (ins == "empty") {
			empty();
		}
		else if (ins == "front") {
			front();
		}
		else if (ins == "back") {
			back();
		}

		//printArr();
		//cout << "head = " << head << ", tail = " << tail << endl<<endl;
	}

	return 0;
}
