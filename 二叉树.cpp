#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree
{
	char data;
	struct BiTree* lchild;
	struct BiTree* rchild;
}BiTree, *BiNode;
BiNode Create();//先序建立二叉树
void Pre(BiNode root);//先序遍历二叉树
void Mid(BiNode root);//中序遍历二叉树
void Post(BiNode root);//后序遍历二叉树
void Level(BiNode root);//二叉树的层次遍历，运用队列，每层的结点挨个先进先出
void Editor(BiNode root);//修改二叉树中的某些值
void Pre1(BiNode root);//先序遍历二叉树      不输出
void Find(BiNode root);//查找树中的值
void InsertChild(BiNode root);//插入
void Destroy(BiNode root);//删除节点
BiNode destroy1(BiNode root);//删除节点
void menu1();//主菜单
void menu2();//二级菜单
int main()
{
	BiNode T = NULL;
	char ch;
	system("color 9F");
	do {
		system("cls");
		menu1();
		ch = getchar();
		getchar();
		switch (ch)
		{
		case'1':
		{
			system("cls");
			printf("开始创建二叉树，请输入数据(输入'#'代表此节点为空，且无左右子树)\n");
			T = Create();
			if (T != NULL)
				printf("二叉树创建成功！");
			else
				printf("二叉树创建失败！");
			system("pause");
			system("cls");
		}break;
		case'2':
		{
			system("cls");
			char c;
			do
			{
				system("cls");
				menu2();
				c = getchar();
				getchar();
				switch (c)
				{
				case'1':
				{
					system("cls");
					if (!T)
					{
						printf("树为空，请创建后重试！\n");
					}
					else
					{
						printf("先序遍历结果为：");
						Pre(T);
						printf("\n");
					}
					system("pause");
					system("cls");
				}	break;
				case'2':
				{	system("cls");
				if (!T)
				{
					printf("树为空，请创建后重试！\n");
				}
				else
				{
					printf("中序遍历结果为：");
					Mid(T);
					printf("\n");
				}
				system("pause");
				system("cls");
				}break;
				case'3':
				{
					system("cls");
					if (!T)
					{
						printf("树为空，请创建后重试！\n");
					}
					else
					{
						printf("后序遍历结果为：");
						Post(T);
						printf("\n");
					}
					system("pause");
					system("cls");

				}	break;
				case'4':
				{
					system("cls");
					if (!T)
					{
						printf("树为空，请创建后重试！\n");
					}
					else
					{
						printf("层次遍历结果为：");
						Level(T);
						printf("\n");
					}
					system("pause");
					system("cls");

				}break;
				case'5':
					system("cls");
					menu1();
					break;
				default:
					system("pause");
					system("cls");
					break;
				}
			} while (c != '5');
		}
		case '3':
			system("cls");
			Editor(T);
			break;
		case '4':
			system("cls");
			Find(T);
			break;
		case '5':
			system("cls");
			InsertChild(T);
			break;
		case '6':
			system("cls");
			Destroy(T);
			break;
		case'7':
			exit(0);
			break;
		default:
			printf("输入错误请重新输入\n");
			getchar();
			system("cls");
			break;
		}
	} while (ch != '7');
}
BiNode Create()//先序建立二叉树
{
	char a;
	BiNode T;
	scanf("%c", &a);
	if (a == '#')
	{
		return NULL;//规定当输入'#'时表示这个节点为空，而且没有左右子树
	}
	else
	{
		T = (BiNode)malloc(sizeof(BiTree));//动态分配内存
		if (NULL == T)
		{
			printf("空间申请失败!");
			system("pause");
			system("cls");
		}
		T->data = a;
		T->lchild = Create();//创建左子树
		T->rchild = Create();//创建右子树
	}
	return T;
}
void Pre(BiNode root)//先序遍历二叉树
{
	if (root)
	{
		printf("%c ", root->data);
		Pre(root->lchild);
		Pre(root->rchild);
	}
}

void Pre1(BiNode root)//先序遍历二叉树   不打印输出
{
	if (root)
	{
		Pre1(root->lchild);
		Pre1(root->rchild);
	}
}

void Mid(BiNode root)//中序遍历二叉树
{
	if (root)
	{
		Mid(root->lchild);
		printf("%c ", root->data);
		Mid(root->rchild);
	}
}

