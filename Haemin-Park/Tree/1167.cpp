#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NODE 100000
using namespace std;

int max_sum, x;
vector<int> g[MAX_NODE + 1];
bool check[MAX_NODE + 1];

void dfs(int start, int sum) {
	check[start] = true;
	//x = start;
	for (int i = 0; i < g[start].size(); i+=2) {
		if (g[start][i] != -1) {
			int next = g[start][i];
			if (check[next] == false) {
				sum += g[start][i + 1];
				dfs(next, sum);
				if (i + 3 < g[start].size())
					sum -= g[start][i + 1];
			}
		}
		else {
			if (max_sum < sum) {
				max_sum = sum;
				x = start;
				cout << start;
			}
			//max_sum = max(max_sum, sum);
		}

	}
}

int main() {
	int v_num, v, input = 0, sum = 0;

	cin >> v_num;

	for (int i = 1; i <= v_num; i++) {
		cin >> v;
		while (input != -1) {
			cin >> input;
			g[v].push_back(input);
		}
		input = 0;
	}

	fill(check, check + v_num + 1, false);
	dfs(1, sum);

	fill(check, check + v_num + 1, false);
	sum = 0;
	dfs(x, sum);
	cout << max_sum;
}