#pragma once
#include "Entry.h"

//��������� ������� ������

class AvrMark
{
private:
	int count = 0;
	int sum = 0;
public:
	AvrMark();
	float getAvrMark();
	void operator()(const Entry en);
};

