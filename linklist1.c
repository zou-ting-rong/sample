#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct Node{
	datatype data;
	struct Node *next;
}list;

list *Init()
{

	list *head;
	head = (list *)malloc(sizeof(list));
	list *temp;
	temp = head;
	for(int i = 0;i < 5;i++)
	{
		list *a;
		a = (list *)malloc(sizeof(list));
		//a = temp;
		a->data = i;
		//a->next = NULL;
		temp->next = a;
		temp = temp->next;
		printf("sucess!\n");
	}
	return head;

}

void display(list *head)
{
	list *temp;
	temp = head;
	while(temp->next){
		temp = temp->next;
		printf("%d\n",temp->data);
		printf("succss\n");
	}
	printf("\n");
}
int main(int argc ,char **argv)
{
	list *head;
	head = (list *)malloc(sizeof(list));
	head = Init();
	display(head);
	return 0;
}
