#include <iostream>
using namespace std;
int s[6562][6562] = { 0, };

void star(int n, int x, int y, bool t) {
	
	if (n < 1) return;

	if (t) {
		for (int i = y ; i < y + n; i++) {
			for (int j = x ; j < x + n; j++)
				s[i][j] = 1;
		}
	}
	else {
		for (int i = 0; i < 3; i++) { // 9등분
			for (int j = 0; j < 3; j++) {
				if(i==1 && j==1)
					star(n / 3, x + j * n / 3, y + i * n / 3, true);
				else
					star(n / 3, x + j * n / 3, y + i * n / 3, false);
			}
		}
	}
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < 3; i++) { // 9등분
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				star(n / 3, j * n / 3, i * n / 3, true);
			else
				star(n / 3, j * n / 3, i * n / 3, false);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 1)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
}