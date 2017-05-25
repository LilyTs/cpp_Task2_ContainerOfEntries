#pragma once
#include "stdafx.h" 

template<class Entry>
class Container
{
public:
	std::deque<Entry> c;
	Container();
	~Container();
	bool add(const Entry &en);
	Container<Entry>& linearSearch(const fieldName crit, const std::string query, Container<Entry> &res) const;
	Container<Entry>& binarySearch(const fieldName crit, std::string query, Container<Entry> &res);
	void remove(Entry en);
	void outputToConsole() const;
	bool saveToFile(std::string fileName) const;
	bool loadFromFile(const std::string fileName);
	void edit(Entry &en);
	double calcAverageMark(fieldName crit, const std::string query) const;
};


