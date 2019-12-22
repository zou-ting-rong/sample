#include"map.h"
void graph(){
	int i,j;
    int start,end;
    int edgeData[MaxVerNum][MaxVerNum];
      //int P[MaxVerNum];
     //int D[MaxVerNum];
    VertexType data[MaxVerNum];
    int path[MaxVerNum][MaxVerNum];
    int dist[MaxVerNum][MaxVerNum];
 
    MGraph *graph = (MGraph *)malloc(sizeof(MGraph));
    initEdge(edgeData);
    initVnum(data);
    CreateMGraph(graph,data,edgeData);
    printf("请选择起始地址\n");
    start = SelectAddress();
    printf("请选择目的地\n");
    end = SelectAddress();
	floyd(graph,path,dist,start,end); 
    return ;
} 
void CreateMGraph(MGraph *G,VertexType *data,int edgeData[MaxVerNum][MaxVerNum]){
	int i,j,k,w;
	G->vnum =  19;
	G->enumw = 22;
	for (i = 0; i < G->vnum; ++i){
		G->vexs[i] = data[i];
	}
	for (i = 0; i < G->vnum; ++i){
		for (j = 0; j < G->vnum; ++j){
			G->edges[i][j] = edgeData[i][j];
		}
	}
	return;
}
void initVnum(VertexType *data){
	strcpy(data[0].address,"借书处");
	strcpy(data[1].address,"出口");
	strcpy(data[2].address,"理工借阅室207");
	strcpy(data[3].address,"一楼自习室");
	strcpy(data[4].address,"二楼自习室");
	strcpy(data[5].address,"图书馆办公室");
	strcpy(data[6].address,"三楼自习室");
	strcpy(data[7].address,"四楼自习室");
	strcpy(data[8].address,"理工借阅室208");
	strcpy(data[9].address,"图书馆咨询处");
	//strcpy(data[10].address,"竞知楼");
	//strcpy(data[11].address,"主图书馆");
	//strcpy(data[12].address,"教工宿舍");
	//strcpy(data[13].address,"南门");
	//strcpy(data[14].address,"11栋");
	//strcpy(data[15].address,"15栋");
	//strcpy(data[16].address,"五食堂");
	//strcpy(data[17].address,"西门");
	//strcpy(data[18].address,"莲池");

	return ;
}

void initEdge(int edgeData[MaxVerNum][MaxVerNum]){
	
	for (int i = 0; i < 19; ++i){
		for (int j = 0; j < 19; ++j){
			edgeData[i][j] = INFINITY;
		}
	}
	edgeData[0][1] = edgeData[1][0] = 10;
	edgeData[1][2] = edgeData[2][1] = 60;
	edgeData[1][5] = edgeData[5][1] = 20;
	edgeData[1][9] = edgeData[9][1] = 15;
	//edgeData[2][14] = edgeData[14][2] = 273;
	//edgeData[2][15] = edgeData[15][2] = 224;
	//edgeData[2][16] = edgeData[16][2] = 115;
	edgeData[3][1] = edgeData[1][3] = 30;
	edgeData[2][5] = edgeData[5][2] = 60;
	edgeData[2][8] = edgeData[2][8] = 10;
	edgeData[2][4] = edgeData[4][2] = 20;
	edgeData[3][4] = edgeData[4][3] = 70;
	edgeData[4][6] = edgeData[6][4] = 80;
	edgeData[6][7] = edgeData[7][6] = 80;
	//edgeData[10][9] = edgeData[9][10] = 430;
	//edgeData[11][10] = edgeData[10][11] = 100;
	//edgeData[12][11] = edgeData[11][12] = 236;
	//edgeData[13][12] = edgeData[12][13] = 437;
	//edgeData[14][10] = edgeData[10][14] = 210;
	//edgeData[15][14] = edgeData[14][15] = 167;
	//edgeData[16][15] = edgeData[15][16] = 215;
	//edgeData[17][15] = edgeData[15][17] = 630;
	//edgeData[18][17] = edgeData[17][18] = 410;

	return;
}
void floyd(MGraph *G,int path[][MaxVerNum],int dist[][MaxVerNum],int start,int end){
	int i,j,k;
	int tmp;
	for (i = 0; i < G->vnum; ++i){
		for (j = 0; j < G->vnum; ++j){
			dist[i][j] = G->edges[i][j];
			path[i][j] = j;
		}
	}
	for (k = 0; k < G->vnum; ++k){
		for (i = 0; i < G->vnum; ++i){
			for (j = 0; j < G->vnum; ++j){
				tmp = (dist[i][k] == INFINITY || dist[k][j] == INFINITY)?INFINITY:(dist[i][k] + dist[k][j]);
				if (dist[i][j] > tmp){
					dist[i][j] = tmp;
					path[i][j] = k;
				}
			}
		}
	}
	for (i = 0; i < G->vnum; ++i){
		if(i != start) continue;
		for (j = 0; j < G->vnum; ++j){
			if (j != end) continue;
				printf("%s  到  %s 的最短路径长度为: %d\n",G->vexs[i].address,G->vexs[j].address,dist[i][j] );
				printf("路径为: %s",G->vexs[j].address);
				if (path[i][j] == j)
					printf("<<%s",G->vexs[i].address );
				else{
					k = j;
					while(path[i][k] != k){
						k = path[i][k];
						printf("<<%s",G->vexs[k].address );
					}
					printf("<<%s",G->vexs[i].address );
				}
				printf("\n");
			
		}		
	}
}


