#include "stdafx.h"
#include "Predicates.h"


NumOfRecordBookPred::NumOfRecordBookPred(int n)
{
	num = n;
}

bool NumOfRecordBookPred::operator() (Entry en)
{
	return en.getNumOfRecordBook() == num;
}

SurnamePred::SurnamePred(std::string aSurname)
{
	surname = aSurname;
}

bool SurnamePred::operator () (Entry en)
{
	return en.getSurname() == surname;
}

CoursePred::CoursePred(int aCourse)
{
	course = aCourse;
}

bool CoursePred::operator() (Entry en)
{
	return en.getCourse() == course;
}

GroupPred::GroupPred(std::string aGroup)
{
	group = aGroup;
}

bool GroupPred::operator() (Entry en)
{
	return en.getGroup() == group;
}

MarkPred::MarkPred(int aMark)
{
	mark = aMark;
}

bool MarkPred::operator() (Entry en)
{
	return en.getMark() == mark;
}
