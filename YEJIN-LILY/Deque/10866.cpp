#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;
template<class T>
class Node{
	T x;
	Node<T>* next;
	
	public:
		Node(){next=NULL;}
		Node(T x){this->x=x; next=NULL;}
		Node<T>* getNext(){return next;}
		Node<T>* setNext(Node<T>* next){this->next=next; return this;}
		T getElem(){return x;}
};

template<class T>
class Deque{
	int deque_size;
	Node<T> header; //빈 노드

	Node<T>* at(int i){
		Node<T>* ret=&header;
		for(int j=0;j<=i;j++)
			ret=ret->getNext();
		return ret;
	}
	
	public:
		Deque(){deque_size=0;}
	
		void push_front(int x){
			Node<T>* ret=&header;
			Node<T>* node=new Node<T>(x);
			node->setNext(at(0));
			ret->setNext(node);
			deque_size++;
		}
		void push_back(int x){
			Node<T>* tail=at(deque_size-1);
			tail->setNext(new Node<T>(x));
			deque_size++;
		}
		void pop_front(){
			if(deque_size==0)
				answer.push_back(-1);
			else{
				Node<T>* ret=&header;
				Node<T>* tmp=ret->getNext();
				Node<T>* node=tmp->getNext();
				ret->setNext(node);
				answer.push_back(tmp->getElem());
				delete tmp;
				deque_size--;
			}
		}
		void pop_back(){
			if(deque_size==0)
				answer.push_back(-1);
			else{
				Node<T>* tmp=at(deque_size-1);
				Node<T>* node=at(deque_size-2);
				node->setNext(NULL);
				answer.push_back(tmp->getElem());
				delete tmp;
				deque_size--;
			}
		
		}
		void size(){
			answer.push_back(deque_size);
		}
		void empty(){
			if(deque_size==0)
				answer.push_back(1);
			else
				answer.push_back(0);
		}
		void front(){
			if(deque_size==0)
				answer.push_back(-1);
			else{
				Node<T>* ret=&header;
				answer.push_back(ret->getNext()->getElem());
			}
				
		}
		void back(){
			if(deque_size==0)
				answer.push_back(-1);
			else
				answer.push_back(at(deque_size-1)->getElem());
		}
	};

int main(){
	int n,k;
	scanf("%d",&n);
	
	string op[8]={"push_front","push_back","pop_front","pop_back","size","empty","front","back"};
	Deque<int> dq;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		
		for(int i=0;i<8;i++){
			if(s==op[0]||s==op[1]){
				scanf("%d",&k);
			}
			if(op[i]==s){
				switch(i){
					case 0:
						dq.push_front(k);
						break;
					case 1:
						dq.push_back(k);
						break;
					case 2:
						dq.pop_front();
						break;
					case 3:
						dq.pop_back();
						break;
					case 4:
						dq.size();
						break;
					case 5:
						dq.empty();
						break;
					case 6:
						dq.front();
						break;
					case 7:
						dq.back();
						break;
			}
			}
			
			
		}
		
	}
	
	for(int i=0;i<answer.size();i++)
		printf("%d\n",answer[i]);
}
