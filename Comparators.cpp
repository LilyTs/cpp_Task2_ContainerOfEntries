#include "stdafx.h"
#include "Comparators.h"


bool cmpNumOfRecordBook::operator()(const Entry &en1, const Entry &en2) {
	return en1.getNumOfRecordBook() < en2.getNumOfRecordBook();
}

bool cmpSurname::operator()(const Entry &en1, const Entry &en2) {
	return en1.getSurname() < en2.getSurname();
}

bool cmpCourse::operator()(const Entry &en1, const Entry &en2) {
	return en1.getCourse() < en2.getCourse();
}

bool cmpGroup::operator()(const Entry &en1, const Entry &en2) {
	return en1.getGroup() < en2.getGroup();
}

bool cmpMark::operator()(const Entry &en1, const Entry &en2) {
	return en1.getMark() < en2.getMark();
}