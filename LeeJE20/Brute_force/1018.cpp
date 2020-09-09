// 2020.08.20 시작
// https://www.acmicpc.net/problem/1018
// 2020.08.25 끝
// correct: 1018

#include<iostream>
#include<climits>
#include<stdio.h>
using namespace std;

int row; //체스판 세로 길이
int column; //체스판 가로 길이

int whiteCount = 0; //왼쪽 위가 white인 경우 체스판 색칠할 개수
int blackCount = 0; //왼쪽 위가 black인 경우 체스판 색칠할 개수
int minCount = INT_MAX; // 다시 칠해야 하는 정사사각형 개수의 최솟값. 무한으로 초기화.

// 체스판
char** board;


// 8 by 8 크기 체스판 검사 
void countColor(int& r, int& c)
{
	// cout<<"r: "<<r<<endl;
	// cout<<"c: "<<c<<endl;
	// 이전 내용 초기화
	blackCount = 0; 
	whiteCount = 0; 
	
	// (r,c)가 체스판의 왼쪽 위일때 검사
	for (int i = r; i < r+8; i++)
	{
		for (int j = c; j < c+8; j++)
		{
			// cout<<"("<<i<<", "<<j<<") = "<< board[i][j];
			//  짝수 부분 (인덱스로 0,0 / 0,2 / 2,2 이런 친구들)
			if ( (i % 2 ) == (j % 2) )
			{
				// cout<<"  짝수 부분"<<endl;
				// 왼쪽 위가 white인 경우
				if (board[i][j] == 'B')
				{
					whiteCount++;
				}
				else //왼쪽 위가 black인 경우
				{
					blackCount++;
				}
			}
			else //홀수 부분 (인덱스 0,1 / 2,3 / 1,1 이런 친구들)
			{
				// cout<<"  홀수 부분"<<endl;
				// 왼쪽 위가 white인 경우
				if (board[i][j] == 'W')
				{
					
					whiteCount++;
				}
				else
				{
					blackCount++;
				}
			}
			// cout<<"wc, bc = "<<whiteCount<<", "<<blackCount<<endl;
		}
	}
	
	// 작은 값을 min으로 선택
	if (minCount > blackCount) minCount = blackCount;
	if (minCount > whiteCount) minCount = whiteCount;
}

void checkBoard()
{

	// cout<<"hello checkBoard()"<<endl;
	int r=0;
	int c=0;
	// cout<<"row: "<<row<<endl;
	// cout<<"column: "<<column<<endl;
	
	
	// 체스판 왼쪽 위
	// 8 by 8 크기로 체스판 돌아야 함
	for(r = 0; r < row - 7; r++)
	{
		for(c = 0; c < column - 7; c++)
		{
			// cout<<"r: "<<r<<"   c: "<<c<<endl;
			countColor(r, c);
		}
	}
}



int main()
{
	register int r=0;
	register int c=0;	
	// cin 속도 빠르게
	cin.sync_with_stdio(false);
	// 나중에 삭제
	// cout<<"1018 start!"<<endl<<endl;
	
	
	cin >> row>> column;
	// cout<<"row: "<<row<<endl;
	// cout<<"column: "<<column<<endl;
	
	// 2차원 동적 배열 만들기
	board = new char*[row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new char[column];
	}
	
	
	// 체스판 모양 입력받기
	// cout<<"입력받기"<<endl;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < column; c++)
		{
			cin>>board[r][c];
			// cout<<"("<<r<<", "<<c<<") = "<<board[r][c]<<" ";
			
		}
		// cout<<endl;
	}
	
	// cout<<"입력 받기 완료"<<endl;
	
	checkBoard();
	
	// cout<<"함수 후: ";
	// cout<<"row: "<<row<<endl;
	// cout<<"column: "<<column<<endl;
	cout<<minCount;	
	
}