void Post(BiNode root)//后序遍历二叉树
{
	if (root)
	{
		Post(root->lchild);
		Post(root->rchild);
		printf("%c ", root->data);
	}
}
void Level(BiNode root)//二叉树的层次遍历，运用队列，每层的结点挨个先进先出。 
{
	BiNode queue[20], pTemp;
	int cur = 0, pre = 0;//cur表示当前入队列的结点，pre表示当前出队列的结点
	queue[cur++] = root;
	while (cur != pre)
	{
		pTemp = queue[pre++];
		printf("%c ", pTemp->data);
		if (pTemp->lchild != NULL) queue[cur++] = pTemp->lchild;
		if (pTemp->rchild != NULL) queue[cur++] = pTemp->rchild;
	}
}
void menu1()
{
	printf("****************************************************\n");
	printf("			1.创建二叉树\n");
	printf("			2.遍历二叉树\n");
	printf("			3.修改二叉树\n");
	printf("			4.查找二叉树\n");
	printf("			5.插入节点\n");
	printf("			6.删除节点\n");
	printf("			7.退出程序\n");
	printf("****************************************************\n");
}
void menu2()
{
	printf("****************************************************\n");
	printf("			1.先序遍历\n");
	printf("			2.中序遍历\n");
	printf("			3.后序遍历\n");
	printf("			4.层次遍历\n");
	printf("			5.返回主菜单\n");
	printf("****************************************************\n");
}




//修改二叉树中的值
void Editor(BiNode root)
{
	char a, b;
	int flag = 0;
	if (root == NULL)
	{
		printf("树为空，请先建立树！");
		getchar();
		return;
	}
	printf("请输入要修改的节点值：");
	a = getchar();
	getchar();
	printf("请输入欲修改成的节点值：");
	b = getchar();
	getchar();
	if (root)
	{
		if (root->data == a)
		{
			root->data = b;
			flag = 1;
		}
		Pre1(root->lchild);
		Pre1(root->rchild);

	}
	if (flag)
	{
		printf("修改成功！");
		system("pause");
	}
	else
	{
		printf("未找到要修改的值！");
		system("pause");
	}
}



void Find(BiNode root)
{
	char a;
	int flag = 0;
	if (root == NULL)
	{
		printf("树为空，请先建立树！");
		getchar();
		return;
	}
	printf("请输入您要查找的节点值：");
	a = getchar();
	getchar();

	if (root)
	{
		if (root->data == a)
		{
			flag = 1;
		}
		Pre1(root->lchild);
		Pre1(root->rchild);

	}
	if (flag)
	{
		printf("查找成功，你输入的%c存在该树中！", a);
		system("pause");
	}
	else
	{
		printf("未找到要查找的值！");
		system("pause");
	}

}

//插入孩子在树节点
void InsertChild(BiNode root)
{
	BiNode child = NULL, node, tnode;  //孩子存放插入位置原孩子，节点存放插入数据，临时节点存放插入节点
	char choice, data;  //选择和数据
	if (root == NULL)
	{
		printf("树为空，请先建立树！");
		getchar();
		return;
	}
	printf("请输入你要插入其后的数据:");
	data = getchar();
	getchar();
	if (root)
	{
		if (root->data == data) tnode = root;
		Pre1(root->lchild);
		Pre1(root->rchild);
	}
	if (tnode)
	{
		printf("1.插入到左孩子 2.插入到右孩子\n");
		choice = getchar();
		if (choice == '1')
		{
			child = tnode->lchild;
			node = (BiNode)malloc(sizeof(BiNode));
			node->data = data;
			node->rchild = NULL;
			node->lchild = child;
			tnode->lchild = node;
			printf("插入成功!\n");
		}
		else if (choice == '2')
		{
			child = tnode->rchild;
			node = (BiNode)malloc(sizeof(BiNode));
			node->data = data;
			node->lchild = NULL;
			node->rchild = child;
			tnode->rchild = node;
			printf("插入成功!\n");
		}
		else
		{
			printf("输入有误，即将回到上一级菜单\n");
		}
		getchar();
	}
	else printf("未找到相关数据的位置\n");
}

void Destroy(BiNode root)
{
	BiNode child = NULL, tnode;  //孩子存放删除节点原孩子，临时节点存放删除节点双亲
	char choice, data;  //选择和数据
	if (root == NULL)
	{
		printf("树为空，请先建立树！");
		getchar();
		return;
	}
	printf("请输入你要删除的数据:");
	data = getchar();
	getchar();
	if (root)
	{
		if (root->lchild != NULL && root->lchild->data == data) tnode = root;
		if (root->rchild != NULL && root->rchild->data == data) tnode = root;
		Pre1(root->lchild);
		Pre1(root->rchild);
	}
	if (tnode->lchild == NULL && tnode->rchild == NULL) free(tnode);
	else destroy1(tnode);
}

BiNode destroy1(BiNode root)
{
	if (root)
	{
		destroy1(root->lchild);
		destroy1(root->rchild);
		free(root);
		root = NULL;
	}
	return root;
}