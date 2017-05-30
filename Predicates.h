#pragma once
#include "stdafx.h"
#include "Entry.h"

class NumOfRecordBookPred
{
protected:
	int num;

public:
	NumOfRecordBookPred(int n);

	bool virtual operator() (Entry en);
};

class SurnamePred
{
protected:
	std::string surname;

public:
	SurnamePred(std::string aSurname);

	bool virtual operator() (Entry en);
};

class CoursePred
{
protected:
	int course;

public:
	CoursePred(int aCourse);

	bool virtual operator() (Entry en);
};

class GroupPred
{
protected:
	std::string group;

public:
	GroupPred(std::string aGroup);

	bool virtual operator() (Entry en);
};

class MarkPred
{
protected:
	int mark;

public:
	MarkPred(int aMark);

	bool virtual operator() (Entry en);
};

