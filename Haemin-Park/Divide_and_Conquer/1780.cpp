#include<iostream>
using namespace std;
int p[2187][2187];
int mo = 0, z = 0, o = 0;

bool isSame(int n, int x, int y) {

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (p[y][x] != p[i][j])
				return false;
		}
	}

	return true;

}

void paper(int n, int x, int y) {

	if (n == 1 || isSame(n, x, y)) {
		if (p[y][x] == -1)
			mo++;
		else if (p[y][x] == 0)
			z++;
		else if (p[y][x] == 1)
			o++;
	}
	else {

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				paper(n / 3, x + j * n / 3, y + i * n / 3);
			}
		}

	}
}

int main() {


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}

	paper(n, 0, 0);

	cout << mo << endl << z << endl << o;

}