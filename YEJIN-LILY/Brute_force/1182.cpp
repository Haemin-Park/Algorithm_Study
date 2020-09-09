#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N,S;
int cnt=0;

void getSum(int index,int sum){
	sum+=v[index];
	
	//범위 초과
	if(index>=N)
		return;
	//문제에서 요구하는 조건
	if(sum==S)
		cnt++;
	//해당 값을 안 더했을 경우
	getSum(index+1,sum-v[index]);
	//해당 값을 더했을 경우
	getSum(index+1,sum);
}

int main(){
	cin>>N>>S;
	
	v.resize(N);
	
	for(int i=0;i<N;i++)
		cin>>v[i];
	
	getSum(0,0);
	
	cout<<cnt;
}
