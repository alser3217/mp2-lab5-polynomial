#include <vector>
#include <sstream>

#include <iostream>

#include "polynomial.h"

std::string Polynomial::to_list(std::string _as_string) {
	std::vector<std::string> s_degrees;
	std::string degree;
	std::vector<std::string> s_coeffs;
	std::string coeff;
	std::string tmp;
	std::vector<std::string> s_monoms;
	for (int i = 0; i < _as_string.size(); i++) {
		while (_as_string[i] != '+' && _as_string[i] != '-' && i < _as_string.size()) {
			tmp += _as_string[i];
			i++;
		}
		if (!tmp.empty())
		  s_monoms.push_back(tmp);
		tmp.clear();
		if (_as_string[i] == '-')
			tmp = "-";
	}
	for (int i = 0, j = 0; i < s_monoms.size(); i++) {
		j = 0;
		while (s_monoms[i][j] != 'x' && j < s_monoms[i].size()) {
			coeff += s_monoms[i][j];
			j++;
		}
		if (coeff == "-")
			coeff += "1";
		if (coeff.empty())
			coeff = "1";
		for (; j < s_monoms[i].size(); j += 2) {
			degree += s_monoms[i][j + 1];
		}
		s_degrees.push_back(degree);
		s_coeffs.push_back(coeff);
		coeff.clear();
		degree.clear();
	}
	for (int i = 0; i < s_monoms.size(); i++) {
		monoms.push_back(Monom(std::stod(s_coeffs[i]), std::stod(s_degrees[i])));
	}
	return tmp;
}

int Polynomial::size() const{
	return Size;
}

Polynomial::Polynomial(std::string _as_string) {
	to_list(_as_string);
	sort();
	reduce();
	string_edit();
	Size = monoms.size();
}

std::ostream& operator<<(std::ostream& os, const Polynomial& pl) {
	os << pl.as_string;
	return os;
}

void Polynomial::sort() {
	for (int i = 0; i < monoms.size() - 1; i++)
		for (int j = 0; j < monoms.size() - 1 - i; j++)
			if (monoms[j] < monoms[j + 1])
				monoms.swap(j);
}

void Polynomial::reduce() {
	int new_degree;
	double new_coeff;
	bool done = false;
	for (int i = 0; i < monoms.size() - 1; i++) {
		if (monoms[i] == monoms[i + 1]) {
			done = true;
			break;
		}
	}
	while (done) {
		done = false;
		for (int i = 0; i < monoms.size() - 1; i++)
			for (int j = 0; j < monoms.size() - 1 - i; j++)
				if (monoms[j] == monoms[j + 1]) {
					new_degree = monoms[j].get_degree();
					new_coeff = monoms[j].get_coeff() + monoms[j + 1].get_coeff();
					monoms.push_back(Monom(new_coeff, new_degree));
					monoms.remove(j);
					monoms.remove(j);
					sort();
				}
		for (int i = 0; i < monoms.size() - 1; i++) {
			if (monoms[i] == monoms[i + 1]) {
				done = true;
				break;
			}
		}
	}
}

void Polynomial::string_edit() {
	std::string result;
	std::string tmp;
	for (int i = 0; i < monoms.size(); i++) {
		if (i != 0 && monoms[i].get_coeff() > 0)
			result += '+';
		if (monoms[i].get_coeff() != 1) {
			std::ostringstream ss;
			ss << monoms[i].get_coeff();
			result += ss.str();
		}
		{
			result += 'x';
			std::ostringstream ss;
			ss << monoms[i].get_degree() / 100;
			result += ss.str();
		}
		{
			result += 'y';
			std::ostringstream ss;
			ss << (monoms[i].get_degree() / 10) % 10;
			result += ss.str();
		}
		{
			result += 'z';
			std::ostringstream ss;
			ss << monoms[i].get_degree() % 10;
			result += ss.str();
		}
	}
	as_string = result;
}

Polynomial Polynomial::operator+(const Polynomial& object) {
	Polynomial result;
	int i = 0, j = 0;
	int degree, coeff;
	while (i < size() && j < object.size()) {
		if (monoms[i].get_degree() == object.monoms[j].get_degree()) {
			coeff = monoms[i].get_coeff() + object.monoms[j].get_coeff();
			degree = monoms[i].get_degree();
			i++;
			j++;
		}
		else if (monoms[i].get_degree() > object.monoms[j].get_degree()) {
			coeff = monoms[i].get_coeff();
			degree = monoms[i].get_degree();
			i++;
		}
		else {
			coeff = object.monoms[j].get_coeff();
			degree = object.monoms[j].get_degree();
			j++;
		}
		result.monoms.push_back(Monom(coeff, degree));
	}
	if (i < j) {
		for (; i < monoms.size(); i++)
			result.monoms.push_back(Monom(monoms[i].get_coeff(), monoms[i].get_degree()));
	}
	else
		for (; j < object.size(); j++)
			result.monoms.push_back(Monom(object.monoms[j].get_coeff(), object.monoms[j].get_degree()));
	result.string_edit();
	return result;
}

Polynomial::Polynomial(const Polynomial& pl) {
	monoms = pl.monoms;
	Size = pl.Size;
	as_string = pl.as_string;
}

Polynomial& Polynomial::operator=(const Polynomial& object) {
	if (this == &object)
		return *this;
	Size = object.Size;
	as_string = object.as_string;
	monoms = object.monoms;
}

Polynomial Polynomial::operator-(const Polynomial& object) {
	Polynomial result;
	int i = 0, j = 0;
	int degree, coeff;
	while (i < size() && j < object.size()) {
		if (monoms[i].get_degree() == object.monoms[j].get_degree()) {
			coeff = monoms[i].get_coeff() - object.monoms[j].get_coeff();
			degree = monoms[i].get_degree();
			i++;
			j++;
		}
		else if (monoms[i].get_degree() > object.monoms[j].get_degree()) {
			coeff = monoms[i].get_coeff();
			degree = monoms[i].get_degree();
			i++;
		}
		else {
			coeff = object.monoms[j].get_coeff();
			degree = object.monoms[j].get_degree();
			j++;
		}
		result.monoms.push_back(Monom(coeff, degree));
	}
	if (i < j)
		for (; i < monoms.size(); i++)
			result.monoms.push_back(Monom(monoms[i].get_coeff(), monoms[i].get_degree()));
	else
		for (; j < object.size(); j++)
			result.monoms.push_back(Monom(object.monoms[j].get_coeff(), object.monoms[j].get_degree()));
	result.string_edit();
	return result;
}

Polynomial Polynomial::operator*(const Polynomial& object) {
	Polynomial result;
	int coef, degree;
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < object.size(); j++) {
			coef = monoms[i].get_coeff() * object.monoms[j].get_coeff();
			degree = monoms[i].get_degree() + object.monoms[j].get_degree();
			if (degree > 999)
			  throw "degree overflow";
			result.monoms.push_back(Monom(coef, degree));
		}
	}
	result.sort();
	result.reduce();
	result.string_edit();
	return result;
}

double Polynomial::value(double x, double y, double z) {
	double result = 0;
	for (int i = 0; i < size(); i++) {
		result += monoms[i].get_coeff() * pow(z, monoms[i].get_degree() % 10) * pow(y, (monoms[i].get_degree() / 10) % 10) * pow(x, monoms[i].get_degree() / 100);
	}
	return result;
}
