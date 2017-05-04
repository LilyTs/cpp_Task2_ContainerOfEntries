#include "stdafx.h"
//#include <boost/algorithm/string/trim.hpp>
#include "InterfaceUtils.h"


InterfaceUtils::InterfaceUtils()
{
}


InterfaceUtils::~InterfaceUtils()
{
}

void InterfaceUtils::printMenu() const {
	std::cout << "1 - add";
	std::cout << "2 - find";
	std::cout << "3 - remove";
	std::cout << "4 - output in the console\n";
	std::cout << "5 - save to file\n";
	std::cout << "6 - edit\n";
	std::cout << "7 - calculate average mark\n" << std::endl;
	std::cout << "0 - exit";
}

void InterfaceUtils::showTitle() const {
	std::cout << "Number of record book  " << "Surname  " << "Course  " << "Group  " << "Discipline  " << "Mark" << std::endl;
}

int InterfaceUtils::inputMenuItem() const {
	printMenu();
	int i;
	bool ok;
	do {
		std::cout << "Enter the menu item number: ";
		std::cin >> i;
		ok = (i >= 0 && i <= 7);
		if (!ok) {
			std::cout << "Error! Incorrect input data.\n" << std::endl;
		}
	} while (!ok);
	return i;
}

//exception?? Need to handle incorrect input
Entry& InterfaceUtils::inputEntry() const {
	Entry en;
	int intVal;
	std::string strVal;
	std::cout << "  Number of student's record book: ";
	std::cin >> intVal;
	en.setNumOfRecordBook(intVal);
	std::cout << "  Surname: ";
	std::cin >> strVal;
	en.setSurname(strVal);
	std::cout << "  Course: ";
	std::cin >> intVal;
	en.setCourse(intVal);
	std::cout << "  Group: ";
	std::cin >> strVal;
	en.setGroup(strVal);
	std::cout << "  Discipline: ";
	std::cin >> strVal;
	en.setDiscipline(strVal);
	std::cout << "  Mark: ";
	std::cin >> intVal;
	en.setMark(intVal);
	return en;
}

int InterfaceUtils::inputCriterionNum() const {
	int item;
	bool ok;
	do {
		std::cout << "\n1 - group";
		std::cout << "\n2 - course";
		std::cout << "\n3 - surname";
		std::cout << "\n4 - number student's record book";
		std::cout << "\n5 - mark";
		std::cout << "Enter the criterion number: ";
		std::cin >> item;
		ok = (item >= 1) && (item <= 5);
	} while (!ok);
	return item;
}

char InterfaceUtils::inputTypeOfSearch() const {
	char item;
	bool ok;
	do {
		std::cout << "Linear(L) or binary(B) search? Enter letter: ";
		std::cin >> item;
		ok = (item == 'L') || (item == 'l') || (item == 'B') || (item == 'b');
	} while (!ok);
	return item;
}

//ввод поискового запроса (искомое значение поля записи)
std::string InterfaceUtils::inputQuery() const {
	std::string query;
	do {
		std::cout << "Enter the required field value: ";
		std::cin >> query;
	} while (query == "");
	return /*boost::algorithm::trim()*/query;
}

void InterfaceUtils::outputRes(Container<Entry> &res) const {
	if (!res.c.empty())
		for each (Entry en in res.c)
		{
			std::cout << en.toString();
		}
	else
		std::cout << "No results";
}



Container<Entry>& InterfaceUtils::linOrBinSearch(Container<Entry> &c, const criterion crit) const {
	Container<Entry> res;
	switch (inputTypeOfSearch()) {
	case 'L':
	case'l':
		res.c = c.linearSearch(crit, inputQuery());
		break;
	case 'B':
	case 'b':
		res = c.binarySearch(crit, inputQuery());
		break;
	}

	return res;
}

//как возвращать множество - через параметр или return, что вернет если ничего не найдено
Container<Entry>& InterfaceUtils::find(Container<Entry> &c) const {
	switch (inputCriterionNum()) {
	case 1:
		return(linOrBinSearch(c, group));
		break;
	case 2:
		return(linOrBinSearch(c, course));
		break;
	case 3:
		return(linOrBinSearch(c, surname));
		break;
	case 4:
		return(linOrBinSearch(c, numRecBook));
		break;
	case 5:
		return(linOrBinSearch(c, mark));
		break;
	}
}


