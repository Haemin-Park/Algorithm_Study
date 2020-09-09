#include <iostream>
using namespace std;
int n, s, cnt = 0;
int* arr;

void pick(int p_sum, int p) {

	if (p == n)
		return;
	
	if (p_sum + arr[p] == s)
		cnt++;

	int q = p + 1;
	
	pick(p_sum + arr[p], q);
	pick(p_sum, q);

}

int main() {

	cin >> n >> s;
	
	arr = new int[n];
	
	for (int i = 0; i < n ; i++) {
		cin >> arr[i];
	}

	pick(0, 0);

	cout << cnt;

	delete[] arr;
}