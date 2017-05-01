// ������� �.�. 2 ���� 9 ������
/*  ����������� ������ ���� ���������� ��������� � ��������� ����. ��������� ������ ��������� ��������� ����� ��� ���������� 
 *  ������� �������� �������. ��� �������� ������ ���������� ������� ����������� � ����� ������ ������� ���������.
 *  1. ������������� �������� ����������, ��������� � �������� �������� ����������. 
 *  2. ����������� ���� � ����� ��������� ���������� � �������������� ��������� ���������� �� ����� � � ����.
 *  3. ����������� �������� ������ �� �������� ��������� � ������� ������������ ��������� �� �������� ���������. ����������� 
 *  ����� � ���� ���������: �������� ����� � �������� ����� �� ��������������� ����������.
 *  4. ������������� ����� ������������ ������� �� ����� � � ����.
 *
 *  ��� �������:
 *  9. ������ � ������� ��������������� ������ �������� ��������� ����������: ����, ��� ������, ������� ��������, ����� ��������
 *  ������, ����������, ������ �� ����������. ����������� ������� ����� �� ����������, �� ������, �� �����. ����� �� ������, �� �����,
 *  �� ������ �������� ������, �� �������, �� �������.
 */

#include "stdafx.h"
#include "Entry.h"

typedef Entry value_type;
typedef std::deque<value_type> container;
typedef std::deque<value_type>::iterator cIterator;

void printMenu() {
		std::cout << "1 - add entry";
		std::cout << "2 - find entry";
		std::cout << "3 - remove entry";
		std::cout << "4 - output in the console\n";
		std::cout << "5 - save to file\n";
		std::cout << "6 - find and edit\n";
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

