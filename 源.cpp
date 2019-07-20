#include <stdio.h>
#include <string.h>
#define MAXWEIGHT 999      //最大可能边权值(表示顶点间无边连接)
#define MAX_VERTEX_NUM 20 //图的最大可能顶点个数
typedef int VRType;       //边权值的类型(整数)
typedef char VertexType[5];  //顶点数据的类型(字符串，最大长度4)
//邻接阵类型
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];  //顶点数组
	AdjMatrix  arcs;                      //邻接矩阵
	int        vexnum,                   //顶点个数
		arcnum;                   //边条数
}MGraph; //图类型
//以下为邻接阵表示的图的基本操作函数
//显示图的邻接矩阵
void Display(MGraph *G) {
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++)
			if (G->arcs[i][j] == MAXWEIGHT)
				printf("%5s", "∞"); //用∞表示无边连接
			else
				printf("%5d", G->arcs[i][j]);
		printf("\n");
	}
}
//判断两个顶点是否相同
int equal(VertexType v1, VertexType v2) {
	return strcmp(v1, v2) == 0;
}
//查找顶点在顶点数组中的下标
int locate(MGraph *G, VertexType v) {
	for (int i = 0; i<G->vexnum; i++)
		if (equal(G->vexs[i], v)) return i;
	return -1;
}
//创建有向网（带权有向图）
void CreateGraph(MGraph *G) {
	VertexType v1, v2;
	VRType weight;
	int i, j, k;
	//printf("输入顶点数：");
	scanf("%d", &G->vexnum);
	printf("输入边数：");
	scanf("%d", &G->arcnum);
	//创建顶点数组
	printf("逐行输入%d个顶点的信息：\n", G->vexnum);
	for (i = 0; i<G->vexnum; i++) {
		scanf("%s", G->vexs[i]);
	}
	//初始化邻接阵
	for (i = 0; i<G->vexnum; i++)
		for (j = 0; j<G->vexnum; j++) {
		G->arcs[i][j] = MAXWEIGHT;//G->arcs[i][j].adj=0;
		//G->arcs[i][j].info=NULL;
		}
	for (i = 0; i<G->vexnum; i++) G->arcs[i][i] = 0;//不允许顶点有指向自身的循环边
	//接受邻接阵数据
	printf("逐行输入弧的起点、终点符号及边权值\n");
	for (k = 0; k<G->arcnum; k++) {
		//输入顶点编号、边权值
		scanf("%s%s%d", v1, v2, &weight);
		//顶点对应数组元素下标
		i = locate(G, v1);
		j = locate(G, v2);
		G->arcs[i][j] = weight;//G->arcs[i][j].adj=weight;
		//G->arcs[j][i] =G->arcs[i][j];
	}
}
int visited[MAX_VERTEX_NUM]; //顶点访问标志数组
//递归深度优先遍历
void DFS(MGraph *G, int i) {
	int n = G->vexnum;
	printf("%5s", G->vexs[i]);  //访问顶点 i
	visited[i] = 1;      //设置顶点 i 的访问标志
	for (int j = 0; j<n; j++)  //扫描第 i 行，寻找 i 的邻接顶点
		if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAXWEIGHT && !visited[j])
			DFS(G, j);   //递归访问 i 的邻接顶点 j
}
//深度优先遍历主程序
void DFSTraverse(MGraph *G) { //对图 g 进行深度优先遍历
	int n = G->vexnum;
	int i;
	for (int i = 0; i<n; i++) visited[i] = 0; //初始化顶点访问标志

	for (i = 0; i<n; i++)
		if (visited[i] == 0) DFS(G, i);
}
void main(void) {
	MGraph g, *gt;
	gt = &g; //获取指向图类型的指针
	CreateGraph(gt); //接受输入，创建有向网
	Display(gt);  //显示图的邻接阵
	DFSTraverse(gt);//深度优先遍历
}
