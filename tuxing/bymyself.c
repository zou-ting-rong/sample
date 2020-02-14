/*************************************************************************
    > File Name: bymyself.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月06日 星期四 21时13分51秒
 ************************************************************************/

#include<stdio.h>
#include<gtk/gtk.h>

int main(int argc,char **argv)
{
	GtkWidget *window;
	char title[] = "ztr";
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
	gtk_widget_set_usize(GTK_WINDOW(window),300,150);
	gtk_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
