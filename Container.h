#pragma once
#include "stdafx.h" 

//typedef std::deque<Entry>::iterator cIterator;

template<class Entry>
class Container
{
public:
	std::deque<Entry> c;
	Container();
	~Container();
	bool add(const Entry &en);
	Container<Entry>& linearSearch(const fieldName crit, const std::string query, Container<Entry> &res) const;
	Container<Entry>& binarySearch(const fieldName crit, const std::string query, Container<Entry> &res);
	void remove(Entry &en);
	void outputToConsole() const;
	bool saveToFile(std::string fileName) const;
	//bool loadFromfile(std::string fileName);
	void edit(Entry &en);
	double calcAverageMark(fieldName crit, const std::string query) const;
};


