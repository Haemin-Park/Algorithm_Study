#include <iostream>
using namespace std;
int n, t_max = 0;
int day[20][2];

void pick(int d, int total) { //d: 일이 끝나는 날
	if (d == n) {
		if (t_max < total) t_max = total;
		return;
	}
	else {
		for (int i = d + 1; i <= n; i++) {
			if (i + day[i][0] - 1 > n) {
				if (t_max < total) t_max = total;
			}
			else
				pick(i + day[i][0] - 1, total + day[i][1]);
	
		}
		return; 
	}
}

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> day[i][0] >> day[i][1];
	}
	
	for (int i = 1; i <= n; i++) {
		pick(i+ day[i][0]-1, day[i][1]); // 시작일 픽스
	}
	
	cout << t_max;
}