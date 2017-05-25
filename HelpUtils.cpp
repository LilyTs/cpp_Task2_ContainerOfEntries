#include "stdafx.h"
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
				std::cin >> res;
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

	while (true) {
		std::cout << msg;
		try {
			std::cin >> str;
			if (str != "") {
				res = std::stoi(str);
				while (res < min || res > max) {
					std::cout << "\nIncorrect input data. Repeat: ";
					std::cin >> res;
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
	std::cout << msg; 
	std::cin >> str; 
	if (str != "")
		res = str;
	return res;
}
