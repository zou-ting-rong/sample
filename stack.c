#include <stdio.h>
#include <stdlib.h>

#define max 10
typedef int datatype;
typedef struct{
	datatype data[max];
	int length;
}stack;

stack *Init()//初始化
{
	stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->length = 0;
	if(s->length == 0){
		printf("初始化成功！\n");
		return ;
	}
	return;

}
int push(stack *s,datatype x)//入栈
{
	if(s->length >= max){
		printf("full!\n");
		return;
	}
	s->length++;
	s->data[s->length - 1] = x;
	return;
}
int pop(stack *s)//出栈
{
	datatype *x;
	x = (datatype *)malloc(sizeof(datatype));
	*x = s->data[s->length - 1];
	s->length--;
	free(x);
	return;
}

int gettop(stack *s)//获取栈顶元素
{
	printf("栈顶元素为：%d\n",s->data[s->length-1]);
	
}

void display(stack *s)//打印函数
{
	for(int i= 0;i < s->length;i++){
		printf("%d\n",s->data[i]);
	}
	return;
}

int main(int argc,char **argv)
{	
	stack *s;
	s = (stack *)malloc(sizeof(stack));//主函数要重新分配一次内存！！
	Init();
	for(int i = 0;i < 10;i++){//入栈10个元素
	push(s,i);
		}
	display(s);
	gettop(s);
	for(int i = s->length-1;i > 8 ;i--){//将后6个数据出栈
		pop(s);
	}
	display(s);
	gettop(s);//获取栈顶元素
	


	return 0;
}


