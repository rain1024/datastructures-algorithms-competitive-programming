# Problem 

## Usage

Run program with an example

```
bazel run src/main:solution < data/1.in
```

Test program

```
bazel test --test_output=all tests:solution_test
bazel test --test_output=all --cache_test_results=no tests:solution_test
```