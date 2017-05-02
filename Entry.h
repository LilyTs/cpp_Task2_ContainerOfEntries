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
	//компараторы, обеспечивающие сравнение записей журнала по различным полям
	bool cmpSurname(const Entry &en1, const Entry &en2);
	bool cmpCourse(const Entry &en1, const Entry &en2);
	bool cmpGroup(const Entry&en1, const Entry &en2);
	bool cmpNumRecBook(const Entry &en1, const Entry &en2);
	bool cmpMark(const Entry &en1, const Entry &en2);

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

