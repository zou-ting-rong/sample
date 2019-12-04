# include<string.h>
# include<stdlib.h>
#include<conio.h>


typedef struct book {
char BookName[100];
char BookNumber[30];
char Author[50];
int  TotalNumber;
int  ResidualNumber;
}book;


typedef struct reader {
char ReaderName[30];
char ReaderNumber[100];
char ReaderPassword[100];
char sex[10];
}reader;


typedef struct borrowbook{
book  data;
struct borrowbook * next;
}borrowbook, *Borrowbook;


typedef struct borrowreader {
reader  data;
struct borrowreader *next;
}borrowreader,*Borrowreader;


typedef struct book_node {
book data;
    struct book_node * next;
Borrowreader reader;
}book_node,*book_link;


typedef struct reader_node {
int BorrowNumber;
reader data;
reader_node *next;
Borrowbook book;
}reader_node,*reader_link;




book_link SearchBookY(book_link H, char BookNumber[30])
{
H = H->next;
while (H&&strcmp(H->data.BookNumber, BookNumber))
{
H = H->next;
}
return H;
}




book_link BookCreate()
{
char book_name[100];
char book_number[30];
char author[50];
int  total_number;
book_link H=(book_link)malloc(sizeof(book_node));//--------------------------------------------------------H为创建的头节点指针，当函数完成的时候，返回H。
book_link p;//---------------------------------------------------------采用尾插法建立链表，p指向当前链表末尾的指针。
H->next = NULL;
p = H;
printf("                             请完成图书信息的录入：                 \n");
printf("请输入书的名字(当输入-1时结束输入):\n");
scanf_s("%s", book_name, 100);
printf("请输入图书的书号：\n");
scanf_s("%s", book_number, 30);
printf("请输入图书的作者：\n");
scanf_s("%s", author, 50);
printf("请输入入库书的总数：\n");
scanf_s("%d", &total_number);
while (strcmp(book_name, "-1"))
{
   book_link s = (book_link)malloc(sizeof(book_node));
strcpy_s(s->data.BookName, book_name);
strcpy_s(s->data.BookNumber, book_number);
strcpy_s(s->data.Author, author);
s->data.TotalNumber = total_number;
s->data.ResidualNumber = s->data.TotalNumber;
s->reader = (Borrowreader)malloc(sizeof(borrowreader));
s->reader->next = NULL;
p->next = s;
s->next = NULL;
p = s;
system("cls");
printf("请输入书名(当输入-1时结束输入):\n");
scanf_s("%s", book_name, 100);
if(strcmp(book_name, "-1")!=0)
{
printf("请输入图书号：\n");
scanf_s("%s", book_number, 30);
while (SearchBookY(H,book_number))
{
printf("图书账号已经存在，请重新输入图书账号：\n");
scanf_s("%s", book_number, 30);
}
printf("请输入作者姓名：\n");
scanf_s("%s", author, 50);
printf("请输入图书的总量：\n");
scanf_s("%d", &total_number);
}
}
printf("                             图书信息录入完成！                     \n");
_getch();
return H;
}


void ShowBook(book_link H)
{
H= H->next;
printf("书号         书名         作者         总量          剩余量\n");
while (H)
{
printf("  %s           %s           %s           %d              %d\n", H->data.BookNumber, H->data.BookName, H->data.Author, H->data.TotalNumber, H->data.ResidualNumber);
H = H->next;
}
}


int EqualBook(book a,book b)
{
int i = 0;
if (strcmp(a.BookName, b.BookName)==0)
{
i++;
printf("%d", i);
}
if (strcmp(a.Author, b.Author)==0)
{
i++;
printf("%d", i);
}
if (i == 2)
return 1;//------------------------------------------------------------当两本书相等的的时候，返回1
else
return 0;//------------------------------------------------------------当两本书不等的时候，返回0
}




book_link SearchBook(book_link H,book s)
{
H = H->next;
while (H&&EqualBook(H->data,s)==0)
{
H = H->next;
}
return H;
}


book_link SearchBookN(book_link H, book s)
{
H = H->next;
while (H&&strcmp(H->data.BookNumber,s.BookNumber))
{
H = H->next;
}
return H;
}




