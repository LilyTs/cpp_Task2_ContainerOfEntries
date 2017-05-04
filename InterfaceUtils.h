#pragma once
#include "Entry.h"
#include "Container.h"

//класс, реализующий взаимодействие с пользователем
class InterfaceUtils
{
public:
	InterfaceUtils();
	~InterfaceUtils();
	void printMenu() const;
	int inputMenuItem() const;
	Entry& inputEntry() const;
	int inputCriterionNum() const;
	char inputTypeOfSearch() const;
	std::string inputQuery() const;
	void outputRes(Container<Entry> &res) const;
	Container<Entry>& linOrBinSearch(Container<Entry> &c, const criterion crit) const;
	void find(Container<Entry> &c) const;
	void showTitle() const;
};

