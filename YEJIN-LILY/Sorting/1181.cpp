#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;

bool compare(string a,string b){
	if(a.length()==b.length())
		return a<b;
	else
		return a.length()<b.length();
}

int main(){
	int N;
	scanf("%d",&N);
	
	answer.resize(N);
	
	for(int i=0;i<N;i++){
		cin>>answer[i];
	}
	
	sort(answer.begin(),answer.end(),compare);
	
	cout<<answer.size()<<endl;
	for(int i=0;i<answer.size();i++){
		if(i==0||answer[i-1]!=answer[i]) //중복되는 것은 벡터에서 처리할 필요 없이 출력만 안 하면 된다
			cout<<answer[i]<<endl;
	}
}
