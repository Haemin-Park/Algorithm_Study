// tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.*/
/*첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.*/
#define MAX 100000 

vector<vector<int> > v;
int parent[MAX];
int check[MAX];
int N; 

void tree(int x) {
    //parent 구분
    check[x] = true; //1부터 시작 true

    for (int i = 0; i < v[x].size(); i++) { //해당 노드와 연결되어있는 노드 확인
        if (check[v[x][i]] == false) { //만약 체크되지 않았다면 자식이다 
            parent[v[x][i]] = x; //부모 넣기
            tree(v[x][i]); //재귀
        }
    }
}


void printp() {//출력
    for (int i = 2; i < N+1; i++)
        cout << parent[i];
}

int main()
{
    cin >> N;
    v.resize(N + 1);

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;     
        v[y].push_back(x);
        v[x].push_back(y); //양쪽 노드
       
    }
    tree(1); //부모찾기
    //cout << "dk";
    printp();
}

