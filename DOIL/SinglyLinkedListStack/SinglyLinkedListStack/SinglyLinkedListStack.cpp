// DoublyLinkedList.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

bool IsEmpty();
void push(int value);
void pop();
void peek();
void size();

void clear_();
void Printlist();
void List();

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

typedef struct _list {
	node* head;
	node* cur;
	node* tail;
	int size;
}list;

list*L = (list*)malloc(sizeof(list));

int main(void)
{

	int choice;
	int value;
		
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	while (1) {

		List();

		printf("choice를 해주세요\n");
		scanf_s("%d", &choice);
		switch (choice) {

		case 1:
			printf("value 값을 입력하시오\n");
			scanf_s("%d", &value);
			push(value);
			Printlist();
			break;

		case 2:
			pop();
			Printlist();
			break;
		
		case 3:
			peek();
			break;
		
		case 4:
			size();
			break;
		
		case 5:
			clear_();
			break;
		}
	}
	return 0;
}
void List()
{
	printf("\n");
	
	printf("1.push\n");	
	printf("2.pop\n");
	printf("3.peek\n");	
	printf("4.size\n");	
	printf("5.clear\n");
	printf("\n");
}

void Printlist()
{
	L->cur = L->head;
	while (L->cur) {
		printf(" %d ->", L->cur->data);
		L->cur = L->cur->next;
	}
	printf("\n");
}

bool IsEmpty()
{
	if (L->head == NULL && L->tail == NULL)   return true;
	else
		return false;
}

void push(int value)
{
	node* New = (node*)malloc(sizeof(node));
	New->data = value;

	if (IsEmpty()) {            //비었을 경우,               New->prev = NULL;
		New->next = NULL;
		L->head = L->tail = New;
	}
	else {
		//      if(L.size== 1){
		if (L->head == L->tail) {         //1개일 경우,
			L->head->next = New;
			
			New->next = NULL;
			L->tail = New;
		}
		else {               //2개 이상일 경우,            New->next = NULL;

			New->next = NULL;
			L->tail->next = New;
			L->tail = New;
		}
	}
	L->size++;
}

void pop()
{
	node* temp;
	
	if (L->size == 1)
		L->head = L->tail = NULL;
	else if (L->size == 2) {
		temp = L->tail;
		L->head->next = NULL;
		L->tail = L->head;
		free(temp);
	}
	else {
		temp = L->tail;
		L->cur = L->head;
		while (L->cur->next != L->tail) L->cur = L->cur->next;		
		free(temp);
		L->cur->next = NULL;
		L->tail = L->cur;	
	}
	L->size--;
}

void peek() 
{
	if (IsEmpty())	printf("DATA가 없습니다.\n");
	else	printf("data 값은 %d입니다.\n", L->tail->data);	
}
void size() 
{
	if(IsEmpty()) printf("크기는 0입니다.\n");
	else printf("크기는 %d입니다.\n", L->size);
}


void clear_()
{
	printf("data를 모두 지우겠습니다.\n");
	while(L->size !=0) pop();
}
