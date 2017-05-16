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

#include "stdafx.h"
#include "Container.h"
#include "Entry.h"
#include "UInterface.h"

void showTitle() {
	std::cout << "Number of record book  " << "Surname  " << "Course  " << "Group  " << "Discipline  " << "Mark" << std::endl;
}

int inputIntValue() {
	std::string str;
	int res;

	try {
		std::cin >> str;
		res = stoi(str);
	}
	catch (std::exception) {
		std::cout << " Input error.\n Repeat: " << std::endl;
		//res = inputIntValue();
	}

	return res;
}

Entry& inputEntry() {
	int numRecBook;
	std::string surname;
	int course;
	std::string group;
	std::string discipline;
	int mark;
	std::string str;

	std::cout << "  Number of student's record book: ";
	numRecBook = inputIntValue();
	std::cout << "  Surname: ";
	//std::cin >> surname;
	std::getline(std::cin, surname);
	std::cout << "  Course: ";
	course = inputIntValue();
	std::cout << "  Group: ";
	//std::cin >> group;
	std::getline(std::cin, group);
	std::cout << "  Discipline: ";
	//std::cin >> discipline;
	std::getline(std::cin, discipline);
	std::cout << "  Mark: ";
	mark = inputIntValue();

	return Entry(numRecBook, surname, course, group, discipline, mark);
}

//текст менюшек и количества пунктов в них
const std::string mainMENU = "\n1 - load from file2 - add\n3 - find\n4 - remove\n5 - edit\n6 - output to console\n7 - save to file\n8 - calculate average mark\n8 - exit\n";
const int cntMainMenuITEMS = 8;

const std::string critForSearchMENU = "\n1 - group\n2 - course\n3 - surname\n4 - number student's record book\n5 - mark\n6 - back";
const int cntSearchCritITEMS = 5;

const std::string critForAvrMarkMENU = "\n1 - group\n2 - course\n3 - discipline\n4 - back";
const int cntMarkCritITEMS = 3;

const std::string removeREQUEST = "What entry do you want to remove? Enter number: \n";
const std::string editREQUEST = "What entry do you want to edit? Enter number: \n";

int inputItem(const int cntITEMS, const std::string REQUEST) {
	int item;
	bool ok;
	do {
		std::cout << REQUEST << std::endl;
		std::cin >> item;
		ok = (item >= 1) && (item <= cntITEMS);
		if (!ok)
			std::cout << "Incorrect input data." << std::endl;
	} while (!ok);
	return item;
}

//int inputIntValue(const std::string message, const int min, const int max)

char inputTypeOfSearch() {
	char item;
	bool ok;
	do {
		std::cout << "Linear(L) or binary(B) search? Enter letter: ";
		std::cin >> item;
		ok = (item == 'L') || (item == 'l') || (item == 'B') || (item == 'b');
	} while (!ok);
	return item;
}

//ввод поискового запроса (искомое значение поля записи)
std::string inputQuery() {
	std::string query;
	do {
		std::cout << "Enter the required field value: ";
		std::cin >> query;
	} while (query == "");
	return /*boost::algorithm::trim()*/query;
}

//возвращает истину, если результирующий контейнер был выведен
bool outputRes(Container<Entry> &res) {
	showTitle();
	if (!res.c.empty())
		for each (Entry en in res.c)
		{
			std::cout << en.toString() << std::endl;
			return true;
		}
	else
		std::cout << "No results" << std::endl;
	return false;
}

void find(Container<Entry> &c, Container<Entry> &res) {
	switch (inputTypeOfSearch()) {
	case 'L':
	case'l':
		switch (inputItem(cntSearchCritITEMS, critForSearchMENU)) {
		case 1:
			res = c.linearSearch(group, inputQuery());
			break;
		case 2:
			res = c.linearSearch(course, inputQuery());
			break;
		case 3:
			res = c.linearSearch(surname, inputQuery());
			break;
		case 4:
			res = c.linearSearch(numRecBook, inputQuery());
			break;
		case 5:
			res = c.linearSearch(mark, inputQuery());
			break;
		}
		break;
	case 'B':
	case 'b':
		switch (inputItem(cntSearchCritITEMS, critForSearchMENU)) {
		case 1:
			res = c.binarySearch(group, inputQuery());
			break;
		case 2:
			res = c.binarySearch(course, inputQuery());
			break;
		case 3:
			res = c.binarySearch(surname, inputQuery());
			break;
		case 4:
			res = c.binarySearch(numRecBook, inputQuery());
			break;
		case 5:
			res = c.binarySearch(mark, inputQuery());
			break;
		}
		break;
	}
}

/*void a() { std::cout << "a() done" << std::endl; }
void b() { std::cout << "b() done" << std::endl; }
void c() { std::cout << "c() done" << std::endl; }
void exit() { exit(0); }*/

int main()
{
	/*UInterface manager = UInterface();
	void(*action[])() = { exit, a, b, c };
	while (true) {
		manager.mainMenu.display();
		if (manager.mainMenu.selection())
			action[manager.mainMenu.opt()]();
	}*/

	setlocale(LC_ALL, "Russian");
	int item;
	Container<Entry> c = Container<Entry>();
	Container<Entry> subset = Container<Entry>();
	std::deque<Entry>::iterator it;

	while ((item = inputItem(cntMainMenuITEMS, mainMENU)) != cntMainMenuITEMS)
	{
		std::string fileName;

		switch (item)
		{
		case 1:
			std::cout << "Enter name of file: ";
			std::cin >> fileName;
			c.loadFromfile(fileName);
			break;
		case 2: //add
			if (c.add(inputEntry()))
				std::cout << "Entry has been added." << std::endl;
			else
				std::cout << "Such entry already exists." << std::endl;
			break;
		case 3: //find
			find(c, subset);
			outputRes(subset);
			break;
		case 4: //remove
			find(c, subset);
			if (outputRes(subset)) {
				int i = inputItem(subset.c.size(), removeREQUEST);
				c.remove(subset.c[i]);
			}
			break;
		case 5: //edit
			find(c, subset);
			if (outputRes(subset)) {
				int i = inputItem(subset.c.size(), editREQUEST);
				c.edit(subset.c[i]);
			}
			break;
		case 6: //console output
			showTitle();
			c.outputToConsole();
			break;
		case 7: //save to file
			std::cout << "Enter name of file: ";
			std::cin >> fileName;
			if (!c.saveToFile(fileName))
				std::cout << "Error of opening file." << std::endl;
			break;
		case 8: //calc average mark
			switch (inputItem(cntMarkCritITEMS, critForAvrMarkMENU)) {
			case 1: //group
				c.calcAverageMark(group, inputQuery());
				break;
			case 2: //course
				c.calcAverageMark(course, inputQuery());
				break;
			case 3: //discipline
				c.calcAverageMark(discipline, inputQuery());
				break;
			}
			break;
		}
	}
    return 0;
}

