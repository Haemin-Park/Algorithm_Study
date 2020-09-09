#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
	
	cin >> n;
	
	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		if (i == 1)
			dp[1] = v[1];
		else if (i == 2)
			dp[2] = v[1] + v[2];
		else if (i == 3) {
			dp[3] = max(v[3] + v[1], v[3] + v[2]);
		}
		else {
			dp[i] = max({ v[i] + v[i - 1] + dp[i - 3], v[i] + dp[i - 2], v[i] + v[i-1] + dp[i - 4] });
		}
		
	}

	cout << max(dp[n], dp[n - 1]);

}