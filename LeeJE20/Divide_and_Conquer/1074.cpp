// 2020-08-27 23:48 시작
// https://www.acmicpc.net/problem/1074
// 2020-08-28 02:07 종료
// correct: 1074

#include<iostream>
#include<stdio.h>
using namespace std;

/*
아이디어

쿼드트리랑 비슷하게 하자!!

int arr[2^15][2^15] // 최대 크기 배열

배열 안에 몇 번째로 방문하는지 정답을 적어두고, 그 정답을 리턴하자!
-> 스택 오버플로우 난다!!!
-> 그냥 방문하면서 그 칸이 r,c인지 확인하자..


정답을 어떻게 적을까??
if size(사이즈는 한 변의 길이) <2 : //제일 작게 쪼개진 경우. 기저 케이스.
	배열 안에 정답을 적는다. -> 전역변수를 하나 만들어두고, 적고 나서 1증가한다. // 이 줄은 하지 않는다.
	if row,column가 원하던 좌표: cout하고 끝 // 변경
	size가 1이 되는 경우는 원하는 r, c에 도착한 경우뿐이므로 order를 cout한다.
else
	4등분으로 쪼갠다.
	r,c가 어느 쪽에 포함되는지 계산한다:
		r, c의 인덱스를 이용해서 구한다.
		포함되는 위치를 location = 0, 1, 2, 3으로 정한다. (0: 왼쪽 위, 1: 오른쪽 위, 2: 왼쪽 아래, 3: 오른쪽 아래)
	
	r, c가 포함되는 조각보다 선행되는 조각의 방문순서를 더해준다:
		order = order + (size/2) *(size/2) * location;
	r,c가 포함되는 조각에 리컬젼으로 방문한다.
	

*/

int N; // 2차원 배열의 크기.
int r; // 찾고자 하는 위치의 row
int c; // 찾고자 하는 위치의 column

// int answer[32768][32768]; // 2차원 배열. 이 배열 안에 정답을 적어둔다.
int order = 0; //방문 순서



void findOrder(int row, int column, int size)
{
	// printf("row: %2d, column: %2d, size: %2d\n");
	// size가 1인 경우. 찾고자 하는 그 위치에 도착함. : 기저
	if (size < 2)
	{	
		// 결과 출력 후 종료
		cout<<order;
		exit(0);
	}
	
	
	//r,c가 어느 조각에 포함되는지 계산한다:
	//location = 0, 1, 2, 3으로 정한다. (0: 왼쪽 위, 1: 오른쪽 위, 2: 왼쪽 아래, 3: 오른쪽 아래)
	int location = -1;
	if ( (row <= r) && (r < row+size/2) && (column <= c) && (c < column+size/2) )
	{
		location = 0;
	}
	else if ( (row <= r) && (r < row+size/2) && (column+size/2 <= c) && (c < column+size) )
	{
		location = 1;
	}
	else if ( (row+size/2 <= r) && (r < row+size) && (column <= c) && (c < column+size/2) )
	{
		location = 2;
	}
	else if ( (row+size/2 <= r) && (r < row+size) && (column+size/2 <= c) && (c < column+size) )
	{
		location = 3;
	}
	else
	{
		// cout<<"location error!"<<endl;
		exit(0);
	}
	
	
	
	//r, c가 포함되는 조각보다 선행되는 조각의 방문순서를 더해준다:
	order = order + (size/2) *(size/2) * location;
	
	// printf("location: %d, order = %3d\n");
	
	// r,c가 포함되는 조각에 리컬젼으로 방문한다.
	switch(location)
	{
		case 0:
			findOrder(row, column, size/2);
			break;
		case 1:
			findOrder(row, column+size/2, size/2);
			break;
		case 2:
			findOrder(row+size/2, column, size/2);
			break;
		case 3:
			findOrder(row+size/2, column+size/2, size/2);
			break;
		default:
			// cout<<"error"<<endl;
			break;
			
	}
	
	// if ()
	// findOrder(row, column, size/2);
	// findOrder(row, column+size/2, size/2);
	// findOrder(row+size/2, column, size/2);
	// findOrder(row+size/2, column+size/2, size/2);
	
	
}


int main()
{
	cin.sync_with_stdio(false);
	
	// printf("\n1074 start!\n");
	
	cin >> N >> r >> c;
	
	int size = 2 << (N-1); //size는 2^N이다.
	// cout<<size;
	findOrder(0, 0, size);
}
