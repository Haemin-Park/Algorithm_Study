//이진 검색트리에서 전위 순회가 주어지면 후위 순회한 결과를 출력한다

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*typedef struct NODE {
    int num, ed;
    NODE *right;
    NODE *left;
}node;
*/

vector<int> pre;

void inputpre() {
    int temp;
    int N = 0;
    while (cin >> temp) { if (temp != EOF) pre.push_back(temp); }
}

void build(int startnum, int endnum) {
     if (startnum > endnum) return;
     
    int partiton=endnum;
  
    int root = pre[startnum];
    while (root < pre[partiton])
        partiton--;

  //  cout << partiton;
    build(startnum+1, partiton);
    build(partiton+1, endnum);    
    cout << root<<"\n";

/*
    if(left) 
        while (true) {
            if (left > pre[i]) { i += 1;  continue; }
            else break;
    }
}

void printpost(NODE* node) {
    if (node->left!=NULL)
        printpost(node->left);
    if (node->right != NULL)
        printpost(node->right);
    cout << node->num;*/

}

int main()
{
    //NODE* tree=NULL;

    inputpre();
    build(0,pre.size()-1);
    //printpost(tree);
      
}
