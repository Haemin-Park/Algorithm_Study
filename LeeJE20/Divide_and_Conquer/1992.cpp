// 2020.08.26 20:31 시작
// https://www.acmicpc.net/problem/1992
// 이정은 작성
// 2020.08.26 21:26 종료
// correct: 1992

#include<iostream>
#include<vector>
using namespace std;



int N; // 영상의 크기
char Image[64][64];

int recursionCount = 0;
// 아이디어
/*
// if size == 1 -> 그 수 반환 (이 줄은 안 해도 될 것 같다)
모든 칸을 다 읽는다
if 전부 같은 수 -> 그 수 반환(출력) (base)
else
	4칸으로 분할한다
	cout<<(
	각 칸에 대해:
		재귀호출
	cout<<)
*/

// size: 영상의 크기
// order: 순서(왼쪽위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서대로)
void makeQuadTree(int size, int row, int column)
{
	// recursionCount++;
	bool isAllSame = true;
	// if (size == 1) cout<<Image[row][column];
	char base = Image[row][column];
	
	
	// 모든 칸을 다 읽는다. 다른 것이 하나라도 있는지 찾는다.
	for (int r = row; r < row+size; r++)
	{
		for (int c = column; c < column+size;c++)
		{
			// 다른게 있나?
			if(Image[r][c] != base)
			{
				isAllSame = false;
				break;
			}
		}
		// 다른걸 찾았으니 루프 그만 돌자~
		if (!isAllSame) break;
	}
	
	
	// 모두 같다면 그 값 반환
	if (isAllSame)
	{
		// 처음 입력받은 영상이 모두 같은 숫자였을때 괄호 표기
		//헐,,, 이건 괄호 안 쳐도 되네..
		// if (recursionCount==1) cout<<"(";
		cout<<base;
		// if (recursionCount==1) cout<<")";
	}
	else
	{
		cout<<"(";
		makeQuadTree(size/2, row, column);
		makeQuadTree(size/2, row, column+size/2);
		makeQuadTree(size/2, row+size/2, column);
		makeQuadTree(size/2, row+size/2, column+size/2);
		cout<<")";
	}
}

int main()
{
	// cout<<endl<<"1992 start~"<<endl;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	// cout<<endl<<"N: "<<N<<endl;
	
	// 영상 입력받기
	for (int row = 0; row < N; row++)
	{
		for (int column = 0; column < N; column++)
		{
			cin >> Image[row][column];
			
			// cout<< Image[row][column]<<" ";
		}
		// cout<<endl;
	}
	
	// cout<<endl<<"재귀함수 시작"<<endl<<endl;
	makeQuadTree(N,0,0);
	// cout<<endl<<"종료합니다."<<endl;
	
}
