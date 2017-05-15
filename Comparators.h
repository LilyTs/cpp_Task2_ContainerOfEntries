#pragma once
#include "Entry.h"

class cmpNumOfRecordBook {
public:
	bool operator()(const Entry &en1, const Entry &en2);
};

class cmpSurname {
public:
	bool operator()(const Entry &en1, const Entry &en2);
};

class cmpCourse {
public:
	bool operator()(const Entry &en1, const Entry &en2);
};

class cmpGroup {
public:
	bool operator()(const Entry &en1, const Entry &en2);
};

class cmpMark {
public:
	bool operator()(const Entry &en1, const Entry &en2);
};
