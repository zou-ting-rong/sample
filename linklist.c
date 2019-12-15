#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int num;
	char name[20];
}student;
typedef struct Node{
	student data;
	struct Node *next;
}linklist;

linklist *Init()
{
	linklist *head;//单链表必须设定一个头指针；还有一个指向头指针的指针进行头指针进行遍历
	head = (linklist *)malloc(sizeof(linklist));
	linklist *temp = head;//声明一个指针指向头指针，用于遍历列表
	for(int i = 1;i < 5;i++){
		linklist *a;
		a = (linklist *)malloc(sizeof(linklist));
		a->data.num = i;
		strcpy(a->data.name,"zhangsan");
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return head;
}

char seacher(linklist *head,int j)
{
	linklist *q = head;
	int i = 0;
	while(q->next){
		q = q->next;
		if(q->next->data.num == j){
			printf("%s\n",q->next->data.name);
			return q->next->data.name//return 可以无返回值，只是用于结束方法等价于break
			//break;//
		}
		i++;
	}
	//printf("%s\n",q->next->data.name);
	return -1;
}
linklist *change(linklist *head,int add,student newdata)
{
	linklist * temp;
	temp = temp->next;//在遍历之前temp指向首元结点
	for(int i = 1;i < add;i++){
		temp = temp->next;
	}
	temp->data = newdata;
	return head;
}

int insert(linklist *head,int add,student data)
{
	linklist *temp = head;
	for(int i = 0;i < add;i++){
		if(temp == NULL){
			printf("插入位置超出链表范围！\n");
			return head;
		}
		temp = temp->next;
	}
	linklist *c;
	c = (linklist *)malloc(sizeof(linklist));
	c->data = data;
	c->next = temp->next;
	temp->next = c;
	return head;
}
void display(linklist *head)
{
	linklist *temp = head;
	while(temp->next){
		temp = temp->next;
		printf("%d %s",temp->data.num,temp->data.name);
	}
	printf("\n");
}
int dle(linklist *head,int add)
{
	linklist *temp = head;//创建一个指向头指针的指针，进行遍历
	for(int i = 0;i < add;i++){
		if(temp == NULL){
			printf("结点不存在！\n");
			return head;
		}
		linklist *p;
		p = (linklist *)malloc(sizeof(linklist));
		p = temp->next;
		temp->next = temp->next->next;
		free(p);
	} 
		return head;//手动释放c指针以免造成内存泄露
}

int main(int argc,char **argv)
{
	printf("初始化链表为：\n");
	linklist *head;
	head = Init();
	display(head);
	seacher(head,3);
	display(head);
	//insert(head,4,5);
	//display(head);
	//dle(head,4);
	//display(head);



	return 0;
}
