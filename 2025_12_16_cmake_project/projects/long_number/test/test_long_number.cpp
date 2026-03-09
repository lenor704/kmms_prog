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

TEST (NumbersMul, Subtest_1) {
  ule::LongNumber ln1 = "144";
  ule::LongNumber ln2 = "37";
  ule::LongNumber expected_1 = "5328";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "144*37";
}
TEST (NumbersMul, Subtest_2) {
  ule::LongNumber ln1 = "33";
  ule::LongNumber ln2 = "-571";
  ule::LongNumber expected_1 = "-18843";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "33*(-571)";
}
TEST (NumbersMul, Subtest_3) {    
  ule::LongNumber ln1 = "-3456";
  ule::LongNumber ln2 = "-1";
  ule::LongNumber expected_1 = "3456";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "-3456*(-1)";
}
TEST (NumbersMul, Subtest_4) {  
  ule::LongNumber ln1 = "7645";
  ule::LongNumber ln2 = "10";
  ule::LongNumber expected_1 = "76450";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "7645*10";
}
TEST (NumbersMul, Subtest_5) {  
  ule::LongNumber ln1 = "456";
  ule::LongNumber ln2 = "0";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "456*(0)";
}
TEST (NumbersMul, Subtest_6) {  
  ule::LongNumber ln1 = "999";
  ule::LongNumber ln2 = "999";
  ule::LongNumber expected_1 = "998001";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "999*999";
}
TEST (NumbersMul, Subtest_7) {  
  ule::LongNumber ln1 = "9986748359";
  ule::LongNumber ln2 = "99857584867599";
  ule::LongNumber expected_1 = "997252571810197545520041";
  ASSERT_EQ(expected_1, ln1 * ln2)
    << "много*много";
}

TEST (NumbersDiv, Subtest_1) {  
  ule::LongNumber ln1 = "137";
  ule::LongNumber ln2 = "-7";
  ule::LongNumber expected_1 = "-19";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "137 / 7";
}
TEST (NumbersDiv, Subtest_2) {  
  ule::LongNumber ln1 = "1234";
  ule::LongNumber ln2 = "1";
  ule::LongNumber expected_1 = "1234";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "1234 / 1";
}
TEST (NumbersDiv, Subtest_3) {  
  ule::LongNumber ln1 = "12";
  ule::LongNumber ln2 = "123";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "12 / 123";
}
TEST (NumbersDiv, Subtest_4) {  
  ule::LongNumber ln1 = "-18720";
  ule::LongNumber ln2 = "165";
  ule::LongNumber expected_1 = "-114";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "18720 / 165";
}
TEST (NumbersDiv, Subtest_5) {  
  ule::LongNumber ln1 = "0";
  ule::LongNumber ln2 = "123";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "0 / 123";
}
TEST (NumbersDiv, Subtest_6) {  
  ule::LongNumber ln1 = "1256";
  ule::LongNumber ln2 = "6";
  ule::LongNumber expected_1 = "209";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "1256 / 6";
}
TEST (NumbersDiv, Subtest_7) {  
  ule::LongNumber ln1 = "-123";
  ule::LongNumber ln2 = "10";
  ule::LongNumber expected_1 = "-13";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "-123 / 10";
}
TEST (NumbersDiv, Subtest_8) {  
  ule::LongNumber ln1 = "99857584867599";
  ule::LongNumber ln2 = "7674849";
  ule::LongNumber expected_1 = "13011016";
  ASSERT_EQ(expected_1, ln1 / ln2)
    << "много/много";
}

