/*************************************************************************
    > File Name: practice.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月01日 星期六 21时12分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

int main(int argc,char **argv)
{
	GtkWidget *window;
	char title[] = "test";
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
	gtk_widget_show(window);
	gtk_main();
	return 0;

}
