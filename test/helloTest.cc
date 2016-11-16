#include "hello.h"
#include "gtest/gtest.h"

TEST(HelloTest, First) {
    Hello h;
    h.printHello();
    EXPECT_EQ(7, 7);
}
