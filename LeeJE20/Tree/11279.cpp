// 2020-11-04 21:46 시작
// https://www.acmicpc.net/problem/11279
// 최대 힙
// 2020-11-04 21:59 종료
// wrong: 11279





/*아이디어



*/



#pragma warning (disable: 4996)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<int> v;




int main()
{
	scanf("%d", &N);
	int op = -1;
	for (int i = 0; i < N; i++)
	{
		//cout << "idx: " << i << endl;
		scanf("%d", &op);
		if (op > 0)
		{
			v.push_back(op);
		}
		else
		{
			if (v.empty())
			{
				printf("0\n");
			}
			else
			{
				sort(v.begin(), v.end());

				printf("%d\n", v.back());
				v.pop_back();
			}
		}
	}
	return 0;
}

