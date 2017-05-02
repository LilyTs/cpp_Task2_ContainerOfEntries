#include "stdafx.h"
#include "Entry.h"


Entry::Entry()
{
}

Entry::~Entry()
{
}

Entry::Entry(int aNumOfRecordBook, std::string aSurname, int aCourse, std::string aGroup, std::string  aDiscipline, int aMark) {
	numOfRecordBook = aNumOfRecordBook;
	surname = aSurname;
	course = aCourse;
	group = aGroup;
	discipline = aDiscipline;
	mark = aMark;
}

std::string Entry::toString() {
	return std::to_string(numOfRecordBook) + "\t" + surname + "\t" + std::to_string(course) + "\t" + group + "\t" + discipline
		+ "\t" + std::to_string(mark);
}

//компараторы, обеспечивающие сравнение записей журнала по различным полям

bool Entry::cmpSurname(const Entry &en1, const Entry &en2) {
	return en1.surname < en2.surname;
}

bool Entry::cmpCourse(const Entry &en1, const Entry &en2) {
	return en1.course < en2.course;
}

bool Entry::cmpGroup(const Entry&en1, const Entry &en2) {
	return en1.group < en2.group;
}

bool Entry::cmpNumRecBook(const Entry &en1, const Entry &en2) {
	return en1.numOfRecordBook < en2.numOfRecordBook;
}

bool Entry::cmpMark(const Entry &en1, const Entry &en2) {
	return en1.mark < en2.mark;
}

const int Entry::getNumOfRecordBook() const {
	return numOfRecordBook;
}

const std::string Entry::getSurname() const {
	return surname;
}

const int Entry::getCourse() const {
	return course;
}

const std::string Entry::getGroup() const {
	return group;
}

const std::string Entry::getDiscipline() const {
	return discipline;
}

const int Entry::getMark() const {
	return mark;
}

void Entry::setNumOfRecordBook(const int value) {
	numOfRecordBook = value;
}

void Entry::setSurname(const std::string value) {
	surname = value;
}

void Entry::setCourse(const int value) {
	course = value;
}

void Entry::setGroup(const std::string value) {
	group = value;
}

void Entry::setDiscipline(const std::string value) {
	discipline = value;
}

void Entry::setMark(const int value) {
	mark = value;
}
