#include "stdafx.h"
#include "string"
#include "MyContainer.h"
#include "Entry.h"


MyContainer<Entry>::MyContainer()
{
}


MyContainer<Entry>::~MyContainer()
{
}

void MyContainer<Entry>::add(const Entry &entry) {
	c.push_back(entry);
}

container& MyContainer<Entry>::linearSearch(const criterion crit, const std::string query) const {
	container res;
	switch(crit){
	case group:
		for each (Entry en in c)
			if (en.getGroup == query)
				res.push_back(en);
		break;
	case surname:
		for each (Entry en in c)
			if (en.getSurname == query)
				res.push_back(en);
		break;
	case course:
		for each (Entry en in c)
			if (en.getCourse == stoi(query))
				res.push_back(en);
		break;
	case numRecBook:
		for each (Entry en in c)
			if (en.getNumOfRecordBook == stoi(query))
				res.push_back(en);
		break;
	case mark:
		for each (Entry en in c)
			if (en.getMark == stoi(query))
				res.push_back(en);
		break;
	}
	return res;
}

container& MyContainer<Entry>::binarySearch(const criterion crit, const std::string query) {
	container res;
	switch (crit) {
	case group:
		sort(c.begin(), c.end(), Entry::cmpGroup);
		cIterator it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpGroup);
		while (it != c.end() && it->getGroup() == query) {
			res.push_back(*it);
			++it;
		}
		break;
	case surname:
		sort(c.begin(), c.end(), Entry::cmpSurname);
		cIterator it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpSurname);
		while (it != c.end() && it->getSurname() == query) {
			res.push_back(*it);
			++it;
		}
		break;
	case course:
		sort(c.begin(), c.end(), Entry::cmpCourse);
		cIterator it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpCourse);
		while (it != c.end() && it->getCourse() == stoi(query)) {
			res.push_back(*it);
			++it;
		}
		break;
	case numRecBook:
		sort(c.begin(), c.end(), Entry::cmpNumRecBook);
		cIterator it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpGroup);
		while (it != c.end() && it->getNumOfRecordBook() == stoi(query)) {
			res.push_back(*it);
			++it;
		}
		break;
	case mark:
		sort(c.begin(), c.end(), Entry::cmpMark);
		cIterator it = std::lower_bound(c.begin(), c.end(), c, Entry::cmpMark);
		while (it != c.end() && it->getMark() == stoi(query)) {
			res.push_back(*it);
			++it;
		}
		break;
	}
	return res;
}

bool MyContainer<Entry>::removeEntry(const Entry &entry) {
	
}

void MyContainer<Entry>::showTitle() const {
	std::cout << "Number of record book  " << "Surname  " << "Course  " << "Group  " << "Discipline  " << "Mark" << std::endl;
}

void MyContainer<Entry>::outputToConsole()  const {

}

bool MyContainer<Entry>::saveToFile(std::fstream &f) const {

}

bool MyContainer<Entry>::edit(Entry &entry) {

}

double MyContainer<Entry>::calculateAverageMark() const {

}

