#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

namespace fs = std::filesystem;

using namespace std;

std::string TEST_ID = "";

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

std::string GetHello(std::string_view in) {
  if (in.size() == 0) {
    return std::string("hello, word");
  } else {
    return std::string("Hello, ") + in.data();
  }
}

string ReadFile(const std::string &filename) {
  std::ifstream f(filename);
  string s((std::istreambuf_iterator<char>(f)),
           std::istreambuf_iterator<char>());
  return s;
}

vector<string> RunProgram(string fileid) {
  vector<string> v;
  string program = "problems/codeforces520B/src/main/solution";
  string test_folder = "problems/codeforces520B/tests/data/";
  string command = program + " < " + test_folder + fileid + ".in > output.txt";
  std::system(command.c_str());
  string actual = ReadFile("output.txt");
  string expectedOutputFile = test_folder + fileid + ".out";
  string expected = ReadFile(expectedOutputFile);
  v.push_back(actual);
  v.push_back(expected);
  return v;
}

TEST(RunTest, AllTestCases) {
  if (TEST_ID != "") {
    std::cout << "TEST_ID = " << TEST_ID << std::endl;
  } else {
    std::cout << "RUN ALL TESTS" << std::endl;
  }

  std::string test_data_folder = "problems/codeforces520B/tests/data";
  for (const auto &entry : fs::directory_iterator(test_data_folder)) {
    string filename = split(entry.path(), "/").back();
    vector<string> v = split(filename, ".");
    string fileid = v[0];
    string extension = v[1];
    if (extension != "in"){
      continue;
    }
    if (TEST_ID != ""){
      if (fileid != TEST_ID){
        continue;
      }
    }
    // Run Test Case
    vector<string> output = RunProgram(fileid);
    string actual = output[0];
    string expected = output[1];
    string message = "❌ FAIL CASE: " + fileid;
    ASSERT_EQ(actual, expected) << message;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  if (argc == 2) {
    TEST_ID = argv[1];
  }
  return RUN_ALL_TESTS();
}