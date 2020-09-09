// 블랙잭 문제 
// N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구하시오.

/* 수정 필요: 
  1. 카드 배열 입력이 동적아님 
  2. M과의 차가 가장 작은거를 출력하는 부분(이 부분은 main함수에서 따로 for문을 돌리기 보다 
     3개의 합이 도출됐을 때 바로 M과 비교하면서 가장 작은 값을 마지막에 출력하면 될 듯) */

#include <iostream>
#include <vector>
using namespace std;

vector<int> Sum;
int n, m;

void printPicked(vector<int>& picked, int cards[]) {
	int sum = 0;
	for (int i = 0; i < picked.size(); i++) {
		//cout << picked.at(i);
		//cout << cards[picked.at(i)]7;
		sum += cards[picked.at(i)];
		
	}
	//cout << sum;

	Sum.push_back(sum);
	//cout << endl;
}

void pick(int n, vector<int>& picked, int toPick, int cards[]) {
	
	if (toPick == 0) { printPicked(picked, cards); return; }

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1, cards);
		picked.pop_back();
	}
}

int main(void) {
	// N, M 입력
	// N: 카드의 개수(3 <=N<= 100), M: 3장 카드 최대 합(10 <= M <=300000)
	cin >> n >> m;

	// 카드 5개 입력
	int cards[5] = { 1, 2, 3, 4, 5 };
	

	// 조합: 순서에 상관없이 3개를 택해 합을 구하는 모든 경우의 수
	vector<int> picked;
	int toPick = 3;
	pick(n, picked, toPick, cards);
	
	
	// M과의 차가 가장 작은거 출력
	for (int i = 0; i < Sum.size(); i++) {
		cout << Sum.at(i);
		
	}
}

// wrong: 2798
