#define _CRT_SECURE_NO_WARNINGS 1

#include "book.h"

void menu()
{
	printf("Append Find Remove Modify Show Quit > ");
}

struct book_node* createHead()
{
	struct book_node* headnode = (struct book_node*)malloc(sizeof(struct book_node));
	headnode->next = NULL;
	return headnode;
}

struct book_node* Create_book_Doc()
{
	//��ʱ����
	struct book_node* p ;
	char* book_num;
	char* book_name;
	char* author_name;
	char* publisher;

	//���崢��ռ�
	book_num = (char*)malloc(8);
	book_name = (char*)malloc(8);
	author_name = (char*)malloc(8);
	publisher = (char*)malloc(8);

	//������ʱ����,��ֵ���ڵ�
	int year = -1;
	int mon = -1;
	int day = -1;
	double price;

	//����ṹ��Ĵ�С
	int sz = sizeof(struct book_node);

	//���봢������
	printf("     ISBN: ");
	scanf("%s", book_num);
	printf("    Title: ");

	//��ȡ'\n'
	getchar();
	gets(book_name);
	printf("   Author: ");
	gets(author_name);
	printf("Publisher: ");
	gets(publisher);
	printf(" Pub date: ");

	//�ж������Ƿ���ȷ
	//�е�����

	scanf("%d/%d/%d", &year, &mon, &day);

	while (!IsRightDate(year, mon, day))
	{
		printf("Incorrect date! Please reenter: ");
		scanf("%d/%d/%d", &year, &mon, &day);
	}

	printf("    Price: ");
	scanf("%lf", &price);

	//��ȡ�ո�
	getchar();

	//��ֵ
	p = (struct book_node*)malloc(sz);
	p->book.book_num = book_num;
	p->book.book_name = book_name;
	p->book.author_name = author_name;
	p->book.publisher = publisher;
	p->book.day = day;
	p->book.mon = mon;
	p->book.year = year;
	p->book.price = price;
	p->next = NULL;

	return p;
}

