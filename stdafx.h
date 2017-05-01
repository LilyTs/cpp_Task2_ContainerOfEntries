// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <iostream>
#include <deque>
#include <iterator>  
#include <sstream>
#include <algorithm>
#include <fstream>

typedef Entry value_type;
typedef std::deque<value_type> container;
typedef std::deque<value_type>::iterator cIterator;

class Entry
{
private:
	int numOfRecordBook; //����� �������
	std::string FIO;
	int course;
	std::string group;
	std::string  discipline;
	int mark;
public:
	Entry()
	{
	}
	Entry(int aNumOfRecordBook, std::string aFIO, int aCourse, std::string aGroup, std::string  aDiscipline, int aMark) {
	}
	~Entry()
	{
	}
};

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
