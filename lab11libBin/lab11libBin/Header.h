#pragma once
#include <stdio.h>
struct TInfo {
	char F[15] = "0";
	char I[15] = "0";
	int yr = 2003;
	int ht = 228;
	int wt = 1337;
};
struct TQ {
	TInfo data;
	FILE* f;
	int head;
	int tail;
};

void newQ(TQ* q, TInfo a);
bool isEmpty(TQ* q);
TQ* pushQ(TQ* q, TInfo a);
TInfo popQ(TQ* q);