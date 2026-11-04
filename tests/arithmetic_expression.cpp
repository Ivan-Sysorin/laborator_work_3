#include "stack.h"
#include <vector>
#include <gtest/gtest.h>

TEST(TArithmeticExpression, right_arithmetic) {
    TArithmeticExpression expr("2 + 3 * 4");
    EXPECT_EQ(expr.GetPostfix(), "234*+");
}

TEST(TArithmeticExpression, right_calculation) {
    TArithmeticExpression expr("(x + y) * z");
    EXPECT_DOUBLE_EQ(expr.Calculate({{'x', 2.0}, {'y', 3.0}, {'z', 4.0}}), 20.0);
}

TEST(TArithmeticExpression, right_record) {
    TArithmeticExpression expr("a + b");
    EXPECT_EQ(expr.GetPostfix(), "ab+");
}

TEST(TArithmeticExpression, can_right_get_operands) {
    TArithmeticExpression expr("a + b * a - c");
     std::vector<char> expected = {'a', 'b', 'c'};
    EXPECT_EQ(expr.GetOperands(), expected);
}

TEST(TArithmeticExpressionTest, CalculateWithBrackets) {
    TArithmeticExpression expr("(a+b)*(c-d)");
    std::map<char, double> values = {
        {'a', 2.0}, {'b', 3.0}, {'c', 5.0}, {'d', 1.0}
    };
    EXPECT_DOUBLE_EQ(expr.Calculate(values), 20.0);
}