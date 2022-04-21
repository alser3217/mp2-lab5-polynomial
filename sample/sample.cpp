#include <iostream>
#include <fstream>
#include <locale.h>

#include "polynomial-all.h"

int main() {
	std::ofstream os;
	std::string s_pl;
	double result;
	double a, b, c;
	setlocale(LC_ALL, "Russian");
	std::cout << "***���������-�����, ��������������� ���������������� ������� List, Polynomial, Monom.***" << std::endl << std::endl;
	std::cout << "������� ������� � �������� � ������� AxByCzD, ��� A - ����������� ��� ������, B, C, D - ������� ����������." << std::endl;
	std::cout << "�������� ��� �������, ������� ������� � ������!" << std::endl;
	std::cin >> s_pl;
	Polynomial pl(s_pl);
	std::cout << "�� �����: " << std::endl << std::endl;
	std::cout << pl << std::endl << std::endl;

	std::cout << "�������  �������, ������� ����� ��������� � ������� ��������: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl1(s_pl);
	Polynomial r_pl1;
	r_pl1 = pl + pl1;
	std::cout << "��������� ��������: " << std::endl << std::endl;
	std::cout << r_pl1 << std::endl << std::endl; 

	std::cout << "�������  �������, ������� ����� ������ �� ������� ��������: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl2(s_pl), r_pl2;
	r_pl2 = pl - pl2;
	std::cout << "��������� ���������: " << std::endl << std::endl;
	std::cout << r_pl2 << std::endl << std::endl;

	std::cout << "�������  �������, �� ������� ����� ������� ������ �������: " << std::endl;
	std::cin >> s_pl;
	Polynomial pl3(s_pl), r_pl3;
	r_pl3 = pl * pl3;
	std::cout << "��������� ���������: " << std::endl << std::endl;
	std::cout << r_pl3 << std::endl << std::endl;

	std::cout << "�������  �����, �������� �  ������� ����� ��������� ��� ������� ��������: " << std::endl;
	std::cin >> a >> b >> c;
	result = pl.value(a, b, c);
	std::cout << "��������� ����������: " << std::endl << std::endl;
	std::cout << result << std::endl << std::endl;

	std::cout << "��� ���������� ���� ��������� � ��������� ���� Results.txt" << std::endl;
	os.open("Result.txt");
	os << "�������� �������: " << pl << std::endl;
	os << "��������� �������� � ��������� " << pl1 << ": " << r_pl1 << std::endl;
	os << "��������� ��������� �������� " << pl2 << ": " << r_pl2 << std::endl;
	os << "��������� �������� �� ������� " << pl3 << ": " << r_pl3 << std::endl;
	os << "��������� ���������� � ����� ("<< a << ", " << b << ", " << c << "): " << result;
	

	return 0;
}