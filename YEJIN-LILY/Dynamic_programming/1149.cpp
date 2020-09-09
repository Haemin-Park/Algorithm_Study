#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[1000][3];
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	int d[1000][3];
	d[0][0]=arr[0][0]; //초기값 세팅
	d[0][1]=arr[0][1];
	d[0][2]=arr[0][2];
	
	
	for(int i=1;i<n;i++){ //점화식 이용
		d[i][0]=min(d[i-1][2],d[i-1][1])+arr[i][0];
		d[i][1]=min(d[i-1][0],d[i-1][2])+arr[i][1];
		d[i][2]=min(d[i-1][0],d[i-1][1])+arr[i][2];
	}
	
	cout<<min(d[n-1][0],min(d[n-1][1],d[n-1][2]));
}
