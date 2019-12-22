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
	printf("请输入书本所属类型：");
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

/*linklist *insertptr(linklist *head,linklist *ptr)//从暂存链表中将数据返回
{
	linklist *temp = temp;
	ptr->next = temp->next;
	temp->next = ptr;
	temp = temp->next;
	return temp;
}*/

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

linklist *Inittem(){
	linklist *temporary;
	temporary = (linklist *)malloc(sizeof(linklist));
	temporary->next = NULL;
	return temporary;
}//暂存链表的初始化

linklist *inserttem(linklist *temporary,book data){
	linklist *temptem = temporary;
	linklist *q;
	q = (linklist *)malloc(sizeof(linklist));
	q->data = data;
	q->next = temporary->next;
	temporary->next = q;
	temporary = temporary->next;
	return temporary;
}//暂存链表的插入

linklist *dletem(linklist *head,linklist *temporary,int i){
	linklist *temptem = temporary;
	while(temporary->next){
		//temptem = temptem->next;
		if(temptem->data.id = i){
			linklist *ptr1;//申请结点
			ptr1 = (linklist *)malloc(sizeof(linklist));
			ptr1 = temptem;
			temptem->next = temptem->next->next;
			//inserttem(head,ptr1);
			insert1(head,ptr1);
			free(ptr1);
		}
		temptem = temptem->next;
	}
}//将暂存链表中的数据返回

void displaytem(linklist *temporary){
	linklist *temptem = temporary;
	while(temporary->next){
		temptem = temptem->next;
		printf("***************************************\n");
		printf("书本的id为：%d\n",temptem->data.id);
		printf("***************************************\n");
		printf("书本的出版时间为：%d  年 %d 月 %d 日 \n",temptem->data.DATA.year,temptem->data.DATA.month,temptem->data.DATA.day);
		printf("***************************************\n");
		printf("书本的名字为：%s\n",temptem->data.name);
		printf("***************************************\n");
		printf("书本作者名字为：%s\n",temptem->data.author_name);
		printf("***************************************\n");
		printf("书本的简介为：%s\n",temptem->data.info);
		printf("***************************************\n");
		printf("书本的出版社为：%s\n",temptem->data.publish);
		printf("***************************************\n");
		printf("书本的单价为：%lf\n",temptem->data.price);
		printf("***************************************\n");
	}
	printf("\n");
}//打印暂存链表中的信息


