#pragma once
#include <stdio.h>
struct TInfo {
	struct {
		char F[31] = "", Num[31] = "", Date[31] = "";
	} FND;
	int numStuff = 0, weightStuff = 0;
};

struct TQ {
	char f[10] = "bin";
	FILE* F = fopen(f, "w+b");
	TInfo data;
	int n = 0;
	int l = 0;
	int k = 10;
};
const TInfo Null_info = { "", "", "", 0, 0 };

TQ* newQ(TQ* q);
bool isEmpty(TQ* q);
TQ* pushQ(TQ* q, TInfo a);
TInfo popQ(TQ* q);
void spaceCheck(TQ* q, int l, int k, FILE* bin);
void moveQ(TQ* q, int l, FILE* bin);
void truncate(TQ* q, int k, FILE* bin);