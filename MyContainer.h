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

	bool edit(Entry &en);
	std::deque<Entry>::iterator begin();
	std::deque<Entry>::iterator end();

	float calcAverageMarkByDiscipline(const std::string query) const;
	float calcAverageMarkByCourse(const int query) const;
	float calcAverageMarkByGroup(const std::string query) const;
};


