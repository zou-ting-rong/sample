#include <stdio.h>
#include <stdlib.h>

#define max 5
typedef int datatype;
typedef struct{
	datatype data[max];
	datatype length;
}seqlist,*pseqlist;
seqlist *Init()
{
	seqlist *l;
	l = (seqlist *)malloc(sizeof(seqlist));
	if (l == NULL)
		return;
	l->length = 0;
}//顺序表的初始化

int getlength(seqlist *l)
{
	if(l == NULL)
		return;
	return ("%d",l->length);
}
int search(seqlist *l,int j)
{
	if(l == NULL)
		return ;
	if(j < 0 || j > l->length)
		return;
	return l->data[j - 1];
}

int insert(seqlist *l,int j,datatype x)
{
	if(l->length >= max)
		printf("顺序表已满\n");
	return;
	for(int i = j;i <= l->length;i++){
		l->data[i + 1] = l->data[i];
	}
	l->data[i-1] = data;
	l->length++;
	return;
}

int del(seqlist *l,int j)
{
	if(j < 0 || j > l->length){
		printf("元素不存在！\n");
		return ;
	}
	for(int i = j;i < l->length){
		l->data[i] = l->data[i + 1];
	}
	l->length--;
	return;
}

void display(seqlist *l)
{
	if(l->length == 0)
		return;
	for(int i = 0;i < l->length;i++){
		printf("%d",l->data[i]);
	}
	printf("\n");
}
int main(int argc,char **argv)
{
	


	return 0;
}