void ShortestPath(MGraph *G, int P[MaxVerNum], int D[MaxVerNum], VertexType *data,int vertex){
	int i,j,k,pre,min;
	int final[MaxVerNum] = {0};
	final[vertex] = 1;
	for (i = 0; i < G->vnum; ++i){
		D[i] = G->edges[vertex][i];
		P[i] = 0;
	}
	D[vertex] = 0;
	final[vertex] = 1;
	P[vertex] = -1;
	for (i = 1; i < G->vnum; ++i){
		min = INFINITY + 1;
		for (k = 0; k < G->vnum; ++k){
			if (final[k] == 0 && D[k]< min){
				j = k;
				min = D[k];
			}
		}
		final[j] = 1;
		for (k = 0; k < G->vnum; ++k){
			if (final[k] == 0 && (D[j] + G->edges[j][k] < D[k])){
				D[k] = D[j] + G->edges[j][k];
				P[k] = j;
			}
		}
	}
	for (i = 1; i < G->vnum; ++i){
		if(D[i] < 10000)
		printf("路程为:%d: \n",D[i] );
		printf("路径为:%s\n", data[i].address);
		pre = P[i];
		while(pre >= vertex || pre == vertex){
			printf(" <<%s",data[pre].address );
			pre = P[pre];
		}
		printf("\n");
	}
	return;
		
}
int SelectAddress(){
	int flat;
	int vertex;
	printf("1.借书处\n");
	printf("2.出口\n");
	printf("3.理工借阅室207\n");
	printf("4.一楼自习室\n");
	printf("5.二楼自习室\n");
	printf("6.图书馆办公室\n");
	printf("7.三楼自习室\n");
	printf("8.四楼办公室\n");
	printf("9.理工借阅室208\n");
	/*printf("10.体育训练馆\n");
	/printf("11.竞知楼\n");
	printf("12.主图书馆\n");
	printf("13.教工宿舍\n");
	printf("14.南门\n");
	printf("15.11栋\n");
	printf("16.15栋\n");
	printf("17.五食堂\n");
	printf("18.西门\n");
	printf("19.莲池\n");*/
	scanf("%d",&flat);
	switch(flat){
		case 1:	vertex = 0;
					break;
		case 2:	vertex = 1;
					break;
		case 3:	vertex = 2;
					break;
		case 4:	vertex = 3;
					break;
		case 5:	vertex = 4;
					break;
		case 6:	vertex = 5;
					break;
		case 7:	vertex = 6;
					break;
		case 8:	vertex = 7;
					break;
		case 9:	vertex = 8;
					break;
		case 10:	vertex = 9;
					break;
		case 11:	vertex = 10;
					break;
		case 12:	vertex = 11;
					break;
		case 13:	vertex = 12;
					break;
		case 14:	vertex = 13;
					break;
		case 15:	vertex = 14;
					break;
		case 16:	vertex = 15;
					break;
		case 17:	vertex = 16;
					break;
		case 18:	vertex = 17;
					break;
		case 19:	vertex = 18;
					break;
		

	}
	return vertex;
}
