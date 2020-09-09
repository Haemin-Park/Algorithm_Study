#include <iostream>
#include <string>
using namespace std;
int six = 665;

int main() {

	int n, p, cnt=0;
	string ssix;

	cin >> n;

	while (cnt != n)
	{
		six++;
		ssix = to_string(six);
		if (ssix.find("666") != string::npos) { // 문자열이 없을 때 string::npos 반환
			cnt++;
		}
		
	} 

	cout << six;

}