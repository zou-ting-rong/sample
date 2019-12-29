#include "linklist.h"
#include "reader.h"
#include "menu.h"
#include "StuInformation.h"
#include "map.h"
int main(int argc,char **argv)
{
	linklist *head;
	head = (linklist *)malloc(sizeof(linklist));
	reader *tip;
	tip = (reader *)malloc(sizeof(reader));
	linkstudent *headS;
	headS = (linkstudent *)malloc(sizeof(linkstudent));
	tip = Initreader();
	head = Init();
	headS = InitS();
	linklist *temporary;
	temporary = (linklist *)malloc(sizeof(linklist));
	//linklist *q;
	//q = (linklsit *)malloc(sizeof(linklist));*/
	menu(head,tip,headS,temporary);
	return 0;
}
