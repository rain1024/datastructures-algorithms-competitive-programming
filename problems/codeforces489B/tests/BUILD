load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_test(
    name = "solution_test",
    srcs = ["solution_test.cpp"],
    deps = [
      "//problems/codeforces489B/src/main:solution",
      "@com_google_googletest//:gtest_main",
    ],
    data = ["data"]
)