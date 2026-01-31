#pragma once
#include <stdlib.h>
#include <assert.h>

typedef struct NODE {
	int x;
	int y;
	int speed;
	struct NODE* next;
}Node;

typedef struct LinkList {
	struct NODE* head;
	struct NODE* end;

}LL;


Node* Node_init(int x,int y,int speed) {
	Node* temp = (Node*)malloc(sizeof(Node));
	assert(temp);
	temp->x = x;
	temp->y = y;
	temp->speed = speed;
	temp->next = NULL;
	return temp;
}

void LinkList_insert(LL*list,int x,int y,int speed) {
	if (list == NULL) {
		return;
	}
	if (list->head == NULL) {
		list->head = list->end = Node_init(x, y, speed);
	}
	else {
		list->end->next = Node_init(x, y, speed);
		list->end = list->end->next;
	}

}







