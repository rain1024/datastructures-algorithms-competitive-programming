#include <string>
#include <string_view>

#include "gtest/gtest.h"

std::string GetHello(std::string_view in) {
  if (in.size() == 0) {
    return std::string("hello, word");
  } else {
    return std::string("Hello, ") + in.data();
  }
}

TEST(GetHello, CanMakeHelloWorldWithEmptyInput) {
  EXPECT_EQ(GetHello(""), "hello, word");
}

TEST(GetHello, CanMakeHelloWithNonEmptyInput) {
  EXPECT_EQ(GetHello("Ari"), "Hello, Ari");
}
