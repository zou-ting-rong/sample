#ifndef StuInformation_h
#define StuInformation_h

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int number;//学号or密码
	char names[20];//用户名
	char flag[20];
}student;

typedef struct NodeS{
	student DataS;
	struct NodeS *next;
}linkstudent;

linkstudent *InitS();
linkstudent *insertS(linkstudent *headS);
int insertA(linkstudent *headS);
int dleS(linkstudent *headS);
int changeS(linkstudent *headS);
linkstudent *sercherS(linkstudent *headS);
//int sercherS(linkstudent *headS);
int sercherS1(linkstudent *headS);
int sercherA(linkstudent *headS);
void displayS(linkstudent *headS);
void displayS1(linkstudent *headS);


#endif
