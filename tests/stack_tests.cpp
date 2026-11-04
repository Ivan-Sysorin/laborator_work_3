#include "stack.h"
#include <gtest/gtest.h>

TEST(Stack, can_add_an_element_to_the_en) {
    Stack<int> n;
    ASSERT_NO_THROW(n.Push(11));
}

TEST(Stack, cannot_return_top_is_empty_stack) {
    Stack<int> n;
    ASSERT_ANY_THROW(n.Top());
}

TEST(Stack, can_return_top_if_is_not_empty_stack) {
    Stack<int> n;
    n.Push(5);
    ASSERT_NO_THROW(n.Top());
}

TEST(Stack, can_return_is_empty) {
    Stack<int> n;
    EXPECT_TRUE(n.IsEmpty());
}

TEST(Stack, can_return_is_not_empty) {
    Stack<int> n;
    n.Push(11);
    EXPECT_FALSE(n.IsEmpty());
}