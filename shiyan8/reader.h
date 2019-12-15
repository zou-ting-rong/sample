#ifndef reader_h
#define reader_h

#include <stdio.h>
#include <stdlib.h>
//#include "linklist.h"
//#include "linklist.c"
#define max 3
/*typedef struct{
	int year;
	int month;
	int day;
}DATAreader;*/
typedef struct{
	int id;
	char name[20];
}bookreader;
typedef struct stack{
	bookreader datareader;
	int length;
	struct stack *next;
}reader;

reader *Initreader();
int push(linklist *head,reader *tip);//借书
int pop(linklist *head,reader *tip);//还书
int inserchbook(reader *tip) ;//查看所借书本
void displayreader(reader *tip);//打印函数
void countreader(reader *tip);

#endif