void AddBook(book_link H)
{
book b;
book_link p;
book_link q = (book_link)malloc(sizeof(book_node));
printf("                             请完成图书信息的增加：                 \n");
printf("请输入书名:\n");
scanf_s("%s", b.BookName, 100);
printf("请输入书的作者：\n");
scanf_s("%s", b.Author, 50);
printf("请输入录入图书的总量：\n");
scanf_s("%d", &b.TotalNumber);
p = SearchBook(H, b);
if (p)
{
p->data.TotalNumber = p->data.TotalNumber + b.TotalNumber;
p->data.ResidualNumber = p->data.ResidualNumber + b.TotalNumber;
}
else
{
p = H;
printf("请输入书号：\n");
scanf_s("%s", b.BookNumber,30);
while (p->next)
{
p = p->next;
}
q->data = b;
q->next = NULL;
q->data.ResidualNumber = q->data.TotalNumber;
q->reader = (Borrowreader)malloc(sizeof(borrowreader));
q->reader->next = NULL;
p->next = q;
}
printf("                             图书信息增加成功                       \n");
}




void ModifyBook(book_link H)
{
char number[100];//------------------------------------------保存要修改的图书的图书号
char s[100];     //-------------------------------------------保存要修改的信息
int num=0;       //-------------------------------------------保存要修改图书的数量
int c=-1;
printf("                             请完成图书信息的修改：                 \n");
printf("请输入要修改图书的图书号：\n");
scanf_s("%s", number,100);
getchar();
H = H->next;
while (H&&strcmp(H->data.BookNumber, number))
{
H = H->next;
}
printf("请输入要修改的选项：\n");
printf("                             请完成图书信息的修改：                 \n");
printf("                              1     修改作者                        \n");
printf("                                                                    \n");
printf("                              2     修改图书号                      \n");
printf("                                                                    \n");
printf("                              3     修改书名                        \n");
printf("                                                                    \n");
printf("                              4     修改图书总量                    \n");
printf("                                                                    \n");
printf("                              5     修改剩余图书总量                \n");
printf("                                                                    \n");
scanf_s("%d", &c);
switch (c)
{
case  1:
{
printf("请输入作者姓名：\n");
scanf_s("%s", s, 100);
strcpy_s(H->data.Author, s);
printf("修改成功\n");
break;
}
case 2:
{
printf("请输入要修改的图号:\n");
scanf_s("%s", s, 100);
strcpy_s(H->data.BookNumber, s);
printf("修改成功\n");
break;
}
case 3:
{
printf("请输入要修改的书名:\n");
scanf_s("%s", s, 100);
strcpy_s(H->data.BookName, s);
printf("修改成功\n");
break;
}
case 4:
{
printf("请输入要修改的图书总量:\n");
scanf_s("%d", num);
H->data.TotalNumber = num;
printf("修改成功\n");
break;
}
case 5 :
{
printf("请输入要修改图书的剩余总量：\n");
scanf_s("%d", num);
H->data.ResidualNumber = num;
printf("修改成功\n");
break;
}
}
printf("                             图书信息修改成功！                     \n");
}




int NumberBook(book_link H)
{
int i = 0;  //------------------------------------------------记录有多少图书储存的变量
H = H->next;
while (H)
{
i++;
H = H->next;
}
return i;
}




void QueryBook(book_link b)
{
char choice=-1;//----------------------------------------控制菜单选项
char number[30];//----------------------------------------保存用于查找的信息
char name[100];
char author[50];
printf("                                请输入选项                          \n");
printf("                              1  按书名查找                         \n");
printf("                                                                    \n");
printf("                              2  按书号查找                         \n");
printf("                                                                    \n");
printf("                              3  按作者查找                         \n");
printf("                                                                    \n");
printf("                              4  显示所有图书                       \n");
scanf_s(" %c",&choice);
switch (choice)
{
case '1':
{
printf("请输入要查找图书的书名：\n");
scanf_s("%s", name, 100);
b = b->next;
while (b)
{
if (!strcmp(b->data.BookName, name))
{
printf("书号         书名         作者         总量          剩余量\n");
printf("  %s           %s           %s           %d              %d\n", b->data.BookNumber, b->data.BookName, b->data.Author, b->data.TotalNumber, b->data.ResidualNumber);
}
b = b->next;
}
break;
}
case '2':
{
printf("请输入要查找图书的书号：\n");
scanf_s("%s", number, 30);
while (b&&strcmp(b->data.BookNumber, number))
{
b = b->next;
}
printf("书号         书名         作者         总量          剩余量\n");
printf("  %s           %s           %s           %d              %d\n", b->data.BookNumber, b->data.BookName, b->data.Author, b->data.TotalNumber, b->data.ResidualNumber);
break;
}
case '3':
{
printf("请输入要查找图书的作者：\n");
scanf_s("%s", author, 50);
while (b)
{
if (!strcmp(b->data.Author, author))
{
printf("书号         书名         作者         总量          剩余量\n");
printf("  %s           %s           %s           %d              %d\n", b->data.BookNumber, b->data.BookName, b->data.Author, b->data.TotalNumber, b->data.ResidualNumber);
}
b = b->next;
}
break;
}
case '4':
{
ShowBook(b);
break;
}
}
}




