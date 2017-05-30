#include "stdafx.h"
#include "CalculatorsAvrMark.h"

AvrMarkByDiscipline::AvrMarkByDiscipline(const std::string d) {
	discipline = d;
}

double AvrMarkByDiscipline::getAvrMark() {
	return sum / count;
}

void AvrMarkByDiscipline::operator()(const Entry en) {
	if (en.getDiscipline() == discipline) {
		++count;
		sum += en.getMark();
	}
}


AvrMarkByCourse::AvrMarkByCourse(const int crs) {
	course = crs;
}

double AvrMarkByCourse::getAvrMark() {
	return sum / count;
}

void AvrMarkByCourse::operator()(const Entry en) {
	if (en.getCourse() == course) {
		++count;
		sum += en.getMark();
	}
}


AvrMarkByGroup::AvrMarkByGroup(const std::string grp) {
	group = grp;
}

double AvrMarkByGroup::getAvrMark() {
	return sum / count;
}

void AvrMarkByGroup::operator()(const Entry en) {
	if (en.getGroup() == group) {
		++count;
		sum += en.getMark();
	}
}
