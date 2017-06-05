#include "stdafx.h"
#include "CalculatorAvrMark.h"
#include "Container.h"
#include "Collectors.h"

AvrMark::AvrMark() {}

float AvrMark::getAvrMark() {
	return (float)sum / count;
}

void AvrMark::operator()(const Entry en) {
	++count;
	sum += en.getMark();
}