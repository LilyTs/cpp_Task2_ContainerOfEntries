#pragma once
#include "stdafx.h"

template<class Entry>
class EntriesUtils
{
private:
	static container c;
public:
	EntriesUtils();
	~EntriesUtils();
	static void add(const Entry &entry);
	bool find(const container &subset);
	bool removeEntry(const Entry &entry);
	void outputToConsole(const container &c);
	bool saveToFile(const container &c, std::fstream &f);
	bool edit(Entry &entry);
	double calculateAverageMark(const container &c);
};

