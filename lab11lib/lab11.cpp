#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma comment(lib, "C:\\Users\\shverd\\source\\repos\\lab11\\lab11dop\\Debug\\lab11dop.lib")
#pragma comment(lib, "C:\\Users\\shverd\\source\\repos\\lab11\\lab11libBin\\Debug\\lab11libBin.lib")
//#pragma comment(lib, "C:\\Users\\shverd\\source\\repos\\lab11\\lab11lib\\Debug\\lab11libList.lib")

#include "C:\\Users\\shverd\source\\repos\lab11\\lab11dop\\lab11dop\\dop.h"
#include "C:\Users\\shverd\\source\\repos\\lab11\\lab11libBin\\lab11libBin\\baseBin.h"
//#include "C:\\Users\\shverd\\source\\repos\\lab11\\lab11lib\\lab11lib\\base.h"
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	FILE* dat, * res;
	dat = fopen("dat.txt", "r");
	res = fopen("res.txt", "wt");

	TQ* q=nullptr;
	TInfo base = Null_info;
	q = newQ(q);
	q = pushQ(q, base);

	bool fl = true;
	int menu = 0;
	int aux = 0;

	while (fl) {
		printf("%s", "Выберите действие:\n");
		printf("%s", "1 - Ввод очереди из файла\n2 - Ввод элемента очереди с клавиатуры\n3 - очистка n элементов\n4 - Очистка очереди\n5 - Фильтр очереди\n6 - Печать очереди\n7 - Выход\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			q = freadQ(&q, dat);
			printf("%s", "Файл считан.");
			fclose(dat); dat = fopen("dat.txt", "r");
			break;
		case 2:
			q = readQ(&q);
			break;
		case 3:
			printf("%s", "Сколько элементов удалить?\n");
			scanf("%d", &aux);
			q = popIt(&q, aux);
			break;
		case 4:
			emptyQ(&q);
			printf("%s", "Очередь очищена.");
			break;
		case 5:
			q = filterQ(q);
			break;
		case 6:
			printQ(q);
			fprintQ(q, res);
			break;
		case 7:
			fclose(dat); fclose(res);
			fl = false;
			break;
		}
	}
}