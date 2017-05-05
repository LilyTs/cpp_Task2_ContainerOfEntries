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

/*void printMenu() {
	std::cout << "1 - add";
	std::cout << "2 - find";
	std::cout << "3 - output to console\n";
	std::cout << "4 - save to file\n";
	std::cout << "5 - calculate average mark\n" << std::endl;
	std::cout << "6 - exit";
}*/

void showTitle() {
	std::cout << "Number of record book  " << "Surname  " << "Course  " << "Group  " << "Discipline  " << "Mark" << std::endl;
}

/*int inputMenuItem() {
	printMenu();
	int i;
	bool ok;
	do {
		std::cout << "Enter the menu item number: ";
		std::cin >> i;
		ok = (i >= 0 && i <= 5);
		if (!ok) {
			std::cout << "Error! Incorrect input data.\n" << std::endl;
		}
	} while (!ok);
	return i;
}*/

//exception?? Need to handle incorrect input
Entry& inputEntry() {
	Entry en;
	int intVal;
	std::string strVal;
	std::cout << "  Number of student's record book: ";
	std::cin >> intVal;
	en.setNumOfRecordBook(intVal);
	std::cout << "  Surname: ";
	std::cin >> strVal;
	en.setSurname(strVal);
	std::cout << "  Course: ";
	std::cin >> intVal;
	en.setCourse(intVal);
	std::cout << "  Group: ";
	std::cin >> strVal;
	en.setGroup(strVal);
	std::cout << "  Discipline: ";
	std::cin >> strVal;
	en.setDiscipline(strVal);
	std::cout << "  Mark: ";
	std::cin >> intVal;
	en.setMark(intVal);
	return en;
}

/*int inputSearchfieldName() {
	int item;
	bool ok;
	do {
		std::cout << "\n1 - group";
		std::cout << "\n2 - course";
		std::cout << "\n3 - surname";
		std::cout << "\n4 - number student's record book";
		std::cout << "\n5 - mark";
		std::cout << "Enter the fieldName number: ";
		std::cin >> item;
		ok = (item >= 1) && (item <= 5);
	} while (!ok);
	return item;
}*/

/*int inputCalcAvgMarkfieldName() {
	int item;
	bool ok;
	do {
		std::cout << "\n1 - group";
		std::cout << "\n2 - course";
		std::cout << "\n3 - discipline";
		std::cout << "Enter the fieldName number: ";
		std::cin >> item;
		ok = (item >= 1) && (item <= 5);
	} while (!ok);
	return item;
}*/

//менюшки-строки и количества пунктов в них
const std::string mainMENU = "\n1 - add\n2 - find\n3 - remove\n4 - edit\n5 - output to console\n6 - save to file\n7 - calculate average mark\n8 - exit\n";
const int cntMainMenuITEMS = 8;
const std::string critForSearchMENU = "\n1 - group\n2 - course\n3 - surname\n4 - number student's record book\n5 - mark\n";
const int cntSearchCritITEMS = 5;
const std::string critForMarkMENU = "\n1 - group\n2 - course\n3 - discipline\n";
const int cntMarkCritITEMS = 3;
const std::string removeREQUEST = "What entry do you want to remove? Enter number: \n";

int inputItem(const int cntITEMS, const std::string REQUEST) {
	int item;
	bool ok;
	do {
		std::cout << REQUEST;
		std::cin >> item;
		ok = (item >= 1) && (item <= cntITEMS);
	} while (!ok);
	return item;
}

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
	if (!res.c.empty())
		for each (Entry en in res.c)
		{
			std::cout << en.toString();
			return true;
		}
	else
		std::cout << "No results";
	return false;
}



Container<Entry>& linOrBinSearch(Container<Entry> &c, const fieldName crit) {
	Container<Entry> res;
	switch (inputTypeOfSearch()) {
	case 'L':
	case'l':
		res = c.linearSearch(crit, inputQuery());
		break;
	case 'B':
	case 'b':
		res = c.binarySearch(crit, inputQuery());
		break;
	}

	return res;
}

//как возвращать множество - через параметр или return, что вернет если ничего не найдено
Container<Entry>& find(Container<Entry> &c) {
	switch (inputItem(cntSearchCritITEMS, critForSearchMENU)) {
	case 1:
		return(linOrBinSearch(c, group));
		break;
	case 2:
		return(linOrBinSearch(c, course));
		break;
	case 3:
		return(linOrBinSearch(c, surname));
		break;
	case 4:
		return(linOrBinSearch(c, numRecBook));
		break;
	case 5:
		return(linOrBinSearch(c, mark));
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int item;
	Container<Entry> c;
	Container<Entry> subset;
	std::fstream f;
	std::deque<Entry>::iterator it;

	while ((item = inputItem(cntMainMenuITEMS, mainMENU)) != cntMainMenuITEMS)
	{
		std::string fileName;

		switch (item)
		{
		case 1: //add
			if (c.add(inputEntry()))
				std::cout << "Entry has been added." << std::endl;
			else
				std::cout << "Such entry already exists." << std::endl;
			break;
		case 2: //find
			outputRes(find(c));
			break;
		case 3: //remove
			subset = find(c);
			if (outputRes(subset)) {
				int i = inputItem(subset.c.size(), removeREQUEST);
				c.remove(subset.c[i]);
			}
			break;
		case 4: //edit
			break;
		case 5: //console output
			c.outputToConsole();
			break;
		case 6: //save to file
			std::cout << "Enter name of file: ";
			std::cin >> fileName;
			f.open(fileName);
			c.saveToFile(f);
			f.close();
			break;
		case 7: //calc average mark
			switch (inputItem(cntMarkCritITEMS, critForMarkMENU)) {
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

