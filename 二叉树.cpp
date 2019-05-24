#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree
{
	char data;
	struct BiTree* lchild;
	struct BiTree* rchild;
}BiTree, *BiNode;
BiNode Create();//������������
void Pre(BiNode root);//�������������
void Mid(BiNode root);//�������������
void Post(BiNode root);//�������������
void Level(BiNode root);//�������Ĳ�α��������ö��У�ÿ��Ľ�㰤���Ƚ��ȳ�
void Editor(BiNode root);//�޸Ķ������е�ĳЩֵ
void Pre1(BiNode root);//�������������      �����
void Find(BiNode root);//�������е�ֵ
void InsertChild(BiNode root);//����
void Destroy(BiNode root);//ɾ���ڵ�
BiNode destroy1(BiNode root);//ɾ���ڵ�
void menu1();//���˵�
void menu2();//�����˵�
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
			printf("��ʼ����������������������(����'#'����˽ڵ�Ϊ�գ�������������)\n");
			T = Create();
			if (T != NULL)
				printf("�����������ɹ���");
			else
				printf("����������ʧ�ܣ�");
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
						printf("��Ϊ�գ��봴�������ԣ�\n");
					}
					else
					{
						printf("����������Ϊ��");
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
					printf("��Ϊ�գ��봴�������ԣ�\n");
				}
				else
				{
					printf("����������Ϊ��");
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
						printf("��Ϊ�գ��봴�������ԣ�\n");
					}
					else
					{
						printf("����������Ϊ��");
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
						printf("��Ϊ�գ��봴�������ԣ�\n");
					}
					else
					{
						printf("��α������Ϊ��");
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
			printf("�����������������\n");
			getchar();
			system("cls");
			break;
		}
	} while (ch != '7');
}
BiNode Create()//������������
{
	char a;
	BiNode T;
	scanf("%c", &a);
	if (a == '#')
	{
		return NULL;//�涨������'#'ʱ��ʾ����ڵ�Ϊ�գ�����û����������
	}
	else
	{
		T = (BiNode)malloc(sizeof(BiTree));//��̬�����ڴ�
		if (NULL == T)
		{
			printf("�ռ�����ʧ��!");
			system("pause");
			system("cls");
		}
		T->data = a;
		T->lchild = Create();//����������
		T->rchild = Create();//����������
	}
	return T;
}
void Pre(BiNode root)//�������������
{
	if (root)
	{
		printf("%c ", root->data);
		Pre(root->lchild);
		Pre(root->rchild);
	}
}

void Pre1(BiNode root)//�������������   ����ӡ���
{
	if (root)
	{
		Pre1(root->lchild);
		Pre1(root->rchild);
	}
}

void Mid(BiNode root)//�������������
{
	if (root)
	{
		Mid(root->lchild);
		printf("%c ", root->data);
		Mid(root->rchild);
	}
}

void Post(BiNode root)//�������������
{
	if (root)
	{
		Post(root->lchild);
		Post(root->rchild);
		printf("%c ", root->data);
	}
}
void Level(BiNode root)//�������Ĳ�α��������ö��У�ÿ��Ľ�㰤���Ƚ��ȳ��� 
{
	BiNode queue[20], pTemp;
	int cur = 0, pre = 0;//cur��ʾ��ǰ����еĽ�㣬pre��ʾ��ǰ�����еĽ��
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
	printf("			1.����������\n");
	printf("			2.����������\n");
	printf("			3.�޸Ķ�����\n");
	printf("			4.���Ҷ�����\n");
	printf("			5.����ڵ�\n");
	printf("			6.ɾ���ڵ�\n");
	printf("			7.�˳�����\n");
	printf("****************************************************\n");
}
void menu2()
{
	printf("****************************************************\n");
	printf("			1.�������\n");
	printf("			2.�������\n");
	printf("			3.�������\n");
	printf("			4.��α���\n");
	printf("			5.�������˵�\n");
	printf("****************************************************\n");
}




//�޸Ķ������е�ֵ
void Editor(BiNode root)
{
	char a, b;
	int flag = 0;
	if (root == NULL)
	{
		printf("��Ϊ�գ����Ƚ�������");
		getchar();
		return;
	}
	printf("������Ҫ�޸ĵĽڵ�ֵ��");
	a = getchar();
	getchar();
	printf("���������޸ĳɵĽڵ�ֵ��");
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
		printf("�޸ĳɹ���");
		system("pause");
	}
	else
	{
		printf("δ�ҵ�Ҫ�޸ĵ�ֵ��");
		system("pause");
	}
}



void Find(BiNode root)
{
	char a;
	int flag = 0;
	if (root == NULL)
	{
		printf("��Ϊ�գ����Ƚ�������");
		getchar();
		return;
	}
	printf("��������Ҫ���ҵĽڵ�ֵ��");
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
		printf("���ҳɹ����������%c���ڸ����У�", a);
		system("pause");
	}
	else
	{
		printf("δ�ҵ�Ҫ���ҵ�ֵ��");
		system("pause");
	}

}

//���뺢�������ڵ�
void InsertChild(BiNode root)
{
	BiNode child = NULL, node, tnode;  //���Ӵ�Ų���λ��ԭ���ӣ��ڵ��Ų������ݣ���ʱ�ڵ��Ų���ڵ�
	char choice, data;  //ѡ�������
	if (root == NULL)
	{
		printf("��Ϊ�գ����Ƚ�������");
		getchar();
		return;
	}
	printf("��������Ҫ������������:");
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
		printf("1.���뵽���� 2.���뵽�Һ���\n");
		choice = getchar();
		if (choice == '1')
		{
			child = tnode->lchild;
			node = (BiNode)malloc(sizeof(BiNode));
			node->data = data;
			node->rchild = NULL;
			node->lchild = child;
			tnode->lchild = node;
			printf("����ɹ�!\n");
		}
		else if (choice == '2')
		{
			child = tnode->rchild;
			node = (BiNode)malloc(sizeof(BiNode));
			node->data = data;
			node->lchild = NULL;
			node->rchild = child;
			tnode->rchild = node;
			printf("����ɹ�!\n");
		}
		else
		{
			printf("�������󣬼����ص���һ���˵�\n");
		}
		getchar();
	}
	else printf("δ�ҵ�������ݵ�λ��\n");
}

void Destroy(BiNode root)
{
	BiNode child = NULL, tnode;  //���Ӵ��ɾ���ڵ�ԭ���ӣ���ʱ�ڵ���ɾ���ڵ�˫��
	char choice, data;  //ѡ�������
	if (root == NULL)
	{
		printf("��Ϊ�գ����Ƚ�������");
		getchar();
		return;
	}
	printf("��������Ҫɾ��������:");
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