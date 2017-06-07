#include "stdafx.h"
#include <conio.h>
#include "HelpUtils.h"

int inputIntValue(const std::string msg, const int min, const int max) {
	int res;
	std::string str;

	while (true) {
		std::cout << msg;
		try {
			std::cin >> str;
			res = std::stoi(str);
			while (res < min || res > max) {
				std::cout << "\nIncorrect input data. Repeat: ";
				std::cin >> str;
				res = std::stoi(str);
			}
			return res;
		}
		catch (std::exception) {
			std::cout << "Input error" << std::endl;
		}
	}
}

int inputIntValue(const int default, const std::string msg, const int min, const int max) {
	int res = default;
	std::string str;
	int buf;
	
	while (true) {
		std::cout << msg << std::endl;
		try {
			std::getline(std::cin, str);
			if (str != "") {
				res = std::stoi(str);
				while (res < min || res > max) {
					std::cout << "\nIncorrect input data. Repeat: ";
					std::cin >> str;
					std::getline(std::cin, str);
					res = std::stoi(str);
				}
			}
			return res;
		}
		catch (std::exception) {
			std::cout << "Input error!" << std::endl;
		}
	}
}

std::string inputStringValue(const std::string default, const std::string msg) {
	std::string str, res = default; 
	std::cout << msg << std::endl;
	std::getline(std::cin, str);
	if (str != "")
		res = str;
	return res;
}

void inputEditedEntry(Entry &en) {
	std::string msg;
	int n;
	do {
		msg = "\nNumber of record book (current value = " + std::to_string(en.getNumOfRecordBook()) + "): ";
		n = inputIntValue(en.getNumOfRecordBook(), msg);
		if (n < 0)
			std::cout << "Error: negative value" << std::endl;
	} while (n < 0);
	
	en.setNumOfRecordBook(n);

	msg = "\nSurname (current value = " + en.getSurname() + "): ";
	en.setSurname(inputStringValue(en.getSurname(), msg));

	msg = "\nCourse (current value = " + std::to_string(en.getCourse()) + "): ";
	en.setCourse(inputIntValue(en.getCourse(), msg, 1, 4));

	msg = "\nGroup (current value = " + en.getGroup() + "): ";
	en.setGroup(inputStringValue(en.getGroup(), msg));

	msg = "\nDiscipline (current value = " + en.getDiscipline() + "): ";
	en.setDiscipline(inputStringValue(en.getDiscipline(), msg));

	msg = "\nMark (current value = " + std::to_string(en.getMark()) + "): ";
	en.setMark(inputIntValue(en.getMark(), msg, 2, 5));
}