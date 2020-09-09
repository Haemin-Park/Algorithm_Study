#include <iostream>
using namespace std;

int main() {

	int n,sum,tmp;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		sum = i;
		tmp = i;

		for(int j = 1000000; j >= 1; j=j / 10) {
			sum = sum + tmp / j;
			tmp = tmp % j;
		}
		
		if (sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	
	return 0;
}
