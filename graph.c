 #define INFINITY      10000       //图的矩阵中A（i，i）记为0，若没有通路，记为INFINITY = 10000
#define MAX_VERTEX_NUM     40   //最大景点数定为40
#define MAX 40
#include<stdlib.h>  //包含system等系统调用
#include<stdio.h>
#include<string.h>  //在使用到字符数组时需要使用
/*****************************************
*功能描述：输出系统菜单主页面
*输入参数：无
*输出参数：无
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
void Menu()  //输出菜单主页的函数
{
 printf("\n                                欢   迎   来   到  烟台大学  \n"     );
 printf("                        ··~~~~~~~~~~~~~····~~~~~~~~~~~~~~~~\n");
 printf("                       。。    1.浏览 校园 景色             。。\n");
 printf("                         。。  2.寻找景点之间最佳路径           。。\n");
 printf("                        。。   3.查找 景点的 浏览路线            。。\n");
 printf("                       。。    4.查询  景点  简介             。。\n");
 printf("                      。。     5.删除一个景点及路径          。。\n");
 printf("                        。。   6.修改 景点 信息               。。\n");
 printf("                        。。   7.退出                       。。\n");
 printf("                         ··~~~~~~~~~~~~~····~~~~~~~~~~~~~~~~\n");
 printf("                      亲  动动你的手指，我想知道你的想法 (1-6菜单选项):    ");
 
}
/*****************************************
*功能描述：输出校园导游路线图
*输入参数：无
*输出参数：无
*返回值： 输出路线图
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
void  xs()
{
 printf("                                                                \n");
 printf("                         **-1.图书馆-** ********                      \n");
 printf("                      **               **      ****                    \n");
 printf("                   **                    **       ***                           \n");
 printf("                 **                        **        ****                   \n");
 printf("               **                            **         *******                        \n");
 printf("             **                                 **           ***                     \n");
 printf("         0.三元湖************ 2.钟楼************** 4八景园     **                    \n");
 printf("           **                      **                  **       **                \n");
 printf("            **                       **                 **       **                \n");
 printf("             **                       **                **        **              \n");
 printf("             **                         **               **        **              \n");
 printf("              **                          **              **        ***  6.东门          \n");
 printf("               **                           **            **         ***      **    \n");
 printf("                 **                            **         **       **         **     \n");
 printf("                  **                              **     **       **          **     \n");
 printf("                    ******* 3.小树林*************5.青春广场**** **           **       \n");
 printf("                                 **                                         **        \n");
  printf("                                 **                                       ***          \n");
   printf("                                 ** ***************************************            \n");
   printf("                                                                \n");
   printf("                                                                \n");
}
/*****************************************
*功能描述：控制从键盘输入按钮的函数
*输入参数：数字
*输出参数：路径图  各个函数模块调用
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
 
void cmd(void)  //控制从键盘输入按钮的函数
{
 int i;
 MGraph b;
 b=InitGraph(); //对导游图b用函数InitGraph()进行初始化，变成烟台大学的导游图~
 Menu();
 
 scanf("%d",&i);
 while(i!=8)
 {
 switch(i)
  {
  case 1:system("cls");xs();Menu();break; //先进行一个清屏操作"cls"
  case 2:system("cls");xs();Floyd(&b);Menu();break;
  case 3:system("cls");xs();ShortPath_DIJ(&b);Menu();break;
  case 4:system("cls");xs();Search(&b);Menu();break;
  case 5:system("cls");xs();dele(&b);Menu();break;
  case 6:system("cls");xs();change(&b);Menu();break;
  case 7:exit(1);break;
  default:break;
  }
 
 scanf("%d",&i);
 }
}
 
/*****************************************
*功能描述：创建图
*输入参数：对图进行初始化
*输出参数：输出地图基本信息
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
MGraph InitGraph(void)  //对图初始化，变成烟台大学的地图~
{
 MGraph G;
 int i,j;
 G.vexnum=7;
 G.arcnum=10;
 for(i=0;i<G.vexnum;i++)
  G.vexs[i].num=i;
 strcpy(G.vexs[0].name,"三元湖");
 strcpy(G.vexs[0].introduction,"在这里可以欣赏三元湖，晨读理想之地，也适合恋爱之地");
 strcpy(G.vexs[1].name,"图书馆");
 strcpy(G.vexs[1].introduction,"这里藏书百万册,设施良好，环境幽雅，适合潜心读书");
 strcpy(G.vexs[2].name,"钟楼");
 strcpy(G.vexs[2].introduction,"烟台大学地标建筑，也是最高的建筑");
 strcpy(G.vexs[3].name,"小树林");
 strcpy(G.vexs[3].introduction,"这里很适合散步 恋爱，你懂得");
 strcpy(G.vexs[4].name,"八景园");
 strcpy(G.vexs[4].introduction,"学生可以读书散步，是一个鸟语花香，绿树成荫的地方");
 strcpy(G.vexs[5].name,"青春广场");
 strcpy(G.vexs[5].introduction,"这里可以举办户外的大型歌舞晚会");
 strcpy(G.vexs[6].name,"东门");
 strcpy(G.vexs[6].introduction,"靠近海最近的门");
 for(i=0;i<G.vexnum;i++)
     for(j=0;j<G.vexnum;j++)
     {
         G.arcs[i][j].adj=INFINITY;
         G.arcs[0][1].adj=80;
         G.arcs[1][0].adj=80;
 
 
         G.arcs[1][4].adj=180;
         G.arcs[4][1].adj=180;
         G.arcs[4][5].adj=300;
         G.arcs[5][4].adj=300;
 
 
         G.arcs[0][2].adj=100;
         G.arcs[2][0].adj=100;
         G.arcs[0][3].adj=120;
         G.arcs[3][0].adj=120;
 
 
         G.arcs[1][6].adj=500;
         G.arcs[6][1].adj=500;
         G.arcs[2][4].adj=150;
         G.arcs[4][2].adj=150;
 
         G.arcs[3][5].adj=250;
         G.arcs[5][3].adj=250;
         G.arcs[2][5].adj=350;
         G.arcs[5][2].adj=350;
 
 
         G.arcs[3][6].adj=320;
         G.arcs[6][3].adj=320;
         G.arcs[6][5].adj=130;
         G.arcs[5][6].adj=130;
 
     }
 
     return G;
}
 
 
/*****************************************
*功能描述：查看某个景点的相关信息
*输入参数：数字4 
*输出参数： 景点的相关内容
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
 
void Search(MGraph *G)//查看某个景点的相关信息
{
 int k,flag=1;
 while(flag)
 {
  printf("请输入要查询的景点编号:");
  scanf("%d",&k);
  if(k<0||k>G->vexnum)
  {
     printf("景点编号不存在!请重新输入景点编号:");
     scanf("%d",&k);
  }
  if(k>=0&&k<G->vexnum)
   flag=0;  //跳出while结构,执行下面的输出
 }
 printf("***********************************************************************************\n");
 printf("* 编号 * 景点名称        * 简介                                                   *  \n");
 printf("* %-4d * %-16s*%-56s* \n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction);
 printf("***********************************************************************************\n");
 
}
 
 
/*****************************************
*功能描述：删除某景点相关内容
*输入参数：数字5
*输出参数：删除该景点  输出  正在建设中
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
 
void dele(MGraph *G)//删除某景点
{
 
    int k,flag=1;
 while(flag)
 {
  printf("请输入要删除的景点编号:");
  scanf("%d",&k);
  if(k<0||k>G->vexnum)
  {
     printf("景点编号不存在!请重新输入景点编号:");
     scanf("%d",&k);
  }
  if(k>=0&&k<G->vexnum)
   flag=0;
 }
 
strcpy(G->vexs[k].name,"此处正在建设中**");
strcpy(G->vexs[k].introduction,"无");
 
printf("删除成功！");
 
 
}
 
 
/*****************************************
*功能描述：修改完善某景点的基本信息
*输入参数：数字 6
*输出参数：  修改完的信息
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
 
void change(MGraph *G)//修改完善某景点的基本信息
{
    char m[100];
 int k,flag=1;
 while(flag)
 {
  printf("请输入要修改的景点编号:");
  scanf("%d",&k);
  if(k<0||k>G->vexnum)
  {
     printf("景点编号不存在!请重新输入景点编号:");
     scanf("%d",&k);
  }
  if(k>=0&&k<G->vexnum)
   flag=0;
 
}
       printf("请输入该景点要修改的信息内容：");
       scanf("%s",m);
       strcpy(G->vexs[k].introduction,m);
       printf("修改成功！");
 
 
}
 
 
/*****************************************
*功能描述：计算出一个景点到其他景点的最短路线
*输入参数：两个景点的编号
*输出参数：输出最近路线  以及路线长度
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
 
void ShortPath_DIJ(MGraph * G)// 用狄克斯特拉算法计算出从一个景点到其他景点之间的最短路径(v0为起点)
{
    int v;//v为其他的顶点
    int v0;//vo为起点
    int w;//循环用，并且正好对应满足条件时顶点的编号
    int i;//循环用
    int min;//在求final外顶点的最短路径的循环结构时用来记录下最短路径
    int t=0;//最后输出路径时用到的参数
    int x;//循环用，并且正好对应满足条件时顶点的编号
    int flag;//一开始判断景点是否存在时用的参数
    int final[20];  //final为已求出顶点路径的集合
    int D[20];  //D数组用来存放从源点v0到v的目前最短路径长度
    int p[20][20]; //有路径时为1，没有路径时为0
 
 
 
 while(flag)  //判断该景点是否存在
 {
  printf("请输入一个起始景点编号:");
  scanf("%d",&v0);
  if(v0<0 || v0>G->vexnum)
  {
     printf("景点编号不存在!请重新输入景点编号:");
     scanf("%d",&v0);
  }
  if(v0>=0 && v0<G->vexnum)
  flag=0;  //flag=0时不再进行while循环，继续进行下面的操作
 }
 
 
 
 
 for(v=0;v<G->vexnum;v++)  //
 {
      final[v]=0;  //final[]置空
      D[v]=G->arcs[v0][v].adj;  //距离初始化
      for(w=0;w<G->vexnum;w++)
      {
          p[v][w]=0;
      }
      if(D[v]<INFINITY)  //当v到源点v0有路径的时候，这时除了可以直接到v0的顶点外其他顶点都不能与v0连通
      {
          p[v][v0]=1;
          p[v][v]=1;
      }
 }
 
 
 
 D[v0]=0;//源点到自己的距离为零
 final[v0]=1;  //源点编号v0放入final中
 
 
 
 for(i=1;i<G->vexnum;i++) //循环直到所有顶点距离源点的最短路径都求出
 {
      min=INFINITY;  //min置最小长度初值
  for(w=0;w<G->vexnum;w++) //选取不在final中且具有最小距离的顶点u
      if(!final[w])  //选取不在final中的顶点u
       if(D[w]<min)//选取具有最小距离的顶点u
       {
           v=w;
           min=D[w];
       }
        final[v]=1;  //顶点u加入final中
 
 
 
     for(w=0;w<G->vexnum;w++)  //修改不在final中的顶点的距离
       if(!final[w] && (min+G->arcs[v][w].adj<D[w]))//根据上面的代码可知min这时代表刚刚添加到final中的顶点v到源点v0的距离，如果这个距离加上v到w的距离小于之前w到源点vo的距离……
       {                                            //arcs[v][w]代表两顶点v,w之间的距离
        D[w]=min+G->arcs[v][w].adj;  //进行修改，修改成更短的距离
        for(x=0;x<G->vexnum;x++)
        {
          p[w][x]=p[v][x];//因为w连通v,所以w可以通过v与其他所有与v连通的顶点连通
        }
        p[w][w]=1;//w自己连通自己
       }
 
 }
 
 
 
 for(v=0;v<G->vexnum;v++)  //输出最短路径
 {
  if(v0!=v)
      printf("%s",G->vexs[v0].name); //先输出源点v0的名字
  for(w=0;w<G->vexnum;w++)
  {
   if(p[v][w]&&w!=v0) //如果v到w连通且w!v0
       printf("-->%s",G->vexs[w].name); //输出顶点w的名字
   t++;
  }
  if(t>G->vexnum-1 && v0!=v)
      printf(" 总路线长%dm\n\n",D[v]); //输出v到源点vo的路径长度
 }
 
}
/*****************************************
*功能描述：计算出任意两个景点的最短路线
*输入参数：一个起始景点
*输出参数：输出一个景点到其他景点的路线
*返回值：无
*其他说明：消息字段之间用分号（；）分隔
*****************************************/
void Floyd(MGraph *G)//佛洛依德算法计算任意两点的最短路径
{
 int v,u,i,w,k,j,flag=1,p[10][10][10],D[10][10];
 for(v=0;v<G->vexnum;v++)
  for(w=0;w<G->vexnum;w++)
  {
   D[v][w]=G->arcs[v][w].adj;
   for(u=0;u<G->vexnum;u++)
    p[v][w][u]=0;
   if(D[v][w]<INFINITY)
   {
    p[v][w][v]=1;p[v][w][w]=1;
   }
  }
 for(u=0;u<G->vexnum;u++)//中转点
  for(v=0;v<G->vexnum;v++)//源点
   for(w=0;w<G->vexnum;w++)//终点
    if(D[v][u]+D[u][w]<D[v][w])//不满足三角不等式就更新距离
    {
     D[v][w]=D[v][u]+D[u][w];
     for(i=0;i<G->vexnum;i++)
      p[v][w][i]=p[v][u][i]||p[u][w][i];
    }
 
 while(flag)
 {
  printf("请输入出发点和目的地的编号:");
  scanf("%d%d",&k,&j);
  if(k<0||k>G->vexnum||j<0||j>G->vexnum)//判断输入是否合法
  {
  printf("景点编号不存在!请重新输入出发点和目的地的编号:");
     scanf("%d%d",&k,&j);
  }
  if(k>=0&&k<G->vexnum&&j>=0&&j<G->vexnum)
   flag=0;
 }
 printf("%s",G->vexs[k].name);
 for(u=0;u<G->vexnum;u++)
  if(p[k][j][u]&&k!=u&&j!=u)
   printf(" *** %s",G->vexs[u].name);//输出到某个点的最短路径
 printf(" *** %s",G->vexs[j].name);
 printf(" 总路线长%dm\n",D[k][j]);
}//Floyd 结束