void DeleteBook(book_link H)
{
printf("                             请完成图书信息的删除：                 \n");
char number[100];//----------------------------------------完成要存储书号的保存
book_link p;     //----------------------------------------指向当前删除的图书
int num=0;      //----------------------------------------保存书的数量
num = NumberBook(H);
printf("请输入要删除图书的图书号：\n");
scanf_s("%s", number, 100);
p = H;
H= H->next;
while (H&&strcmp(H->data.BookNumber, number))
{
p = p->next;
H = H->next;
}
if (num== 1)
{
free(H);
printf("删除成功，并且库存已空：\n");
}
else
{
p->next = H->next;
free(H);
printf("删除成功：\n");
}
}


reader_link  SearchReader(reader_link H, char number_reader[100])
{
if (!H)
{
return NULL;
}
else
{
H = H->next;
while (H&&strcmp(H->data.ReaderNumber, number_reader))
{
H = H->next;
}
return H;
}
}




reader_link ReaderCreeate()
{
printf("                             请完成读者信息的创建：                 \n");
char reader_name[30];
char reader_number[100];
char reader_sex[10];
char password[100] = { '1','2','3','4','5','6' };
reader_link H = (reader_link)malloc(sizeof(reader_node)); //--------保存读者的信息的头节点
reader_link p;//-------------------------------------------采用尾插法建立链表
H->next = NULL;
p = H;
printf("请完成读者信息的录入：\n");
printf("请输入读者的号(当输入-1时结束输入):\n");
scanf_s("%s", reader_number, 100);
printf("请输入读者的姓名：\n");
scanf_s("%s", reader_name, 30);
printf("请输读者性别：\n");
scanf_s("%s", reader_sex, 10);
while (strcmp(reader_number, "-1"))
{
reader_link s = (reader_link)malloc(sizeof(reader_node));
strcpy_s(s->data.ReaderNumber, reader_number);
      strcpy_s(s->data.ReaderName, reader_name);
strcpy_s(s->data.sex,reader_sex);
strcpy_s(s->data.ReaderPassword, password);
s->BorrowNumber = 15;
s->book= (Borrowbook)malloc(sizeof(borrowbook));
s->book->next = NULL;
p->next = s;
s->next = NULL;
p = s;
system("cls");
printf("请输入读者的号(当输入-1时结束输入)：\n");
scanf_s("%s", reader_number,100);
while(SearchReader(H, reader_number))
{
printf("读者账号已经存在，请重新输入读者账号：\n");
scanf_s("%s", reader_number, 100);
}
if (strcmp(reader_number, "-1") != 0)
{
printf("请输入读者的姓名：\n");
scanf_s("%s", reader_name, 30);
printf("请输入读者的性别：\n");
scanf_s("%s", reader_sex, 10);
}
}
printf("                             读者信息创建成功：                 \n");
return H;
}


void  ShowReader(reader_link H)
{
H = H->next;
printf("读者姓名            读者号           读者性别\n");
while (H)
{
printf("      %s                %s                 %s\n",H->data.ReaderName,H->data.ReaderNumber,H->data.sex);
H = H->next;
}
}




void AddReader(reader_link H)
{
char password[100] = { '1','2','3','4','5','6' };
reader b;
reader_link p;
reader_link q = (reader_link)malloc(sizeof(reader_node));
printf("请依次输入读者号:\n");
scanf_s("%s", b.ReaderNumber, 100);
while(SearchReader(H, b.ReaderNumber))
{
printf("读者账号已经存在，请重新输入读者账号：\n");
scanf_s("%s", b.ReaderNumber, 100);
}
printf("请输入读者的姓名：\n");
scanf_s("%s", b.ReaderName, 30);
printf("请输入读者的性别：\n");
scanf_s("%s",b.sex,10);
strcpy_s(b.ReaderPassword, password);
p = H;
while (p->next)
{
p = p->next;
}
q->data = b;
q->next = NULL;
q->BorrowNumber = 15;
q->book = (Borrowbook)malloc(sizeof(borrowbook));
q->book->next = NULL;
p->next = q;
}


void DeleteReader(reader_link H)
{
printf("                             请完成图书信息的修改：                 \n");
char number[100];//----------------------------------------完成要存储读者号的保存
reader_link p;     //----------------------------------------指向当前删除的图书
printf("请输入要删除读者的读者号：\n");
scanf_s("%s", number, 100);
p = H;
H = H->next;
while (H&&strcmp(H->data.ReaderNumber, number))
{
p = p->next;
H = H->next;
}
if (H->BorrowNumber != 15)
{
printf("该读者有图书借阅，无法删除读者\n");
}
else
{
if (!strcmp(H->data.ReaderNumber, number))
{
printf("书库中不存在这本书，无法删除！\n");
}
else
{
p->next = H->next;
free(H);
printf("删除成功\n");
}
}
}


