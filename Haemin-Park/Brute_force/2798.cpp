#include <iostream>
#include <vector>
using namespace std;

int N, M;
int max_sum = 0;

int blackJack(vector<int> nums);

int main() {

	cin >> N >> M;
	
	vector<int> nums(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	cout << blackJack(nums);

}

int blackJack(vector<int> nums) {

	int sum=0;

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				sum = nums[i] + nums[j] + nums[k];
				if (max_sum < sum && sum <= M)
					max_sum = sum;
				
			}
		}
	}

	return max_sum;

}
