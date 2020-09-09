// correct: 2798

#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;


int MAX = 21; // 문제에서의 M. 카드 합 상한값(MAX 미만이어야 함)
int NUM = 0; // 문제에서의 N, 전체 카드 개수
vector<int> card; //카드
vector<int> picked;
int maxSum = 0; // 최대 합(정답)
int localSum = 0; // 최대합의 후보. 여기서 수를 계산.


// n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
// n: 전체 원소의 개수
// picked: 지금까지 고른 원소들의 번호
// toPick: 더 고를 원소의 수
// 일때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
void findSum(int n, vector<int>& picked, int toPick)
{
	//기저: max 초과하면 안됨
	if (localSum > MAX) return;
	// 기저 사례: 더 고를 원소가 없을 때 maxSum과 localSum 비교
	if (toPick == 0)
	{
		
		if (maxSum<localSum) 
		{
			maxSum = localSum;
			// cout<< " maxSum: "<< maxSum <<endl;
		}
		return;
	}
	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back()+1;
	// 이 단계에서 원소 하나를 고른다.
	for(int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		localSum += card[picked.back()];
		// cout<< card[picked.back()] <<" 추가해서 로컬섬이 "<< localSum <<endl;
		findSum(n, picked, toPick -1);
		localSum -= card[picked.back()];
		picked.pop_back();
	}
}


//교재 코드
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
// 		printPicked(picked);
// 		return;
// 	}
// 	// 고를 수 있는 가장 작은 번호를 계산한다.
// 	int smallest = piecked.empty() ? 0 : picked.back()+1;
// 	// 이 단계에서 원소 하나를 고른다.
// 	for(int next = smallest; next < n; ++next)
// 	{
// 		piecked.push_back(next);
// 		pick(n, picked, toPick -1);
// 		picked.pop_back();
// 	}
// }


int main()
{
	cin.sync_with_stdio(false);
	// cout<<"2789 blackjack start!"<<endl<<endl;
	
	cin >> NUM;
	cin >> MAX;
	int cardnum;
	for (register int i = 0; i<NUM; i++)
	{
		cin >> cardnum;
		card.push_back(cardnum);
	}
	
	findSum(NUM, picked, 3);
	
	cout<<maxSum;
}
