#include <iostream>
using namespace std;

int main() {
	int n;
	int s[301], step[301];
	long dp[301];

	s[0] = 0; dp[0] = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> s[i];
	
	dp[1] = s[1]; step[1] = 0;
	for (int i = 2; i <= n; i++) {
		
		if ((dp[i - 1] > dp[i - 2]) && (step[i - 1] != 1)) {
			dp[i] = s[i] + dp[i - 1];
			step[i] = 1;
		}
		else {
			
			if (s[i - 1] + dp[i - 3] > dp[i - 2]) {

				dp[i] = s[i] + s[i - 1] + dp[i - 3];
				step[i] = 1;
			}
			else {
				dp[i] = s[i] + dp[i - 2];
				step[i] = 2;
			}
				
		}

	}

	cout << dp[n];
}