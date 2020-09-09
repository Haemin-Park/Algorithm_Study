#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
string answer="";

void solution(int y,int x,int n){
	char first=v[y][x];

	if(n==1){
		answer+=first;
		return;
	}
	
	bool flag=true;
	
	for(int i=y;i<y+n;i++){
		for(int j=x;j<x+n;j++){
			if(first!=v[i][j]){ //다르면 4개로 분할
				flag=false;
				answer+='(';
				solution(y,x,n/2);
				solution(y,x+n/2,n/2);
				solution(y+n/2,x,n/2);
				solution(y+n/2,x+n/2,n/2);
				answer+=')';
				return;
			}
		}
	}
	
	if(flag){
		answer+=first;
		return;
	}
}

int main(){
	int N;
	cin>>N;
	
	
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		v.push_back(s);
	}
	
	solution(0,0,N);
	cout<<answer;
}
