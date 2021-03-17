// 2021.03.15 17:35

// https://programmers.co.kr/learn/courses/30/lessons/42628
// 이중우선순위큐
// 
// wrong: 42628


/*
max힙 기반

min 값은 벡터의 마지막 값에

삽입)
min과 같거나 작다면: push_back
그 외: 평범한 max힙처럼 하고, 마지막에 기존 min을 맨 뒤로 보내기. swap(size-1, size-2)

top_max)
    size==0 -> return 0
    그 외: return v[0]
    
top_min)
    size==0 -> return 0
    그 외: return v[size-1]

삭제_max)
size==0 -> return 0
//size == 1 -> 삭제, size--, //min=maximum 해주기
size == 1 or 2-> 맨 뒤로 보내기, 삭제,size--, //min = v[0];
size > 2 -> 
    1) min과 그 전 값 바꾸기swap(size-1, size-2)
    2) max를 맨 뒤로 보내기 swap(0, size-1), 
    3) 맨 뒤 삭제 v.pop_back(), size-- -> min은 맨 뒤에 있게 됨
    4) v[0]으로 온 애 아래로 보내기
        - while( ( lIdx < size && v[0]< 왼쪽자식) or ( rIdx < size &&오른쪽자식))
            if ( lIdx < size && v[0]< 왼쪽자식) 왼쪽swap
            if ( rIdx < size &&오른쪽자식) 오른쪽 swap
    
삭제_min)
size==0 -> return 0
size == 1 or 2-> 삭제, size--, //min=maximum 해주기
//size == 2-> 삭제, size--,  //min = v[0];
size > 2 -> 
    1) pop_back,  size--
    2) height = log2(size)
    3) idx range(power(2, height)-1, size) 최솟값 찾아서 맨 뒤에 두기
        - 최솟값 찾는 법: 알고리즘 min
*/


#include <string>
#include <vector>
#include<cmath>
#include <cstring> // stoi(str);
#include<iostream>

using namespace std;



class dpq
{
    
    int size = 0;
    const int maximum = 99999999;

    int lIdx(int idx)
    {
        return idx*2+1;
    }
    
    int rIdx(int idx)
    {
        return idx*2+2;
    }
    
    void swap(int idx1, int idx2)
    {
        int tmp = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = tmp;
    }
    public:
	
		vector<int> v;
	
        void push(int i)
        {

            v.push_back(i); // min은 size-2 위치에 있게됨
            size++;
            if (i > v[size-2])
            {            

                int location = size-1;

                // max heap: 부모보다 크면 계속 올리기
                while (location > 0 && v[location] > v[(location-1)/2])
                {
					
                    swap(location, (location-1)/2);
                    location = (location-1)/2;
                }
                

				// min을 맨 뒤로 보내기
				if (size>1)
				{
					swap(size-1, size-2);
				}
				
				
				//1~ 2번 계산됨.. 상수시간
				// size-2에 있는 애 위로 올리기
				location = size-2;
				int count = 0;
				
				while (location > 0 && v[location] > v[(location-1)/2])
				{
					
					swap(location, (location-1)/2);
					location = (location-1)/2;
				}
            }
        }
    
        int top_max()
        {
            if (v.empty()) return 0;
            else return v[0];
        }
    
        int top_min()
        {
            if (v.empty()) return 0;
            else return v[size-1];
        }
    
