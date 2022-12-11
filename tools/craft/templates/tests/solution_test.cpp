#include <cstdlib>
#include <fstream>
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

void ReadFile(const std::string &filename) {
  std::ifstream MyReadFile(filename);
  std::string myText;
  std::cout << "Read File " << filename << std::endl;
  while (getline(MyReadFile, myText)) {
    // Output the text from the file
    std::cout << myText << std::endl;
  }
  MyReadFile.close();
}

std::string RunProgram() {
  std::system("tree -L 4 problems > test111.txt");
  ReadFile("test111.txt");
  std::system("problems/codeforcesAA/src/main/solution < problems/codeforcesAA/tests/data/1.in > test222.txt");
  ReadFile("test222.txt");
  std::cout << "End Program " << std::endl;
  return "";
}

TEST(GetHello, CanMakeHelloWorldWithEmptyInput) {
  RunProgram();
  EXPECT_EQ(GetHello(""), "hello, word");
}

TEST(GetHello, CanMakeHelloWithNonEmptyInput) {
  EXPECT_EQ(GetHello("Ari"), "Hello, Ari");
}