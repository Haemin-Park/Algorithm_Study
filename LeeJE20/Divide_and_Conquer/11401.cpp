// 2020-08-26 22:50 시작
// https://www.acmicpc.net/problem/11401
// 이항 계수 3 
// wrong: 11401

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

// long long DNUM=1000000007;

#define DNUM 10 //테스트용
long long a;

long long cT[4000001] = {1}; // 캐시테이블


// 팩토리얼 캐시테이블
void fillCacheTable(int n)
{
	long long result = 1;
	for (int i = 2; i < n+1; i++)
	{
		result *= (long long) i;
		result %= DNUM;
		cT[i] = result;
		// printf("[%d] = %lld \n", i, result);
	}
}

// 모듈연산된 팩토리얼
long long facMod(int n)
{
	long long result = cT[n];
	return result;
}

vector<int> binary;
long long pow(long long n)
{
	// int a;
	// int b;
	
	// printf("ppower\n");
	int P= (int)DNUM;
	while ( P >= 1)
	{
		binary.push_back(P%2);
		P =  (int)(P/2);
		// printf("%3d ", binary.back());
	}
	
	long long result = 1;
	

	for (long long i = 0; i <binary.size(); i++)
	{
		n = n << 1;
		if (binary[i] == 1)
		{
			result = ((n%DNUM)*result)%DNUM;
		}
		// printf("\n i: %3lld, n = %3lld, result = %3lld ", i, n, result);
	}
	// cout<<endl<<endl;
	return result;
}



int com(int n, int k)
{
	// cout<<"k = "<<k<<endl;
	if (n <= 2) return 1;
	if (k> (int)(n/2)) k = n-k;
	if (k == 0) return 1;
	
	
	if (k == 1) return n;
	
	long long A;
	long long B;
	A = cT[n];
	B =( (cT[k]%DNUM) * (cT[n-k]%DNUM) ) %DNUM;
	// printf("A, B = %lld, %lld\n", A, B);
	
	B = pow(B);
	
	long long result = (A*B)%DNUM;
	
	// if (result >= DNUM) result -= DNUM; 
	
	return result;
}


int main()
{
	// cout<<endl<<"11401 시작"<<endl;
	
	cin.sync_with_stdio(false);
	int n;
	int k;
	
	cin >> n >> k;
	
	fillCacheTable(n);
	
	
	int result = com(n, k);
	
	
	// cout<<endl<<"결과: ";
	cout<< result;
}
