#include <stdio.h>
#include <stdlib.h>

#define max 5
typedef int datatype;
typedef struct{
	datatype data[5];
	int length;
}stack;

stack *Init()
{
	stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->length = 0;
	if(s->length == 0){
		printf("初始化成功！\n");
		return ;
	}
	else{
		printf("初始化失败！\n");
	}
	/*for(int i = 0;i < max;i++){
		s->data[i] = i;
		s->length++;
	}*/
	return;

}
int push(stack *s,datatype x)
{
	if(s->length >= max){
		printf("full!\n");
		return;
	}
	s->length++;
	s->data[s->length - 1] = x;
	return;
}
int pop(stack *s)
{
	datatype *x;
	x = (datatype *)malloc(sizeof(datatype));
	*x = s->data[s->length - 1];
	s->length--;
	free(x);
	return;
}

int gettop(stack *s)
{
	printf("%d\n",s->data[4]);
	
}

void display(stack *s)
{
	for(int i= 0;i < s->length;i++){
		printf("%d\n",s->data[i]);
	}
	return;
}

int main(int argc,char **argv)
{	
	//typedef int datatype;
	//datatype data;
	stack *s;
	s = (stack *)malloc(sizeof(stack));//主函数要重新分配一次内存！！
	//int arr[] = {0,1,2,3,4};
	//data = arr;
	Init();
	//display(s);
	push(s,2);
	//pop(s);
	//display(s);
	//gettop(s);
	


	return 0;
}


