//
//  main.c
//  图邻接表

#include <stdio.h>
#include <stdlib.h>

#define M 10
#define true 1
#define false 0

////////////
typedef int Elemtype;
typedef struct QNode {
	Elemtype data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct {
	QueuePrt front, rear;
}LinkQueue;
//初始化
void initQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}
//插入一个节点
void InsertQueue(LinkQueue *q, Elemtype e) {
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (p == NULL)
		exit(0);
	p->data = e;
	p->next = NULL;

	//插进去
	q->rear->next = p;
	q->rear = p;
}
//出队列
void DeleteQueue(LinkQueue *q, Elemtype *e) {
	QueuePrt p;
	if (q->front == q->rear) {
		return;
	}

	p = q->front->next;
	*e = p->data;

	q->front->next = p->next;
	if (q->rear == p)
		q->rear = q->front;
	free(p);
}
//销毁一个队列
void DestroyQueue(LinkQueue *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}
//队列是否为空
int isEmpty(LinkQueue* a)
{
	if (a->front == a->rear)
		return 1;
	return 0;
}

////////////
typedef char Element;
typedef int BOOL;
//邻接表的节点
typedef struct Node {
	int adj_vex_index;  //弧头的下标，也就是被指向的下标
	Element data;       //节点值
	struct Node * next; //边指针
}EdgeNode;

//顶点节点表
typedef struct vNode {
	Element date;          //顶点的权值
	EdgeNode * firstedge;  //顶点下一个是谁？
}VertexNode, Adjlist[M];

//总图的一些信息
typedef struct Graph {
	Adjlist adjlist;       //顶点表
	int arc_num;           //边的个数
	int node_num;          //节点个数
	BOOL is_directed;      //是不是有向图
}Graph, *GraphLink;

void creatGraph(GraphLink *g) {
	int i, j, k;
	EdgeNode *p;

	printf("输入顶点数目,边数和有向？：\n");
	scanf("%d %d %d", &(*g)->node_num, &(*g)->arc_num, &(*g)->is_directed);

	//安排一下顶点数组，有几个走几个，安排的明明白白
	printf("输入顶点信息：\n");
	for (i = 0; i < (*g)->node_num; i++) {
		getchar();
		scanf("%c", &(*g)->adjlist[i].date);
		(*g)->adjlist[i].firstedge = NULL;
	}
	printf("输入边信息：\n");
	//再安排边，知道边的两端是谁就好了
	for (k = 0; k < (*g)->arc_num; k++) {
		//第一个输入的是弧尾下标，第二个是弧头下标
		// i ----> j
		getchar();
		scanf("%d %d", &i, &j);

		//新建一个节点是必须的
		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		//弧头的下标
		p->adj_vex_index = j;
		//头插法插进去，插的时候要找到弧尾，那就是顶点数组的下标i
		p->next = (*g)->adjlist[i].firstedge;
		(*g)->adjlist[i].firstedge = p;

		//如果无向
		if (!(*g)->is_directed)
		{
			// j -----> i
			p = (EdgeNode *)malloc(sizeof(EdgeNode));
			p->adj_vex_index = i;
			p->next = (*g)->adjlist[j].firstedge;
			(*g)->adjlist[j].firstedge = p;
		}

	}
}

void putGragh(GraphLink g) {
	int i;
	//遍历一遍顶点坐标，每个再进去走一次
	for (i = 0; i < g->node_num; i++) {
		EdgeNode * p = g->adjlist[i].firstedge;
		while (p) {
			printf("%c->%c ", g->adjlist[i].date, g->adjlist[p->adj_vex_index].date);
			p = p->next;
		}
		printf("\n");
	}
}

int visited[M];
//深度遍历
void DFS(Graph *g, int i) {
	visited[i] = true;
	printf("%c ", g->adjlist[i].date);
	EdgeNode *p = g->adjlist[i].firstedge;
	while (p) {
		if (visited[p->adj_vex_index] == 0) {
			DFS(g, p->adj_vex_index);
		}
		p = p->next;
	}
}

void DFSTraverse(Graph *g)
{
	int i;
	for (i = 0; i < g->node_num; i++)
	{
		if (!visited[i])
			DFS(g, i);
	}
}

//广度遍历
void BFSTraverse(Graph *g)
{
	int i;
	int tmp;
	EdgeNode *p;
	//初始化队列
	LinkQueue q;
	initQueue(&q);

	for (i = 0; i < g->node_num; i++) {
		if (!visited[i]) {
			visited[i] = true;
			printf("%c ", g->adjlist[i].date);

			//队列插进来一个节点
			InsertQueue(&q, i);
			//队列不是空的时候就从队列里面操作
			while (!isEmpty(&q)) {
				//从队列取一个就得把和他连着的点都填进去
				DeleteQueue(&q, &tmp);
				//添加和他连着的所有未点亮的点
				p = g->adjlist[tmp].firstedge;
				while (p) {
					if (!visited[p->adj_vex_index]) {
						visited[p->adj_vex_index] = true;
						printf("%c ", g->adjlist[p->adj_vex_index].date);
						InsertQueue(&q, p->adj_vex_index);
					}
					p = p->next;
				}
			}
		}
	}

}

int main(int argc, const char * argv[]) {
	// insert code here...
	system("cls");
	GraphLink g = (Graph *)malloc(sizeof(Graph));
	//数目：7 6 0
	//顶点信息：a b c d e f g
	//边的信息：0 2 0 3 0 1 4 5 1 6 1 2

	creatGraph(&g);
	putGragh(g);
	int i;
	for (i = 0; i < M; i++) {
		visited[i] = false;
	}
	printf("深度优先遍历：");
	DFSTraverse(g);

	for (i = 0; i < M; i++) {
		visited[i] = false;
	}
	printf("广度优先遍历：");
	BFSTraverse(g);
	printf("\nHello, World!\n");
	return 0;
}


//输入顶点数目,边数和有向？：
//7 6 0
//输入顶点信息：
//a b c d e f g
//输入边信息：
//0 2 0 3 0 1 4 5 1 6 1 2
//a->b a->d a->c
//b->c b->g b->a
//c->b c->a
//d->a
//e->f
//f->e
//g->b
//深度优先遍历：a b c g d e f 广度优先遍历：a b d c g e f 
// Hello, World!