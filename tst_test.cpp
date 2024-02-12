#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "gacube.h"

using namespace testing;

TEST(GACubeTest, GaCubeConstructor)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
