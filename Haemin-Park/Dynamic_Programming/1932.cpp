#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n;

	cin >> n;
	
	vector<vector<int>> t(n + 1, vector<int>(n + 1));
	vector<vector<long>> dp(n + 1, vector<long>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> t[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + t[i][j];
		}
	}

	long max=0;

	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i])
			max = dp[n][i];
	}

	cout << max;
	
}