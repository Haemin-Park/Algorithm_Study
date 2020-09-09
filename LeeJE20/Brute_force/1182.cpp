// 2020.08.26 시작
// https://www.acmicpc.net/problem/1182
// 2020.08.26 끝
// correct: 1182

#include<iostream>
#include<vector>
// #include<list>
#include<stdio.h>
using namespace std;

int N; // 입력받을 정수의 개수
int S; // 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 됨
vector<int> seq; //입력받은 정수들


int sCnt; // 합이 S가 되는 부분수열의 개수
// int localSum; // 합이 S가 되는지 알아보기 위해 더한 수



void count(vector<int>& picked, int toPick)
{
	if (toPick == 0)
	{
		// cout<<"합 구하기: ";
		int sum = 0;
		for (int i = 0; i < picked.size(); i++)
		{
			// cout<< seq[picked[i]] <<" ";
			sum += seq[picked[i]];
		}
		// cout<<endl<<"sum: "<<sum<<endl<<endl;
		if (sum == S) sCnt++;
		return;
	}
	
	int smallest = picked.empty()? 0 : picked.back()+1;
	for (int next = smallest; next<N; next++)
	{
		picked.push_back(next);
		count(picked, toPick-1);
		picked.pop_back();
	}
}
	
// 	for()
// 	남은친구들에서 이번 선택을 선택
	
// 	return count()+이번선택
// }


// // 교재 코드
// // n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
// // n: 전체 원소의 개수
// // picked: 지금까지 고른 원소들의 번호
// // toPick: 더 고를 원소의 수
// // 일때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
// void pick(int n, vector<int>& picked, int toPick)
// {
// 	// 기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
// 	if (toPick == 0)
// 	{
// 		// cout<<picked[0]<<"  "<<picked[1]<<endl;
// 		// printPicked(picked);
// 		return;
// 	}
	
	
// 	// 고를 수 있는 가장 작은 번호를 계산한다.
// 	int smallest = picked.empty() ? 0 : picked.back()+1;
// 	// 이 단계에서 원소 하나를 고른다.
// 	for(int next = smallest; next < n; ++next)
// 	{
// 		picked.push_back(next);
// 		pick(n, picked, toPick -1);
// 		picked.pop_back();
// 	}
// }




int main()
{
	// cout<<endl<<"1182 start!"<<endl;
	
	cin>>N>>S;
	
	int tmp;
	for (int i = 0; i<N;i++)
	{
		cin >> tmp;
		seq.push_back(tmp);
		
		// cout<<seq[i]<<" ";
	}
	// cout<<"size: "<<seq.size();
	// cout<<endl<<endl;
	
	
	for (int i = 0; i < N; i++)
	{
		vector<int> picked;
		count(picked, i+1);
	}
	
	
	cout<<sCnt;
}




