#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> str;
char qt[64][64];

bool allColorSame(int n, int x, int y) {

	char first;

	first = qt[y][x];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (qt[y][x] != qt[i][j])
				return false;
		}
	}

	return true;
}

void quardTree(int n, int x, int y) {

	if (n == 1) {

		str.push_back(qt[y][x]);
		return;
	}
	else if (allColorSame(n, x, y)) {

		str.push_back(qt[y][x]);
		return;
	}
	else {
		str.push_back('(');
		quardTree(n / 2, x, y);
		quardTree(n / 2, x + n / 2, y);
		quardTree(n / 2, x, y + n / 2);
		quardTree(n / 2, x + n / 2, y + n / 2);
		str.push_back(')');
	}
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> qt[i][j];

		}
	}

	quardTree(n, 0, 0);

	for (int i = 0; i < str.size(); i++)
		cout << str[i];
}