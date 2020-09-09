#include <iostream>
#include <vector>
using namespace std;
int paper[128][128];
int w = 0, b = 0;

void findColor(int n, int x, int y) {

	int wc = 0, bc = 0;

	if (n == 1) {
		if (paper[y][x] == 0)
			w++;
		else
			b++;

	}
	else {

		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {

				if (paper[i][j] == 0) {
					wc++;
				}
				else if (paper[i][j] == 1) {
					bc++;
				}
			}
		}

		if (wc == n * n) w++;
		else if (bc == n * n) b++;
		else {
			findColor(n / 2, x, y);
			findColor(n / 2, x + n / 2, y);
			findColor(n / 2, x, y + n / 2);
			findColor(n / 2, x + n / 2, y + n / 2);
		}
	}
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> paper[i][j];

		}
	}

	findColor(n, 0, 0);

	cout << w << endl << b;

}
