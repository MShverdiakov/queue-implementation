	#pragma once
	#include "C:\\Users\\shverd\\source\\repos\\lab11\\lab11libBin\\lab11libBin\\baseBin.h"
	#include <stdio.h>
	void emptyQ(TQ** q);
	TQ* freadQ(TQ** q, FILE* dat);
	TQ* readQ(TQ** q);
	TQ* filterQ(TQ* q);
	TQ* popIt(TQ** q, int n);
	TInfo correct(TInfo b);
	void printQ(TQ* q);
	void fprintQ(TQ* q, FILE* res);
