/*************************************************************************
    > File Name: practicebyselfcallback.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月02日 星期日 21时16分51秒
 ************************************************************************/

#include<stdio.h>
#include<gtk/gtk.h>

//关闭窗口的回调函数
gint closewindow(GtkWidget *widget,gpointer gdata)
{
	g_print("close the window.\n");
	gtk_main_quit();
	return FALSE;
}

int main(int argc,char **argv)
{
	GtkWidget *window;
	char title[] = "test";
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//新建一个窗口
	gtk_window_set_title(GTK_WINDOW(window),title);
	g_signal_connect(GTK_OBJECT(window),"destory",G_CALLBACK(closewindow),NULL);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
