#include <iostream>
#include <vector>
using namespace std;
long long p[101];

long long pado(int n) {

	if (p[n] != -1) {
		return p[n];
	}
	else {
		if (n - 5 < 0)
			return p[n] = pado(n - 1) + pado(5 - n);
		else if (n - 5 == 0)
			return p[n] = pado(n - 1);
		else
			return p[n] = pado(n - 1) + pado(n - 5);
	}
}

int main() {

	for (int i = 0; i < 101; i++)
		p[i] = -1;

	p[1] = 1; p[2] = 1; p[3] = 1;


	int t;
	cin >> t;
	vector<int> v(t);

	for (int i = 0; i < t; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < t; i++) {
		cout << pado(v[i]);
		if (i != t - 1)
			cout << endl;
	}
	
}