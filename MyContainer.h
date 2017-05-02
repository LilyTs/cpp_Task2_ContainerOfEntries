#pragma once
#include "stdafx.h" 

template<class Entry>
class MyContainer
{
private:
	void showTitle() const;
public:
	typedef std::deque<Entry>::iterator cIterator;
	std::deque<Entry> c;
	MyContainer();
	~MyContainer();
	void add(const Entry &entry);
	container& linearSearch(const criterion crit, const std::string query) const;
	container& binarySearch(const criterion crit, const std::string query);
	bool removeEntry(const Entry &entry);
	void outputToConsole() const;
	bool saveToFile(std::fstream &f) const;
	bool edit(Entry &entry);
	double calculateAverageMark() const;
};

