// 2020-09-10 02:03 시작
// https://www.acmicpc.net/problem/10866
// 덱
// 2020-08-31 02:46 종료
// correct: 10866

/*감상평: 김철연 교수님과 함께 하는 링크드 리스트 시간이 생각났다.

덱 사이즈를 처음엔 size로 하려고 했는데 size 함수랑 이름이 같아서 오류 났다.
변수 이름과 함수 이름은 같게 하면 안 된다.

명령을 if else로 구분하였는데 더 좋은 방법이 있을까?
*/

/*아이디어: 
최대 사이즈가 정해져 있으므로 배열을 기반으로 한다.
원형 큐처럼 처음과 끝의 인덱스를 가리키는 헤드 테일을 갖고 빙글빙글 돌린다.

사이즈는 push, pop 할때마다 체크.
pop은 헤드 테일만 조정하고, 물리적 삭제는 안 한다.
*/

#include<string.h>
#include<iostream>
using namespace std;

#define MAX 10000

string instruction[]  = {"push_front", "push_back" , "pop_front", "pop_back", "size", "empty", "front", "back"};

int d[MAX];

int N; //입력받을 명령 수


int head = 1; // 맨 앞 정수의 인덱스
int tail = 0; // 맨 뒤 정수의 인덱스
int d_size = 0; // 사이즈

int size()
{	
	cout<<d_size<<endl;
	return d_size;
}

int empty()
{
	if (d_size) // 비어있지 않다면
	{	
		cout<<0<<endl;
		return 0;
	}
	
	// 비어있다면
	cout<< 1<<endl;
	return 1;
	
}

int empty_no_print()
{
	if (d_size) // 비어있지 않다면
	{	
		
		return 0;
	}
	
	// 비어있다면
	
	return 1;
}

int front()
{
	if(empty_no_print())
	{
		cout<<-1<<endl;
		return -1;
	}
	
	cout<<d[head]<<endl;
	return d[head];
}

int back()
{
	if(empty_no_print())
	{
		cout<<-1<<endl;
		return -1;
	}
	
	cout<<d[tail]<<endl;
	return d[tail];
}

void push_front()
{
	int x;
	cin >> x;
	
	head--;
	if(head< 0)
	{
		head = MAX -1;
	}
	d[head] = x;
	d_size++;
	
}

void push_back()
{
	int x;
	cin >> x;
	
	tail++;
	if(tail>MAX -1)
	{
		tail = 0;
	}
	d[tail] = x;
	d_size++;
}

void pop_front()
{
	front();
	if(empty_no_print())
	{
		return;
	}
	
	
	head++;
	if (head>MAX-1)
	{
		head = 0;
	}
	d_size--;
}

void pop_back()
{
	back();
	
	if(empty_no_print())
	{
		return;
	}
	
	tail--;
	if (tail<0)
	{
		tail = MAX-1;
	}
	d_size--;
}



int main()
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	string inst;
	
	for (int i = 0; i < N; i++)
	{
		cin>>inst;
		
		if(inst == instruction[0]) push_front();
		else if (inst == instruction[1]) push_back();
		else if (inst == instruction[2]) pop_front();
		else if (inst == instruction[3]) pop_back();
		else if (inst == instruction[4]) size();
		else if (inst == instruction[5]) empty();
		else if (inst == instruction[6]) front();
		else if (inst == instruction[7]) back();
		else
		{
			cout<<endl<<endl<<"error!"<<endl;
			cout<<"input: "<<inst<<endl;
			cout<<"kill"<<endl;
			break;
		}
		
	}
	return 0;
}