#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, m, bc = 0, wc = 0, min_c = 2501;
	char c;

	vector<vector<char>> bb({
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'})
	});
	vector<vector<char>> wb({
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'}),
		vector<char>({ 'W','B','W','B','W','B','W','B'}),
		vector<char>({ 'B','W','B','W','B','W','B','W'})
	});

	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			board[i][j] = c;
		}
	}

	for (int w = 0; w + 7 < m; w++) {
		for (int h = 0; h + 7 < n; h++) {

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {

					if (board[h + i][w + j] != bb[i][j])
						bc++;

					if (board[h + i][w + j] != wb[i][j])
						wc++;

				}
			}
	
			if (bc <= wc && bc <= min_c)
				min_c = bc;
			else if (wc < bc && wc <= min_c)
				min_c = wc;
			
			bc = 0;
			wc = 0;
		}
		
	}
	cout << min_c;

	return 0;
} 
