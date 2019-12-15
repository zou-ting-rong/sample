#ifndef library_h
#define library_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void display(linklist *head);//展示
int del(linklist *head);//按id删除书本
void bubble_id(linklist *head);//按id将图书进行排序
void bubble_price(linklist *head);//按价格将图书进行排序
int findByname(linklist *head);//根据名字进行查找
int findByauthor_name(linklist *head);//根据作者名字进行查找
void count(linklist *head);//计算图书馆共计有多少书本

#endif
