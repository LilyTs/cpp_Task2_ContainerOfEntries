#pragma once
#include "Entry.h"

//вычисл€ют среднюю оценку

class AvrMarkByDiscipline
{
private:
	std::string discipline;
	int count = 0;
	int sum = 0;
public:
	AvrMarkByDiscipline(const std::string d);
	double getAvrMark();
	void virtual operator()(const Entry en);
};

class AvrMarkByCourse
{
private:
	int course;
	int count = 0;
	int sum = 0;
public:
	AvrMarkByCourse(const int crs);
	double getAvrMark();
	void virtual operator()(const Entry en);
};

class AvrMarkByGroup
{
private:
	std::string group;
	int count = 0;
	int sum = 0;
public:
	AvrMarkByGroup(const std::string grp);
	double getAvrMark();
	void virtual operator()(const Entry en);
};

