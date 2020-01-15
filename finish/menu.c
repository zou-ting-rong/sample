#include "menu.h"

void menu(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	system("clear");
	int i;
	printf("***********九江学院图书馆欢迎你***********\n");
	printf("*********************************************\n");
	printf("|1|管理员                        |2|普通用户\n");
	printf("*********************************************\n");
	printf("|3|地图                          |4|退出系统\n");
	printf("*********************************************\n");
	printf("***********请输入你对应的用户名称************\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			system("clear");
			hostname(head,tip,headS,temporary);
			//manager(head,tip,headS,temporary);
			break;
		case 2:
			system("clear");
			//user(head,tip);
			username(head,tip,headS,temporary);
			break;
		case 3:
			system("clear");
			graph();
			sleep(6);
			menu(head,tip,headS,temporary);
			break;
		case 4:
			break;

		default:
			system("clear");
			printf("选择有误,请重新输入：\n");
			menu(head,tip,headS,temporary);
		} 
}
/*void manager(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
			int j;
			printf("      *************管理员**************\n");
			printf("*********************************************************\n");
			printf("|1|添加图书               |2|按id排序\n");
			printf("*********************************************\n");
			printf("|3|按价格排序             |4|计算图书馆图书总数\n");
			printf("*********************************************\n");
			printf("|5|删除指定编号图书       |6|按id进行查找 \n");
			printf("*********************************************\n");
			printf("|7|按书名进行查找         |8|根据作者名字进行查找\n");
			printf("*********************************************\n");
			printf("|9|修改指定图书相关信息   |10|查看图书馆全部图书相关信息\n");
			printf("*********************************************\n");
			printf("|11|学生库信息            |12|返回上一界面\n");
			printf("*********************************************\n");
			printf("|13|查看已被借出或被预约的书本\n");
			printf("*********************************************\n");
			printf("请输入你的选择\n");
			scanf("%d",&j);
			switch(j){
				case 1:
					system("clear");
					insert(head);
					system("clear");
					manager(head,tip,headS,temporary);
					break;
				case 2:
					system("clear");
					bubble_id(head);
					system("clear");
					manager(head,tip,headS,temporary);
					break;
				case 3:
					system("clear");
					bubble_price(head);
					manager(head,tip,headS,temporary);
					break;
				case 4:
					system("clear");
					count(head);
					manager(head,tip,headS,temporary);
					break;
				case 5:
					system("clear");
					dle(head);
					manager(head,tip,headS,temporary);
					break;
				case 6:
					system("clear");
					seacher(head);
					manager(head,tip,headS,temporary);
					break;
				case 7:
					system("clear");
					findByname(head);
					manager(head,tip,headS,temporary);
					break;
				case 8:
					system("clear");
					findByauthor_name(head);
					manager(head,tip,headS,temporary);
					break;
				case 9:
					system("clear");
					change(head);
					manager(head,tip,headS,temporary);
					break;
				case 10:
					system("clear");
					display(head);
					//system("clear");
					manager(head,tip,headS,temporary);
					break;
				case 11:
					system("clear");
					students(head,tip,headS,temporary);
					break;
				case 12:
					system("clear");
					menu(head,tip,headS,temporary);
					break;
				case 13:
					system("clear");
					printf("*****************已被借出的书本**************\n");
					displayB(head);
					manager(head,tip,headS,temporary);
					break;
				default:
					printf("输入选项错误！\n");
					manager(head,tip,headS,temporary);
				}
		}
*/
void manager(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
			int j;
			printf("      *************管理员**************\n");
			printf("*********************************************************\n");
			printf("|1|添加图书               |2|查找书本\n");
			printf("*********************************************\n");
			printf("|3|排序                   |4|删除指定编号书本\n");
			printf("*********************************************\n");
			printf("|5|修改指定图书相关信息   |6|查看图书馆全部图书信息 \n");
			printf("*********************************************\n");
			printf("|7|学生库信息             |8|查看已被借出书本\n");
			printf("*********************************************\n");
			printf("|9|返回上一层                                \n");
			printf("*********************************************\n");
			printf("请输入你的选择\n");
			scanf("%d",&j);
			switch(j){
				case 1:
					system("clear");
					insert(head);
					system("clear");
					manager(head,tip,headS,temporary);
					break;
				case 2:
					system("clear");
					menu1(head,tip,headS,temporary);
					break;
				case 3:
					system("clear");
					menu2(head,tip,headS,temporary);
					manager(head,tip,headS,temporary);
					break;
				case 4:
					system("clear");
					dle(head);
					manager(head,tip,headS,temporary);
					break;
				case 5:
					system("clear");
					change(head);
					manager(head,tip,headS,temporary);
					break;
				case 6:
					system("clear");
					display(head);
					//system("clear");
					manager(head,tip,headS,temporary);
					break;
				case 7:
					system("clear");
					students(head,tip,headS,temporary);
					manager(head,tip,headS,temporary);
					break;
				case 8:
					system("clear");
					printf("*****************已被借出的书本**************\n");
					displayB(head);
					manager(head,tip,headS,temporary);
					break;
				case 9:
					system("clear");
					menu(head,tip,headS,temporary);
					break;
				default:
					printf("输入选项错误！\n");
					manager(head,tip,headS,temporary);
				}
		}
