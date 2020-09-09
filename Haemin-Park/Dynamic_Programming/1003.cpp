#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int f[50], z[50], o[50]; 

tuple<int,int> fibo(int n) {

	if (n == 0) {
		z[n] = 1;
		return make_tuple(z[n], o[n]);
	}
	else if (n == 1) {
		o[n] = 1;
		return make_tuple(z[n], o[n]);
	}
	else {
		
		if (z[n] != 0 || o[n] != 0) {

			return make_tuple(z[n], o[n]);
		}
		else {

			tuple<int, int> t1, t2;

			t1 = fibo(n - 1);
			t2 = fibo(n - 2);

			z[n] = get<0>(t1) + get<0>(t2);
			o[n] = get<1>(t1) + get<1>(t2);

			return make_tuple(z[n], o[n]);
		}

	}
}

int main() {

	int n;

	for (int i = 0; i < 50; i++) {
		f[i] = -1;
		
		z[i] = 0;
		o[i] = 0;
	}
	f[0] = 0; f[1] = 1;

	cin >> n;
	vector<int> tc(n);
	for (int i = 0; i < n; i++) {
		cin >> tc[i];
	}
	for (int i = 0; i < tc.size(); i++) {
		
		fibo(tc[i]);
		cout << z[tc[i]] << " " << o[tc[i]];
		if (i != tc.size() - 1)
			cout << endl;

	}
}