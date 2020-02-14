/*************************************************************************
    > File Name: enter.c
    > Author: 邹庭荣
    > Mail: 1198875194@qq.com 
    > Created Time: 2020年02月14日 星期五 20时45分49秒
 ************************************************************************/

#include<stdio.h>
#include<gtk/gtk.h>

GtkWidget *name;
GtkWidget *passwd;
//处理按键的回调函数
void button_deal(GtkWidget *widget,gpointer *data)
{
	const gchar *uname;
	const gchar *upasswd;
	uname = (gchar *)malloc(sizeof(gchar));
	upasswd = (gchar *)malloc(sizeof(gchar));
	uname = gtk_entry_get_text(GTK_ENTRY(name));
	upasswd = gtk_entry_get_text(GTK_ENTRY(passwd));//获取键盘输入
	g_print("%s\n",uname);
	g_print("%s\n",upasswd);
}

int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box;
	GtkWidget *label;

	char title[] = "test";
	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),title);
	gtk_widget_set_usize(GTK_WINDOW(window),300,300);
	gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	box = gtk_vbox_new(FALSE,0);
	
	label = gtk_label_new("name:");
	gtk_box_pack_start(box,label,FALSE,FALSE,5);
	gtk_widget_show(label);

	name = gtk_entry_new();//创建输入构件
	gtk_entry_set_visibility(GTK_ENTRY(name),TRUE);
	gtk_box_pack_start(box,name,FALSE,FALSE,5);
	gtk_widget_show(name);

	label = gtk_label_new("passwd:");
	gtk_box_pack_start(box,label,FALSE,FALSE,5);
	gtk_widget_show(label);

	passwd = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(passwd),FALSE);//设置为不可见
	gtk_box_pack_start(box,passwd,FALSE,FALSE,5);
	gtk_widget_show(passwd);

	button = gtk_button_new_with_label("ENTRY");
	gtk_box_pack_start(box,button,FALSE,FALSE,5);
	gtk_signal_connect(GTK_OBJECT(button),"pressed",GTK_SIGNAL_FUNC(button_deal),"entry");//声明按钮的回调函数
	gtk_widget_show(button);

	gtk_container_add(GTK_CONTAINER(window),box);
	gtk_widget_show(box);
	gtk_widget_show(window);
	gtk_main();
	return 0;
} 
