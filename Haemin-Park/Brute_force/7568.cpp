#include <iostream>
using namespace std;

int main() {

	int n, kg, cm, num;

	cin >> n;

	int **people = new int*[n];

	for (int i = 0; i < n; i++) {
		cin >> kg >> cm;
		people[i] = new int[2];
		people[i][0] = kg;
		people[i][1] = cm;

	}

	for (int i = 0; i < n; i++)
	{
		num = 1;
		for (int j = 0; j < n; j++) {
			if (people[i][0] < people[j][0] && people[i][1] < people[j][1])
				num++;
		}
		cout << num << " ";
	}
}