void ModifyReader(reader_link r)
{
printf("                             请完成读者信息的修改：                 \n");
int choice1 = -1;//--------------------------------------控制菜单变量
char number[100];//------------------------------------------保存要修改的读者信息的读者号
char s[100];     //------------------------------------------保存要修改的信息
char c = -1;      //------------------------------------------用于控制修改的变量
printf("请输入要修改读者的读者号：\n");
scanf_s("%s", number, 100);
getchar();
r= r->next;
while (r&&strcmp(r->data.ReaderNumber, number))
{
r = r->next;
}
printf("请输入要修改的选项：\n");
printf("                             请完成图书信息的修改：                 \n");
printf("                              1     修改读者姓名                    \n");
printf("                                                                    \n");
printf("                              2     修改读者号                      \n");
printf("                                                                    \n");
printf("                              3     修改读者密码                    \n");
printf("                                                                    \n");
printf("                              4     修改读者性别                    \n");
scanf_s("%c", &c);
switch(c)
{
 case '1':
{
printf("请输入读者姓名：\n");
scanf_s("%s", s, 100);
strcpy_s(r->data.ReaderName, s);
printf("修改成功\n");
break;
}
 case '2':
{
printf("请输入读者号：\n");
scanf_s("%s", s, 100);
strcpy_s(r->data.ReaderNumber, s);
printf("修改成功\n");
break;
}
 case '3':
{
printf("请输入读者密码：\n");
scanf_s("%s", s, 100);
strcpy_s(r->data.ReaderPassword, s);
printf("修改成功\n");
break;
}
case '4':
{
printf("请输入读者性别：\n");
scanf_s("%s", s, 100);
strcpy_s(r->data.sex, s);
printf("修改成功\n");
break;
}
}
}


void ResetPassword(reader_link r)
{


char password1[100];
char password2[100];
int m = 0, n = 0, p = 0, q = 0;//-------------------------------------控制循环变量
int i = 0;
while (i != 2)
{
printf("请输入密码;\n");
while (1)
{
if (n >= 0)
{
password1[m++] = _getch();


if (m - 1 >= 0 && password1[m - 1] == '\b')
{
putchar(8);
putchar(' ');
putchar(8);
m--;
n--;
}
else
{
if (password1[m - 1] == '\r')
break;
printf("*");
n++;
}
}
else
{
_getch();
n = 0;
m = 0;
}
}
password1[n] = '\0';
i++;
printf("\n");
printf("请再次输入密码：\n");
while (1)
{
if (q >= 0)
{
password2[p++] = _getch();
if (p - 1 >= 0 && password2[p - 1] == '\b')
{
putchar(8);
putchar(' ');
putchar(8);
p--;
q--;
}
else
{
if (password2[p - 1] == '\r')
break;
putchar('*');
q++;
}
}
else
{
_getch();
q = 0;
p = 0;
}
}
password2[q] = '\0';
i++;
if (strcmp(password1, password2))
{
printf("\n");
printf("两次密码输入不一致，请再次输入密码:\n");
i = 0;
}
}
strcpy_s(r->data.ReaderPassword, password1);
}




int Password( char password2[100])
{
int m = 0, n = 0;//-------------------------------------控制循环变量
int i = 0,p=0;
char password1[100];
while (i!=1)
{
while (1)
{
if (n >= 0)
{
password1[m++] = _getch();


if (m - 1 >= 0 && password1[m - 1] == '\b')
{
putchar(8);
putchar(' ');
putchar(8);
m--;
n--;
}
else
{
if (password1[m - 1] == '\r')
break;
printf("*");
n++;
}
}
else
{
_getch();
n = 0;
m = 0;
}
}
password1[n] = '\0';
i=1;
printf("\n");
if (strcmp(password1, password2))
{
printf("请再次输入密码：\n");
if (p>=0&&p <3)
{
i = 0;
p++;
n = 0;
m = 0;
printf("还有%d次机会:\n", 4 - p);
}
}
}
if (p == 3)
return 0;
else
return 1;
}


reader_link login(reader_link H , char number_reader[100])      
{
char password[10] = {'1','2','3','4','5','6'};
// char number_reader[100];
char password_reader[100];
printf("请输入读者账号：\n");
scanf_s("%s", number_reader, 100);
reader_link r = SearchReader(H, number_reader);//------------------------------------保存读者的信息的节点
if (!r)
{
printf("读者不存在，请先注册读者账号：\n");
_getch();
return NULL;
}
else
{
if (!strcmp(r->data.ReaderPassword, password))
{
printf("读者第一次登录系统，请初始化密码：\n");
ResetPassword(r);
printf("\n");
}
printf("请输入读者密码;\n");
if (Password(r->data.ReaderPassword))
{
printf("登陆成功\n");
return r;
}
else
{
printf("密码错误，请重新输入\n");
return NULL;
}
}
}


