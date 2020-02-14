/*************************************************************************
    > File Name: onlyselect.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月06日 星期四 20时27分45秒
 ************************************************************************/

#include<stdio.h>
#include<gtk/gtk.h>

int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box;
	GSList *group = NULL;//一个用来存放单选框的组
	char title[] = "test";
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
	gtk_widget_set_usize(GTK_WINDOW(window),300,150);
	gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	box = gtk_hbox_new(FALSE,0);//创建一个新的组合盒
	
	button = gtk_button_new_with_label("button1");
	gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,0);
	gtk_widget_show(button);
	
	
	button = gtk_button_new_with_label("button2");
	gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,0);
	gtk_widget_show(button);
	

	button = gtk_button_new_with_label("button3");
	gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,0);
	gtk_widget_show(button);


	button = gtk_button_new_with_label("button4");
	gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,0);
	gtk_widget_show(button);

	gtk_container_add(GTK_CONTAINER(window),box);
	gtk_widget_show(window);
	gtk_widget_show(box);
	gtk_main();
	return 0;
}
