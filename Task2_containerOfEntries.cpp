// Цаплина Л.В. 2 курс 9 группа
/*  Результатом должна быть консольная программа с текстовым меню. Программа должна содержать шаблонный класс для управления 
 *  данными согласно заданию. Для хранения данных необходимо выбрать оптимальный с точки зрения задания контейнер.
 *  1. Предусмотреть операции добавления, изменения и удаления элемента контейнера. 
 *  2. Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл.
 *  3. Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям. Реализовать 
 *  поиск в двух вариантах: линейный поиск и двоичный поиск на отсортированном контейнере.
 *  4. Предусмотреть вывод подмножества выборки на экран и в файл.
 *
 *  Мой вариант:
 *  9. Запись в журнале экзаменационной сессии содержит следующую информацию: курс, код группы, фамилия студента, номер зачетной
 *  книжки, дисциплина, оценка по дисциплине. Вычисляются средние баллы по дисциплине, по группе, по курсу. Поиск по группе, по курсу,
 *  по номеру зачетной книжки, по фамилии, по оценкам.
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

