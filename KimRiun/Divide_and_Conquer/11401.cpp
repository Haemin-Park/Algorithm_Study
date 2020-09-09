// 이항 계수3
/*자연수 n과 정수 k가 주어졌을 때 이항 계수 nCk를 1,000,000,007로 
나눈 나머지를 구하는 프로그램을 작성하시오.*/

// https://www.acmicpc.net/problem/11401 
// 런타임 에러

#include <iostream>
using namespace std;

#define DevidingNum 1000000007 

int n, k;
unsigned long long nCk, N_K, K; // nCk, n!/(n-k+1)!, k!


// 이항계수 계산 및 나머지 구하는 함수
void bino_coef(int n, int k) {

	/* nCk % 1000000007 
	   = n!/((n-k!)k!) % 1000000007 
	   = n(n-1)...(n-k+1)/k! % 1000000007 임을 이용함.
	n!대신 n(n-1)...(n-k+1)이 더 작으므로 overflow에서 벗어나길 기대했음...

	N_K = n(n-1)...(n-k+1)
	K = k!
	nCk = N_K/ K  */

  
	if (n == 0 || k == 0) {
  	  cout << "1";
   	  return; 
 	}
  
  
  
	unsigned long long result = 1; // c++ 정수 자료형 중 가장 큰 범위 unsigned long long
	if (n-k < k) k = n - k;	//5C3 = 5C2 임을 이용하여 중복을 최대한 줄임
	

	// k! 
	for (int i = 2; i <= k; i++) {
		result = result * i;
  	}
	K = result;
  
	
	// nx(n-1)x...x(n-k+1) 
  	result = 1;
	for (int i = n - k + 1; i <= n; i++) {
		result = result * i; /* ERROR: N_K를 계산 과정에서 overflow가 일어나 정확한 값 도출되지 않음 -> 페르마 소정리 공부하기*/
	}
	N_K = result; 

	// nCk
	nCk = N_K / K;

	
	cout << nCk % DevidingNum; // 작은 수는 정확하게 답이 도출되지만 9,223,372,036,854,775,807를 벗어나면 정확하게 계산 안됨 
	
	
}




int main() {
	
	// n과 k 입력 (1 <= n <= 4,000,000) (0 <= k <= n)
	cin >> n >> k;

	//// 이항계수 계산 및 나머지 구하기
	bino_coef(n, k);
	

	return 0;
}

// wrong: 11401
