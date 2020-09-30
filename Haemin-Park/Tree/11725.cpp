#include <iostream>
#include <vector>
using namespace std;

int r[100001] = {0,};
vector<int> v[100001];

void findP(int n){
	for(int i=0; i<v[n].size(); i++){
		if(r[v[n][i]] == 0){
			r[v[n][i]] = n;
			findP(v[n][i]);
		}
	}
}

int main() {
	
	int n, a, b;
	
	cin.tie(0);
	cin>>n;
	r[1] = -1;
	for(int i=2; i<=n; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	findP(1);
	
	for(int i=2; i<=n; i++){
		cout<<r[i]<<"\n";
	}
	
	return 0;
}