void jieyue(reader_link r, book_link b,reader_link reader_login)
{
book a;//------------------------------------------保存要借阅的书号
book_link book_jieyue;//----------------------------------修改借阅书的结点
reader_link reader_jieyue;//------------------------------保存要借阅读者的节点
char number_reader[100];
reader_jieyue = reader_login;
printf("\n");
printf("请输入要要借阅的书号：\n");
scanf_s("%s", a.BookNumber, 30);
book_jieyue = SearchBookN(b, a);
if (book_jieyue->data.ResidualNumber == 0)
printf("该书已经为空，无法完成借阅：\n");
if (reader_jieyue->BorrowNumber == 0)
printf("读者借阅书已满，请先归还图书再借阅：\n");
Borrowreader reader_last;//-----------------------------用于指向读者借阅图书链表的最后一个
Borrowbook book_last;//----------------------------------用于图书借阅读者链表的最后一个
Borrowbook book_=(Borrowbook)malloc(sizeof(borrowbook));   //------------------------------用于指向当前要开辟的图书
Borrowreader reader_ = (Borrowreader)malloc(sizeof(borrowreader));   //--------------------用于指向当前要开辟的读者
reader_last = book_jieyue->reader;
book_last= reader_jieyue->book;
while (book_last->next)
{
book_last = book_last->next;
}
book_->data = book_jieyue->data;
book_->next = NULL;
book_->data.ResidualNumber--;
book_last->next= book_;
reader_jieyue->BorrowNumber--;
while (reader_last->next)
{
reader_last = reader_last->next;
}
reader_->data = reader_jieyue->data;
reader_->next = NULL;
reader_last->next = reader_;
book_jieyue->data.ResidualNumber--;
printf("借阅完成\n");
}


void guihuan(reader_link r, book_link b,reader_link reader_login)
{
Borrowbook book_guihuan;//----------------在读者信息中存储要借阅图书的链表结点
Borrowbook p;//---------------------------指向要归还书的前驱结点
Borrowreader q;//-------------------------指向要归还读者的前驱结点
Borrowreader reader_guihuan;//------------指向要归还图书的当前结点
reader_link read;     //------------------指向当前要归还图书的读者号
book_link book_guihuan1;//--------------- 存储要借阅归还的节点
char number_reader[100];//----------------保存读者的图书号
char number_book[100];//------------------保存要归换的图书号
    read = reader_login;
    book_guihuan = read->book;
book_guihuan = book_guihuan->next;
printf("书号         书名         作者        \n");
if (book_guihuan==NULL)
printf("没有借阅图书\n");
else
{
while (book_guihuan)
{
printf("  %s           %s           %s         \n", book_guihuan->data.BookNumber, book_guihuan->data.BookName, book_guihuan->data.Author);
book_guihuan = book_guihuan->next;
}
printf("请输入要归还的图书号:\n");
scanf_s("%s", number_book, 100);
p = read->book;
book_guihuan = p->next;
while (book_guihuan->next&&strcmp(number_book, book_guihuan->data.BookNumber))
{
p = p->next;
book_guihuan = book_guihuan->next;
}
p->next = book_guihuan->next;
r->BorrowNumber++;
book_guihuan1 = SearchBookN(b, book_guihuan->data);
q = book_guihuan1->reader;
reader_guihuan = q->next;
while (reader_guihuan->next&&strcmp(number_reader, book_guihuan1->reader->data.ReaderNumber))
{
q = q->next;
reader_guihuan = reader_guihuan->next;
}
q->next = reader_guihuan->next;
book_guihuan1->data.ResidualNumber++;
free(reader_guihuan);
free(book_guihuan);
printf("归还成功\n");
}
}




void jiami(char *password)
{
int i;
i = strlen(password);
i = i + 1;
for (int j = 0; j < strlen(password); j++)
{
password[j] = password[j] + i;
i--;
}
}




void jiemi(char *password)
{
int i;
i = strlen(password);
i = i + 1;
for (int j = 0; j < strlen(password); j++)
{
password[j] = password[j] - i;
i--;
}
}




void FilePassword(char password[100])
{
FILE *fp;
if ((fp = fopen("E:\\图书馆管理系统\\管理员密码.txt", "w+")) == NULL)
{
printf("文件无法打开！\n");
exit(0);
}
jiami(password);
fprintf(fp, "%s", password);
fclose(fp);
}




