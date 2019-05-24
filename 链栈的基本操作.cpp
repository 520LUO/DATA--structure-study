/*
栈的抽象数据类型
ADT 栈(stack)
Data
	元素具有相同的类型，相邻元素具有前驱和后继关系
Operation
	InitStack(*S)：初始化操作，建立一个空栈S
	DestroyStack(*S):若栈存在，则销毁它
	ClearStack(S):将栈清空
	StackEmpty(S):若栈为空，返回true,否则返回false
	GetTop(S,*e):若栈存在且非空，用e返回S的栈顶元素
	Push(S,e):若栈存在，插入新元素e到栈S中并成为栈顶元素
	Pop(S,*e):删除栈S中栈顶元素，并用e返回其值
	StackTraverse(S):遍历栈中所有元素
	StackLength(S):从栈顶遍历所有元素
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

/*初始化栈*/
Status InitStack(PLinkStack *S）
{
	*S = (PLinkStack)malloc(sizeof(struct LinkStack));
	(*S)->top = NULL;
	(*S)->count = 0;
	return OK;
}

/*清空栈*/
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

/*销毁栈*/
Status DestroyStack(PLinkStack *S)
{
	ClearStack(*S);
	free(*S);
	return OK;
}

/*判断栈是否为空*/
Status StackEmpty(PLinkStack S)
{
	if (S->top)/*栈存在且非空*/
		return FALSE;
	else
		return TRUE;
}

/* 若栈存在且非空，用e返回S的栈顶元素 */
Status GetTop(PLinkStack S, SElemType *e)
{
	if (!S->top)return ERROR;
	*e = S->top->data;
	return OK;
}

/*入栈*/
Status Push(PLinkStack S, SElemType *e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(struct StackNode));
	p->data = *e;
	p->next = S->top;
	S->top = p;
	S->count++;
	return OK;
}

/*出栈*/
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

/*查看栈元素个数*/
int StackLength(PLinkStack S)
{
	return S->count;
}

/*遍历栈中所有元素*/
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

/*显示元素格式*/
Status visit(SElemType e)
{
	printf("%d ", e);
	return OK;
}

int main()
{
	SElemType e, i;
	PLinkStack s;
	printf("InitStack初始化栈并将1--12压入栈\n\n");
	if (InitStack(&s))
		for (e = 1; e <= 12; e++)
		{
			Push(s, &e);
		}
	printf("StackTraverse栈中元素从栈顶依次为:\n\n");
	StackTraverse(s, visit);
	Pop(s, &e);
	printf("\nPop弹出的元素为:%d\n\n", e);
	Pop(s, &e);
	printf("Pop又弹出的元素为:%d\n\n", e);
	printf("Push将刚刚弹出的元素%d再次压入\n\n", e);
	Push(s, &e);
	printf("StackEmpty判断栈是否为空:%d(1:是 0:不是)\n\n", StackEmpty(s));
	GetTop(s, &e);
	printf("GetTop当前栈顶元素为:%d\n\n", e);
	printf("StackLength:当前栈长度为%d \n\n", StackLength(s));
	ClearStack(s);
	printf("ClearStack栈清空后，StackEmpty栈是否为空%d(1:是 0:不是)\n\n", StackEmpty(s));
	DestroyStack(&s);
	printf("DestroyStack栈销毁\n");
	return 0;

}