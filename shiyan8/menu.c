#include "menu.h"

void menu(linklist *head,reader *tip){
	int i;
	printf("***********九江学院图书馆欢迎你***********\n");
	printf("*********************************************\n");
	printf("|1|管理员                        |2|普通用户\n");
	printf("*********************************************\n");
	printf("***********请输入你对应的用户名称************\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			manager(head,tip);
			break;
		case 2:
			user(head,tip);
			break;
		default:
			printf("选择有误！\n");
		} 
} 
void manager(linklist *head,reader *tip){
			int j;
			int mima;
			int m;
			m = 123456;
			printf("请输入管理员密码：\n");
			scanf("%d",&mima);
			if(mima == m){
			printf("*************管理员**************\n");
			printf("|1|添加图书               |2|按id排序\n");
			printf("|3|按价格排序             |4|计算图书馆图书总数\n");
			printf("|5|删除指定编号图书       |6|按id进行查找 \n");
			printf("|7|按书名进行查找         |8|根据作者名字进行查找\n");
			printf("|9|修改指定图书相关信息   |10|查看图书馆全部图书相关信息\n");
			printf("|11|返回上一界面\n");
			printf("请输入你的选择");
			scanf("%d",&j);
			switch(j){
				case 1:
					insert(head);
					manager1(head,tip);
					break;
				case 2:
					bubble_id(head);
					manager1(head,tip);
					break;
				case 3:
					bubble_price(head);
					manager1(head,tip);
					break;
				case 4:
					count(head);
					manager1(head,tip);
					break;
				case 5:
					dle(head);
					manager1(head,tip);
					break;
				case 6:
					seacher(head);
					manager1(head,tip);
					break;
				case 7:
					findByname(head);
					manager1(head,tip);
					break;
				case 8:
					findByauthor_name(head);
					manager1(head,tip);
					break;
				case 9:
					change(head);
					manager1(head,tip);
					break;
				case 10:
					display(head);
					manager1(head,tip);
					break;
				case 11:
					menu(head,tip);
					break;
				default:
					printf("输入选项错误！\n");
				}
			}
		} 

void user(linklist *head,reader *tip){
				int k;
				printf("**************普通用户*****************\n");
				printf("|1|查找图书                |2|借书\n");
				printf("|3|还书                    |4|查看所借书本\n");
				printf("|5|返回上一层\n");
				printf("请输入你的选择\n");
				scanf("%d",&k);
				switch(k){
					case 1:
						findByname(head);
						user(head,tip);
						break;
					case 2:
						push(head,tip);
						user(head,tip);
						break;
					case 3:
						pop(head,tip);
						user(head,tip);
						break;
					case 4:
						displayreader(tip);
						user(head,tip);
						break;
					case 5:
						menu(head,tip);
						break;
					default:
						printf("选择错误！\n");
				}
			}


void manager1(linklist *head,reader *tip){
			int j;
			int mima;
			printf("*************管理员**************\n");
			printf("|1|添加图书               |2|按id排序\n");
			printf("|3|按价格排序             |4|计算图书馆图书总数\n");
			printf("|5|删除指定编号图书       |6|按id进行查找 \n");
			printf("|7|按书名进行查找         |8|根据作者名字进行查找\n");
			printf("|9|修改指定图书相关信息   |10|查看图书馆全部图书相关信息\n");
			printf("|11|返回上一界面\n");
			printf("请输入你的选择");
			scanf("%d",&j);
			switch(j){
				case 1:
					insert(head);
					manager1(head,tip);
					break;
				case 2:
					bubble_id(head);
					manager1(head,tip);
					break;
				case 3:
					bubble_price(head);
					manager1(head,tip);
					break;
				case 4:
					count(head);
					manager1(head,tip);
					break;
				case 5:
					dle(head);
					manager1(head,tip);
					break;
				case 6:
					seacher(head);
					manager1(head,tip);
					break;
				case 7:
					findByname(head);
					manager1(head,tip);
					break;
				case 8:
					findByauthor_name(head);
					manager1(head,tip);
					break;
				case 9:
					change(head);
					manager1(head,tip);
					break;
				case 10:
					display(head);
					manager1(head,tip);
					break;
				case 11:
					menu(head,tip);
					break;
				default:
					printf("输入选项错误！\n");
				}
			}
