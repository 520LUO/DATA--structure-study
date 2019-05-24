/*
ջ�ĳ�����������
ADT ջ(stack)
Data
	Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ
Operation
	InitStack(*S)����ʼ������������һ����ջS
	DestroyStack(*S):��ջ���ڣ���������
	ClearStack(S):��ջ���
	StackEmpty(S):��ջΪ�գ�����true,���򷵻�false
	GetTop(S,*e):��ջ�����ҷǿգ���e����S��ջ��Ԫ��
	Push(S,e):��ջ���ڣ�������Ԫ��e��ջS�в���Ϊջ��Ԫ��
	Pop(S,*e):ɾ��ջS��ջ��Ԫ�أ�����e������ֵ
	StackTraverse(S):����ջ������Ԫ��
	StackLength(S):��ջ����������Ԫ��
endADT
 */

#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW        -1
#define STACK_INIT_SIZE 10
#define STACKINCREMENT   2
#define OK               1
#define ERROR            0
#define TRUE             1
#define FALSE            0

typedef int SElemType;
typedef int Status;


typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}*PLinkStack;

/*��ʼ��ջ*/
Status InitStack(PLinkStack *S��
{
	*S = (PLinkStack)malloc(sizeof(struct LinkStack));
	(*S)->top = NULL;
	(*S)->count = 0;
	return OK;
}

/*���ջ*/
Status ClearStack(PLinkStack S)
{
	LinkStackPtr p;
	while (S->top) {
		p = S->top;
		S->top = S->top->next;
		S->count--;
		free(p);
	}
	return OK;
}

/*����ջ*/
Status DestroyStack(PLinkStack *S)
{
	ClearStack(*S);
	free(*S);
	return OK;
}

/*�ж�ջ�Ƿ�Ϊ��*/
Status StackEmpty(PLinkStack S)
{
	if (S->top)/*ջ�����ҷǿ�*/
		return FALSE;
	else
		return TRUE;
}

/* ��ջ�����ҷǿգ���e����S��ջ��Ԫ�� */
Status GetTop(PLinkStack S, SElemType *e)
{
	if (!S->top)return ERROR;
	*e = S->top->data;
	return OK;
}

/*��ջ*/
Status Push(PLinkStack S, SElemType *e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(struct StackNode));
	p->data = *e;
	p->next = S->top;
	S->top = p;
	S->count++;
	return OK;
}

/*��ջ*/
Status Pop(PLinkStack S, SElemType *e)
{
	LinkStackPtr p;
	if (!GetTop(S, e))return ERROR;
	p = S->top;
	S->top = S->top->next;
	S->count--;
	free(p);
	return OK;
}

/*�鿴ջԪ�ظ���*/
int StackLength(PLinkStack S)
{
	return S->count;
}

/*����ջ������Ԫ��*/
Status StackTraverse(PLinkStack S, Status(*visit)(SElemType))
{
	LinkStackPtr p;
	p = S->top;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

/*��ʾԪ�ظ�ʽ*/
Status visit(SElemType e)
{
	printf("%d ", e);
	return OK;
}

int main()
{
	SElemType e, i;
	PLinkStack s;
	printf("InitStack��ʼ��ջ����1--12ѹ��ջ\n\n");
	if (InitStack(&s))
		for (e = 1; e <= 12; e++)
		{
			Push(s, &e);
		}
	printf("StackTraverseջ��Ԫ�ش�ջ������Ϊ:\n\n");
	StackTraverse(s, visit);
	Pop(s, &e);
	printf("\nPop������Ԫ��Ϊ:%d\n\n", e);
	Pop(s, &e);
	printf("Pop�ֵ�����Ԫ��Ϊ:%d\n\n", e);
	printf("Push���ոյ�����Ԫ��%d�ٴ�ѹ��\n\n", e);
	Push(s, &e);
	printf("StackEmpty�ж�ջ�Ƿ�Ϊ��:%d(1:�� 0:����)\n\n", StackEmpty(s));
	GetTop(s, &e);
	printf("GetTop��ǰջ��Ԫ��Ϊ:%d\n\n", e);
	printf("StackLength:��ǰջ����Ϊ%d \n\n", StackLength(s));
	ClearStack(s);
	printf("ClearStackջ��պ�StackEmptyջ�Ƿ�Ϊ��%d(1:�� 0:����)\n\n", StackEmpty(s));
	DestroyStack(&s);
	printf("DestroyStackջ����\n");
	return 0;

}