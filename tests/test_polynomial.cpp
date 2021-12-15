#include "gtest/gtest.h"
#include "polynomial.h"
#include "polynomial.cpp"

TEST (Polynomial, can_create_polynomial) {
	ASSERT_NO_THROW (Polynomial pl);
}

TEST (Polynomial, can_subtract_polynomials) {
	Polynomial pl1, pl2;
	ASSERT_NO_THROW (pl1 - pl2);
}

TEST (Polynomial, can_add_polynomials) {
	Polynomial pl1, pl2;
	ASSERT_NO_THROW (pl1 - pl2);
}

TEST (Polynomial, can_multiply_polynomials) {
	Polynomial pl1, pl2;
	ASSERT_NO_THROW (pl1 * pl2);
}

TEST (Polynomial, throws_when_degree_of_polynomial_more_then_999) {
	Polynomial pl1("x8y8z8"), pl2("x7y7z7");
	ASSERT_ANY_THROW (pl1 * pl2);
}

TEST(Polynomial, can_assign_polynomials) {
	Polynomial pl1, pl2;
	ASSERT_NO_THROW (pl1 = pl2);
}

TEST(Polynomial, can_assign_polynomial_to_itself) {
	Polynomial pl;
	ASSERT_NO_THROW(pl = pl);
}