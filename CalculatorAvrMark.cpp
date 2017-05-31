#include "stdafx.h"
#include "CalculatorAvrMark.h"
#include "Container.h"
#include "Collectors.h"

AvrMark::AvrMark(int n) {
	count = n;
}

float AvrMark::getAvrMark() {
	return (float)sum / count;
}

void AvrMark::operator()(const Entry en) {
	sum += en.getMark();
}