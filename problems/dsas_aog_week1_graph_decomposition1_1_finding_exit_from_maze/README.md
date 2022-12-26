# Codeforces Problem 

## Usage

Run program with an example

```
bazel run src/main:reachability < tests/data/1.in
```

Test program

```
# Run all tests
bazel test --test_output=all tests:solution_test
bazel test --test_output=all --cache_test_results=no tests:solution_test
# Run test with pecific test id
bazel test --test_output=all tests:solution_test --test_arg=1
```