#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int K,L;
	//cin>>K>>L; ->시간초과되는 원인
    scanf("%d %d",&K,&L);
	
	map<int,int> stu; //중복되는 key값이 들어오면 최근에 들어온 value값으로 해당 key값의 value를 갱신한다.
    
	for(int i=0;i<L;i++){
		int num;
		scanf("%d",&num);
		
		stu[num]=i; //학번: key, 들어온 순서: value
	}
	
	vector<pair<int,int>> v;
	
	map<int,int>::iterator iter; //map순회할 때 사용
	
	for(iter=stu.begin();iter!=stu.end();iter++){
		v.push_back(make_pair(iter->second,iter->first));
	}
	
	sort(v.begin(),v.end()); //sort: 벡터만 적용?
	
	int m=min(K,int(v.size()));
	
	for(int i=0;i<m;i++){
		//cout<<v[i].second<<endl; 
        printf("%08d\n",v[i].second);
	} 
}
