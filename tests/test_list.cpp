#include "gtest/gtest.h"
#include "list.h"

TEST (List, can_create_list) {
  ASSERT_NO_THROW (List<int> list);
}

TEST (List, can_get_size) {
  List<int> ls;
  EXPECT_EQ (0, ls.size());
}

TEST (List, can_push_element) {
  List<int> ls;
  ls.push_back(5);
  EXPECT_EQ (5, ls[0]);
}

TEST (List, can_remove_element) {
  List<int> ls;
  ls.push_back(5);
  ls.remove(0);
  EXPECT_EQ (0, ls.size());
}

TEST (List, is_empty_returns_true) {
  List<int> ls;
  EXPECT_EQ (1, ls.is_empty());
}

TEST (List, is_empty_returns_false) {
  List<int> ls;
  ls.push_back(5);
  EXPECT_EQ (0, ls.is_empty());
}

TEST (List, clear_deletes_every_element_of_the_list) {
  List<int> ls;
  ls.push_back(5);
  ls.push_back(5);
  ls.clear();
  EXPECT_EQ (0, ls.size());
}

TEST (List, swap_swaps_element_with_the_next_one) {
  List<int> ls;
  ls.push_back(4);
  ls.push_back(8);
  ls.swap(0);
  EXPECT_EQ (ls[0] / ls[1], 2);
}

TEST (List, can_assign_lists) {
  List<int> ls1, ls2;
  ASSERT_NO_THROW (ls1 = ls2);
}

TEST (List, can_assign_list_to_itself) {
  List<int> ls;
  ASSERT_NO_THROW (ls = ls);
}