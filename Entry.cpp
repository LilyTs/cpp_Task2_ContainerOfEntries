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

std::ostream& Entry::operator<<(std::ostream &os) {
	os << this->toString();
	return os;
}

bool Entry::operator==(const Entry &en) const {
	return
		this->numOfRecordBook == en.getNumOfRecordBook() &&
		this->surname == en.getSurname() &&
		this->course == en.getCourse() &&
		this->group == en.getGroup() &&
		this->discipline == en.getDiscipline() &&
		this->mark == en.getMark();
}

bool Entry::operator!=(const Entry &en) const {
	return !(*this == en);
}

void Entry::edit() {
	std::string s;
	std::cout << "Number of record book (current value = " << this->getNumOfRecordBook() << "): ";
	std::cin >> s;
	if (s != "")
		this->setNumOfRecordBook(stoi(s));
	std::cout << "Surname (current value = " << this->getSurname() << "): ";
	std::cin >> s;
	if (s != "")
		this->setSurname(s);
	std::cout << "Course (current value = " << this->getCourse() << "): ";
	std::cin >> s;
	if (s != "")
		this->setCourse(stoi(s));
	std::cout << "Group (current value = " << this->getGroup() << "): ";
	std::cin >> s;
	if (s != "")
		this->setGroup(s);
	std::cout << "Discipline (current value = " << this->getDiscipline() << "): ";
	std::cin >> s;
	if (s != "")
		this->setDiscipline(s);
	std::cout << "Mark (current value = " << this->getMark() << "): ";
	std::cin >> s;
	if (s != "")
		this->setMark(stoi(s));
}


//аксессоры

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
