#pragma once
struct TInfo {
	struct {
		char F[31] = "", Num[31] = "", Date[31] = "";
	} FND;
	int numStuff = 0, weightStuff = 0;
};
struct node {
	TInfo data;
	node* next;
};
struct TQ {
	node* head;
	node* tail;
	int k = 0;
};
const TInfo Null_info = { "", "", "", 0, 0 };

TQ* newQ(TQ* q);
bool isEmpty(TQ* q);
TQ* pushQ(TQ* q, TInfo a);
TInfo popQ(TQ* q);