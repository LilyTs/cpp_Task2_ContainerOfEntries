#pragma once
#include "stdafx.h"

//запись в журнале экзаменационной сессии
class Entry
{
private:
	int numOfRecordBook; //номер зачетки
	std::string surname;
	int course;
	std::string group;
	std::string  discipline;
	int mark;
public:
	Entry();
	Entry(int aNumOfRecordBook, std::string aSurname, int aCourse, std::string aGroup, std::string  aDiscipline, int aMark);
	~Entry();
	std::string toString();
	bool operator==(const Entry &en) const;
	bool operator!=(const Entry &en) const;
	void edit();
	const int getNumOfRecordBook() const;
	const std::string getSurname() const;
	const int getCourse() const;
	const std::string getGroup() const;
	const std::string getDiscipline() const;
	const int getMark() const;

	void setNumOfRecordBook(const int value);
	void setSurname(const std::string value);
	void setCourse(const int value);
	void setGroup(const std::string value);
	void setDiscipline(const std::string value);
	void setMark(const int value);
};

std::ostream& operator<<(std::ostream &os, const Entry &en);
std::istream& operator>>(std::istream &is, Entry &en);
std::string skipFieldsNames(std::istream &is);
