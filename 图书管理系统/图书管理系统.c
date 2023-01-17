#define _CRT_SECURE_NO_WARNINGS 1

#include "book.h"

int main()
{
	//创建头结点
	struct book_node* List = createHead();
	//两个临时节点
	struct book_node* node = NULL, * p = NULL;

	char ch = 0;
	int flag = 1;

	do
	{
		menu();
		scanf("%c%*c", &ch);
		switch (ch)
		{
		case 'a':
		case 'A':
			 p = Create_book_Doc();
			 if (flag)
			 {
				 List->next = p;
				 flag = 0;
			 }
			 else
			 {
				 node->next = p;
			 }
			 node = p;
			break;
		case 'f':
		case 'F':
			SearchNodePrintByName(List);
			break;
		case 'r':
		case 'R':
			SearchNodeDelByNum(List);
			break;
		case 'm':
		case 'M':
			node = SearchNodeModifyByNum(List,node);
			break;
		case 's':
		case 'S':
			BubbleSortOfList(List);
			Print_All_booknode(List);
			break;
		case 'q':
		case 'Q':
			printf("Thank you! Goodbye!\n");
			ch = 0;
			break;
		default :
			printf("Incorrect choice!");
			break;
		}
	} while (ch);
	return 0;
}
