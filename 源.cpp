#include <stdio.h>
#include <string.h>
#define MAXWEIGHT 999      //�����ܱ�Ȩֵ(��ʾ������ޱ�����)
#define MAX_VERTEX_NUM 20 //ͼ�������ܶ������
typedef int VRType;       //��Ȩֵ������(����)
typedef char VertexType[5];  //�������ݵ�����(�ַ�������󳤶�4)
//�ڽ�������
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];  //��������
	AdjMatrix  arcs;                      //�ڽӾ���
	int        vexnum,                   //�������
		arcnum;                   //������
}MGraph; //ͼ����
//����Ϊ�ڽ����ʾ��ͼ�Ļ�����������
//��ʾͼ���ڽӾ���
void Display(MGraph *G) {
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++)
			if (G->arcs[i][j] == MAXWEIGHT)
				printf("%5s", "��"); //�áޱ�ʾ�ޱ�����
			else
				printf("%5d", G->arcs[i][j]);
		printf("\n");
	}
}
//�ж����������Ƿ���ͬ
int equal(VertexType v1, VertexType v2) {
	return strcmp(v1, v2) == 0;
}
//���Ҷ����ڶ��������е��±�
int locate(MGraph *G, VertexType v) {
	for (int i = 0; i<G->vexnum; i++)
		if (equal(G->vexs[i], v)) return i;
	return -1;
}
//��������������Ȩ����ͼ��
void CreateGraph(MGraph *G) {
	VertexType v1, v2;
	VRType weight;
	int i, j, k;
	//printf("���붥������");
	scanf("%d", &G->vexnum);
	printf("���������");
	scanf("%d", &G->arcnum);
	//������������
	printf("��������%d���������Ϣ��\n", G->vexnum);
	for (i = 0; i<G->vexnum; i++) {
		scanf("%s", G->vexs[i]);
	}
	//��ʼ���ڽ���
	for (i = 0; i<G->vexnum; i++)
		for (j = 0; j<G->vexnum; j++) {
		G->arcs[i][j] = MAXWEIGHT;//G->arcs[i][j].adj=0;
		//G->arcs[i][j].info=NULL;
		}
	for (i = 0; i<G->vexnum; i++) G->arcs[i][i] = 0;//����������ָ�������ѭ����
	//�����ڽ�������
	printf("�������뻡����㡢�յ���ż���Ȩֵ\n");
	for (k = 0; k<G->arcnum; k++) {
		//���붥���š���Ȩֵ
		scanf("%s%s%d", v1, v2, &weight);
		//�����Ӧ����Ԫ���±�
		i = locate(G, v1);
		j = locate(G, v2);
		G->arcs[i][j] = weight;//G->arcs[i][j].adj=weight;
		//G->arcs[j][i] =G->arcs[i][j];
	}
}
int visited[MAX_VERTEX_NUM]; //������ʱ�־����
//�ݹ�������ȱ���
void DFS(MGraph *G, int i) {
	int n = G->vexnum;
	printf("%5s", G->vexs[i]);  //���ʶ��� i
	visited[i] = 1;      //���ö��� i �ķ��ʱ�־
	for (int j = 0; j<n; j++)  //ɨ��� i �У�Ѱ�� i ���ڽӶ���
		if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAXWEIGHT && !visited[j])
			DFS(G, j);   //�ݹ���� i ���ڽӶ��� j
}
//������ȱ���������
void DFSTraverse(MGraph *G) { //��ͼ g ����������ȱ���
	int n = G->vexnum;
	int i;
	for (int i = 0; i<n; i++) visited[i] = 0; //��ʼ��������ʱ�־

	for (i = 0; i<n; i++)
		if (visited[i] == 0) DFS(G, i);
}
void main(void) {
	MGraph g, *gt;
	gt = &g; //��ȡָ��ͼ���͵�ָ��
	CreateGraph(gt); //�������룬����������
	Display(gt);  //��ʾͼ���ڽ���
	DFSTraverse(gt);//������ȱ���
}
