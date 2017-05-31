#pragma once
#include "Entry.h"

//вычисляет среднюю оценку

class AvrMark
{
private:
	int count;
	int sum = 0;
public:
	AvrMark(const int n);
	float getAvrMark();
	void operator()(const Entry en);
};

