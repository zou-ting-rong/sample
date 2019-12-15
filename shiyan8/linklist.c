#include "linklist.h"
void bubble_id(linklist *head){//有待改善
	linklist *temp = head;
	int m;
	printf("请输入图书馆的书本数：\n");
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
	printf("请输入图书馆的书本数：\n");
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
	//printf("%s\n",names);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.name,names);
		if(i == 0){
			printf("该书本的id:%d\n",temp->data.id);
			return 1;
		}
		else{
			printf("图书馆没有该书本！\n");
		}
		
	}
	return -1;
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
			printf("该书本的id:%d\n",temp->data.id);
			return temp->data.id;
		}
	}
	return -1;//查找成功
}

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
	linklist * temp;
	printf("请输入所要修改的书本的编号：\n");
	scanf("%d",&j);
	while(temp->next){
		if(temp->data.id == j){
			printf("请输入你要更改的信息类型：\n");
			printf("1:id                 2:name\n");
			printf("3:author_name        4:DATA(出版日期)\n");	
			printf("5:info               6:publish\n");
			printf("7:price                          \n");
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
	printf("请输入书本的名称：\n");
	scanf("%s",c->data.name);
	printf("请输入书本作者的名字：\n");
	scanf("%s",c->data.author_name);
	printf("请输入书本的相关简介：\n");
	scanf("%s",c->data.info);
	printf("请输入书本的出版社：\n");
	scanf("%s",c->data.publish);
	printf("请输入书本的价格：\n");
	scanf("%lf",&(c->data.price));
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
		printf("书本的id为：%d\n",temp->data.id);
		printf("书本的出版时间为：%d  年 %d 月 %d 日 \n",temp->data.DATA.year,temp->data.DATA.month,temp->data.DATA.day);
		printf("书本的名字为：%s\n",temp->data.name);
		printf("书本作者名字为：%s\n",temp->data.author_name);
		printf("书本的简介为：%s\n",temp->data.info);
		printf("书本的出版社为：%s\n",temp->data.publish);
		printf("书本的单价为：%lf\n",temp->data.price);

	}
	printf("\n");
}
int dle(linklist *head)
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
				return 1;
			}
			temp = temp->next;
		}
		linklist *p;
		p = (linklist *)malloc(sizeof(linklist));
		p = temp->next;
		temp->next = temp->next->next;
		free(p);
		head->count--;
		return -1;//手动释放c指针以免造成内存泄露
} 
void count (linklist *head)
{
	printf("图书馆一共有%d 本书\n",head->count);
}

