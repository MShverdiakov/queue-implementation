#define _CRT_SECURE_NO_WARNINGS
#include "base.h"
#include <stdio.h>

TQ* newQ(TQ* q){
	TQ* b = new TQ;
	b->head = new node;
	b->head->next = nullptr;
	b->tail = b->head;
	b->k = 1;
	q = b;
	return q;
}
bool isEmpty(TQ* q) {
	if (q->k <= 0) {
		return true;
	}
	else return false;
}
TQ* pushQ(TQ* q, TInfo a) {
	q->tail->next = new node;
	q->tail = q->tail->next;
	q->tail->data = a; 
	q->tail->next = nullptr; 
	q->k++;
	return q;
}
TInfo popQ(TQ* q) {
	TInfo data = q->head->data;
	q->head = q->head->next; 
	q->k--;
	return data;
}