void LoadPassword(char password[100])
{
FILE *fp;
if ((fp = fopen("E:\\图书馆管理系统\\管理员密码.txt", "r")) == NULL)
{
printf("文件无法打开！\n");
exit(0);
}
rewind(fp);
fscanf(fp, "%s", password);
jiemi(password);
fclose(fp);
}




int LengthBorrowreader(Borrowreader r)
{
int i = 0;
r = r->next;
while (r!=NULL)
{
i++;
r = r->next;
}
return i;
}




int LengthBorrowbook(Borrowbook b)
{
int i = 0;
b = b->next;
while (b)
{
i++;
b = b->next;
}
return i;
}




int LengthReader(reader_link H)
{
int i = 0;
H = H->next;
while (H)
{
i++;
H = H->next;
}
return i;
}




void FileBook(book_link H)
{
FILE *fp; //------------------------------------------------指向文件的指针
int number;//----------------------------------------------存储图书的数量
int number1;//---------------------------------------------存储当前图书有多少人借阅
Borrowreader r;//-------------------------------------------指向当前借阅图书节点
if ((fp = fopen("E:\\图书馆管理系统\\图书信息.txt", "w+")) == NULL)
{
printf("文件无法打开！\n");
exit(0);
}
number = NumberBook(H);
if (number == 0)
{
printf("图书书库为空，无法输入文件中：\n");
exit(0);
}
else
{
fprintf(fp, "%d\n", number);
H = H->next;
while (H)
{
fprintf(fp, "%s %s %s %d %d\n", H->data.BookNumber, H->data.BookName, H->data.Author, H->data.ResidualNumber, H->data.TotalNumber);
number1 = LengthBorrowreader(H->reader);
fprintf(fp, "%d\n", number1);
r = H->reader->next;
while (r)
{
fprintf(fp, "%s %s %s %s\n", r->data.ReaderName, r->data.ReaderNumber, r->data.ReaderPassword, r->data.sex);
r = r->next;
}
H = H->next;
}
}
fclose(fp);
}




book_link LoadBook()
{
FILE * fp;//-----------------------------------------指向文件的指针
int number;//---------------------------------------存储有多少图书的节点
int number1;//--------------------------------------存储有多少读者借阅这本书
book_link p = NULL;//-------------------------------------存储在文件中读取的信息
book_link q = NULL;//-----------------------------------------保存链表中的最后一个节点
book_link H = (book_link)malloc(sizeof(book_node)); //-------------------------------------保存图书信息的头节点
Borrowreader R = NULL;//-----------------------------保存借阅图书的读者
Borrowreader r = NULL;//------------------------------------------------------------------保存借阅图书的读者的最后一个节点
H->next = NULL;
if ((fp = fopen("E:\\图书馆管理系统\\图书信息.txt", "r")) == NULL)
{
return NULL;
}
rewind(fp);
fscanf(fp, "%d", &number);
for (int i = 0; i < number; i++)
{
p = (book_link)malloc(sizeof(book_node));
p->next = NULL;
p->reader = (Borrowreader)malloc(sizeof(borrowreader));
p->reader->next = NULL;
fscanf(fp, "%s %s %s %d %d", p->data.BookNumber, p->data.BookName, p->data.Author, &p->data.ResidualNumber, &p->data.TotalNumber);
fscanf(fp, "%d", &number1);
if (number1 != 0)
{
r = p->reader;
for (int j = 0; j < number1; j++)
{
R = (Borrowreader)malloc(sizeof(borrowreader));
R->next = NULL;
fscanf(fp, "%s %s %s %s", R->data.ReaderName, R->data.ReaderNumber, R->data.ReaderPassword, R->data.sex);
r->next = R;
r = R;
}
}
if (H->next == NULL)
{
H->next = p;
q = p;
}
else
{
q->next = p;
q = p;
}
}
fclose(fp);
return H;
}




void FileReader(reader_link H)
{


FILE *fp; //------------------------------------------------指向文件的指针
int number;//----------------------------------------------存储读者的数量
int number1;//---------------------------------------------存储当前读者借阅借阅多少图书
Borrowbook b;//-------------------------------------------指向当前借阅图书节点
if ((fp = fopen("E:\\图书馆管理系统\\读者信息.txt", "w+")) == NULL)
{
printf("文件无法打开！\n");
exit(0);
}
number = LengthReader(H);
if (number == 0)
{
printf("读者库为空，无法输入文件中：\n");
exit(0);
}
else
{
fprintf(fp, "%d\n", number);
H = H->next;
while (H)
{
jiami(H->data.ReaderPassword);
fprintf(fp, "%s %s %s %s %d\n", H->data.ReaderName, H->data.ReaderNumber, H->data.ReaderPassword, H->data.sex,H->BorrowNumber);
number1 = LengthBorrowbook(H->book);
fprintf(fp, "%d\n", number1);
b = H->book->next;
while (b)
{
fprintf(fp, "%s %s %s %d %d\n", b->data.BookName, b->data.BookNumber, b->data.Author, b->data.ResidualNumber, b->data.TotalNumber);
b = b->next;
}
H = H->next;
}
}
fclose(fp);
}


