// Цаплина Л.В. 2 курс 9 группа
/*  Результатом должна быть консольная программа с текстовым меню. Программа должна содержать шаблонный класс для управления 
 *  данными согласно заданию. Для хранения данных необходимо выбрать оптимальный с точки зрения задания контейнер.
 *  1. Предусмотреть операции добавления, изменения и удаления элемента контейнера. 
 *  2. Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл.
 *  3. Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям. Реализовать 
 *  поиск в двух вариантах: линейный поиск и двоичный поиск на отсортированном контейнере.
 *  4. Предусмотреть вывод подмножества выборки на экран и в файл.
 *  ----------------------------------------------------------------------------------------------------------------------------
 *  Мой вариант:
 *  9. Запись в журнале экзаменационной сессии содержит следующую информацию: курс, код группы, фамилия студента, номер зачетной
 *  книжки, дисциплина, оценка по дисциплине. Вычисляются средние баллы по дисциплине, по группе, по курсу. Поиск по группе, по курсу,
 *  по номеру зачетной книжки, по фамилии, по оценкам.
 */

/*Общий класс Контейнер и специализированный класс MyContainer.
В контейнере вывод на консоль получает поток, файловый ввод/вывод получает поток*/

#include "stdafx.h"
#include <conio.h>
#include "MyContainer.h"
#include "Entry.h"
#include "HelpUtils.h"

Entry& inputEntry(Entry &en) {
	int numRecBook;
	std::string surname;
	int course;
	std::string group;
	std::string discipline;
	int mark;
	std::string msg;

	msg = "  Number of student's record book: ";
	numRecBook = inputIntValue(msg);
	std::cout << "  Surname: ";
	std::cin >> surname;
	msg = "  Course: ";
	course = inputIntValue(msg, 1, 4);
	std::cout << "  Group: ";
	std::cin >> group;
	std::cout << "  Discipline: ";
	std::cin >> discipline;
	msg = "  Mark: ";
	mark = inputIntValue(msg, 2, 5);

	en = Entry(numRecBook, surname, course, group, discipline, mark);
	return en;
}

//текст менюшек и количества пунктов в них
const std::string mainMENU = "\n1 - load from file\n2 - add\n3 - find\n4 - output to console\n5 - save to file\n6 - calculate average mark\n0 - exit\n";
const int cntMainMenuITEMS = 7;

const std::string critForSearchMENU = "\n1 - group\n2 - course\n3 - surname\n4 - number of record book\n5 - mark\n0 - back\n";
const int cntSearchCritITEMS = 6;

const std::string critForAvrMarkMENU = "\n1 - group\n2 - course\n3 - discipline\n0 - back\n";
const int cntMarkCritITEMS = 4;

const std::string findSUBMENU = "1 - remove\n2 - edit\n3 - save to file\n0 - back\n";
const int cntFindSubmenuITEMS = 4;

const std::string removeREQUEST = "What entry do you want to remove? Enter number: ";
const std::string editREQUEST = "What entry do you want to edit? Enter number: ";

int inputItem(const int cntITEMS, const std::string REQUEST) {
	int item;
	bool ok;
	do {
		std::cout << REQUEST << std::endl;
		std::cin >> item;
		ok = (item >= 0) && (item <= cntITEMS - 1);
		if (!ok)
			std::cout << "Incorrect input data." << std::endl;
	} while (!ok);
	std::cout << std::endl;
	return item;
}

char inputTypeOfSearch() {
	char item = 0;
	std::cout << "Linear(L) or binary(B) search? Enter letter: ";
	bool ok;
	do {
		item = _getche();
		ok = (item == 'L') || (item == 'l') || (item == 'B') || (item == 'b');
		if (!ok)
			std::cout << "\nInput error! Repeat:" << std::endl;
	} while (!ok);
	return item;
}

//ввод поискового запроса (искомое значение поля записи)
std::string inputQuery() {
	std::string query;
	do {
		std::cout << "Enter the required field value: ";
		std::cin >> query;
		std::cout << std::endl;
	} while (query == "");
	return query;
}

std::string inputFileName() {
	std::string fileName;
	std::cout << "Enter name of file: ";
	std::cin >> fileName;
	return fileName;
}

//возвращает истину, если результирующий контейнер был выведен (не пустой)
bool outputRes(MyContainer &res) {
	if (!res.empty()) {
		std::cout << "Search results:\n\n";
		res.output(std::cout);
		return true;
	}
	else
		std::cout << "\nNo results" << std::endl;
	return false;
}

