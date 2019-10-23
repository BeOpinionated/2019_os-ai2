#include "iostream"
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <Queue>
using namespace std;
typedef struct Node{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}*Tree;
int index=0;
void treeNodeConstructer (Tree &root,char data[])//����һ��������
{
	char e=data[index++];
	if(e=='#') root=NULL; 
	//�������# ��û�к��ӣ����û�����ӣ��鿴���Һ��ӣ����û���Һ��ӣ��򷵻���һ�㣨����ջ��ʵ�֣���
	else  
		{
			root=(Node *)malloc(sizeof(Node));
			root->data=e;
			treeNodeConstructer(root->lchild,data);
			treeNodeConstructer(root->rchild,data);
	}
}
void DFS (Tree root)//������ȱ���������ջ��ʵ��
{
	stack <Node *>nodeStack;
	nodeStack.push(root);
	Node *node;
	while(!nodeStack.empty()){
		node=nodeStack.top();
		cout<<node->data;
		nodeStack.pop();
		if(node->rchild) nodeStack.push(node->rchild);
		if(node->lchild) nodeStack.push(node->lchild);
	}
}
void BFS(Tree root)//������ȱ���������������ʵ��
{

	queue<Node *> nodeQueue;
	nodeQueue.push(root);
	Node *node;
	while(!nodeQueue.empty())
	{
		node=nodeQueue.front();//���������Ԫ��
		nodeQueue.pop();
		cout<<node->data;
		if(node->lchild) nodeQueue.push(node->lchild);
		if(node->rchild) nodeQueue.push(node->rchild);
	}
}
int main(){
	char data[15]={'A','B','D','#','#','E','#','#','C','F','#','#','G','#','#'};
	Tree tree;
	treeNodeConstructer(tree,data);
	cout<<"������ȱ����Ľ���ǣ�";
	DFS(tree);
	cout<<endl;
	cout<<"������ȱ����Ľ���ǣ�";
	BFS(tree);
	return 0;
}
