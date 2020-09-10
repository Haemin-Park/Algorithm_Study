#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string is_VPS(string s){
	stack<char> st;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')
			st.push(s[i]);
		else if(st.empty()&&s[i]==')')
			return "NO";
		else
			st.pop();
	}
	
	if(st.empty())
		return "YES";
	else
		return "NO";
}

int main(){
	int t;
	scanf("%d",&t);
	
	vector<string> answer;
	
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		
		answer.push_back(is_VPS(s));
	}
	
	for(int i=0;i<answer.size();i++)
		cout<<answer[i]<<endl;
}
