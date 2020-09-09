#include <iostream>
#include <cmath>
using namespace std;

int cnt=0;
int r,c;
bool flag=true;

void solution(int n,int y,int x){
	if(!flag)
		return;
	
	if(n==1){
		for(int i=y;i<y+2;i++){
			for(int j=x;j<x+2;j++){
				if(i==r&&j==c){
					flag=false;
					return;
				}
				cnt++;
			}
		}
		return;
	}
	
	int square=pow(2,n-1);
	
	//4분면으로 나누었을 때 해당 사분면에 (r,c)가 존재하지 않는다면 굳이 그 사분면을 재귀호출할 필요가 없다.
	if(flag){
		if((y<=r&&r<y+square)&&(x<=c&&c<x+square)) //1사분면에 위치
			solution(n-1,y,x);
		else
			cnt+=pow(2,2*n-2);
	}
	if(flag){
		int dx=x+square; //x값을 변경하면 밑에서 4분면을 호출할 때 x값이 아예 바뀌어버린다. 로컬변수로 선언한다.->여기서 오류..
		if((y<=r&&r<y+square)&&(dx<=c&&c<dx+square)) //2사분면에 위치
			solution(n-1,y,dx);
		else
			cnt+=pow(2,2*n-2);
	}
	if(flag){
		int dy=y+square;
		if((dy<=r&&r<dy+square)&&(x<=c&&c<x+square)) //3사분면에 위치
			solution(n-1,dy,x);
		else
			cnt+=pow(2,2*n-2);
	}
	if(flag){
		int dy=y+square;
		int dx=x+square;
		
		if((dy<=r&&r<dy+square)&&(dx<=c&&c<dx+square)) //4사분면에 위치
			solution(n-1,dy,dx);
		else
			cnt+=pow(2,2*n-2);
	}
	
}

int main(){
	int n;
	scanf("%d %d %d",&n,&r,&c);
	
	solution(n,0,0);
	cout<<cnt;
}
