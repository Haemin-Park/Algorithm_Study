#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<string> d;

void f(string s) {

	if (s == "pop_front") {
		if (!d.empty()) {
			cout << d.front()<<endl;
			d.pop_front();
		}
		else
			cout << "-1"<<endl;
	}
	else if (s == "pop_back") {
		if (!d.empty()) {
			cout << d.back()<<endl;
			d.pop_back();
		}
		else
			cout << "-1"<<endl;
	}
	else if (s == "size") {
		cout << d.size()<<endl;
	}
	else if (s == "empty") {
		if (d.empty())
			cout << "1"<<endl;
		else
			cout << "0"<<endl;
	}
	else if (s == "front") {
		if (d.empty())
			cout << "-1" << endl;
		else
			cout << d.front()<<endl;
	}
	else if (s == "back") {
		if (d.empty())
			cout << "-1" << endl;
		else
			cout << d.back() << endl;
	}
	else if (s.at(5) == 'f') {
		d.push_front(s.substr(11));
	}
	else if (s.at(5) == 'b') {
		d.push_back(s.substr(10));
	}
}

int main() {
	int n;
	string s;
	cin >> n;
	
	while (std::cin.get() != '\n');

	for (int i = 0; i < n; i++) {
		getline(cin, s);
		f(s);
	}
}