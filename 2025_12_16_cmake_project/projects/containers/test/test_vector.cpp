#include <gtest/gtest.h>

#include "vector.hpp"

using ule::Vector;

TEST(VectorTest, init){
    Vector<int> a;
    EXPECT_EQ(a.get_size(), 0);
}

TEST(VectorTest, push_back_int){
    Vector<int> a;
    a.push_back(1);
    EXPECT_EQ(a.get_size(),1);
    a.push_back(2);
    EXPECT_EQ(a.get_size(),2);
    a.push_back(3);
    EXPECT_EQ(a.get_size(),3);
    a.push_back(4);
    EXPECT_EQ(a.get_size(),4);
    a.print();
}

TEST(VectorTest, push_back_char){
    Vector<char> a;
    a.push_back('a');
    EXPECT_EQ(a.get_size(),1);
    a.push_back('b');
    EXPECT_EQ(a.get_size(),2);
    a.push_back('c');
    EXPECT_EQ(a.get_size(),3);
    a.push_back('d');
    EXPECT_EQ(a.get_size(),4);
    a.print();
}

TEST(VectorTest, int_has_item){
    Vector<int> a;
    a.push_back(1);
    EXPECT_TRUE(a.has_item(1));
    EXPECT_FALSE(a.has_item(2));
}

TEST(VectorTest, char_has_item){
    Vector<char> c;
    c.push_back('a');
    EXPECT_TRUE(c.has_item('a'));
    EXPECT_FALSE(c.has_item('b'));
}

TEST(VectorTest, int_remove_first){
    Vector<int> a;
    for (int i = 0; i < 11; i++){
        a.push_back(i);
    }
    EXPECT_EQ(a.get_size(), 11);
    a.remove_first(5);
    EXPECT_EQ(a.get_size(), 10);
    EXPECT_FALSE(a.has_item(5));
    a.push_back(2);
    a.remove_first(2);
    EXPECT_EQ(a.get_size(), 10);
    a.print();
}

TEST(VectorTest, int_insert){
    Vector<int> a;
    for (int i = 0; i < 11; i++){
        a.push_back(i);
    }
    a.insert(5, 100);
    EXPECT_EQ(a.get_size(), 12);
    a.insert(2, 1000);
    EXPECT_EQ(a.get_size(), 13);
    EXPECT_TRUE(a.has_item(100));
    EXPECT_TRUE(a.has_item(1000));
    a.print();
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