void menu1(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
			int j;
			printf("*********************************************************\n");
			printf("|1|按编号查找             |2|按书名查找\n");
			printf("*********************************************\n");
			printf("|3|按作者名查找           |4|按书本类型查找\n");
			printf("*********************************************\n");
			printf("|5|返回上一层\n");
			printf("*********************************************\n");
			printf("请输入你的选择\n");
			scanf("%d",&j);
			switch(j){
				case 1:
					system("clear");
					seacher(head);
					menu1(head,tip,headS,temporary);
					break;
				case 2:
					system("clear");
					findByname(head);
					menu1(head,tip,headS,temporary);
					break;
				case 3:
					system("clear");
					findByauthor_name(head);
					menu1(head,tip,headS,temporary);
					break;
				case 4:
					system("clear");
					findBytype(head);
					menu1(head,tip,headS,temporary);
					break;
				case 5:
					system("clear");
					manager(head,tip,headS,temporary);
					break;
				default:
					printf("输入选项错误！\n");
					menu1(head,tip,headS,temporary);
				}
		}

void menu2(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
			int j;
			printf("*********************************************************\n");
			printf("|1|按价格排序             |2|按编号排序\n");
			printf("*********************************************\n");
			printf("|3|返回上一层\n");
			printf("*********************************************\n");
			printf("请输入你的选择\n");
			scanf("%d",&j);
			switch(j){
				case 1:
					system("clear");
					bubble_price(head);
					menu2(head,tip,headS,temporary);
					break;
				case 2:
					system("clear");
					bubble_id(head);
					menu2(head,tip,headS,temporary);
					break;
				case 3:
					system("clear");
					menu1(head,tip,headS,temporary);
					break;
				default:
					printf("输入选项错误！\n");
					menu2(head,tip,headS,temporary);
				}
		}
void in(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	int t;
	printf("*********************************************\n");
	printf("|1|重新输入               |2|返回上一层\n");
	printf("*********************************************\n");
	scanf("%d",&t);
	switch(t){
		case 1:
			system("clear");
			manager(head,tip,headS,temporary);
			break;
		case 2:
			system("clear");
			menu(head,tip,headS,temporary);
			break;
		default:
			printf("*********************************************\n");
			printf("选择错误，请重新选择：\n");
			in(head,tip,headS,temporary);
	} 
}
void user(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){//********************************
				int k;
				printf("**************普通用户*****************\n");
				printf("*********************************************\n");
				printf("|1|按书名查找图书              |2|借书\n");
				printf("*********************************************\n");
				printf("|3|还书                        |4|查看所借书本\n");
				printf("*********************************************\n");
				printf("|5|修改个人信息                |6|返回上一层\n");
				printf("*********************************************\n");
				printf("|7|按书本类型查找              |8|预约书本  \n");
				printf("*********************************************\n");
				printf("|9|查看图书馆信息                            \n");
				printf("请输入你的选择\n");
				scanf("%d",&k);
				switch(k){
					case 1:
						system("clear");
						findByname(head);
						user(head,tip,headS,temporary);
						break;
					case 2:
						system("clear");
						push(head,tip,temporary);
						user(head,tip,headS,temporary);
						break;
					case 3:
						system("clear");
						pop(head,tip,temporary);
						user(head,tip,headS,temporary);
						break;
					case 4:
						system("clear");
						displayreader(tip);
						user(head,tip,headS,temporary);
						break;
					case 5:
						system("clear");
						changeS(headS);
						user(head,tip,headS,temporary);
						break;
					case 6:
						system("clear");
						menu(head,tip,headS,temporary);
						break;
					case 7:
						system("clear");
						findBytype(head);
						user(head,tip,headS,temporary);
					case 8:
						system("clear");
						linklist *q;
						q = (linklist *)malloc(sizeof(linklist));
						q = findBynameptr(head);
						changeflagO(head,q->data.id);
						gaintimeB(q,tip);
						user(head,tip,headS,temporary);
						break;
					case 9:
						system("clear");
						display(head);
						user(head,tip,headS,temporary);
						break;
					default:
						system("clear");
						printf("选择错误！\n");
						user(head,tip,headS,temporary);
				}
			}