int IsRightDate(int year, int mon, int day)
{
	if (year > 0)
	{
		if (mon > 0 && mon < 13)
		{
			if (day > 0 && day <= Mday(year, mon))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Mday(int year, int mon)
{
	int M = 0;
	if (year > 0)
	{
		switch (mon)
		{
		case 1: M = 31; break;
		case 2: M = 28 + IsLeapYear(year); break;
		case 3: M = 31; break;
		case 4: M = 30; break;
		case 5: M = 31; break;
		case 6: M = 30; break;
		case 7: M = 31; break;
		case 8: M = 31; break;
		case 9: M = 30; break;
		case 10: M = 31; break;
		case 11: M = 30; break;
		case 12: M = 31; break;
		}
	}
	return M;
}

int IsLeapYear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void Print_All_booknode(struct book_node* head)
{
	//���ͷΪ�շ���
	struct book_node* ptr;
	if (head == NULL)
	{
		return;
	}

	//ѭ����ӡ
	printf("ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n");
	for (ptr = head ->next; ptr; ptr = ptr->next)
	{
		printf("%-13s ", ptr->book.book_num);
		printf("%-30s ", ptr->book.book_name);
		printf("%-20s ", ptr->book.author_name);
		printf("%-30s ", ptr->book.publisher);
		printf("%04d/%02d/%02d ", ptr->book.year, ptr->book.mon, ptr->book.day);
		printf("%8.2f ", ptr->book.price);
		printf("\n");
	}
}

void BubbleSortOfList(struct book_node* list)
{
	//��ʱ����
	infom tmp;
	struct book_node* prt = NULL;
	struct book_node* qrt = NULL;

	//ð������ 
	for (prt = list->next; prt; prt = prt->next)
	{
		for (qrt = list->next; qrt->next; qrt = qrt->next)
		{
			if (strcmp(qrt->book.book_num, qrt->next->book.book_num) > 0 )
			{
				tmp = qrt->book;
				qrt->book = qrt->next->book;
				qrt->next->book = tmp;
			}
		}
	}
}

void Print_node(struct book_node* node)
{
	struct book_node* ptr = NULL;
	ptr = node;
	printf("%-13s ", ptr->book.book_num);
	printf("%-30s ", ptr->book.book_name);
	printf("%-20s ", ptr->book.author_name);
	printf("%-30s ", ptr->book.publisher);
	printf("%04d/%02d/%02d ", ptr->book.year, ptr->book.mon, ptr->book.day);
	printf("%8.2f ", ptr->book.price);
	printf("\n");
}

void SearchNodePrintByName(struct book_node* list)
{
	//��������,���������ַ���
	char temp[31] = { 0 };

	//Lָ��,��������
	struct book_node* L = list->next;

	//�鿴�Ƿ��ҵ�
	int flag = 0;

	printf("Title: ");
	gets(temp);

	int num = 1;
	//����
	while (L)
	{
		if (strcmp(temp, L->book.book_name) == 0)
		{
			if (num)
			{
				printf("ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n");
				num = 0;
			}
			Print_node(L);
			flag = 1;
		}
		L = L->next;
	}

	//û�ҵ�
	if (flag == 0)
	{
		printf("Not found!\n");
	}
}

void SearchNodeDelByNum(struct book_node* list)
{
	//��������,�����ַ���
	char temp[14] = { 0 };
	printf("ISBN: ");
	gets(temp);

	//ָ��Ѱ��deleteλ��
	struct book_node* p = NULL;
	p = list;

	//���Ƿ�Ѱ�ҵ�
	int flag = 0;

	while (p->next != NULL)
	{
		if (strcmp(temp, p->next->book.book_num) == 0)
		{
			printf("Remove(y/n)? ");

			//ѭ������
			int ok = 1;

			//��ȡ�ַ�

			char ch = 0;
			scanf("%c%*c", &ch);

			while (ok)
			{
				if (ch == 'y' || ch == 'Y')
				{
					ok = 0;
					flag = 1;
					struct book_node* mid = NULL;
					mid = p->next;
					p->next = mid->next;
					free(mid);
					return;
				}
				else if (ch == 'n' || ch == 'N')
				{
					ok = 0;
					flag = 1;
					return;
				}
				else
				{
					printf("Incorrect answer!\n");
					printf("Remove(y/n)? ");
					scanf("%c%*c", &ch);
				}
			}
			return;
		}
		p = p->next;
	}

	//������,û�ҵ�
	if (flag == 0)
	{
		printf("Not found!\n");
	}
}

struct book_node* SearchNodeModifyByNum(struct book_node* list, struct book_node* L)
{
	char temp[14] = { 0 };
	printf("ISBN: ");
	gets(temp);

	struct book_node* p = NULL;
	p = list;

	//���Ƿ�Ѱ�ҵ�
	int flag = 0;

	while (p->next)
	{
		if (strcmp(temp, p->next->book.book_num) == 0)
		{
			printf("Modify(y/n)? ");
			
			//ѭ������
			int ok = 1;
			char ch = 0;
			scanf("%c%*c", &ch);

			while (ok)
			{
				if (ch == 'y' || ch == 'Y')
				{
					ok = 0;
					flag = 1;
					if (p->next->next != NULL) 
					{
						ModifyInfom(p);
					}
					else
					{
						struct book_node* newnode = NULL;
						struct book_node* mid = NULL;
						mid = p->next;
						newnode = Create_book_Doc();
						p->next = newnode;
						free(mid);
						L = p->next;
					}
				}
				else if (ch == 'n' || ch == 'N')
				{
					ok = 0;
					flag = 0;
				}
				else
				{
					printf("Incorrect answer!\n");
					printf("Modify(y/n)? ");
					scanf("%c%*c", &ch);
				}
			}
		}
		p = p->next;
	}

	//������,û�ҵ�
	if (flag == 0)
	{
		printf("Not found!\n");
	}
	return L;
}
void ModifyInfom(struct book_node* node)
{
	struct book_node* newnode = NULL;
	newnode = Create_book_Doc();
	newnode->next = node->next->next;
	node->next = newnode;
}