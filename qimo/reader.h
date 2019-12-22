#ifndef reader_h
#define reader_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 3
typedef struct{
	int id;
	char name[20];
	//time_t borrowtime;//时间
	//time_t returntime;//时间
	struct tm *borrowtime;
	struct tm *returntime;
}bookreader;
typedef struct stack{
	bookreader datareader;
	int length;
	struct stack *next;
}reader;

reader *Initreader();
void *push(linklist *head,reader *tip,linklist *temporary);//借书
int pop(linklist *head,reader *tip,linklist *temporary);//还书
int inserchbook(reader *tip) ;//查看所借书本
void displayreader(reader *tip);//打印函数
void countreader(reader *tip);
void gaintimeB(linklist *head,reader *tip);//获取借书时间模块
void gaintimeRl(linklist *head);//图书馆获得读者还书时间
void gaintimeR(linklist *head,reader *tip);//获取还书时间模块
void payment(linklist *head,reader *tip);
#endif


