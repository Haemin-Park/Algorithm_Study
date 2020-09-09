#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T;
vector<string> sv;

//괄호 검사 함수
void checkVPS() {

	string ps;
	string temp; // ps의 ) 괄호를 스택 형식으로 저장
	int length;
	
	for (int i = 0; i < T; i++) {
		
		ps = sv[i]; // 문자열 하나씩 처리
		temp = ""; 
		length = ps.length();
		
		

		// 마지막 괄호가 )인가
		if (ps.back() != ')') {
			cout << "NO" << endl;
			continue;
		}
		
		// (괄호와 )괄호의 개수가 같은가
		for (int j = 0; j < length; j++) {
			
			if (ps.back() == ')') {
				temp.push_back(')');
				ps.pop_back();
			}
			else {
				if (!temp.empty()) {
					temp.pop_back();
					ps.pop_back();
				}
				
			}
			
		}
			
		if (ps.empty() && temp.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}

int main() {

	// 입력 문자열의 수
	cin >> T; 

	// T개의 문자열 데이터 입력
	string ps;
	for (int i = 0; i < T; i++) {
		cin >> ps;
		sv.push_back(ps);
		
	}
	
	//// 괄호 검사 함수
	checkVPS();
	

	return 0;
}
