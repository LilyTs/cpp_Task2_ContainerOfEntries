#pragma once
#include "stdafx.h" 
#include "Container.h"
#include "Entry.h"
#include "Predicates.h"

class MyContainer : public Container<Entry>
{
public:
	MyContainer(); 
	MyContainer(std::deque<Entry> cont);
	~MyContainer();
	bool add(const Entry &en);

	MyContainer linSearchByNumOfRecordBook(const int query) const;
	MyContainer linSearchBySurname(const std::string query) const;
	MyContainer linSearchByCourse(const int query) const;
	MyContainer linSearchByGroup(const std::string query) const;
	MyContainer linSearchByMark(const int query) const;

	MyContainer binSearchByNumOfRecordBook(const int query);
	MyContainer binSearchBySurname(const std::string query);
	MyContainer binSearchByCourse(const int query);
	MyContainer binSearchByGroup(const std::string query);
	MyContainer binSearchByMark(const int query);

	void remove(Entry en);
	void outputToConsole() const;
	bool saveToFile(std::fstream &f) const;
	bool loadFromFile(std::fstream &f);
	void edit(Entry &en);

	double calcAverageMarkByDiscipline(const std::string query) const;
	double calcAverageMarkByCourse(const int query) const;
	double calcAverageMarkByGroup(const std::string query) const;
};