        void pop_max()
        {
            if (v.empty())
            {
                return;
            }
            else if (size == 1 || size == 2)
            {
                swap(0, size-1);
                v.pop_back();
                size--;
            }
            else
            {
                // 1) min과 그 전 값 바꾸기
                swap(size-1, size-2);
                // 2) max를 맨 뒤로 보내기
                swap(0, size-1);
                // 3) 맨 뒤 삭제 v.pop_back(), size-- -> min은 맨 뒤에 있게 됨
                v.pop_back();
                size--;
                
                // 4) v[0]으로 온 애 아래로 보내기
                int loc = 0; //location

                // 자식보다 작으면 계속 내리기
                
				// 실수: loc를 업데이트 안 해줌..
				// 실수: v[0]< v[lIdx(loc)]부분을 v[loc]으로 해야 함..
                while( ( lIdx(loc) < size && v[loc]< v[lIdx(loc)]) or ( rIdx(loc) < size && v[loc] < v[rIdx(loc)]))
                {
					//cout<<"\nloc, lIdx, rIdx = "<<loc<<", "<<lIdx(loc)<<", "<<rIdx(loc)<<"\n";
					//cout<<"현재 상태:";
					//print();
					
					// 실수: 두 자식 중 더 큰 애와 맞바꿔야 올라온 애가 다른쪽 자식보다 크다
                    //if (lIdx(loc) < size && v[loc] < v[lIdx(loc)]) 
					if (v[lIdx(loc)] > v[rIdx(loc)]) 
					{
						//cout<<"left 와 교환\n";
						swap(loc, lIdx(loc));
						loc = lIdx(loc);
						//cout<<"left 와 교환, 교환 이후:";
						//print();
					}
					//실수:  else if로 해야 하는데 그냥 if로 함
                	//else if (rIdx(loc) < size && v[loc] < v[rIdx(loc)]) 
					else
					{
						//cout<<"right와 교환\n";
						swap(loc, rIdx(loc));
						loc = rIdx(loc);
						//cout<<"right와 교환, 교환 이후:";
						//print();
					}
                }
            
            }
        }
    
        void pop_min()
        {
            if (v.empty())
            {
                return;
            }
            else if (size == 1 || size == 2)
            {
                v.pop_back();
                size--;
            }
            else
            {
                v.pop_back();
                size--;
                
                // 최솟값 찾아서 맨 뒤에 두기
                int height = log2(size);
				// 실수: 마지막 레벨이 아닌, 트리의 리프들을 검사해야 한다
                //int minIdx = pow(2, height)-1;
				// 시작: 마지막 노드의 부모+1
				int minIdx = (size-1 -1 )/2+1;
                for (int i = minIdx; i<size;i++)
                {
                    if (v[i]<v[minIdx])
                        minIdx = i;
                }
                swap(minIdx, size-1);
				
				//1~ 2번 계산됨.. 상수시간
				// minIdx에 있는 애 위로 올리기
				int location = minIdx;
				
				while (location > 0 && v[location] > v[(location-1)/2])
				{
					
					swap(location, (location-1)/2);
					location = (location-1)/2;
				}
				
            }
        }
	
		void print()
		{
			cout<<"\n";
			
			for (int i = 0;  i < v.size(); i++)
			{
				cout<<" "<<i;
			}
			cout<<"\n";
			for (int i = 0;  i < v.size(); i++)
			{
				
				cout<<v[i]<<" ";
			}
			cout<<"\n";
		}
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    dpq dpq;
    vector<string>::iterator iter= operations.begin();
    
    dpq.push(1);
    cout<<dpq.top_min();
//     for (iter= operations.begin(); iter != operations.end(); iter++)
//     {
//         char op = (*iter)[0];
//         if (op == 'I')
//         {
//             int num = stoi((*iter).substr(2));
//             cout<<(*iter).substr(2)<<":  "<<num<<endl;
//             dpq.push(num);
//         }
//         else if ((*iter) == "D 1")
//         {
//             dpq.pop_max();
//         }
//         else if ((*iter) == "D -1")
//         {
//             dpq.pop_min();
//         }
        
        
//     }
    
//     answer.push_back(dpq.top_max());
//     answer.push_back(dpq.top_min());
    return answer;
}

int main()
{
	dpq dpq;
    vector<string>::iterator iter;
    
	vector<int> arr({1, 2, -3, 6, -7, 6, 5, -7, -5});
	
	for (int i = 0; i < arr.size(); i++)
	{
		dpq.push(arr[i]);
		// dpq.print();
		// cout<<"max, min = "<<dpq.top_max()<<", "<<dpq.top_min()<<"\n";
	}
    
	cout<<"~~~~~~~~~~~ pop_max\n\n";
	for (int i = 0; dpq.v.size(); i++)
	{
		dpq.pop_max();
		dpq.print();
		cout<<"max, min = "<<dpq.top_max()<<", "<<dpq.top_min()<<"\n";
		dpq.pop_min();
		dpq.print();
		cout<<"max, min = "<<dpq.top_max()<<", "<<dpq.top_min()<<"\n";	
	}
	
	cout<<"last"<<endl;
	cout<<dpq.top_min();
	dpq.print();
}
