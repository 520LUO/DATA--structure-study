#include<stdio.h>
#include<stdlib.h>
typedef int boolean;
#define true 1
#define false 0
typedef struct queue {
	int element[50];
	int rear;
	int front;
}*Squeue, Queue;
void InsQueue(Squeue q) {
	int num, i = 0, record = 0;
	printf("请输入您想入队的元素个数：");
	scanf("%d", &num);
	for (i; i < num; i++)
	{
		printf("请输入第%d个元素：", i + 1);
		if (++q->rear <= 9)
		{
			if (q->rear == q->front&&record == 1)
			{
				printf("数据溢出\n");
				system("pause");
				exit(1);
			}
			else if (q->rear == q->front)
			{
				record++;
			}
			scanf("%d", &q->element[q->rear]);
		}
		else
		{
			q->rear -= 10;
			scanf("%d", &q->element[q->rear]);
			if (q->rear == q->front)
			{
				printf("数据溢出\n");
				system("pause");
				exit(1);
			}
		}
	}
}
boolean IsEmpty(Squeue q)
{
	if (q->rear == -1 || q->front - 1 == q->rear)
		return true;
	else
		return false;
}
void DelQueue(Squeue q) {
	if (IsEmpty(q)) {
		printf("不存在队列\n");
		q->front = 0;
	}
	else {
		printf("队列为:");
		do {
			printf("%d-->", q->element[q->front]);
			q->front++;
		} while (!IsEmpty(q));
		printf("end\n");
	}
}
void GetFront(Squeue q)
{
	int i;
	if (IsEmpty(q))
		printf("不存在该队列\n");
	else
		printf("队首元素为：%d\n", q->element[q->front]);

}
void EnEmpty(Squeue q) {
	q->front = 0;
	q->rear = -1;
	printf("sucess!\n");
}
void main() {
	int input;
	Squeue q;
	q = (Squeue)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = -1;
	while (1)
	{
		printf("1.Insert Queue\n");
		printf("2.Get Queue\n");
		printf("3.Get   Front\n");
		printf("4.IS queue empty?\n");
		printf("5.Clear Queue\n");
		printf("6.Exit\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			InsQueue(q);
			break;
		case 2:
			DelQueue(q);
			break;
		case 3:
			GetFront(q);
			break;
		case 4:
			if (IsEmpty(q))
				printf("不存在该队列\n");
			else
				printf("存在该队列\n");
			break;
		case 5:
			EnEmpty(q);
			break;
		case 6:
			exit(0);
		default:
			printf("input error!\n");
			break;
		}
	}
}