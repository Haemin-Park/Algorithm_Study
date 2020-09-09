#include <iostream>
#include <algorithm>
using namespace std;

/*
n'개'의 잔이 있을 때, 경우는 2가지로 나눌 수 있다.
1. n-1번째 잔을 마신 경우: 연속 3잔이 되면 안 되기 때문에 n-2번째 잔은 마시면 안된다
d[n]=d[n-3]+arr[n-1]+arr[n];

2. n-1번째 잔을 안 마신 경우: 상관없음
d[n]=d[n-2]+arr[n]

**주의**
두 번 연속 먹지 않을 경우가 존재한다=n번째의 잔을 먹지 않을 수도 있음
d[n]=d[n-1]
*/

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[10001];
	
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	
	int d[10001];
	d[0]=0;
	d[1]=arr[1];
	d[2]=arr[1]+arr[2];

	for(int i=3;i<=n;i++){
		d[i]=max(d[i-3]+arr[i-1]+arr[i],max(d[i-2]+arr[i],d[i-1])); ->i 대신 n을 넣어서 오류..
	}
	
	cout<<d[n];
}
