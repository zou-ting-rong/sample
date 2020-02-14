/*************************************************************************
    > File Name: toggle.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月03日 星期一 20时38分45秒
 ************************************************************************/

#include<stdio.h>
#include<gtk/gtk.h>

//按键的回调函数
void button_deal(GtkWidget *widget,gpointer *data)
{
	g_print("Button event:%s\n",data);
}

int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *button;
	char title[] = "test";
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
	gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	button = gtk_check_button_new_with_label("button");
	gtk_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(button_deal),"pressed");
	gtk_signal_connect(GTK_OBJECT(button),"released",GTK_SIGNAL_FUNC(button_deal),"released");
	gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(button_deal),"clicked");
	gtk_signal_connect(GTK_OBJECT(button),"enter",GTK_SIGNAL_FUNC(button_deal),"enter");
	gtk_signal_connect(GTK_OBJECT(button),"leave",GTK_SIGNAL_FUNC(button_deal),"leave");
	gtk_signal_connect(GTK_OBJECT(button),"toggle",GTK_SIGNAL_FUNC(button_deal),"toggle");
	gtk_container_add(GTK_CONTAINER(window),button);
	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
