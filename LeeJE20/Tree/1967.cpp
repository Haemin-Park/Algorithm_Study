// 2021-01-22 19:35 시작
// https://www.acmicpc.net/problem/1967
// 트리의 순회

// 2021-01-23 09:40 종료
// correct: 1967



/*
트리의 높이 문제다.

루트에 대해, 서브트리 중 가장 최장을 고른다.
서브트리가 하나라면, 그 최장이 tempResult다.
서브트리가 여러개라면, 여러 서브트리중 최댓값 2개의 합이 tempResult다.
tempResult와 현재의 result를 비교하여 큰 것을 채택

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
	public:
		int h = -1; // 이 노드가 루트일 때의 최대 높이
		int w = 0; //부모와 연결되는 가중치
		int p = 0; // 부모
		vector<int> c; // 자식
};

int n; // 노드의 개수
Node dataList[10001]; //인덱스가 노드 번호
int height[10001] = {-1}; // 각 노드의 높이
int result;

int findLongestHeight(Node &a)
{
	// cout<<a.w<<" 의 높이: "<<a.h<<endl;
	// cout<<a.w<<endl;
	if (a.h != -1)
	{
		// cout<<"높이 바로 리턴"<<"\n";
		return a.h;
	}
	
	int tmpResult = 0;

	
	for (int i = 0; i < a.c.size(); i++)
	{
		
		tmpResult = max(tmpResult, findLongestHeight(dataList[a.c[i]])+dataList[a.c[i]].w);
	}
	
	a.h = tmpResult;
	// cout<<"업데이트: "<<a.w<<"  의 높이: "<<a.h<<endl;
	// cout<<"입력확인: "<<dataList[9].w<<"  의 높이: "<<dataList[9].h<<endl;
	
	
	
	return a.h;
}

void solve(Node a)
{
	if (a.c.empty())
	{
		return;
	}
	int tempResult = 0;
	
	int max1;
	int max2;
	vector<int> weights;
	weights.push_back(0); // 자식이 하나일 경우 대비
	if (a.c.size() == 1)
	{
		tempResult = findLongestHeight(dataList[a.c[0]])+dataList[a.c[0]].w;
		if (result < tempResult)
		{
			result = tempResult;
		}
		return;
		
	}
	
	
	vector<int>::iterator iter = a.c.begin();
	
	// a의 자식들에 대해 최장높이 구하기
	for (iter = a.c.begin(); iter !=a.c.end(); iter++)
	{
		weights.push_back(findLongestHeight(dataList[*iter])+dataList[*iter].w);
	}
	
	// 각 자식들의 높이 중 최대, 2번째 최대 구하기
	
	// 최댓값 구하기
	max1 = *max_element(weights.begin(), weights.end());
	// 웨이트에서 최댓값 제거
weights.erase(max_element(weights.begin(), weights.end()));
	// 다시 최댓값(2번째 최대)
	max2 = *max_element(weights.begin(), weights.end());
	
	// 높이 계산
	tempResult = max1+max2;
	
	if (result < tempResult)
	{
		result = tempResult;
	}
	
	return;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	if(n == 1)
	{
		cout<<0;
		return 0;
	}
	int a, b, c;
	
	// 트리 구축
	for (int i = 0; i < n-1; i++)
	{

		cin>>a>>b>>c;
		dataList[b].w = c;
		// dataList[b].p = a;
		dataList[a].c.push_back(b);
	}
	
	// test
	// cout<<findLongestHeight(dataList[4])<<endl;
	// solve(dataList[3]);
	
	// cout<<endl<<endl<<"one more"<<endl;
	// solve(dataList[3]);
	
	// cout<<findLongestHeight(dataList[9])<<endl;
	// cout<<endl<<endl<<(dataList[9].h)<<endl;
	// cout<<findLongestHeight(dataList[9])<<endl;
	
	// 풀이
	for (int i = 0; i < n; i++)
	{
		solve(dataList[i]);
		// cout<<findLongestHeight(dataList[1])<<endl;
	}
	
	
	
	cout << result;
	
}
