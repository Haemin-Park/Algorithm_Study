// 2020-09-01 12:24 시작
// https://www.acmicpc.net/problem/2156
// 포도주 시식
// wrong: 2156 

/*
감상평: 
*/


/* 아이디어

돌놓기처럼..


캐시테이블[포도주 번호: n][이번의 선택: 2(o 또는 x)][케이스 ox, xo, xx, oo: 4]

이번 잔 선택
	직전 o, 전전 x:
		max( ct[n-1][1][0]~ct[n-1][1][0] )
	직전 x, 전전 o
	직전 x, 전전 x
	직전 o, 전전 o : -1
	
	
이번 잔 비선택
	전전 o, 직전 x
	전전 x, 직전 o
	전전 x, 직전 x
	전전 o, 직전 o



0부터 n-1까지 캐시테이블 채우고, CT[n-1][][] 중 최댓값을 답으로 낸다.
*/

#include<iostream>
#include<stdio.h>
#include<algorithm> // max 사용
using namespace std;

int N; // 포도주 잔의 개수
int q[10000]; // 포도주 양. quantity
int ct[10000][2][4] = {-1, }; // 캐시테이블.


int main()
{
	cin.sync_with_stdio(false);
	// cout<<endl<<"2156 start"<<endl;
	
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>q[i];
	}
	
	// 2번째가 o
	ct[1][1][0] = q[1]; // xo 로 시작.. 다음의 xo
	ct[1][1][1] = q[0]+q[1]; // oo 로 시작.. 다음의 oo
	ct[1][1][2] = q[1]; // xo로 시작.. 다음의 xo
	
	// 2번째가 x
	ct[1][0][0] = 0; // xx 로 시작.. 다음의 xx
	ct[1][0][1] = q[0]; // ox 로 시작.. 다음의 ox
	ct[1][0][2] = 0; // xx로 시작..  다음의 xx
	ct[1][0][3] = q[0]; // ox로 시작. 다음의 ox
	
	for (int i = 2; i < N; i++)
	{
		// 현재o 
		// ox
		ct[i][1][0] = q[i] + max(ct[i-1][0][1], ct[i-1][0][3]);
		// xo
		ct[i][1][1] = q[i] + max(ct[i-1][1][0], ct[i-1][1][2]);
		// xx
		ct[i][1][2] = q[i] + max(ct[i-1][0][0], ct[i-1][0][2]);
		
		// 현재 x 
		// ox
		ct[i][0][0] = max(ct[i-1][0][1], ct[i-1][0][3]);
		// xo
		ct[i][0][1] = max(ct[i-1][1][0], ct[i-1][1][2]);
		// xx
		ct[i][0][2] = max(ct[i-1][0][0], ct[i-1][0][2]);
		// oo
		ct[i][0][3] = ct[i-1][1][1];
		
	}
	
	int result = max({ct[N-1][1][0], ct[N-1][1][1], ct[N-1][1][2],        ct[N-1][0][0], ct[N-1][0][1], ct[N-1][0][2], ct[N-1][0][3]});
		
	cout<<result;
}
