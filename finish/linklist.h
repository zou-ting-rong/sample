#ifndef library_h
#define library_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct{
	int year;
	int month;
	int day;
}Data;

typedef struct{
	int id;
	Data DATA;
	char name[20];
	char author_name[20];
	char info[50];
	char publish[20];
	double price;
	char flag[20];//标志位，来展示图书的状态
	char typebook[20];//书本类型
	char people[20];
	struct tm *borrowtime;//图书借走时间
	struct tm *returntime;//图书归还时间
}book;

typedef struct Node{
	book data;
	struct Node *next;
	int count;//计数器
}linklist;


linklist *Init();
int seacher(linklist *head);//按id进行查找
linklist *change(linklist *head);//修改图书信
linklist *insert(linklist *head);//添加书本
void displayB(linklist *head);//展示借出书本
void display(linklist *head);//展示
linklist *dle(linklist *head);
linklist *del1(linklist *head,int i);//按id删除书本
void bubble_id(linklist *head);//按id将图书进行排序
void bubble_price(linklist *head);//按价格将图书进行排序
linklist *findBynameptr(linklist *head);
int findByname(linklist *head);//根据名字进行查找
int findBytype(linklist *head);
int findByauthor_name(linklist *head);//根据作者名字进行查找
void count(linklist *head);//计算图书馆共计有多少书本
linklist *Inittemporary();//定义一个存放借出去的书本链表
linklist *inserttem(linklist *temporary,book data);//将借出去的书本存入暂存栈
linklist *dletem(linklist *head,linklist *temporary,int i);//将暂存链表中的数据返回给linklit *head
void displaytem(linklist *temporary);
linklist *insert1(linklist *head,linklist *temporary);
void changeflagB(linklist *head,int id);
void changeflagI(linklist *head,int id);
void changeflagO(linklist *head,int id);
#endif
