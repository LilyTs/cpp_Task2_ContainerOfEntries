#pragma once
#include "Entry.h"

class cmpNumOfRecordBook {
	bool operator()(const Entry &en1, const Entry &en2);
}

class cmpSurname {
	bool operator()(const Entry &en1, const Entry &en2);
}

class cmpCourse {
	bool operator()(const Entry &en1, const Entry &en2);
}

class cmpGroup {
	bool operator()(const Entry &en1, const Entry &en2);
}

class cmpMark {
	bool operator()(const Entry &en1, const Entry &en2);
}
