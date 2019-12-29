/*************************************************************************
    > File Name: findandserchaer.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2019年12月27日 星期五 19时56分09秒
 ************************************************************************/
#include "linklist.h"
void bubble_id(linklist *head){//有待改善
	linklist *temp = head;
	int m;
	printf("请输入需要排序的书本数：\n");
	scanf("%d",&m);
	for(int i = 0;i < m ;i++ ){//边界有待修改！
		for(int j = 0;j < m  -i -1;j++){
			linklist *tmp;
			tmp = (linklist *)malloc(sizeof(linklist));
			if(temp->data.id > temp->next->data.id){
				tmp->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tmp->data;
				free(tmp);
			}
			temp = temp->next;
		}
	}
}
//根据书本的价格大小来进行排序
void bubble_price(linklist *head){//有待改善
	linklist *temp = head;
	count(head);
	printf("请输入需要排序的的书本数：\n");
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m - 1;i++ ){
		for(int j = 0;j < m -i -1;j++){
			linklist *tmp;
			tmp = (linklist *)malloc(sizeof(linklist));
			if(temp->data.price > temp->next->data.price){
				tmp->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tmp->data;
				free(tmp);
			}
			temp = temp->next;
		}
	}
}
//根据书本的名字来进行查询并返回id
int findByname(linklist *head){
	linklist *temp = head;
	int i;
	char names[20];
	printf("请输入要查询课本的名字：\n");
	scanf("%s",names);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.name,names);
		if(i == 0){
			printf("该书本的id:%d\n",temp->data.id);
			return temp->data.id;
		}
		
	}
	return -1;
}

linklist *findBynameptr(linklist *head){
	linklist *temp = head;
	int i;
	char names[20];
	printf("请输入要查询课本的名字：\n");
	scanf("%s",names);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.name,names);
		if(i == 0){
			printf("该书本的id:%d\n",temp->data.id);
			return temp;
		}
		
	}
	return temp;
}
int findByauthor_name(linklist *head){
	linklist *temp = head;
	int i;
	char Author_name[20];
	printf("请输入要查询书本的作者名字：\n");
	scanf("%s",Author_name);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.author_name,Author_name);
		if(i == 0){
				printf("***************************************\n");
				printf("书本的id为：%d\n",temp->data.id);
				printf("***************************************\n");
				printf("书本的出版时间为：%d  年 %d 月 %d 日 \n",temp->data.DATA.year,temp->data.DATA.month,temp->data.DATA.day);
				printf("***************************************\n");
				printf("书本的名字为：%s\n",temp->data.name);
				printf("***************************************\n");
				printf("书本作者名字为：%s\n",temp->data.author_name);
				printf("***************************************\n");
				printf("书本的简介为：%s\n",temp->data.info);
				printf("***************************************\n");
				printf("书本的出版社为：%s\n",temp->data.publish);
				printf("***************************************\n");
				printf("书本的单价为：%lf\n",temp->data.price);
				printf("***************************************\n");
				printf("***************************************\n");
			return temp->data.id;
		}
	}
	return -1;//查找成功
}

int findBytype(linklist *head){
	linklist *temp = head;
	int i;
	char type[20];
	printf("请输入要查询书本的类型：\n");
	scanf("%s",type);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.typebook,type);
		if(i == 0){
				printf("***************************************\n");
				printf("书本的id为：%d\n",temp->data.id);
				printf("***************************************\n");
				printf("书本的出版时间为：%d  年 %d 月 %d 日 \n",temp->data.DATA.year,temp->data.DATA.month,temp->data.DATA.day);
				printf("***************************************\n");
				printf("书本的名字为：%s\n",temp->data.name);
				printf("***************************************\n");
				printf("书本作者名字为：%s\n",temp->data.author_name);
				printf("***************************************\n");
				printf("书本的简介为：%s\n",temp->data.info);
				printf("***************************************\n");
				printf("书本的出版社为：%s\n",temp->data.publish);
				printf("***************************************\n");
				printf("书本的单价为：%lf\n",temp->data.price);
				printf("***************************************\n");
			return temp->data.id;
		}
	}
	return -1;//查找成功
}
void changeflagB(linklist *head,int id){//用于还书和预约书来更改书本的状态
	linklist *temp = head;
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == id){
			strcpy(temp->data.flag,"borrow");
		}
	}
	return;
}//借书改变书本状态

void changeflagO(linklist *head,int id){//用于还书和预约书来更改书本的状态
	linklist *temp = head;
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == id){
			strcpy(temp->data.flag,"order");
		}
	}
	return;
}//还书改变书本状态

void changeflagI(linklist *head,int id){//用于还书和预约书来更改书本的状态
	linklist *temp = head;
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == id){
			strcpy(temp->data.flag,"inlibrary");
			return;
		}
	}
	return;
}//预约书改变书本状态

