#include "stdafx.h"
#include "Entry.h"
#include "HelpUtils.h"

Entry::Entry()
{
	course = 0;
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

std::string Entry::toString() const {
	return std::to_string(numOfRecordBook) + "\t\t\t " + surname + "\t\t" + std::to_string(course) + "\t" + group + "\t" + discipline
		+ "\t\t" + std::to_string(mark);
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

std::ostream& operator<<(std::ostream &os, const Entry &en) {
	os << "Number of record book: " + std::to_string(en.getNumOfRecordBook()) + "\n" +
		"Surname: " + en.getSurname() + "\n" +
		"Course: " + std::to_string(en.getCourse()) + "\n" +
		"Group: " + en.getGroup() + "\n" +
		"Discipline: " + (en.getDiscipline()) + "\n" +
		"Mark: " + std::to_string(en.getMark()) + "\n";
	return os;
}

/*
std::ostream& operator<<(std::ostream &os, const Entry &en) {
	os << en.toString() + "\n";
	return os;
}*/

std::string skipFieldsNames(std::istream &is , std::string fieldName) {
	std::string str;
	std::string substr = " ";
	std::string helpStr;
	getline(is, str);
	int pos = str.find(":");
	if ((pos == -1) && (str != ""))
		throw std::exception();
	else
	{
		helpStr = str.substr(0, pos);
		if (fieldName != helpStr)
			throw std::exception();
		else
		{
			while ((pos <= str.length()) && (substr == " "))
			{
				++pos;
				substr = str[pos];
			}
			if (pos > str.length())
				return "";
			else
			{
				return str.substr(pos);
			}
		}
	}
}

std::istream& operator>>(std::istream &is, Entry &en) {

	en.setNumOfRecordBook(stoi(skipFieldsNames(is, "Number of record book")));
	en.setSurname(skipFieldsNames(is, "Surname"));
	en.setCourse(stoi(skipFieldsNames(is, "Course")));
	en.setGroup(skipFieldsNames(is, "Group"));
	en.setDiscipline(skipFieldsNames(is, "Discipline"));
	en.setMark(stoi(skipFieldsNames(is, "Mark")));
	skipFieldsNames(is, "");
	return is;
}