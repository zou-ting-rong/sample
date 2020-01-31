/*************************************************************************
    > File Name: tree1.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年01月31日 星期五 20时30分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
	char data;
	struct treenode *lchild;
	struct treenode *rchild;
}tree,*LPtree;

//创建一个新节点
LPtree CreatTree(char data)
{
	LPtree newnode = (LPtree)malloc(sizeof(tree));
	newnode->data = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	return newnode;
}

void InsertNode(LPtree ParentNode,LPtree lchild,LPtree rchild)
{
	ParentNode->lchild = lchild;
	ParentNode->rchild = rchild;
}

void display(LPtree nodedata)
{
	printf("%c\t",nodedata->data);
}

//先序遍历
void Preoder(LPtree root)
{
	if(root != NULL){
		display(root);
		Preoder(root->lchild);
		Preoder(root->rchild);
	}
}
//非递归先序遍历
void TraverBystack(LPtree root)
{
	//准备一个栈
	if(root == NULL)
		return;
	LPtree stack[10];
	int stacktop = -1;
	LPtree temp = root;
	while(stacktop != -1 || temp != NULL){
		while(temp != NULL){
			printf("%c\t",temp->data);
			stack[++stacktop] = temp;//伪入栈
			temp = temp->lchild;
		}
		if(stacktop != -1){
			temp = stack[stacktop];//伪出栈
			stacktop--;
			temp = temp->rchild;
		}
	}

}
//中序遍历
void Inorder(LPtree root)
{
	if(root != NULL){
		Inorder(root->lchild);
		display(root);
		Inorder(root->rchild);
	}
}

//后序遍历
void Foorder(LPtree root)
{
	if(root != NULL){
		Foorder(root->lchild);
		Foorder(root->rchild);
		display(root);
	}
}
int main(int argc,char **argv)
{
	LPtree A = CreatTree('A');
	LPtree B = CreatTree('B');
	LPtree C = CreatTree('C');
	printf("先序遍历\n");
	InsertNode(A,B,C);
	Preoder(A);
	printf("\n非递归遍历\n");
	TraverBystack(A);
	printf("\n中序遍历\n");
	Inorder(A);
	printf("\n后序遍历\n");
	Foorder(A);
}


