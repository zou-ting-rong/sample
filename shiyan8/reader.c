#include "reader.h"

reader *Initreader(){
	reader *tip;
	tip = (reader *)malloc(sizeof(reader));
	tip->next = NULL;

	if(tip->next == NULL){
		printf("初始化成功！\n");
	}
	return tip;//没有该返回值代码运行是则会出现段错误！造成空指针错误
}

int push(linklist *head,reader *tip){ 
	int i;//用来接住返回数据
	int m;
	linklist *temp = head; 
	i = findByname(head);
	if(i == 1){
		reader *q;//用于接住数据、
		q = (reader *)malloc(sizeof(reader));
		printf("请输入你要借的书本的id：\n");
		scanf("%d",&(q->datareader.id));
		printf("请输入你想要借的书本的名字：\n");
		scanf("%s",q->datareader.name);
		m = q->datareader.id;
		q->next = tip->next;
		tip->next = q;
		tip->length++;
		dle(head);
		/*while(temp->next){
			if(temp->data.id == m){
				linklist *p;
				p = (linklist *)malloc(sizeof(linklist));
				p = temp->next;
				temp->next = temp->next->next;
				free(p);
				head->count--;
			}
			temp = temp->next;
		}*/
		display(head);
		displayreader(tip);
		return 1;
	}
	else{
		printf("图书馆没有该书，请重新查寻!\n");
	}
	return -1;
}//借书

int pop(linklist *head,reader *tip){
	reader *temp = tip;
	int i;
	printf("请输入你想要归还的书本编号：\n");
	scanf("%d",&i);
	while(temp->next){
		if(temp->next->datareader.id == i){
			reader *q;
			q = (reader *)malloc(sizeof(reader));
			q = temp->next;
			temp->next = temp->next->next;
			free(q);
			printf("还书成功！\n");
			displayreader(tip);
			return 1;
		}
		temp = temp->next;
	} 
	return -1;
}//还书

void serchbook(reader *tip){
	int i;
	reader *temp = tip;
	printf("请输入的书本的id：\n");
	scanf("%d",&i);
	while(temp->next){
		if(temp->datareader.id == i){
			printf("该书本的名字为：%s",temp->datareader.name);
		}
		printf("你未借该书本\n");
	}
}//查看所借书本

void displayreader(reader *tip){
	reader *temp = tip;
	printf("********所借的书本信息如下********：\n");
	while(temp->next){
		temp = temp->next;
		printf("书本的id：%d\n",temp->datareader.id);
		//printf("书本的出版日期:%d年%d月%d日",temp->data.DATA);
		printf("书本的名字:%s\n",temp->datareader.name);
		//printf("书本作者的名字:%s",temp->data.author_name);
		//printf("书本简介：%s",temp->data.info);
		//printf("书本的出版社：%s",temp->data.publish);
		//printf("书本的价格：%d",temp->data.price);
	}
	printf("\n");

}
//查看读者借了多少本书，并且查看所借书本
void countreader(reader *tip){
	printf("%d",tip->length);
	displayreader(tip);
}
