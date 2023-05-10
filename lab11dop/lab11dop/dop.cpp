#define _CRT_SECURE_NO_WARNINGS
#include"dop.h"
#include "C:\\Users\\shverd\\source\\repos\\lab11\\lab11libBin\\lab11libBin\\baseBin.h"
#include <stdio.h>


void emptyQ(TQ** q) {
	while (not(isEmpty(*q))) {
		popQ(*q);
	}
	return;
}
TQ* freadQ(TQ** q, FILE* dat) {
	TInfo buff;
	printf("%s", "Ввод с коррекцией? 1 - да ");
	int k = 0;
	scanf("%d", &k);
	while (not(feof(dat))) {
		fscanf(dat, "%s %s %s %d %d", buff.FND.F, buff.FND.Num, &buff.FND.Date, &buff.numStuff, &buff.weightStuff);
		if (k == 1) {
			*q = pushQ(*q, correct(buff));
		}
		else {
			*q = pushQ(*q, buff);
		}
	}
	return *q;
}
TQ* readQ(TQ** q) {
	TInfo buff;
	printf("%s", "Ввод с коррекцией? 1 - да \n");
	int k = 0;
	scanf("%d", &k);
	printf("%s", "Введите фамилию\n");
	scanf("%s", &buff.FND.F);
	printf("%s", "Введите номер\n");
	scanf("%s", &buff.FND.Num);
	printf("%s", "Введите дату\n");
	scanf("%s", &buff.FND.Date);
	printf("%s", "Введите кол-во вещей и их общий вес (через пробел)\n");
	scanf("%d %d", &buff.numStuff, &buff.weightStuff);
	if (k == 1) {
		*q = pushQ(*q, correct(buff));
	}
	else {
		*q = pushQ(*q, buff);
	}
	return *q;
}
TQ* filterQ(TQ* q) {
	TQ* b = q;
	TInfo buff = Null_info;
	int kol = 0, sumW = 0, i = b->n;
	printf("%d", q->n);
	while (not(isEmpty(b))) {
		buff = popQ(b);
		sumW += buff.weightStuff;
		if (buff.numStuff == 1 && buff.weightStuff >= 30) {
			printf("Найден %s %s %s\n", buff.FND.F, buff.FND.Num, buff.FND.Date);
			kol++;
		}
	}
	float averageWeight = 0;
	if (i != 0)
		averageWeight = sumW / (i - 2.0);
	if (kol == 0) {
		printf("Данные, соответствующие запросу,не найдены\n");
		printf("Средний вес багажа: %g\n", averageWeight);
	}
	else
		printf("Средний вес багажа: %g\n", averageWeight);

	return b;
}
TQ* popIt(TQ** q, int n) {
	int i = 0;
	while (not(isEmpty(*q)) and i < n) {
		popQ(*q); i++;
	}
	return *q;
}
TInfo correct(TInfo Pass) {
	if (Pass.numStuff <= 0) { Pass.numStuff = 1; Pass.weightStuff = 0; }
	if (Pass.weightStuff <= 0) { Pass.weightStuff = 0; }
	if (Pass.weightStuff > 50) { Pass.weightStuff = 50; }
	if (Pass.numStuff > 50) { Pass.numStuff = 50; }
	return Pass;
}
void printQ(TQ* q) {
	TQ* buff = q;
	TInfo b;
	while (not(isEmpty(buff))) {
		b = popQ(buff);
		printf("%s %c %s %c %s %c %d %c %d %s", b.FND.F, ' | ', b.FND.Num, ' | ', b.FND.Date, ' | ', b.numStuff, ' | ', b.weightStuff, "\n");
	}
	return;
}
