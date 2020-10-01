// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
// 원인: 시간초과

/* 아이디어
	1. 입력받은 두 개의 정점 중 이미 출현한 적 있는 정점이 무조건 부모이고, 새로운 정점이 자식임
	 ex) 1 6, 6 3, 3 5 순으로 들어왔다면  1(root) -> 6 -> 3 -> 5 순으로 트리가 연결되어 있다는 뜻
	2. 배열 parent에 부모 노드 번호 저장. 따라서 출현한 적 있는 정점은 parent에서 양의 정수를 가짐
	3. 두 정점이 모두 처음 출현한다면 큐에 담아서 순서를 뒤로 보내 나중에 처리한다.
*/


#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

//#define MAX 100000



int main() {

	
	int n, size;

	scanf_s("%d", &n);

	size = n + 1;
	int* parent=new int[size](); // 인덱스: 정점 번호, 저장된 원소: 부모 노드의 번호
	
	parent[1] = 1; // init

	int v1, v2;
	queue<int> f_Q; // save first vertex v1
	queue<int> s_Q; // save second vertex v2
	
	for (int i = 1; i < n; i++) {
		scanf_s("%d %d",&v1, &v2);
		if (parent[v1] > 0) { // case1: v1이 v2의 부모
			parent[v2] = v1;
		}
		else if(parent[v2] > 0){ // case2: v2가 v1의 부모
			parent[v1] = v2;
		}
		else { // case3: 두 정점 중 누가 부모인지 알 수 없음. 나중에 처리
			f_Q.push(v1);
			s_Q.push(v2);
		}
	}


	// case3만 따로 처리
	while (!f_Q.empty()) {
		v1 = f_Q.front();
		v2 = s_Q.front();
		f_Q.pop();
		s_Q.pop();
		if (parent[v1] > 0) {
			parent[v2] = v1;
		}
		else if (parent[v2] > 0) {
			parent[v1] = v2;
		}
		else {
			f_Q.push(v1);
			s_Q.push(v2);
		}


	}

	// 부모 노드 출력
	for (int i = 2; i < size; i++) {
		printf("%d\n",parent[i]);
	}




	return 0;
}
