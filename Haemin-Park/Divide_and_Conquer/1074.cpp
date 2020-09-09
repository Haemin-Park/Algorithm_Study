#include <iostream>
#include <cmath>
using namespace std;
int n, r, c, cnt = -1;

void s(int n, int y, int x) {

	if (n == 2) { // 4개(하나의 Z)
		cnt++;
		if (y == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		return;
	}
	
	s(n / 2, y, x);
	s(n / 2, y, x + n / 2);
	s(n / 2, y + n / 2, x);
	s(n / 2, y + n / 2, x + n / 2); 
	// Z모양
}

int main() {
	cin >> n >> r >> c;
	s(pow(2, n), 0, 0);
}