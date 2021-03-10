// https://programmers.co.kr/learn/courses/30/lessons/43165

// 2021.01.25 15:04 시작
// 타겟 넘버
// 2021.01.25 15:04 시작



/* 아이디어
그냥 모든 경우의 수를 다 구해보자...
*/

//후기
// 내가 한 게 dfs라는데 어딜 봐서 그런건지 모르겠다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void makeTarget(const vector<int> &numbers,const int &target, int sum, int idx, int &count)
{
	// cout<<"idx, num, sum = "<<idx<<", "<<numbers[idx]<<", "<<sum<<endl;
    if (idx==numbers.size())
    {
        if(sum == target)
        {
            count++;
        }
        return;
    }
    makeTarget(numbers, target, sum+numbers[idx], idx+1, count);
    makeTarget(numbers, target, sum-numbers[idx], idx+1, count);

}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    makeTarget(numbers, target, 0, 0, answer);
    
    return answer;
}

int main()
{
	vector<int> numbers = {1, 1, 1, 1, 1};
	int answer = solution(numbers, 3);
	cout<<endl<<"답: "<<answer<<endl;
}

