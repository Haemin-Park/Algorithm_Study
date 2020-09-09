#include <iostream>
using namespace std;
long long f[1000001];

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < 1000001; i++) {
		f[i] = -1;
	}
	f[1] = 1; f[2] = 2;

	for (int i = 3; i <= n; i++) {
		
		f[i] = (f[i - 1] + f[i - 2]) % 15746;
	}

	cout << f[n];
	
}