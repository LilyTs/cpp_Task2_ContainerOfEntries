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
#include "MyMyContainer.h"
#include "Entry.h"
#include "InterfaceUtils.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int item;
	MyMyContainer<Entry> c;
	std::fstream f;

	while ((item = inputMenuItem()) != 0)
	{
		std::string fileName;

		switch (item)
		{
		case 1:
			c.add(inputEntry());
			std::cout << "Entry has been added." << std::endl;
			break;
		case 2:
			find();
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
    return 0;
}

