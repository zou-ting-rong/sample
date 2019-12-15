#include "linklist.c"
#include "reader.c"
#include "menu.c"
int main(int argc,char **argv)
{	
	linklist *head;
	head = (linklist *)malloc(sizeof(linklist));
	reader *tip;
	tip = (reader *)malloc(sizeof(reader));
	tip = Initreader();
	head = Init();
	menu(head,tip);
	return 0;
}