TEST (NumbersOst, Subtest_1) {  
  ule::LongNumber ln1 = "-123";
  ule::LongNumber ln2 = "10";
  ule::LongNumber expected_1 = "7";
  ASSERT_EQ(expected_1, ln1 % ln2)
    << "-123 % 10";
}
TEST (NumbersOst, Subtest_2) {  
  ule::LongNumber ln1 = "123";
  ule::LongNumber ln2 = "-10";
  ule::LongNumber expected_1 = "3";
  ASSERT_EQ(expected_1, ln1 % ln2)
    << "123 % -10";
}
TEST (NumbersOst, Subtest_3) {  
  ule::LongNumber ln1 = "120";
  ule::LongNumber ln2 = "4";
  ule::LongNumber expected_1 = "0";
  ASSERT_EQ(expected_1, ln1 % ln2)
    << "120 % 4";
}
/*
#include <gtest/gtest.h>

#include "long_number.hpp"

using ule::LongNumber;

class FComparisons : public testing::Test {
	public:
		LongNumber 
			n_2{"-2"}, n_1{"-1"}, n_1_copy{"-1"},
			
			p_1{"1"}, p_1_copy{"1"}, p_12{"12"};
};

TEST_F(FComparisons, equal) {
	EXPECT_TRUE(p_1 == p_1_copy) << "EXPECT_TRUE: 1 == 1";
	EXPECT_FALSE(n_1 == p_1) << "EXPECT_FALSE: -1 == 1";
	EXPECT_FALSE(p_1 == p_12) << "EXPECT_FALSE: 1 == 12";
	EXPECT_EQ(p_1, p_1_copy) << "EXPECT_EQ: 1 == 1";
	EXPECT_EQ(n_1, n_1_copy) << "EXPECT_EQ: -1 == -1";
}

TEST_F(FComparisons, not_equal) {
	EXPECT_TRUE(n_1 != p_1) << "EXPECT_TRUE: -1 != 1";
	EXPECT_TRUE(p_1 != p_12) << "EXPECT_TRUE: 1 != 12";
	EXPECT_FALSE(p_1 != p_1_copy) << "EXPECT_FALSE: 1 == 1";
	ASSERT_NE(p_1, p_12) << "ASSERT_NE: 1 != 12";
	ASSERT_NE(n_1, p_1) << "ASSERT_NE: -1 != 1";
}

TEST_F(FComparisons, more) {
	EXPECT_TRUE(p_12 > p_1) << "12 > 1";
	EXPECT_TRUE(p_1 > n_1) << "1 > -1";
	EXPECT_TRUE(n_1 > n_2) << "-1 > -2";
	EXPECT_FALSE(p_1_copy > p_1) << "1 > 1";
	EXPECT_FALSE(p_1 > p_12) << "1 > 12";
}

TEST_F(FComparisons, less) {
	EXPECT_TRUE(p_1 < p_12) << "1 < 12";
	EXPECT_TRUE(n_1 < p_1) << "-1 < 1";
	EXPECT_TRUE(n_2 < n_1) << "-2 < -1";
	EXPECT_FALSE(p_1_copy < p_1) << "1 < 1";
	EXPECT_FALSE(p_12 < p_1) << "12 < 1";
}

class FArithmetic : public testing::Test {
	public:
		LongNumber 
			n_19602{"-19602"}, n_99{"-99"}, n_87{"-87"}, n_17{"-17"},
			n_16{"-16"}, n_15{"-15"},
			n_7{"-7"}, n_4{"-4"}, n_3{"-3"}, n_2{"-2"}, n_1{"-1"},
		
			p_0{"0"}, p_1{"1"}, p_1_copy{"1"}, p_2{"2"}, p_3{"3"},
			p_4{"4"}, p_6{"6"}, p_12{"12"}, p_16{"16"}, p_17{"17"}, 
			p_99{"99"}, p_99_copy{"99"}, 
			p_113{"113"}, p_198{"198"}, p_1188{"1188"}, p_19602{"19602"},
			
			n_100{"-100"}, n_6{"-6"}, p_100{"100"}, p_{"6"};
};

TEST_F(FArithmetic, summ) {
	EXPECT_EQ(p_2, p_1 + p_1_copy) << "1 + 1 = 2";
	EXPECT_EQ(p_0, p_1 + n_1) << "1 + (-1) = 0";
	EXPECT_EQ(p_198, p_99 + p_99_copy) << "99 + 99 = 198";	
	EXPECT_EQ(n_87, n_99 + p_12) << "-99 + 12 = -87";	
	EXPECT_EQ(n_87, p_12 + n_99) << "12 + (-99) = -87";	
}

TEST_F(FArithmetic, substraction) {
	EXPECT_EQ(p_0, p_1 - p_1_copy) << "1 - 1 = 0";
	EXPECT_EQ(p_2, p_1 - n_1) << "1 + (-1) = 2";
	EXPECT_EQ(n_87, p_12 - p_99) << "12 - 99 = -87";
}

TEST_F(FArithmetic, multiply) {
	EXPECT_EQ(p_1, p_1 * p_1_copy) << "1 * 1 = 1";
	EXPECT_EQ(n_1, p_1 * n_1) << "1 * (-1) = -1";
	EXPECT_EQ(p_0, p_0 * p_99) << "0 * 99 = 0";
	EXPECT_EQ(p_1188, p_12 * p_99) << "12 * 99 = 1188";
	EXPECT_EQ(n_19602, p_198 * p_99 * n_1) << "198 * 99 * -1 = -19602";
}

TEST_F(FArithmetic, division) {
	EXPECT_EQ(p_2, p_2 / p_1) << "2 / 1 = 2";
	EXPECT_EQ(p_198, p_19602 / p_99) << "19602 / 99 = 198";
	EXPECT_EQ(p_99, n_19602 / p_198 / n_1) << "-19602 / 198 / -1  = 99";
}

TEST_F(FArithmetic, division_full_sign_example) {
	EXPECT_EQ(p_16, p_100 / p_6) << "100 / 6 = 16";
	EXPECT_EQ(n_16, p_100 / n_6) << "100 / -6 = -16";
	EXPECT_EQ(n_17, n_100 / p_6) << "-100 / 6 = -17";
	EXPECT_EQ(p_17, n_100 / n_6) << "-100 / -6 = 17";
}

TEST_F(FArithmetic, remainder) {
	EXPECT_EQ(p_1, p_3 % p_2) << "3 % 2 = 1";
	EXPECT_EQ(p_6, p_19602 % p_12) << "19602 % 12 = 6";
	EXPECT_EQ(p_1, n_15 % p_4) << "-15 % 4 = 1";
	EXPECT_EQ(p_2, p_113 % n_3) << "113 % -3 = 2";
	EXPECT_EQ(p_6, n_15 % n_7) << "-15 % -7 = 6";
}

TEST_F(FArithmetic, remainder_full_sign_example) {
	EXPECT_EQ(p_4, p_100 % p_6) << "100 % 6 = 4";
	EXPECT_EQ(p_4, p_100 % n_6) << "100 % -6 = 4";
	EXPECT_EQ(p_2, n_100 % p_6) << "-100 % 6 = 2";
	EXPECT_EQ(p_2, n_100 % n_6) << "-100 % -6 = 2";
}
*/
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
