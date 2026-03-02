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

TEST (NumbersSum, Subtest_1) {
  ule::LongNumber ln1 = "999";
  ule::LongNumber ln2 = "1";
  ule::LongNumber expected_1 = "1000";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "999+1";
}
TEST (NumbersSum, Subtest_2) {
  ule::LongNumber ln1 = "-571";
  ule::LongNumber ln2 = "33";
  ule::LongNumber expected_1 = "-538";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "-571+33";
}
TEST (NumbersSum, Subtest_3) {    
  ule::LongNumber ln1 = "-3456";
  ule::LongNumber ln2 = "-3457";
  ule::LongNumber expected_1 = "-6913";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "-3456+(-3457)";
}
TEST (NumbersSum, Subtest_4) {  
  ule::LongNumber ln1 = "7645";
  ule::LongNumber ln2 = "3456";
  ule::LongNumber expected_1 = "11101";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "7645+3456";
}
TEST (NumbersSum, Subtest_5) {  
  ule::LongNumber ln1 = "456";
  ule::LongNumber ln2 = "-457";
  ule::LongNumber expected_1 = "-1";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "456+(-457)";
}
TEST (NumbersSum, Subtest_6) {  
  ule::LongNumber ln1 = "-456";
  ule::LongNumber ln2 = "456";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 + ln2)
    << "-456+456";
}

TEST (NumbersSub, Subtest_1) {
  ule::LongNumber ln1 = "1000";
  ule::LongNumber ln2 = "1";
  ule::LongNumber expected_1 = "999";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "1000-1";
}
TEST (NumbersSub, Subtest_2) {
  ule::LongNumber ln1 = "-571";
  ule::LongNumber ln2 = "33";
  ule::LongNumber expected_1 = "-604";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "-571-33";
}
TEST (NumbersSub, Subtest_3) {    
  ule::LongNumber ln1 = "-3456";
  ule::LongNumber ln2 = "-3457";
  ule::LongNumber expected_1 = "1";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "-3456-(-3457)";
}
TEST (NumbersSub, Subtest_4) {  
  ule::LongNumber ln1 = "7645";
  ule::LongNumber ln2 = "3456";
  ule::LongNumber expected_1 = "4189";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "7645-3456";
}
TEST (NumbersSub, Subtest_5) {  
  ule::LongNumber ln1 = "456";
  ule::LongNumber ln2 = "-457";
  ule::LongNumber expected_1 = "913";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "456-(-457)";
}
TEST (NumbersSub, Subtest_6) {  
  ule::LongNumber ln1 = "456";
  ule::LongNumber ln2 = "456";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 - ln2)
    << "456-456";
}

TEST(multiply, integer_long_number) {
  ule::LongNumber ln1 = "123";
  ule::LongNumber expected_1 = "-123";
  ASSERT_EQ(expected_1, ln1 * -1)
    <<"WRONG";
}


int main(int argc, char **argv) {
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}