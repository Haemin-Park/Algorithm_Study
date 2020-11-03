#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	priority_queue<int> pq;
	
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		
		if(k==0){
			if(!pq.empty()){
				printf("%d\n",pq.top());
				pq.pop();
			}else
				printf("0\n");
		}else{
			pq.push(k);
		}
	}
}