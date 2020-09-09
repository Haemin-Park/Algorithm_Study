// 2020-09-08 16:36 시작
// https://www.acmicpc.net/problem/9012
// 괄호
// 2020-09-08 17:42 종료
// correct: 9012

/*
감상평: 
문제 자체는 평이했으나, 입력 받는 부분이 어려웠다.
처음에 while(cin>>text)로 하면 개행 나오면 자동으로 중단될 줄 알았는데 아니었다...
그래서 string으로 받았다.

마지막에 9012 start를 안 지워서 오랜 기간 삽질했다...그냥 저런거 쓰지 말자..
*/ 

/*아이디어
STL 스택 쓰자.

스택 생성 (전역으로 하면 다음 입력 전에 지우기 귀찮으니까 로컬로 하자)
while 입력이 끝날 때까지:
	if ( :
		스택에 넣는다
	else ) :
		if stack is not empty:
			스택 pop
		else //스택이 비었다면, 즉 (가 없어서 짝이 안 맞으면
			cout<<NO
			break
if stack is not empty: // (가 짝지어지지 못하고 끝난 경우
	cout<< NO
else
	cout<< YES

*/

#include <iostream>
#include <stack>
#include <stdio.h>
#include<string.h>
using namespace std;

int T; // T개의 텍스트 데이터가주어질 것이다.

int main()
{
	// cout<<endl<<"9012 시작!"<<endl;
	scanf("%d", &T);
	// cout<<T<<endl;
	
	string b; //입력받은 괄호(bracket)

	for (int i = 0; i < T; i++)
	{
		// cout<<endl<<"루프시작 : "<<i<<endl;
		bool flag = true;
		int cnt = 0;
		cin >> b; 
		
		for (int j = 0; j < b.size(); j++)
		{
			// cout<<b<<endl;
			// scanf("%s", &b);
			if (b[j] == '(')
			{
				cnt++;
			}
			else // )인 경우
			{
				if(cnt > 0) // (가 있어서 짝이 잘 맞으면
				{
					cnt--;
				}
				else //cnt가 0인 경우
				{
					printf("NO\n"); // (가 없어서 짝이 안 맞으면. 즉, )가 많은 경우
					flag = false;
					break;
					
				}
			}
		}
		
		// cout<<"입력끝"<<endl;
		if (flag)
			cout << ( (cnt==0) ? "YES\n":"NO\n"); // 짝이 맞는 경우 : (가 많은 경우
		// scanf("%s", &b);
	}
	
	return 0;
}