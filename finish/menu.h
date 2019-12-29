#ifndef menu_h
#define menu_h

#include "linklist.h"
#include "StuInformation.h"
#include "linklist.h"
#include "reader.h"
#include "map.h"
#include <stdio.h>
#include <unistd.h>

void menu(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void manager(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void user(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void manager1(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
//void hostname(linklist *head,reader *tip,linkstudent *headS,linklist *temporary)
void username(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void userregister(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void userfirst(linklist *head,linkstudent *headS,reader *tip,linklist *temporary);
void in(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
void students(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);

void hostname(linklist *head,reader *tip,linkstudent *headS,linklist *temporary);
#endif