reader_link LoadReader()
{
FILE * fp;//-----------------------------------------指向文件的指针
int number;//---------------------------------------存储有读者的数量
int number1;//--------------------------------------存储有读者借阅了多少本书
reader_link p = NULL;//-----------------------------存储在文件中读取的信息
reader_link q = NULL;//-----------------------------保存链表中的最后一个节点
reader_link H = (reader_link)malloc(sizeof(reader_node)); //-------------------------------------保存读者信息的头节点
Borrowbook R = NULL;//-------------------------------保存读者借阅的图书
Borrowbook r = NULL;//--------------------------------保存借阅读者借阅图书的最后一个节点
H->next = NULL;
if ((fp = fopen("E:\\图书馆管理系统\\读者信息.txt", "r")) == NULL)
{
return NULL;
}
rewind(fp);
fscanf(fp, "%d", &number);
for (int i = 0; i < number; i++)
{
p = (reader_link)malloc(sizeof(reader_node));
p->next = NULL;
p->book = (Borrowbook)malloc(sizeof(borrowbook));
fscanf(fp, "%s %s %s %s %d", p->data.ReaderName, p->data.ReaderNumber, p->data.ReaderPassword, p->data.sex,&p->BorrowNumber);
jiemi(p->data.ReaderPassword);
fscanf(fp, "%d", &number1);
if (number1 != 0)
{
r = p->book;
for (int j = 0; j < number1; j++)
{
R = (Borrowbook)malloc(sizeof(borrowbook));
R->next = NULL;
fscanf(fp, "%s %s %s %d %d", R->data.BookName, R->data.BookNumber, R->data.Author, &R->data.ResidualNumber, &R->data.TotalNumber);
r->next = R;
r = R;
}
}
if (H->next == NULL)
{
H->next = p;
q = p;
}
else
{
q->next = p;
q = p;
}
}
fclose(fp);
return H;
}




void menu_root(reader_link *r,book_link *b)
{
char choice = -1;//-----------------------------------控制菜单循环变量
int choice1 = -1;//--------------------------------------控制菜单变量
while (choice1!=0)
{
printf("          **********************************************************\n");
printf("                               1    建立库存信息                    \n");
printf("                                                                    \n");
printf("                               2    增加图书信息                    \n");
printf("                                                                    \n");
printf("                               3    修改图书信息                    \n");
printf("                                                                    \n");
printf("                               4    删除图书信息                    \n");
printf("                                                                    \n");
printf("                               5    创建读者信息                    \n");
printf("                                                                    \n");
printf("                               6    删除读者信息                    \n");
printf("                                                                    \n");
printf("                               7    修改图书信息                    \n");
printf("                                                                    \n");
printf("                               8    修改管理员密码                  \n");
printf("                                                                    \n");
printf("                               0    返回上层目录                    \n");
printf("          **********************************************************\n");
printf("\n");
scanf_s("%c", &choice);
system("cls");
switch(choice)
{
case '1':
{
if (*b == NULL)
{
*b = BookCreate();
ShowBook(*b);
}
else
{
printf("书库已经建立，无需再次建库\n");
}
_getch();
break;
}
case '2':
{
AddBook(*b);
ShowBook(*b);
_getch();
break;
}
case '3':
{
ModifyBook(*b);
_getch();
break;
}
case '4':
{
DeleteBook(*b);
_getch();
break;
}
case '5':
{
if (*r == NULL)
{
*r = ReaderCreeate();
}
else
printf("读者库已经建立，无需重复建立！\n");
_getch();
break;
}
case '6':
{
DeleteReader(*r);
_getch();
break;
}
case '7':
{
ModifyReader(*r);
break;
}
case '8':
{
reader_link r=(reader_link)malloc(sizeof(reader_node));
ResetPassword(r);
FilePassword(r->data.ReaderPassword);
break;
}
case '0':
{
choice1 = 0;
break;
}
}
}
}




