// 2020-11-04 20:12 시작
// https://www.acmicpc.net/problem/5639
// 이진검색트리
// 2020-11-04 21:40 종료
// wrong: 5639

// https://wanna-b.tistory.com/59
// 입력 개수 안 주어졌을때 입력받는법 참고



// 느낀점: 뭐가 문제인지 모르겠다.

/*아이디어

처음: 루트
들어온 숫자가 이전보다 작으면-> 왼쪽에 넣는다.


루프: 현재, 이전

현재가 이전보다 작으면: 현재는 이전의 왼쪽 자식 노드
현재가 이전보다 크면:
	현재가 x보다 작을때까지 계속 비교: x는 현재의 선조노드
		이전 x의 오른쪽 자식으로 넣는다.




후위
루프
왼쪽 출력
오른쪽 출력
지금 출력

*/



#pragma warning (disable: 4996)
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;




// 노드 클래스
class node
{
public:
	// 부모 노드(인덱스)
	int parentIdx = -1;
	int value = -1;
	int left = -1;
	int right = -1;
};

vector<node> preorder;

void inorder(int idx)
{
	
	// 	int a;
	// 	cin >> a;

	// 	printf("preorder[idx].left = %d\n", preorder[idx].left);
	if (preorder[idx].left == -1 && preorder[idx].right == -1)
	{
		// printf("inorder 빠져나감\n");
		printf("%d\n", preorder[idx].value);
		return;
	}
	//printf("현재: %3d\n", preorder[idx].value);
	//printf("now : %3d, left: %3d, right : %3d\n\n", idx, preorder[idx].left, preorder[idx].right);

	if (preorder[idx].left != -1)
		inorder(preorder[idx].left);
	if (preorder[idx].right != -1)
		inorder(preorder[idx].right);
	printf("%d\n", preorder[idx].value);

}


int main()
{
	int n;
	//printf("hellpo\n");


	 //do {
	 //scanf("%d", &n);
	 //node node;
	 //node.value = n;
	 //preorder.push_back(node);

	 ////} while (getchar() != ' ');

	 //} while (getc(stdin) == ' ');

	 
	 while (scanf("%d", &n) != EOF) {

		 node node;
		 node.value = n;
		 preorder.push_back(node);

	 }


	//for (int i = 0; i < 9; i++)
	//{
	//	scanf("%d", &n);
	//	node node;
	//	node.value = n;
	//	preorder.push_back(node);

	//}



	int rootIdx = 0;
	for (int i = 1; i < preorder.size(); i++)
	{
		if (preorder[i].value < preorder[i - 1].value)
		{
			preorder[i - 1].left = i;
			preorder[i].parentIdx = i - 1;
			// 			printf("%d의 left는 %d\n", preorder[i-1].value, preorder[i].value);
		}
		else
		{
			// 			vector ancestor<int>;
			int j = i - 1;
			//선조노드 벡터
			int before = i - 1;
			// 현재가 선조보다 크고 선조가 없지 않다면
			while ((j != -1 && preorder[j].value < preorder[i].value))
			{
				before = j;

				// printf("j(%d)의 parent: %d\n", preorder[j].value, preorder[preorder[j].parentIdx].value);
				j = preorder[j].parentIdx;


			}

			preorder[before].right = i;
			preorder[i].parentIdx = before;

			//printf("%d의 right는 %d\n", preorder[before].value, preorder[i].value);

		}
	}


	inorder(0);
	return 0;
}

