#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/7562
// 나이트의 이동
// 너비우선 경로계산
// 2021.01.

bool isInRange(const int &l, const int &cx, const int &cy)
{
	if (cx<l && cx >= 0 && cy < l && cy >= 0)
		return true;
	else
		return false;
}

// bool isCloser(const int &cx, const int &cy, const int &mx, const int &my, const int &tx,const int &ty)
// {
// 	int now = ((tx-cx)*(tx-cx)) + ((ty-cy)*(ty-cy));
// 	int move = ((tx-mx)*(tx-mx)) + ((ty-my)*(ty-my));
	
// 	if (move > now)
// }

void find(const int &l, int cx, int cy,const int &tx,const int &ty, vector<vector<int>> &count, vector<vector<bool>> &found, queue<int> & qx, queue<int> &qy)
{
	while(!qx.empty())
	{
		int mx = qx.front();
		qx.pop();
		
		int my = qy.front();
		qy.pop();
		cx = mx;
		cy = my;
		
		// cout<<"now: "<<cx<<", "<<cy<<endl;
		
		if (cx == tx && cy == ty)
		{
			break;
		}

		for (int i = -1; i < 2; i+=2)
		{
			for (int j = -2; j < 3; j+=4)
			{
				if (isInRange(l, cx+i, cy+j))
				{
					// cout<<"inRange: "<<cx+i<<", "<<cy+j<<endl;
					if (!found[cx+i][cy+j])
					{
						found[cx+i][cy+j] = true;
						qx.push(cx+i);
						qy.push(cy+j);
						count[cx+i][cy+j] = count[cx][cy]+1;
					}
				}
				if (isInRange(l, cx+j, cy+i)&& (!found[cx+j][cy+i]))
				{
					if (!found[cx+j][cy+i])
					{
						found[cx+j][cy+i] = true;
						//find(l, cx+j, cy+i, tx, ty, count);
						qx.push(cx+j);
						qy.push(cy+i);
						count[cx+j][cy+i] = count[cx][cy]+1;
					}
				}
			}
		}
		
		
		
	}
	

	
	cout<<count[cx][cy]<<"\n";
	return;
	
}

void solution()
{
	int l, cx, cy, tx, ty; //current, target
	
	cin>>l>>cx>>cy>>tx>>ty;
	vector<vector<bool>> found(l, vector <bool>(l,false) );
	
	vector<vector<int>> count(l, vector <int>(l,0) );
	
	found[cx][cy] = true;
	queue<int> qx;
	queue<int> qy;
	
	qx.push(cx);
	qy.push(cy);
	find(l, 0, 0, tx, ty, count, found, qx, qy);

	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		solution();
	}
}
