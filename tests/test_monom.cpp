#include "gtest/gtest.h"
#include "monom.h"
#include "monom.cpp"

TEST (Monom, can_create_monom) {
	ASSERT_NO_THROW (Monom mn(5, 200));
}

TEST (Monom, can_get_coeff) {
	Monom mn(5, 200);
	EXPECT_EQ (5, mn.get_coeff());
}

TEST (Monom, can_get_degree) {
	Monom mn(5, 200);
	EXPECT_EQ (200, mn.get_degree());
}

TEST (Monom, can_assign_monoms) {
	Monom mn1(5, 200), mn2(6, 300);
	ASSERT_NO_THROW (mn1 = mn2);
}

TEST (Monom, can_assign_monom_to_itself) {
	Monom mn(5, 200);
	ASSERT_NO_THROW (mn = mn);
}