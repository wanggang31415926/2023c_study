#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book_info
{
	char* book_num;
	char* book_name;
	char* author_name;
	char* publisher;
	int year;
	int mon;
	int day;
	double price;
}infom;

typedef struct book_node
{
	infom book;
	struct book_node* next;
}book_node, * Llist;

//创建表头
struct book_node* createHead();

void menu();
//创建头结点
struct book_node* Create_book_Doc();
int IsRightDate(int year, int mon, int day);
int Mday(int year, int mon);
int IsLeapYear(int year);
//打印整个链表
void Print_All_booknode(struct book_node* head);
//打印某一节点
void Print_node(struct book_node* node);
//冒泡排序
void BubbleSortOfList(struct book_node* list);
//书名查找
void SearchNodePrintByName(struct book_node* list);
//书号查找删除
void SearchNodeDelByNum(struct book_node* list);
//书号查找修改
struct book_node* SearchNodeModifyByNum(struct book_node* list, struct book_node* L);
void ModifyInfom(struct book_node* node);