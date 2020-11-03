#include <iostream>
using namespace std;

int tree[10000];



void postOrder(int start,int end){
	if(start==end)
		return;
	if(start==end-1){
		printf("%d\n",tree[start]);
		return;
	}
	
	int idx=start+1;
	
	while(1){
		if(tree[idx]<tree[start]&&idx<end)
			idx++;
		else
			break;
	}
		
	postOrder(start+1,idx);
	postOrder(idx,end);
	
	printf("%d\n",tree[start]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	//??
	int idx;
	for (idx = 0; scanf("%d", tree + idx) > 0; idx++);
	
	postOrder(0,idx);
	
	return 0;
}