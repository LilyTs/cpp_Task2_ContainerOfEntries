#include "stdafx.h"
#include "string"
#include "Container.h"
#include "Entry.h"
#include "Comparators.h"


Container<Entry>::Container()
{
	c = std::deque<Entry>();
}


Container<Entry>::~Container()
{
}

bool Container<Entry>::add(const Entry &en) {
	if (std::find(c.begin(), c.end(), en) == c.end()) {
	c.push_back(en); 
		return true;
	}
	return false;
}

Container<Entry>& Container<Entry>::linearSearch(const fieldName crit, const std::string query) const {
	Container res;
	switch(crit){
	case group:
		for each (Entry en in c)
			if (en.getGroup() == query)
				res.c.push_back(en);
		break;
	case surname:
		for each (Entry en in c)
			if (en.getSurname() == query)
				res.c.push_back(en);
		break;
	case course:
		for each (Entry en in c)
			if (en.getCourse() == stoi(query))
				res.c.push_back(en);
		break;
	case numRecBook:
		for each (Entry en in c)
			if (en.getNumOfRecordBook() == stoi(query))
				res.c.push_back(en);
		break;
	case mark:
		for each (Entry en in c)
			if (en.getMark() == stoi(query))
				res.c.push_back(en);
		break;
	}
	return res;
}



Container<Entry>& Container<Entry>::binarySearch(const fieldName crit, const std::string query) {
	Container<Entry> res;
	std::deque<Entry>::iterator it;
	Entry en;
	cmpNumOfRecordBook cmpN = cmpNumOfRecordBook();
	switch (crit) {
	case group:
		cmpGroup cmpGr = cmpGroup();
		std::sort(c.begin(), c.end(), cmpGr);
		en = Entry(0, "", 0, query, "", 0);
		it = std::lower_bound(c.begin(), c.end(), en, cmpGr);
		while (it != c.end() && it->getGroup() == query) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case surname:
		cmpSurname cmpSrn = cmpSurname();
		std::sort(c.begin(), c.end(), cmpSrn);
		en = Entry(0, query, 0, "", "", 0);
		it = std::lower_bound(c.begin(), c.end(), en, cmpSrn);
		while (it != c.end() && it->getSurname() == query) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case course:
		cmpCourse cmpCrs = cmpCourse();
		std::sort(c.begin(), c.end(), cmpCrs);
		en = Entry(0, "", stoi(query), query, "", 0);
		it = std::lower_bound(c.begin(), c.end(), en, cmpCrs);
		while (it != c.end() && it->getCourse() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case numRecBook:
		//cmpNumOfRecordBook cmpN = cmpNumOfRecordBook();
		std::sort(c.begin(), c.end(), cmpN);
		en = Entry(stoi(query), "", 0, query, "", 0);
		it = std::lower_bound(c.begin(), c.end(), en, cmpN);
		while (it != c.end() && it->getNumOfRecordBook() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case mark:
		cmpMark cmpM = cmpMark();
		std::sort(c.begin(), c.end(), cmpM);
		en = Entry(0, "", 0, query, "", stoi(query));
		it = std::lower_bound(c.begin(), c.end(), en, cmpM);
		while (it != c.end() && it->getMark() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	}
	return res;
}

void Container<Entry>::remove(Entry &en) {
	std::remove(c.begin(), c.end(), en);
}

void Container<Entry>::outputToConsole()  const {
	for each(Entry entry in c) {
		std::cout << entry.toString() << "\n";
	}
}

bool Container<Entry>::saveToFile(const std::string fileName) const {
	std::fstream f(fileName, std::ios::out);
	if (f.is_open()) {
		copy(c.begin(), c.end(), std::ostream_iterator<Entry>(f, "\n"));
		f.close();
		return true;
	}
	return false;
}

bool Container<Entry>::loadFromfile(const std::string fileName) {
	std::fstream f(fileName, std::ios::in);
	if (f.is_open()) {
		std::istream_iterator<Entry> is(f);
		c.clear();
		++is;  //skip title
		Entry en = *is;
		add(en);
		while (!f.fail() && !f.eof()) {
			try {
				++is;
				en = *is;
				add(en);
			}
			catch (std::exception) {};
		}
		f.close();
		return true;
	}
	return false;
}

void Container<Entry>::edit(Entry &en) {
	std::deque<Entry>::iterator it = find(c.begin(), c.end(), en);
	en.edit();
}

double Container<Entry>::calcAverageMark(const fieldName crit, const std::string query) const {
	int sum = 0;
	int count = 0;
	int intVal;
	switch(crit){
	case group:
		for each(Entry en in c) {
			if (en.getGroup() == query) {
				sum += en.getMark();
				++count;
			}
		}
		break;
	case course:
		intVal = stoi(query);
		for each(Entry en in c) {
			if (en.getCourse() == intVal) {
				sum += en.getMark();
				++count;
			}
		}
		break;
	case discipline:
		for each(Entry en in c) {
			if (en.getDiscipline() == query) {
				sum += en.getMark();
				++count;
			}
		}
		break;
	}
	return sum / count;
}