void userfirst(linklist *head,linkstudent *headS,reader *tip,linklist *temporary){
				int i;
				i = sercherS1(headS);
				if(i == 1){
					user(head,tip,headS,temporary);
			}
				else{
					system("clear");
					printf("学号输入错误!\n");
					
					username(head,tip,headS,temporary);
				}
		} 
	
void hostname(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	int i;
	int m;
	printf("*************管理员**************\n");
	printf("********************************************************\n");
	printf("|1|登入                  |2|注册\n");
	printf("********************************************************\n");
	printf("|3|返回上一层\n");
	printf("********************************************************\n");
	printf("请输入你的选择:\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			system("clear");
			int i;
			i = sercherA(headS);
			if(i == 1){
				printf("正在登入...\n");
				sleep(1);
				manager(head,tip,headS,temporary);	
			}
			else{
				printf("该管理员不存在\n");
				hostname(head,tip,headS,temporary);
			}
			break;
		case 2:
			system("clear");
			int mima;
			mima = 123456;
			int l;
			printf("请输入注册密码：");
			scanf("%d",&l);
			if(l == mima){
			insertA(headS);
			printf("注册成功\n");
			} 
			m = sercherA(headS);
			if(m == 1){
				printf("正在登入...\n");
				sleep(1);
				manager(head,tip,headS,temporary);
				}
			else{
				printf("用户名或密码错误！\n");
				hostname(head,tip,headS,temporary);
			}
				break;
		case 3:
			system("clear");
			menu(head,tip,headS,temporary);
			break;
		default:
			printf("输入有误,请重新输入：\n");
			hostname(head,tip,headS,temporary);

	}
}
void username(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	int i;
	printf("*********普通用户**************\n");
	printf("********************************************************\n");
	printf("|1|登入                  |2|注册\n");
	printf("********************************************************\n");
	printf("|3|返回上一层\n");
	printf("********************************************************\n");
	printf("请输入你的选择:\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			system("clear");
			userfirst(head,headS,tip,temporary);
			break;
		case 2:
			system("clear");
			userregister(head,tip,headS,temporary);
			break;
		case 3:
			system("clear");
			menu(head,tip,headS,temporary);
			break;
		default:
			printf("输入有误,请重新输入：\n");
			username(head,tip,headS,temporary);

	}
}

void userregister(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	insertS(headS);
	system("clear");
	printf("注册成功！\n");
	system("clear");
	printf("正在登录...\n");
	sleep(1);
	userfirst(head,headS,tip,temporary);
}
void students(linklist *head,reader *tip,linkstudent *headS,linklist *temporary){
	int l;
	int q;
	printf("********************************************************\n");
	printf("|1|查看已在库中信息          |2|手动添加学生\n");
	printf("********************************************************\n");
	printf("|3|修改学生信息              |4|返回上一级 \n");
	printf("********************************************************\n");
	printf("请输入你的选择：\n");
	scanf("%d",&l);
	switch(l){
		case 1:
			displayS(headS);
			displayS1(headS);
			students(head,tip,headS,temporary);
			break;
		case 2:
			system("clear");
			printf("需要添加几个学生信息：\n");
			scanf("%d",&q);
			for(int x = 0;x < q;x++){
				insertS(headS);
				}
			
			system("clear");
			students(head,tip,headS,temporary);
			break;
		case 3:
			system("clear");
			displayS(headS);
			system("clear");
			changeS(headS);
			students(head,tip,headS,temporary);
			break;
		case 4:
			system("clear");
			manager(head,tip,headS,temporary);
			break;
		default:
			printf("选择错误！\n");
			students(head,tip,headS,temporary);
		}
} 
