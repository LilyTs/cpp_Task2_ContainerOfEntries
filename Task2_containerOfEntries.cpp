// ������� �.�. 2 ���� 9 ������
/*  ����������� ������ ���� ���������� ��������� � ��������� ����. ��������� ������ ��������� ��������� ����� ��� ���������� 
 *  ������� �������� �������. ��� �������� ������ ���������� ������� ����������� � ����� ������ ������� ���������.
 *  1. ������������� �������� ����������, ��������� � �������� �������� ����������. 
 *  2. ����������� ���� � ����� ��������� ���������� � �������������� ��������� ���������� �� ����� � � ����.
 *  3. ����������� �������� ������ �� �������� ��������� � ������� ������������ ��������� �� �������� ���������. ����������� 
 *  ����� � ���� ���������: �������� ����� � �������� ����� �� ��������������� ����������.
 *  4. ������������� ����� ������������ ������� �� ����� � � ����.
 *  ----------------------------------------------------------------------------------------------------------------------------
 *  ��� �������:
 *  9. ������ � ������� ��������������� ������ �������� ��������� ����������: ����, ��� ������, ������� ��������, ����� ��������
 *  ������, ����������, ������ �� ����������. ����������� ������� ����� �� ����������, �� ������, �� �����. ����� �� ������, �� �����,
 *  �� ������ �������� ������, �� �������, �� �������.
 */

#include "stdafx.h"
#include "EntriesUtils.h"

class Entry
{
private:
	int numOfRecordBook; //����� �������
	std::string surname;
	int course;
	std::string group;
	std::string  discipline;
	int mark;
public:
	Entry()
	{
	}
	Entry(int aNumOfRecordBook, std::string aSurname, int aCourse, std::string aGroup, std::string  aDiscipline, int aMark) {
		numOfRecordBook = aNumOfRecordBook;
		surname = aSurname;
		course = aCourse;
		group = aGroup;
		discipline = aDiscipline;
		mark = aMark;
	}
	~Entry()
	{
	}
};

void printMenu() {
		std::cout << "1 - add entry";
		std::cout << "2 - find entry";
		std::cout << "3 - remove entry";
		std::cout << "4 - output in the console\n";
		std::cout << "5 - save to file\n";
		std::cout << "6 - edit\n";
		std::cout << "7 - calculate average mark\n" << std::endl;
		std::cout << "0 - exit";
}

int inputItem(){
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
Entry& inputEntry() {
	int num;
	std::string surname;
	int course;
	std::string group;
	std::string  discipline;
	int mark;
	std::cout << "  Number of student's record book: ";
	std::cin >> num;
	std::cout << "  Surname: ";
	std::cin >> surname;
	std::cout << "  Course: ";
	std::cin >> course;
	std::cout << "  Group: ";
	std::cin >> group;
	std::cout << "  Discipline: ";
	std::cin >> discipline;
	std::cout << "  Mark: ";
	std::cin >> mark;
	Entry entry(num, surname, course, group, discipline, mark);
	return entry;
}

void doMenuAction() {
	int item;
	container c;
	std::fstream f;

	while ((item = inputItem()) != 0)
	{
		std::string fileName;

		switch (item)
		{
		case 1:
			EntriesUtils<Entry>::add(inputEntry());
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
    return 0;
}

