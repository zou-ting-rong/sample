#include "reader.h"

void gaintimeB(linklist *head,reader *tip){
	time_t t;
	time(&t);
	tip->datareader.borrowtime = localtime(&t);
	head->data.borrowtime = localtime(&t);
}
//获取借书时间

void gaintimeR(linklist *head,reader *tip){
	time_t t;
	time(&t);
	tip->datareader.returntime = localtime(&t);
}

void gaintimeRl(linklist *head){
	time_t t;
	time(&t);
	head->data.returntime = localtime(&t);
}
void payment(linklist *head,reader *tip){
	if((tip->datareader.returntime - tip->datareader.borrowtime)){
		int day;
		int pay;
		day = tip->datareader.returntime - tip->datareader.borrowtime;
		pay = day * 1;
		printf("你需要缴纳的超时费用：%d 元\n",pay);
	}
}
//获取还书时间
reader *Initreader(){
	reader *tip;
	tip = (reader *)malloc(sizeof(reader));
	tip->next = NULL;

	if(tip->next == NULL){
		printf("初始化成功！\n");
	}
	return tip;//没有该返回值代码运行是则会出现段错误！造成空指针错误
}

void *push(linklist *head,reader *tip,linklist *temporary){ 
	int i;//用来接住返回数据
	int m;
	//linklist *temp = head;
	linklist *p;//用来接收返回的temp指针
	p = (linklist *)malloc(sizeof(linklist));
	//i = findByname(head);
	p = findBynameptr(head);
	i = p->data.id;
	if(i == 1){
		reader *q;//用于接住数据、
		q = (reader *)malloc(sizeof(reader));
		q->datareader.id = p->data.id;
		strcpy(q->datareader.name,p->data.name);
		gaintimeB(p,q);
		q->next = tip->next;
		tip->next = q;
		tip->length++;
		changeflagB(head,q->datareader.id);//////
		displayreader(tip);
	} 
		else{
		printf("***************************************\n");
		printf("图书馆没有该书，请重新查寻!\n");
		printf("***************************************\n");
		} 
}//借书

int pop(linklist *head,reader *tip,linklist *temporary){
	reader *temps = tip;
	linklist *temp = head;
	int i;
	printf("***************************************\n");
	printf("请输入你想要归还的书本编号：\n");
	printf("***************************************\n");
	scanf("%d",&i);
	while(temps->next){
		if(temps->next->datareader.id == i){
			reader *q;
			q = (reader *)malloc(sizeof(reader));
			q = temps->next;
			temps->next = temps->next->next;
			gaintimeR(head,q);
			payment(head,q);
			changeflagI(head,i);
			free(q);
			printf("***************************************\n");
			printf("还书成功！\n");
			printf("***************************************\n");
			return 1;//
		}
		temps = temps->next;
	} 
	return -1;
}//还书

void serchbook(reader *tip){
	int i;
	reader *temp = tip;
	printf("***************************************\n");
	printf("请输入的书本的id：\n");
	printf("***************************************\n");
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
		printf("***************************************\n");
		printf("书本的id：%d\n",temp->datareader.id);
		printf("***************************************\n");
		//printf("书本的出版日期:%d年%d月%d日",temp->data.DATA);
		printf("书本的名字:%s\n",temp->datareader.name);
		printf("***************************************\n");
		printf("借书日期：%d-%d-%d\n",1900+temp->datareader.borrowtime->tm_year,1+temp->datareader.borrowtime->tm_mon,temp->datareader.borrowtime->tm_mday);

	}
	printf("\n");

}
//查看读者借了多少本书，并且查看所借书本
void countreader(reader *tip){
	printf("***************************************\n");
	printf("一共借书：%d\n",tip->length);
	printf("***************************************\n");
	displayreader(tip);
}

