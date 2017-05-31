#pragma once
#include "Entry.h"
#include "MyContainer.h"

//выдел€ют коллекцию записей с требуемым значением пол€  фамили€ курс группа оценка

class NumOfRecordBookCollector
{
private:
	int numOfRecordBook;
	std::deque<Entry> *c;

public:
	NumOfRecordBookCollector(const int num);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};

class SurnameCollector
{
private:
	std::string surname;
	std::deque<Entry> *c;

public:
	SurnameCollector(const std::string s);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};

class CourseCollector
{
private:
	int course;
	std::deque<Entry> *c;

public:
	CourseCollector(const int crs);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};

class GroupCollector
{
private:
	std::string group;
	std::deque<Entry> *c;

public:
	GroupCollector(const std::string grp);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};

class MarkCollector
{
private:
	int mark;
	std::deque<Entry> *c;

public:
	MarkCollector(const int m);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};

class DisciplineCollector
{
private:
	std::string discipline;
	std::deque<Entry> *c;

public:
	DisciplineCollector(const std::string d);
	std::deque<Entry> getCollection();
	void virtual operator()(const Entry en);
};
