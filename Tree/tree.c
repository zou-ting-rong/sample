/*************************************************************************
    > File Name: tree.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年01月30日 星期四 21时23分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node{
	char id;
	struct tree_node *left;
	struct tree_node *right;
}tree,*LPtree;


//利用递归来创建树
void CreatTree(tree_node *T)
{
	
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		T = NULL;
	}
	else{
		tree_node *T;
		T = (tree_node *)malloc(sizeof(tree_node));
		T->id = ch;
		CreatTree(T->left);
		CreatTree(T->right);
	}
}

void PreShow(tree_node *T)
{
	if(T == NULL){
		return;
	}
	printf("%c",T->id);
	PreShow(T->left);
	PreShow(T->right);
}

int main(int argc,char **argv)
{
	tree_node *t;
	CreatTree(t);
	PreShow(t);
}
