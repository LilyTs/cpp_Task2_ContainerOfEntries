#include "stdafx.h"
#include "EntriesUtils.h"


EntriesUtils<Entry>::EntriesUtils()
{
}


EntriesUtils<Entry>::~EntriesUtils()
{
}

void EntriesUtils<Entry>::add(const Entry &entry) {
	c.push_back(entry);
}

bool EntriesUtils<Entry>::find(const container &subset) {

}

bool EntriesUtils<Entry>::removeEntry(const Entry &entry) {

}

void EntriesUtils<Entry>::outputToConsole(const container &c) {

}

bool EntriesUtils<Entry>::saveToFile(const container &c, std::fstream &f) {

}

bool EntriesUtils<Entry>::edit(Entry &entry) {

}

double EntriesUtils<Entry>::calculateAverageMark(const container &c) {

}

