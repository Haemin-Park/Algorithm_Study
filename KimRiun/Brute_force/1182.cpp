// 부분수열의 합 
/*N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 
그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.*/
#include <iostream>
#include <stdio.h>
using namespace std;

int n, s; // n: 정수 개수, s: 합
int seq[20]; // 수열
int result = 0; // 개수

void PartialSum(int idx, int sum) {
	//printf("PartialSum(%d, %d)  ", idx, sum);
	
	// 마지막 원소를 벗어나면 return
	if (idx == n) return;
	
	
	// 해당 원소를 누적해서 더함
	sum = seq[idx] + sum;

	// 더한 합이 s와 같으면 result 증가
	if (sum == s) result++;
		
	// recursion
	// 해당 원소를 빼고 부분합을 구할 경우
	PartialSum(idx + 1, sum - seq[idx]);
	// 해당 원소를 포함해서 부분합을 구할 경우
	PartialSum(idx + 1, sum);
	
}

int main() {
	// 정수의 개수 n과 합 s 입력
	 cin >> n >> s; 

	// n개의 정수들로 이루어진 수열 입력	
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	//// 모든 부분수열을 찾고 그 합을 구한다.
	PartialSum(0, 0);

	
	// 합이 S가 되는 부분수열의 개수를 출력한다
	cout << result;
	
	return 0;
}

// correct: 1182
