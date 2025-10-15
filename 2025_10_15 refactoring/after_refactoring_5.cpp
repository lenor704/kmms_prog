#include <cmath>
#include <iostream>

int main() { 
	int day, month, year;
	std::cout << "Введите дату дня" << std::endl;
	std::cin >> day;
	std::cout << "Введите число месяца" << std::endl;
	std::cin >> month;
	std::cout << "Введите год" << std::endl;
	std::cin >> year;
	
	const int y = year % 100;
	const int c = year / 100;
	const int s = (
		day 
		+ (13 * month - 1) / 5 
		+ y / 4 
		+ c / 4 
		- 2 * c 
		+ 777
	) % 7;

	switch (s) {
		case 0:
			std::cout << "Суббота" << std::endl;
			break;
		case 1:
			std::cout << "Воскресенье" << std::endl;
			break;
		case 2:
			std::cout << "Понедельник" << std::endl;
			break;
		case 3:
			std::cout << "Вторник" << std::endl;
			break;
		case 4:
			std::cout << "Среда" << std::endl;
			break;
		case 5:
			std::cout << "Четверг" << std::endl;
			break;
		case 6:
			std::cout << "Пятница" << std::endl;
			break;
	}
	
	system("pause");
	return 0;
}