//результат != -1
int convertToInt(std::string str) {
	int res = -1;
	while (res == -1) {
		try {
			res = stoi(str);
		}
		catch (std::exception) {
			std::cout << "Input error! Repeat:" << std::endl;
			std::cin >> str;
		}
	}
	return res;
}

MyContainer find(MyContainer &c) {
	switch (inputTypeOfSearch()) {
	case 'L':
	case 'l':
		std::cout << "\n\nSelect criterion of search:\n\n";
		switch (inputItem(cntSearchCritITEMS, critForSearchMENU)) {
		case 1: 
			return c.linSearchByGroup(inputQuery());
			break;
		case 2:
			return c.linSearchByCourse(convertToInt(inputQuery()));
			break;
		case 3:
			return c.linSearchBySurname(inputQuery());
			break;
		case 4:
			return c.linSearchByNumOfRecordBook(convertToInt(inputQuery()));
			break;
		case 5:
			return c.linSearchByMark(convertToInt(inputQuery()));
			break;
		case 0:
			throw "back";
		}
		break;
	case 'B':
	case 'b':
		switch (inputItem(cntSearchCritITEMS, critForSearchMENU)) {
		case 1:
			return c.binSearchByGroup(inputQuery());
			break;
		case 2:
			return c.binSearchByCourse(convertToInt(inputQuery()));
			break;
		case 3:
			return c.binSearchBySurname(inputQuery());
			break;
		case 4:
			return c.binSearchByNumOfRecordBook(convertToInt(inputQuery()));
			break;
		case 5:
			return c.binSearchByMark(convertToInt(inputQuery()));
			break;
		case 0:
			throw "back";
		}
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int item, sz;
	int i = 0;
	std::fstream f;
	MyContainer c = MyContainer();
	MyContainer subset = MyContainer();
	std::deque<Entry>::iterator it;
	Entry en;
	float m = 0;
	std::string str = "";

	while ((item = inputItem(cntMainMenuITEMS, mainMENU)) != cntMainMenuITEMS)
	{
		std::string fileName;

		switch (item)
		{
		case 1: //load data
			f.open(inputFileName(), std::fstream::in);
			c.loadFromFile(f);
			break;
		case 2: //add
			if (c.add(inputEntry(en)))
				std::cout << "Entry has been added." << std::endl;
			else
				std::cout << "Such entry already exists." << std::endl;
			break;
		case 3: //find
			try {
					subset = find(c);
					sz = subset.size();
					if (outputRes(subset)) {
						std::cout << "Select action: \n";
						switch (inputItem(cntFindSubmenuITEMS, findSUBMENU)) {
						case 1: //remove
							if (sz > 1) 
								i = inputItem(subset.size(), removeREQUEST);
							c.remove(subset[i]);
							break;
						case 2: //edit
							if (sz > 1)
								i = inputItem(subset.size(), editREQUEST);
							std::cout << "(Press Enter to skip input of a new value)" << std::endl;
							std::getline(std::cin, str);
							if (!c.edit(subset[i])) {
								std::cout << "\nSuch entry already exists." << std::endl;
							}
							break;
						case 3: //save to file
							f.open(inputFileName(), std::fstream::out);
							if (!subset.saveToFile(f))
								std::cout << "Error of opening file." << std::endl;
							break;
						}
					}
				}
			catch (char* back) { }
		break;
		case 4: //console output
			c.output(std::cout);
			break;
		case 5: //save to file
			f.open(inputFileName(), std::fstream::out);
			if (!c.saveToFile(f))
				std::cout << "Error of opening file." << std::endl;
			break;
		case 6: //calc average mark
			switch (inputItem(cntMarkCritITEMS, critForAvrMarkMENU)) {
			case 1: //group
				m = c.calcAverageMarkByGroup(inputQuery());
				break;
			case 2: //course
				m = c.calcAverageMarkByCourse(convertToInt(inputQuery()));
				break;
			case 3: //discipline
				m = c.calcAverageMarkByDiscipline(inputQuery());
				break;
			}
			if (m != 0)
				std::cout << "\nAverage mark = " << m << std::endl;
			else
				std::cout << "Such entries are not found." << std::endl;
			break;
		case 0:
			exit(0);
		}
	}
    return 0;
}

