#include "stdafx.h"
#include "Collectors.h"

NumOfRecordBookCollector::NumOfRecordBookCollector(const int num) {
	numOfRecordBook = num;
	c = new std::deque<Entry>();
}

std::deque<Entry> NumOfRecordBookCollector::getCollection() {
	return *c;
}

void NumOfRecordBookCollector::operator()(const Entry en) {
	if (en.getNumOfRecordBook() == numOfRecordBook)
		(*c).push_back(en);
}


SurnameCollector::SurnameCollector(const std::string s) {
	surname = s;
	c = new std::deque<Entry>();
}

std::deque<Entry> SurnameCollector::getCollection() {
	return *c;
}

void SurnameCollector::operator()(const Entry en) {
	if (en.getSurname() == surname)
		(*c).push_back(en);
}



CourseCollector::CourseCollector(const int crs) {
	course = crs;
	c = new std::deque<Entry>();
}

std::deque<Entry> CourseCollector::getCollection() {
	return *c;
}

void CourseCollector::operator()(const Entry en) {
	if (en.getCourse() == course)
		(*c).push_back(en);
}



GroupCollector::GroupCollector(const std::string grp) {
	group = grp;
	c = new std::deque<Entry>();
}

std::deque<Entry> GroupCollector::getCollection() {
	return *c;
}

void GroupCollector::operator()(const Entry en) {
	if (en.getGroup() == group)
		(*c).push_back(en);
}



MarkCollector::MarkCollector(const int m) {
	mark = m;
	c = new std::deque<Entry>();
}

std::deque<Entry> MarkCollector::getCollection() {
	return *c;
}

void MarkCollector::operator()(const Entry en) {
	if (en.getMark() == mark)
		(*c).push_back(en);
}
