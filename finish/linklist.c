#include "linklist.h"

linklist *Init(){
	linklist *head;//单链表必须设定一个头指针；还有一个指向头指针的指针进行头指针进行遍历
	head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	head->count = 0;//
	if(head->next == NULL){
		printf("初始化成功！\n");
	}
	return head;
}

int seacher(linklist *head)
{
	int b;
	linklist *temp = head;
	printf("请输入你要查找的书本的编号：\n");
	scanf("%d",&b);
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == b){
			printf("该书本的名字：%s\n",temp->data.name);
			return temp->data.id;
		}
	}
	return -1;
}

linklist *change(linklist *head)
{
	int i;
	int j;
	linklist * temp = head;
	printf("请输入所要修改的书本的编号：\n");
	scanf("%d",&j);
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == j){
			printf("请输入你要更改的信息类型：\n");
			printf("***************************************\n");
			printf("|1|:id                 |2|:name\n");
			printf("***************************************\n");
			printf("|3|:author_name        |4|:DATA(出版日期)\n");	
			printf("***************************************\n");
			printf("|5|:info               |6|:publish\n");
			printf("***************************************\n");
			printf("|7|:price                          \n");
			printf("***************************************\n");
			scanf("%d",&i);
			switch(i){
				case 1:
					printf("id更改为：\n");
					scanf("%d",&(temp->data.id));
					break;
				case 2:
					printf("书本名字更改为：\n");
					scanf("%s",temp->data.name);
					break;
				case 3:
					printf("作者名字更改为：\n");
					scanf("%s",temp->data.author_name);
					break;
				case 4:
					printf("生产日期更改为：\n");
					scanf("%d",&(temp->data.DATA.year));
					scanf("%d",&(temp->data.DATA.month));
					scanf("%d",&(temp->data.DATA.day));
					break;
				case 5:
					printf("书本简介更改为：\n");
					scanf("%s",temp->data.info);
					break;
				case 6:
					printf("出版社更改为：\n");
					scanf("%s",temp->data.publish);
					break;
				case 7:
					printf("价格更改为:\n");
					scanf("%lf",&(temp->data.price));

				default:
					printf("输入的选择有误！\n");
			}
			return temp;
		}
		else{
			printf("编号输入错误！\n");
		}
	} 

}
linklist *insert1(linklist *head,linklist *ptr){
	linklist *temp = head;
	ptr->next = temp->next;
	temp->next = ptr;
	temp = temp->next;
	head->count++;
} 
linklist *insert(linklist *head)
{
	int i;
	linklist *temp = head;
	printf("请输入添加多少本书本：\n");
	scanf("%d",&i);
	for(int j = 0;j < i;j++){
	linklist *c;
	c = (linklist *)malloc(sizeof(linklist));
	head->count++;//计数器加一
	printf("请输入书本的id：\n");
	scanf("%d",&(c->data.id));
	while(temp->next){
		if(temp->data.id == c->data.id){
			printf("该编号已存在！请重新输入编号！\n");
			scanf("%d",&(c->data.id));
		}
		break;
	}
	printf("请输入该书本的出版时间：\n");
	scanf("%d",&(c->data.DATA.year));
	scanf("%d",&(c->data.DATA.month));
	scanf("%d",&(c->data.DATA.day));
	printf("***************************************\n");
	printf("请输入书本的名称：\n");
	scanf("%s",c->data.name);
	printf("***************************************\n");
	printf("请输入书本作者的名字：\n");
	scanf("%s",c->data.author_name);
	printf("***************************************\n");
	printf("请输入书本的相关简介：\n");
	scanf("%s",c->data.info);
	printf("***************************************\n");
	printf("请输入书本的出版社：\n");
	scanf("%s",c->data.publish);
	printf("请输入书本的价格：\n");
	scanf("%lf",&(c->data.price));
	printf("请输入书本所属类型：\n");
	scanf("%s",c->data.typebook);
	printf("***************************************\n");
	//printf("书本的状态：\n");
	//scanf("%s",c->data.flag);
	strcpy(c->data.flag,"inlibrary");	
	c->next = temp->next;
	temp->next = c;
	temp = temp->next;
	}
	return temp;
}

void display(linklist *head)
{
	linklist *temp = head;
	printf("*********图书馆库中有的书本及其相关信息**********\n");
	while(temp->next){
		temp = temp->next;
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
		printf("书本的类型：%s",temp->data.typebook);
		printf("***************************************\n");
		printf("书本的状态：%s\n",temp->data.flag);
		printf("***************************************\n");
	}
	printf("\n");
}

void displayB(linklist *head)
{
	linklist *temp = head;
	int i;
	int m;
	printf("*********图书馆库被借出书本及其相关信息**********\n");
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.flag,"borrow");
		m = strcmp(temp->data.flag,"order");
		if(i == 0 || m == 0){
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
		printf("书本的类型为：%s\n",temp->data.typebook);
		printf("***************************************\n");
		printf("书本的状态为：%s\n",temp->data.flag);
		printf("图书被借时间：%d-%d-%d\n",1900+temp->data.borrowtime->tm_year,1+temp->data.borrowtime->tm_mon,temp->data.borrowtime->tm_mday);
		}
		
	} 
}

linklist *dle(linklist *head)//返回一个指针的删除
{
	int i;
	linklist *temp = head;//创建一个指向头指针的指针，进行遍历
	printf("请输入你要删除书的编号：\n");
	scanf("%d",&i);
		while(temp->next){
			if(temp->next->data.id == i){
				linklist *p;
				p = (linklist *)malloc(sizeof(linklist));
				p = temp->next;
				temp->next = temp->next->next;
				free(p);
				head->count--;
				return temp->next;
			}
			temp = temp->next;
		}
}

linklist *dle1(linklist *head,int i)//返回一个整型的删除
{
	linklist *temp = head;//创建一个指向头指针的指针，进行遍历
		while(temp->next){
			if(temp->next->data.id == i){
				linklist *p;
				p = (linklist *)malloc(sizeof(linklist));
				p = temp->next;
				temp->next = temp->next->next;
				free(p);
				head->count--;
				return temp;//用来入暂存链表
			}
			temp = temp->next;
		}
		return head;
	}

void count (linklist *head)
{
	printf("***************************************\n");
	printf("图书馆一共有%d 本书\n",head->count);
	printf("***************************************\n");
}
