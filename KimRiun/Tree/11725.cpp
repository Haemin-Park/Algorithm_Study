// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000
int parent[MAX];
int n;



int main() {

	cin >> n;

	
	
	parent[1] = 1; // init

	int v1, v2;
	for (int i = 1; i < n; i++) {
		cin >> v1 >> v2;
		if (parent[v1] > 0) {
			parent[v2] = v1;
		}
		else if(parent[v2] > 0){
			parent[v1] = v2;
		}
	}


	for (int i = 2; i < n+1; i++) {
		cout << parent[i] << "\n";
	}




	return 0;
}
