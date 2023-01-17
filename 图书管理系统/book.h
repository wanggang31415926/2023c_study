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

//������ͷ
struct book_node* createHead();

void menu();
//����ͷ���
struct book_node* Create_book_Doc();
int IsRightDate(int year, int mon, int day);
int Mday(int year, int mon);
int IsLeapYear(int year);
//��ӡ��������
void Print_All_booknode(struct book_node* head);
//��ӡĳһ�ڵ�
void Print_node(struct book_node* node);
//ð������
void BubbleSortOfList(struct book_node* list);
//��������
void SearchNodePrintByName(struct book_node* list);
//��Ų���ɾ��
void SearchNodeDelByNum(struct book_node* list);
//��Ų����޸�
struct book_node* SearchNodeModifyByNum(struct book_node* list, struct book_node* L);
void ModifyInfom(struct book_node* node);