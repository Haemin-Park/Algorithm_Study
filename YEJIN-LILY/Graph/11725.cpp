#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> tree[100001];
int depth[100001];
int parent[100001];
stack<int> st;

void dfs(int node){
	st.push(node);
	depth[node]=1;
	//parent[node]=-1;
	
	while(!st.empty()){
		int next=st.top();
		st.pop();
		
		
		for(int i=0;i<tree[next].size();i++){
			int next2=tree[next][i];
			
			if(depth[next2]==0){
				st.push(next2);
				depth[next2]=depth[next]+1;
				parent[next2]=next;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	
	int x,y;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y); //양방향
		tree[y].push_back(x);
	}
	
	dfs(1); //루트부터 DFS로 탐색해서 부모노드 저장
	
	for(int i=2;i<=n;i++)
		cout<<parent[i]<<'\n'; //endl: 시간초과의 원인
}
