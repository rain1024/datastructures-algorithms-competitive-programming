import os
from os.path import dirname, join
import sys
import shutil

CURRENT_DIR = dirname(__file__)
PROBLEMS_DIR = join(dirname(dirname(CURRENT_DIR)), "problems")
print(PROBLEMS_DIR)

class CodeforcesGenerator:
  pass

def replace_string_in_file(filename, old, new):
    with open(filename) as f:
        text = f.read()
    text = text.replace(old, new)
    with open(filename, "w") as f:
        f.write(text)

def task_rename_files(domain, problem_id):
    problem_dir = join(PROBLEMS_DIR, f"{domain}{problem_id}")

    # Update tests/BUILD file
    test_build_file = join(problem_dir, "tests/BUILD")
    old = "//problems/codeforcesAA/src/main:solution"
    new = f"//problems/{domain}{problem_id}/src/main:solution"
    replace_string_in_file(test_build_file, old, new)
    
    # Update tests/solution_test.cpp
    test_solution_file = join(problem_dir, "tests/solution_test.cpp")
    old = "codeforcesAA"
    new = f"{domain}{problem_id}"
    replace_string_in_file(test_solution_file, old, new)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Boilderplate to generate workspace for solving problem.")
        print("Usage: python crape.py domain problem_id")
        sys.exit(1)
    domain = sys.argv[1]
    problem_id = sys.argv[2]
    problem_dir = join(PROBLEMS_DIR, f"{domain}{problem_id}")
    try:
        shutil.copytree(join(CURRENT_DIR, "templates"), problem_dir)
    except Exception as e:
        print(e)
        sys.exit(1)
    task_rename_files(domain, problem_id)