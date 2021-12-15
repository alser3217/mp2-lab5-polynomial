#ifndef __POLYNOMIAL__
#define __POLYNOMIAL__

#include <string>
#include <fstream>

#include "list.h"
#include "monom.h"

class Polynomial {
	List<Monom> monoms = List<Monom>();
	int Size = 0;
	std::string as_string;

	std::string to_list(std::string _as_string);
	void sort();
	void reduce();
	void string_edit();
public:
	Polynomial(std::string _as_string = "");
	int size() const;
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& pl);
	Polynomial operator+(const Polynomial& object);
	Polynomial operator-(const Polynomial& object);
	Polynomial& operator=(const Polynomial& object);
	Polynomial operator*(const Polynomial& object);
	Polynomial(const Polynomial& pl);
	double value(double x, double y, double z);
};

#endif
