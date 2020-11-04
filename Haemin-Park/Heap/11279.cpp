#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX_HEAP 1000000
using namespace std;

int maxheap[MAX_HEAP + 1];
int tail;

void make_maxheap(int flag, int p) {
	if (flag == 1) {
		if (p == 1) return;
		else {
			if (maxheap[p / 2] < maxheap[p]) {
				swap(maxheap[p / 2], maxheap[p]);
				make_maxheap(1, p / 2);
			}
		}
	}
	else if (flag == 0){
		if (p > tail)
			return;
		else {
			if (max(maxheap[p * 2], maxheap[p * 2 + 1]) > maxheap[p]) {
				if (maxheap[p * 2] > maxheap[p * 2 + 1]) {
					swap(maxheap[p * 2], maxheap[p]);
					make_maxheap(0, p * 2);
				}
				else {
					swap(maxheap[p * 2 + 1], maxheap[p]);
					make_maxheap(0, p * 2 + 1);
				}
			}
		}
	}
}

int main() {
	int n, input;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input);
		if (input == 0) {
			if (tail == 0)
				printf("0\n");
			else if (tail == 1) {
				printf("%d\n", maxheap[1]);
				maxheap[1] = 0;
				tail--;
			}
			else {
				printf("%d\n", maxheap[1]);
				maxheap[1] = 0;
				swap(maxheap[1], maxheap[tail]);
				tail--;
				make_maxheap(0, 1);
			}
		}
		else {
			tail++;
			maxheap[tail] = input;
			make_maxheap(1, tail);
		}
	}
}
