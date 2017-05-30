#include "stdafx.h"
#include "string"
#include "Container.h"
#include "MyContainer.h"
#include "Entry.h"
#include "HelpUtils.h"
#include "Comparators.h"
#include "Collectors.h"
#include "CalculatorsAvrMark.h"

MyContainer::MyContainer() {
	c = std::deque<Entry>();
}

MyContainer::MyContainer(std::deque<Entry> cont) {
	c = cont;
}

MyContainer::~MyContainer() {

}

bool MyContainer::add(const Entry &en) {
	if (std::find(c.begin(), c.end(), en) == c.end()) {
	c.push_back(en); 
		return true;
	}
	return false;
}

MyContainer MyContainer::linSearchByNumOfRecordBook(const int query) const {
	NumOfRecordBookCollector coll = NumOfRecordBookCollector(query);
	return MyContainer(linearSearch(coll));
}

MyContainer MyContainer::linSearchBySurname(const std::string query) const {
	SurnameCollector coll = SurnameCollector(query);
	return MyContainer(linearSearch(coll));
}

MyContainer MyContainer::linSearchByCourse(const int query) const {
	CourseCollector coll = CourseCollector(query);
	return MyContainer(linearSearch(coll));
}

MyContainer MyContainer::linSearchByGroup(const std::string query) const {
	GroupCollector coll = GroupCollector(query);
	return MyContainer(linearSearch(coll));
}

MyContainer MyContainer::linSearchByMark(const int query) const {
	MarkCollector coll = MarkCollector(query);
	return MyContainer(linearSearch(coll));
}


MyContainer MyContainer::binSearchByNumOfRecordBook(const int query) {
	NumOfRecordBookCollector coll = NumOfRecordBookCollector(query);
	cmpNumOfRecordBook cmp = cmpNumOfRecordBook();
	Entry en = Entry(query, "", 0, "", "", 0);
	return binarySearch(cmp, coll, en);
}

MyContainer MyContainer::binSearchBySurname(const std::string query) {
	SurnameCollector coll = SurnameCollector(query);
	cmpSurname cmp = cmpSurname();
	Entry en = Entry(0, query, 0, "", "", 0);
	return binarySearch(cmp, coll, en);
}

MyContainer MyContainer::binSearchByCourse(const int query) {
	CourseCollector coll = CourseCollector(query);
	cmpCourse cmp = cmpCourse();
	Entry en = Entry(0, "", query, "", "", 0);
	return binarySearch(cmp, coll, en);
}

MyContainer MyContainer::binSearchByGroup(const std::string query) {
	GroupCollector coll = GroupCollector(query);
	cmpGroup cmp = cmpGroup();
	Entry en = Entry(0, "", 0, query, "", 0);
	return binarySearch(cmp, coll, en);
}

MyContainer MyContainer::binSearchByMark(const int query) {
	MarkCollector coll = MarkCollector(query);
	cmpMark cmp = cmpMark();
	Entry en = Entry(0, "", 0, "", "", query);
	return binarySearch(cmp, coll, en);
}

void MyContainer::remove(Entry en) {
	return Container::remove(en);
}

void MyContainer::outputToConsole()  const {
	return Container::outputToConsole();
}

bool MyContainer::saveToFile(std::fstream &f) const {
	return Container::saveToFile(f);
}

bool MyContainer::loadFromFile(std::fstream &f) {
	return Container::loadFromFile(f);
}

void MyContainer::edit(Entry &en) {
	std::deque<Entry>::iterator it = std::find(c.begin(), c.end(), en);
	it->edit();
}

double MyContainer::calcAverageMarkByDiscipline(const std::string query) const {
	AvrMarkByDiscipline calc = AvrMarkByDiscipline(query);
	return calcAverageMark<AvrMarkByDiscipline>(calc);
}

double MyContainer::calcAverageMarkByCourse(const int query) const {
	AvrMarkByCourse calc = AvrMarkByCourse(query);
	return calcAverageMark<AvrMarkByCourse>(calc);
}

double MyContainer::calcAverageMarkByGroup(const std::string query) const {
	AvrMarkByGroup calc = AvrMarkByGroup(query);
	return calcAverageMark<>(calc);
}