void menu_reader(reader_link *r, book_link *b,reader_link *reader_login)
{
char choice = -1;//-----------------------------------控制菜单循环变量
int choice1 = -1;//--------------------------------------控制菜单变量
Borrowbook book_guihuan;//----------------------------在读者信息中存储要借阅图书的链表结点
book_link book;//--------------------------------------储存要显示图书的编号
char number[30];//-----------------------------------------储存要显示读者的信息的图书号
Borrowreader reader;//-------------------------------------要显示的读者
while (choice1 != 0)
{
printf("          **********************************************************\n");
printf("                               1    借阅图书                        \n");
printf("                                                                    \n");
printf("                               2    归还图书                        \n");
printf("                                                                    \n");
printf("                               3    查询图书                        \n");
printf("                                                                    \n");
printf("                               4    修改密码                        \n");
printf("                                                                    \n");
printf("                               5    查看借阅图书信息                \n");
printf("                                                                    \n");
printf("                               0    返回上层目录                    \n");
printf("          **********************************************************\n");
scanf_s("%c", &choice);
system("cls");
switch(choice)
{
   case '1':
  {
  jieyue(*r, *b ,*reader_login);
  _getch();
  break;
   }
  case '2':
 {
 guihuan(*r, *b,*reader_login);
 _getch();
 break;
 }
  case '3':
  {
  QueryBook(*b);
  _getch();
  printf("输入书号，查看借阅读者(输入-1不查看)：\n");
  scanf_s("%s", number,30);
  if (strcmp(number, "-1"))
  {
  book = SearchBookY(*b, number);
  reader = book->reader->next;
  if (reader == NULL)
  printf("该书未被借阅！\n");
  else
  {
  printf("读者姓名            读者号           读者性别\n");
  while (reader)
  {
  printf("      %s                %s                 %s\n", reader->data.ReaderNumber, reader->data.ReaderName, reader->data.sex);
  reader = reader->next;
  }
  }
  }
  _getch();
  break;
  }
  case '4':
  {
  ResetPassword(*reader_login);
  printf("\n修改成功！\n");
  _getch();
  break;
  }
  case '5':
  {
  printf("                             您借阅的图书如下                        \n");
  book_guihuan = (*reader_login)->book->next;
  if (book_guihuan == NULL)
  printf("您没有借阅图书！\n");
  else
  {
  while (book_guihuan)
  {
  printf("  %s           %s           %s         \n", book_guihuan->data.BookNumber, book_guihuan->data.BookName, book_guihuan->data.Author);
  book_guihuan = book_guihuan->next;
  }
  }
  _getch();
  break;
  }
  case '0':
  {
  choice1 = 0;
  break;
  }
}


}
}




void main()
{
printf("          **********************************************************\n");
printf("          *                                                        *\n");
printf("          *                         欢迎使用                       *\n");
printf("          *                                                        *\n");
printf("          *                      图书管理系统                      *\n");
printf("          **********************************************************\n");
printf("\n\n");
_getch();
system("cls");
   reader_link r =NULL;//-----------------------------指向读者的头指针
book_link b = NULL;  //---------------------------------指向图书的头指针
char choice = -1;//-------------------------------控制循环变量
char password_root[100] = { '1','2','3'};
char password_reader[100];
char number_reader[100];//-------------------------保存登陆读者的读者号
reader_link reader_login;//------------------------保存要登陆读者的结点
LoadPassword(password_root);
b = LoadBook();
r = LoadReader();
while (choice != 0)
{
printf("          **********************************************************\n");
printf("          **********************************************************\n");
printf("                                    欢迎使用                        \n");
printf("                                                                    \n");
printf("                               1    管理员模式                      \n");
printf("                                                                    \n");
printf("                               2    读者模式                        \n");
printf("                                                                    \n");
printf("                               3    退出                            \n");
printf("          **********************************************************\n");
printf("          **********************************************************\n");
printf("\n\n");
printf("请输入选项：\n");
scanf_s("%c", &choice);
system("cls");
switch (choice)
{
case  '1':
{
printf("请输入密码，进入管理员模式;\n");
if (Password(password_root) == 1)
{
system("cls");
printf("          **********************************************************\n");
printf("                                欢迎使用管理员模式                  \n");
_getch();
menu_root(&r, &b);
}
else
{
system("cls");
printf("                       密码错误，无法进入管理员模式                 \n");
_getch();
system("cls");
}
break;
}
case  '2':
{
if ((reader_login=login(r, number_reader)))
{
system("cls");
printf("          **********************************************************\n");
printf("                                欢迎使用读者模式                    \n");
_getch();
menu_reader(&r, &b,&reader_login);
}
break;
}
case  '3':
{
FileBook(b);
printf("          **********************************************************\n");
printf("                            请输入管理员密码，退出系统              \n");
if (Password(password_root) == 1)
{
FileBook(b);
FileReader(r);
choice = 0;
printf("                        您已退出图书管理系统！                  \n");
}
else
{
printf("                         密码错误，无法退出！                  \n");
_getch();
system("cls");
}
break;
}
case '0':
{
choice = -1;
break;
}
}
}
} 



