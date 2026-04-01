#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using ule::DoublyLinkedList;

TEST(ListTest, init){
    DoublyLinkedList<int> a;
    EXPECT_EQ(a.get_size(), 0);
}

TEST(ListTest, push_back_int){
    DoublyLinkedList<int> a;
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

TEST(ListTest, push_back_char){
    DoublyLinkedList<char> a;
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

TEST(ListTest, int_has_item){
    DoublyLinkedList<int> a;
    a.push_back(1);
    EXPECT_TRUE(a.has_item(1));
    EXPECT_FALSE(a.has_item(2));
}

TEST(ListTest, char_has_item){
    DoublyLinkedList<char> c;
    c.push_back('a');
    EXPECT_TRUE(c.has_item('a'));
    EXPECT_FALSE(c.has_item('b'));
}

TEST(ListTest, int_remove_first){
    DoublyLinkedList<int> a;
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
	a.remove_first(2);
	a.remove_first(10);
    a.print();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
