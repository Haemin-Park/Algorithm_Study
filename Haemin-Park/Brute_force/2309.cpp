#include <iostream>
#include <algorithm>
using namespace std;

int n[9], sum = 0, n1, n2;

bool find() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {

			if (n[i] + n[j] == sum) {
				n1 = n[i];
				n2 = n[j];

				return true;
			}

		}
	}
	
	return false;
}

int main() {

	for (int i = 0; i < 9; i++) {
		cin >> n[i];
		sum += n[i];
	}

	sum -= 100;

	find();
	sort(n, n + 9);

	for (int i = 0; i < 9; i++) {

		if (n[i] == n1 || n[i] == n2)
			continue;
		cout << n[i] << endl;
	}
}