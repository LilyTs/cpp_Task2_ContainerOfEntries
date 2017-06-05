#include "stdafx.h"
#include "string"
#include "Container.h"
#include "MyContainer.h"
#include "Entry.h"
#include "HelpUtils.h"
#include "Comparators.h"
#include "Collectors.h"
#include "CalculatorAvrMark.h"

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

void MyContainer::edit(Entry &en) {
	std::deque<Entry>::iterator it = std::find(c.begin(), c.end(), en);
	inputEditedEntry(*it);
}

float MyContainer::calcAverageMarkByDiscipline(const std::string query)const {
	DisciplineCollector coll = DisciplineCollector(query);
	MyContainer cont = MyContainer(linearSearch(coll));

	if (!cont.empty()) {
		AvrMark calc = AvrMark(cont.size());
		for (auto el : cont)
			calc(el);
		return calc.getAvrMark();
	}
	return 0;
}

float MyContainer::calcAverageMarkByCourse(const int query) const {
	CourseCollector coll = CourseCollector(query);
	MyContainer cont = MyContainer(linearSearch(coll));
	
	if (!cont.empty()) {
		AvrMark calc = AvrMark(cont.size());
		for (auto el : cont)
			calc(el);
		return calc.getAvrMark();
	}
	return 0;
}

float MyContainer::calcAverageMarkByGroup(const std::string query) const {
	GroupCollector coll = GroupCollector(query);
	MyContainer cont = MyContainer(linearSearch(coll));

	if (!cont.empty()) {
		AvrMark calc = AvrMark(cont.size());
		for (auto el : cont)
			calc(el);
		return calc.getAvrMark();
	}
	return 0;
}

std::deque<Entry>::iterator MyContainer::begin() {
	return c.begin();
}

std::deque<Entry>::iterator MyContainer::end() {
	return c.end();
}

