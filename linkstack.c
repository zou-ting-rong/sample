#include <stdio.h>
#include <stdlib.h>

#define max 20
typedef int datatype;
typedef struct Node{
	datatype data;
	struct Node *next;
	int length;
}linkstack;

linkstack *Init()
{
	linkstack *top;
	top = (linkstack *)malloc(sizeof(linkstack));
	top = NULL;
	if(top == NULL){
		printf("初始化成功！\n");
	}
	return top;
}

int push(linkstack *top,datatype x)
{
	linkstack *temp = top;
	linkstack *q;
	q = (linkstack *)malloc(sizeof(linkstack));
	q->data = x;
	top = q;
	//top = q;
	top->next = temp;
	temp->next = NULL;
	top->length++;
	return top;
}

int pop(linkstack *top,int j)
{
	linkstack *q;
	q = (linkstack *)malloc(sizeof(linkstack));
	for(int i = top->length;i >= top->length - j;i--){
		linkstack *q;
		q = (linkstack *)malloc(sizeof(linkstack));
		q->data = top->data;
		top->length++;
		top = top->next;
		free(q);
	}
	return top;
}
int insert(linkstack *top,int j)
{
	linkstack *temp = top;
	for(int i = top->length;i > top->length-j;i--){
		temp = top->next;
	}
	linkstack *q;
	q = (linkstack *)malloc(sizeof(linkstack));
	q->data = temp->data;
	temp->next = temp->next->next;
	free(q);
	return top;
}
void display(linkstack *top)
{
	linkstack *temp = top;
	while(temp->next){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}




int main(int argc ,char **argv)
{
	linkstack *top;
	top = (linkstack *)malloc(sizeof(linkstack));
	Init();
	for(int i = 0;i <5;i++){
		push(top,i);
		//printf("sucess\n");
	}
	display(top);
	return 0;
}
