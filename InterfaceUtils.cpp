#include "stdafx.h"
//#include <boost/algorithm/string/trim.hpp>
#include "InterfaceUtils.h"


InterfaceUtils::InterfaceUtils()
{
}


InterfaceUtils::~InterfaceUtils()
{
}

void InterfaceUtils::printMenu() {
	std::cout << "1 - add entry";
	std::cout << "2 - find entry";
	std::cout << "3 - remove entry";
	std::cout << "4 - output in the console\n";
	std::cout << "5 - save to file\n";
	std::cout << "6 - edit\n";
	std::cout << "7 - calculate average mark\n" << std::endl;
	std::cout << "0 - exit";
}

int InterfaceUtils::inputMenuItem() {
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
Entry& InterfaceUtils::inputEntry() {
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
	std::cin >> en.group;
	std::cout << "  Discipline: ";
	std::cin >> en.discipline;
	std::cout << "  Mark: ";
	std::cin >> en.mark;
	return en;
}

int InterfaceUtils::inputCriterionNum() {
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

char InterfaceUtils::inputTypeOfSearch() {
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
std::string InterfaceUtils::inputQuery() {
	std::string query;
	do {
		std::cout << "Enter the required field value: ";
		std::cin >> query;
	} while (query == "");
	return /*boost::algorithm::trim()*/query;
}

void InterfaceUtils::outputRes(container &res) {
	if (!res.empty())
		for each (Entry en in res)
		{
			std::cout << en.toString();
		}
	else
		std::cout << "No results";
}



void InterfaceUtils::linOrBinSearch(const criterion crit) {
	container foundEntries;
	switch (inputTypeOfSearch()) {
	case 'L':
	case'l':
		foundEntries = MyContainer<Entry>::linearSearch(crit, inputQuery());
		break;
	case 'B':
	case 'b':
		sort(EntriesUtils<Entry>::c.begin(), EntriesUtils<Entry>::c.end(), Entry::cmpGroup);
		foundEntries = EntriesUtils<Entry>::binarySearch(crit, inputQuery());
		break;
	}

	outputRes(foundEntries);
}

//как возвращать множество - через параметр или return, что вернет если ничего не найдено
void InterfaceUtils::find() {
	switch (inputCriterionNum()) {
	case 1:
		linOrBinSearch(group);
		break;
	case 2:
		linOrBinSearch(course);
		break;
	case 3:
		linOrBinSearch(surname);
		break;
	case 4:
		linOrBinSearch(numRecBook);
		break;
	case 5:
		linOrBinSearch(mark);
		break;
	}
}
