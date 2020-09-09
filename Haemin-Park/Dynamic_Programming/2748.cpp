#include <iostream>
using namespace std;

long long f[100];

long long fibo(int n) {

	long long& ret = f[n];
	if (n == 0) return ret;
	else if (n == 1) return ret;
	else {

		if (ret != -1) {
			return ret;
		}
		else return ret = fibo(n - 1) + fibo(n - 2);
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < 100; i++) {
		
		f[i] = -1;
	}

	f[0] = 0; f[1] = 1;

	cout << fibo(n);
}