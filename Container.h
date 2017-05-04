#pragma once
#include "stdafx.h" 

//typedef std::deque<Entry>::iterator cIterator;

template<class Entry>
class Container
{
public:
	typedef std::deque<Entry>::iterator cIterator;
	std::deque<Entry> c;
	Container();
	~Container();
	void add(const Entry &entry);
	cIterator findFirst(const criterion crit, const std::string query) const;
	Container<Entry>& linearSearch(const criterion crit, const std::string query) const;
	Container<Entry>& binarySearch(const criterion crit, const std::string query);
	bool remove(const Container &subset);
	bool remove(cIterator &it);
	void outputToConsole() const;
	bool saveToFile(std::fstream &f) const;
	bool edit(cIterator &it);
	double calcAverageMark(criterion crit, const std::string query) const;
};

