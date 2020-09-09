#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n,r,g,b;
	cin >> n;

	vector<vector<int>> h(n + 1, vector<int>(3));
	vector<vector<int>> dp(n + 1, vector<int>(3));

	for (int i = 1; i <= n; i++) {
		
		cin >> r >> g >> b;
		h[i][0] = r; h[i][1] = g; h[i][2] = b;
	}

	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + h[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + h[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + h[i][2];
	}

	cout << min({ dp[n][0], dp[n][1], dp[n][2]});
}