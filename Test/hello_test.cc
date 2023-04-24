#include <gtest/gtest.h>
#include "main.h"
#include "state_machine_for_testing.c"


TEST(HelloTest1, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// Demonstrate some basic assertions.
TEST(HelloTest2, BasicAssertions) {
  update_state_machine();
  EXPECT_EQ(get_state(), 2);
}

