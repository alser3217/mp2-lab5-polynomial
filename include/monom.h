#ifndef __MONOM__
#define __MONOM__

class Monom {
	double coeff;
	int degree;
public:
	Monom(double _coeff, int _degree) : coeff(_coeff), degree(_degree){}
	double get_coeff();
	int get_degree();
	friend std::ostream& operator<<(std::ostream& os, const Monom& mn);
	friend bool operator>(const Monom& mn1, const Monom& mn2);
	friend bool operator<(const Monom& mn1, const Monom& mn2);
	friend bool operator==(const Monom& mn1, const Monom& mn2);
	Monom& operator=(const Monom& mn);
};

#endif
