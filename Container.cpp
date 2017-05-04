#include "stdafx.h"
#include "string"
#include "Container.h"
#include "Entry.h"


Container<Entry>::Container()
{
}


Container<Entry>::~Container()
{
}

void Container<Entry>::add(const Entry &entry) {
	c.push_back(entry);
}

/*cIterator find(const criterion crit, const std::string query) const {
	switch (crit) {
	case group:
		break;
	case course:
		break;
	case surname:
		break;

	}
}*/

Container<Entry>& Container<Entry>::linearSearch(const criterion crit, const std::string query) const {
	Container res;
	switch(crit){
	case group:
		for each (Entry en in c)
			if (en.getGroup == query)
				res.c.push_back(en);
		break;
	case surname:
		for each (Entry en in c)
			if (en.getSurname == query)
				res.c.push_back(en);
		break;
	case course:
		for each (Entry en in c)
			if (en.getCourse == stoi(query))
				res.c.push_back(en);
		break;
	case numRecBook:
		for each (Entry en in c)
			if (en.getNumOfRecordBook == stoi(query))
				res.c.push_back(en);
		break;
	case mark:
		for each (Entry en in c)
			if (en.getMark == stoi(query))
				res.c.push_back(en);
		break;
	}
	return res;
}



Container<Entry>& Container<Entry>::binarySearch(const criterion crit, const std::string query) {
	Container<Entry> res;
	cIterator it;
	switch (crit) {
	case group:
		sort(c.begin(), c.end(), Entry::cmpGroup);
		it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpGroup);
		while (it != c.end() && it->getGroup() == query) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case surname:
		sort(c.begin(), c.end(), Entry::cmpSurname);
		it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpSurname);
		while (it != c.end() && it->getSurname() == query) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case course:
		sort(c.begin(), c.end(), Entry::cmpCourse);
		it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpCourse);
		while (it != c.end() && it->getCourse() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case numRecBook:
		sort(c.begin(), c.end(), Entry::cmpNumRecBook);
		it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpGroup);
		while (it != c.end() && it->getNumOfRecordBook() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	case mark:
		sort(c.begin(), c.end(), Entry::cmpMark);
		it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpMark);
		while (it != c.end() && it->getMark() == stoi(query)) {
			res.c.push_back(*it);
			++it;
		}
		break;
	}
	return res;
}

bool Container<Entry>::remove(const Container &subset) {
	//std::remove_if(c.begin(), c.end(), [&]() {this->c});
	
}

bool Container<Entry>::remove(cIterator &it) {

}

void Container<Entry>::outputToConsole()  const {
	for each(Entry entry in c) {
		std::cout << entry.toString() << "\n";
	}
}

bool Container<Entry>::saveToFile(std::fstream &f) const {
	for each(Entry entry in c) {
		f << entry.toString();
	}
}

bool Container<Entry>::edit(cIterator &it) {

}

double Container<Entry>::calcAverageMark(const criterion crit, const std::string query) const {
	int sum = 0;
	int count = 0;
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
		int valCourse = stoi(query);
		for each(Entry en in c) {
			if (en.getCourse() == valCourse) {
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

