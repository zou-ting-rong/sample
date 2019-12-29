#include "StuInformation.h"
linkstudent *InitS(){
	linkstudent *headS;
	headS = (linkstudent *)malloc(sizeof(linkstudent));
	headS->next = NULL;
	return headS;
}

linkstudent *insertS(linkstudent *headS){
	linkstudent *temps = headS;
	linkstudent *q;
	q = (linkstudent *)malloc(sizeof(linkstudent));
	printf("请输入学号：");
	scanf("%d",&(q->DataS.number));
	printf("*********************************\n");
	printf("请输入姓名：");
	scanf("%s",q->DataS.names);
	printf("*********************************\n");
	printf("%d\n",q->DataS.number);
	//printf("请输入用户类别：");
	//scanf("%s",q->DataS.flag);
	strcpy(q->DataS.flag,"ordinary");
	q->next = temps->next;
	temps->next = q;
	temps = temps->next;
	return temps;
}

int insertA(linkstudent *headS){
	printf("********管理员账号初始化*********\n");
	linkstudent *q;
	q = (linkstudent *)malloc(sizeof(linkstudent));
	linkstudent *temps = headS; 
	printf("请输入用户名：");
	scanf("%s",q->DataS.names);
	printf("*********************************\n");
	printf("请输入密码：");
	scanf("%d",&(q->DataS.number));
	printf("*********************************\n");
	strcpy(q->DataS.flag,"administant");
	q->next = temps->next;
	temps->next = q;
	temps = temps->next;
	return 1;
}


/*int insertS(linkstudent *headS){
	printf("********普通用户账号初始化*********\n");
	linkstudent *q;
	q = (linkstudent *)malloc(sizeof(linkstudent));
	linkstudent *temps = headS; 
	printf("请输入姓名：");
	scanf("%s",q->DataS.names);
	printf("*********************************\n");
	printf("请输入学号：");
	scanf("%d",&(q->DataS.number));
	printf("*********************************\n");
	strcpy(q->DataS.flag,"ordinary");
	q->next = temps->next;
	temps->next = q;
	temps = temps->next;
	return 1;
}*/
int dleS(linkstudent *headS){
	linkstudent *temps = headS;
	int i;
	printf("请输入要删除学生的学号：\n");
	scanf("%d",&i);
	while(temps->next){
		if(temps->next->DataS.number == i){
			linkstudent *q;
			q = (linkstudent *)malloc(sizeof(linkstudent));
			q = temps->next;
			temps->next = temps->next->next;
			free(q);
		return 1;
		}
		else{
			printf("没有该学生！\n");
		}
	}
	return -1;
}

int changeS(linkstudent *headS){
	int i;
	linkstudent *q;//用于接住返回指针
	q = sercherS(headS);
	printf("|1|学号          |2|用户名\n");
	printf("请输入要修改的信息类型：\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			system("clear");
			printf("学号更改为：\n");
			scanf("%d",&(q->DataS.number));
			break;
		case 2:
			system("clear");
			printf("姓名更改为：\n");
			scanf("%s",q->DataS.names);
			break;
		default:
			printf("选择错误！\n");
	}
	printf("更改后的学生信息为：\n");
	displayS1(headS);
	return 1;
}

int sercherA(linkstudent *headS){
	int i;
	int j;
	char host[20];
	linkstudent *temps = headS;
	printf("请输入用户名：");
	scanf("%s",host);
	printf("*********************************\n");
	printf("请输入密码：");
	scanf("%d",&i);
	while(temps->next){
		temps = temps->next;
		if(temps->DataS.number == i){
			j = strcmp(temps->DataS.names,host);
			if(j == 0){
				return 1;
			}
		}
	}
	return -1;
} 
linkstudent *sercherS(linkstudent *headS){
	int i;
	int j;
	linkstudent *temps = headS;
	printf("请输入学号\n");
	scanf("%d",&i);
	while(temps->next){
		temps = temps->next;
		j = strcmp(temps->DataS.flag,"ordinary");         
		if(temps->DataS.number == i){
			j = strcmp(temps->DataS.flag,"ordinary");
			if(j == 0){
			printf("%s\n",temps->DataS.names);
			return temps;
			}
		} 
		else{
			printf("学生库中没有该学生！\n");
			return temps;
		}
	}
	return temps;
} 

int sercherS1(linkstudent *headS){
	int i;
	linkstudent *temps = headS;
	printf("请输入学号\n");
	scanf("%d",&i);
	while(temps->next){
		temps = temps->next;
		if(temps->DataS.number == i){
			printf("%s\n",temps->DataS.names);
			return 1;
		}
		else{
			printf("学生库中没有该学生！\n");
		}
	}
	return -1;
}
 
void displayS(linkstudent *headS){
	linkstudent *temps = headS;
	int i;
	while(temps->next){
		temps = temps->next;
		i = strcmp(temps->DataS.flag,"administant");
		if(i == 0){
			printf("**************************************\n");
			printf("****************管理员****************\n");
			printf("管理员账号：%s\n",temps->DataS.names);
			printf("**************************************\n");
		}
	} 
	printf("\n");
}

void displayS1(linkstudent *headS){
	linkstudent *temps = headS;
	int i;
	while(temps->next){
		temps = temps->next;
		i = strcmp(temps->DataS.flag,"ordinary");
		if(i == 0){
				printf("学生的学号：%d\n",temps->DataS.number);
				printf("学生的名字：%s\n",temps->DataS.names);
			}
		} 
	printf("\n");
} 
