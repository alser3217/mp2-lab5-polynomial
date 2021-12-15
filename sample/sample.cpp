#include <iostream>
#include <fstream>

#include "polynomial-all.h"

int main() {
	std::ofstream os;
	std::string s_pl;
	double result;
	double a, b, c;
	setlocale(LC_ALL, "Russian");
	std::cout << "***Программа-сэмпл, демонстрирующая функцианальность классов List, Polynomial, Monom.***" << std::endl << std::endl;
	std::cout << "Введите полином с мономами в формате AxByCzD, где A - коэффициент при мономе, B, C, D - степени переменных." << std::endl;
	std::cout << "ВВОДЯТСЯ ВСЕ СТЕПЕНИ, ВКЛЮЧАЯ НУЛЕВУЮ И ПЕРВУЮ!" << std::endl;
	std::cin >> s_pl;
	Polynomial pl(s_pl);
	std::cout << "Вы ввели: " << std::endl << std::endl;
	std::cout << pl << std::endl << std::endl;

	std::cout << "Введите  полином, который будет прибавлен к первому полиному: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl1(s_pl);
	Polynomial r_pl1;
	r_pl1 = pl + pl1;
	std::cout << "Результат сложения: " << std::endl << std::endl;
	std::cout << r_pl1 << std::endl << std::endl; 

	std::cout << "Введите  полином, который будет вычтен из первого полинома: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl2(s_pl), r_pl2;
	r_pl2 = pl - pl2;
	std::cout << "Результат вычитания: " << std::endl << std::endl;
	std::cout << r_pl2 << std::endl << std::endl;

	std::cout << "Введите  полином, на который будет умножен первый полином: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl3(s_pl), r_pl3;
	r_pl3 = pl * pl3;
	std::cout << "Результат умножения: " << std::endl << std::endl;
	std::cout << r_pl3 << std::endl << std::endl;

	std::cout << "Введите  точку, значение в  который будет посчитано для первого полинома: " << std::endl;
	std::cin >> a >> b >> c;
	result = pl.value(a, b, c);
	std::cout << "Результат вычисления: " << std::endl << std::endl;
	std::cout << result << std::endl << std::endl;

	std::cout << "Все результаты были сохранены в текстовый файл Results.txt" << std::endl;
	os.open("Result.txt");
	os << "Исходный полином: " << pl << std::endl;
	os << "Результат сложения с полиномом " << pl1 << ": " << r_pl1 << std::endl;
	os << "Результат вычитания полинома " << pl2 << ": " << r_pl2 << std::endl;
	os << "Результат умноженя на полином " << pl3 << ": " << r_pl3 << std::endl;
	os << "Результат вычисления в точке ("<< a << ", " << b << ", " << c << "): " << result;
	

	return 0;
}