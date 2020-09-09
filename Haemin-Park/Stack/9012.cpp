#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<string> r(1000,"");
stack<char> s;

void check(int n, string v) {

	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		s.push(v.at(i)); // at(i): Receiving text from a specific location in a string
	}

	for (int i = 0; i < v.size(); i++) {
		if (i == 0 && s.top() == '(') {
			r[n] = "NO";
			return;
		}
		else if (i == v.size() - 1 && s.top() == ')') {
			r[n] = "NO";
			return;
			
		}
		else {
			if (s.top() == ')') { 
				s.pop();
				cnt++; 
			}
			else if (s.top() == '(') { 
				s.pop();
				cnt--;
				if (cnt < 0) {
					r[n] = "NO";
					return;
				}
			}
		}
	}

	if (cnt == 0) r[n] = "YES";
	else r[n] = "NO";
	
}

int main() {
	
	cin >> n;
	vector<string> v(n, "");

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		s = {};//stack initialization
		check(i, v[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << r[i] << endl;
	}
}