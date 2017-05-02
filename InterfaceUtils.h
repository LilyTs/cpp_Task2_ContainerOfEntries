#pragma once
#include "Entry.h"
#include "MyContainer.h"

//�����, ����������� �������������� � �������������
class InterfaceUtils
{
public:
	InterfaceUtils();
	~InterfaceUtils();
	void printMenu();
	int inputMenuItem();
	Entry& inputEntry();
	int inputCriterionNum();
	char inputTypeOfSearch();
	std::string inputQuery();
	void outputRes(container &res);
	void linOrBinSearch(const criterion crit);
	void find();
};

