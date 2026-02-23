#include <gtest/gtest.h>

#include "long_number.hpp"

TEST (NumbersEqual, Subtest_1) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 == ln2)
		<< "Неверно при равных значениях";
}
TEST (NumbersEqual, Subtest_2) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 == ln2)
		<< "Неверно при равных числах по модулю с отличающимся знаком";
}
TEST (NumbersEqual, Subtest_3) {		
	ule::LongNumber ln1 = "-3456";
	ule::LongNumber ln2 = "-3457";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 == ln2)
		<< "Неверно при различных значениях";
}
TEST (NumbersEqual, Subtest_4) {	
	ule::LongNumber ln1 = "-3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 == ln2)
		<< "Неверно при отрицательных равных значениях";
}
TEST (NumbersEqual, Subtest_5) {	
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-345";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 == ln2)
		<< "Неверно при разной длине";
}

TEST (NumbersNotEqual, Subtest_1) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "3456";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 != ln2)
		<< "Неверно при равных значениях";
}
TEST (NumbersNotEqual, Subtest_2) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 != ln2)
		<< "Неверно при равных числах по модулю с отличающимся знаком";
}
TEST (NumbersNotEqual, Subtest_3) {		
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "3457";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 != ln2)
		<< "Неверно при различных значениях";
}
TEST (NumbersNotEqual, Subtest_4) {	
	ule::LongNumber ln1 = "-3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 != ln2)
		<< "Неверно при отрицательных равных значениях";
}
TEST (NumbersNotEqual, Subtest_5) {	
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-345";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 != ln2)
		<< "Неверно при разной длине";
}

TEST (NumbersGreater, Subtest_1) {
	ule::LongNumber ln1 = "3457";
	ule::LongNumber ln2 = "3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 > ln2)
		<< "Неверно при ln1 > ln2 одного знака одной длины";
}
TEST (NumbersGreater, Subtest_2) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 > ln2)
		<< "Неверно при равных числах по модулю с отличающимся знаком (ln1 > ln2)";
}
TEST (NumbersGreater, Subtest_3) {		
	ule::LongNumber ln1 = "456";
	ule::LongNumber ln2 = "3457";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 > ln2)
		<< "Неверно при ln1 < ln2 больше 0 разной длины";
}
TEST (NumbersGreater, Subtest_4) {	
	ule::LongNumber ln1 = "-3451";
	ule::LongNumber ln2 = "-3457";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 > ln2)
		<< "Неверно при отрицательных значениях одной длины (ln1 > ln2)";
}
TEST (NumbersGreater, Subtest_5) {	
	ule::LongNumber ln1 = "-456";
	ule::LongNumber ln2 = "-3457";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 > ln2)
		<< "Неверно при отрицательных значениях разной длины (ln1 > ln2)";
}

TEST (NumbersLess, Subtest_1) {
	ule::LongNumber ln1 = "3457";
	ule::LongNumber ln2 = "3456";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 < ln2)
		<< "Неверно при ln1 > ln2 одного знака одной длины";
}
TEST (NumbersLess, Subtest_2) {
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 < ln2)
		<< "Неверно при равных числах по модулю с отличающимся знаком (ln1 > ln2)";
}
TEST (NumbersLess, Subtest_3) {		
	ule::LongNumber ln1 = "3456";
	ule::LongNumber ln2 = "3457";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 < ln2)
		<< "Неверно при ln1 < ln2 одного знака одной длины";
}
TEST (NumbersLess, Subtest_4) {	
	ule::LongNumber ln1 = "-3459";
	ule::LongNumber ln2 = "-3456";
	bool expected_1 = true;
	ASSERT_EQ(expected_1, ln1 < ln2)
		<< "Неверно при отрицательных значениях одной длины(ln1 > ln2)";
}
TEST (NumbersLess, Subtest_5) {	
	ule::LongNumber ln1 = "-456";
	ule::LongNumber ln2 = "-3457";
	bool expected_1 = false;
	ASSERT_EQ(expected_1, ln1 < ln2)
		<< "Неверно при отрицательных значениях разной длины(ln1 > ln2)";
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}