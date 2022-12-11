import os
from os.path import dirname, join
import sys
import shutil

CURRENT_DIR = dirname(__file__)
PROBLEMS_DIR = join(dirname(dirname(CURRENT_DIR)), "problems")
print(PROBLEMS_DIR)


def task_rename_files(domain, problem_id):
    # Update tests/BUILD file
    problem_dir = join(PROBLEMS_DIR, f"{domain}{problem_id}")
    test_build_file = join(problem_dir, "tests/BUILD")
    with open(test_build_file) as f:
        text = f.read()
    old = "//problems/codeforcesAA/src/main:solution"
    new = f"//problems/{domain}{problem_id}/src/main:solution"
    text = text.replace(old, new)
    with open(test_build_file, "w") as f:
        f.write(text)

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