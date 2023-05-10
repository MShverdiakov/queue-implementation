#define _CRT_SECURE_NO_WARNINGS
#include "baseBin.h"
#include <stdio.h>
#include <cstdio>


TQ* newQ(TQ* q) {
	TQ* b = new TQ;
	TInfo buff = Null_info;
	FILE* fp = fopen(b->f, "w+b");
	fseek(fp, 0, SEEK_SET);
	fwrite(&buff, sizeof(TInfo), 1, fp);
	fwrite(&buff, sizeof(TInfo), 10, fp);
	b->n++;
	q = b;
	return q;
}
bool isEmpty(TQ* q) {
	bool fl = false;
	if (q->n == 0) {
		fl = true;
	}
	return fl;
}
TQ* pushQ(TQ* q, TInfo a) {
	fwrite(&a, sizeof(TInfo), 1, q->F);
	q->n++;
	q->k--;
	return q;
}
TInfo popQ(TQ* q) {
	TInfo buff;
	fseek(q->F, q->l*sizeof(TInfo), SEEK_SET);
	fread(&buff, sizeof(TInfo), 1, q->F);
	q->n--;
	q->l++;
	spaceCheck(q, q->l, q->k, q->F);
	return buff;
}
void spaceCheck(TQ* q, int l, int k, FILE* bin) {
	if (l > 10) {
		moveQ(q, l - 10, bin);
	}
	if (k > 10) {
		truncate(q, 10, bin);
	}
}
void moveQ(TQ* q, int l, FILE* bin) {
	int i;
	TInfo buff;
	for (i = l; i > 0; i -= i) {
		fseek(bin, l * sizeof(TInfo), SEEK_SET);
		fread(&buff, sizeof(TInfo), 1, bin);
		fseek(bin, (l - 1) * sizeof(TInfo), SEEK_SET);
		fwrite(&buff, sizeof(TInfo), 1, bin);
	}
	return;
}
void truncate(TQ* q, int k, FILE* bin) {
	int i;
	for (i = 0; i < k - 10; i++) {
		fseek(bin, (k - i) * sizeof(TInfo), SEEK_SET);
		fwrite(0, 0, 1, bin);
	}
	return;
}