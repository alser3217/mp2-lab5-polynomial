#include <fstream>

#include "monom.h"

double Monom::get_coeff() {
	return coeff;
}

int Monom::get_degree() {
	return degree;
}

std::ostream& operator<<(std::ostream& os, const Monom& mn) {
	os << mn.coeff << " " << mn.degree;
	return os;
}

bool operator>(const Monom& mn1, const Monom& mn2) {
	return mn1.degree > mn2.degree;
}

bool operator<(const Monom& mn1, const Monom& mn2) {
	return mn1.degree < mn2.degree;
}

bool operator==(const Monom& mn1, const Monom& mn2) {
	return mn1.degree == mn2.degree;
}

Monom& Monom::operator=(const Monom& mn) {
	if (this == &mn)
		return *this;
	coeff = mn.coeff;
	degree = mn.degree;
	return *this;
}
