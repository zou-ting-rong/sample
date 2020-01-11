/*************************************************************************
    > File Name: shuanglinklist.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年01月10日 星期五 15时18分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prior;
}node;

typedef struct doublelist{
	node *head;
	node *tail;
	size_t size;
}doublelist;

node *creat_node(int data){
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->prior = NULL;
	newnode->next = NULL;
	return newnode;
}//创建一个新结点

doublelist *init(){
	doublelist *list;
	list = (doublelist *)malloc(sizeof(doublelist));
	if(list ==NULL){
		printf("分配内存失败\n");
	}
	else{
	list->head = list->tail = NULL;
	list->size = 0;
	return list;
	}
} 
//头插法
doublelist *inserthead(doublelist *list){
	int a;
	printf("请输入数据\n");
	scanf("%d",&a);
	node *new_node = creat_node(a);
	if(list->size == 0){
		list->head = new_node;
		list->tail = new_node;
	}
	else{
		new_node->next = list->head;
		list->head->prior = new_node;
		list->head = new_node;
	}
	list->size++;
}

//尾插法
doublelist *inserttail(doublelist *list){
	int a;
	printf("请输入数据\n");
	scanf("%d",&a);
	node *new_node = creat_node(a);
	if(list->size == 0){
		list->tail = new_node;
		list->head = new_node;
	}
	else{
		new_node->prior = list->tail;
		list->tail->next = new_node;
		list->tail = new_node;
	}
	list->size++;
}

//正向遍历双链表
void displayforward(doublelist *list){
	node *temp;
	temp = list->head;
	while(temp){
		printf("%d\n",temp->data);
		temp = temp->next;
		}
	return;
}
//反向遍历双链表
void displayreverse(doublelist *list){
	node *tmp;
	tmp = list->tail;
	while(tmp){
		printf("%d\n",tmp->data);
		tmp = tmp->prior;
	}
	return;
}
//删除头结点
int delhead(doublelist *list){
	if(list->size == 0){
		return 0;
	}
	if(list->size ==1){
		free(list->head);
		list = init();
		return 1;
		} 
		node *tmp;
		tmp = list->head;
		list->head = tmp->next;
		list->head->prior = NULL;
		free(tmp);
		tmp = NULL;
		list->size--;
}
//删除尾节点
int deltail(doublelist *list){
	if(list->size == 0){
		return 0;
	}
	if(list->size ==1){
		free(list->tail);
		list = init();
		return 1;
		}	 
		node *tmp;
		tmp = list->tail;
		list->tail->prior = tmp->prior->prior;
		list->tail->next = NULL;
		free(tmp);
		tmp = NULL;
		list->size--;
		return 1;
}
//删除任意位置的结点
int wantonlynode(doublelist *list){
	int local;
	printf("请输入你想要删除的结点位置\n");
	scanf("%d",&local);
	if(local < 0 || local > list->size){
		printf("位置超出双链表范围\n");
		return 0;
	}
	if(local ==0){
		delhead(list);
	}
	if(local == list->size){
		deltail(list);
	}
	node *tmp =NULL;
	if(local < list->size/2){
		tmp = list->head;
		for(int i = 0;i < local;i++){
			tmp = tmp->next;
		}
		tmp->prior->next = tmp->next;
		tmp->next->prior = tmp->prior;
		free(tmp);
		tmp = NULL;
	}
	if(local >= list->size/2){
		tmp = list->tail;
		int move = list->size - local;
		for(int i = move;i > 0;i--){
			tmp = tmp->prior;
		}
		tmp->next->prior = tmp->prior;
		tmp->prior->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
//获取头结点
node *getnodehead(doublelist *list){
	return list->head;
}
//获取为节点
node *getnodetail(doublelist *list){
	return list->tail;
}
//获取某个位置的结点
node *getnode(doublelist *list){
	int local;
	printf("请输入你想要获取的结点的位置\n");
	scanf("%d",&local);
	if(local < 0 || local > list->size){
		printf("位置超出双链表范围\n");
	}
	node *tmp = NULL;
	if(local-1 == 0){
		tmp = getnodehead(list);
		printf("%d\n",tmp->data);
		return tmp;
	}
	if(local == list->size){
		tmp = getnodetail(list);
		printf("%d\n",tmp->data);
		return tmp;
	}
	if(local < list->size/2){
		for(int i = 0;i < local;i++){
			tmp = tmp->next;
		}
		printf("%d\n",tmp->data);
		return tmp;
	}
	if(local >= list->size/2){
		int move = list->size - local;
		for(move;move > 0;move--){
			tmp = tmp->prior;
		}
		printf("%d\n",tmp->data);
		return tmp;
	}
}
//改变某个结点的数据域
node *changenodedata(doublelist *list){
	int newdata;
	node *temp;
	temp = NULL;
	temp = getnode(list);
	printf("请输入新数据\n");
	scanf("%d",&newdata);
	temp->data = newdata;
	return temp;
}

int main(int argc,char **argv)
{
	doublelist *list = init();
	inserthead(list);
	displayforward(list);
	//inserttail(list);
	//display(list);
	//delhead(list);
	changenodedata(list);
	displayreverse(list);
	return 0;
}
