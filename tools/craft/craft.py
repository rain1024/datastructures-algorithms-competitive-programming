import os
from os.path import dirname, join
import sys
import shutil

CURRENT_DIR = dirname(__file__)
PROBLEMS_DIR = join(dirname(dirname(CURRENT_DIR)), "problems")
print(PROBLEMS_DIR)


def replace_string_in_file(filename, old, new):
    with open(filename) as f:
        text = f.read()
    text = text.replace(old, new)
    with open(filename, "w") as f:
        f.write(text)


class CodeGenerator:
    def __init__(self, domain, problem_id):
        self.domain = domain
        self.problem_id = problem_id

    def generate(self):
        domain = self.domain
        problem_id = self.problem_id
        problem_dir = join(PROBLEMS_DIR, f"{domain}{problem_id}")
        try:
            shutil.copytree(join(CURRENT_DIR, "templates", domain), problem_dir)
        except Exception as e:
            print(e)
            sys.exit(1)

class CodeforcesGenerator(CodeGenerator):
    def __init__(self, domain, problem_id):
        super().__init__(domain, problem_id)

    def generate(self):
        super().generate()
        self.task_rename_files()

    def task_rename_files(self):
        domain = self.domain
        problem_id = self.problem_id
        problem_dir = join(PROBLEMS_DIR, f"{domain}{problem_id}")

        # Update tests/BUILD file
        test_build_file = join(problem_dir, "cpp/tests/BUILD")
        old = "//problems/codeforcesAA/cpp/main:solution"
        new = f"//problems/{domain}{problem_id}/cpp/main:solution"
        replace_string_in_file(test_build_file, old, new)

        # Update tests/solution_test.cpp
        test_solution_file = join(problem_dir, "cpp/tests/solution_test.cpp")
        old = "codeforcesAA"
        new = f"{domain}{problem_id}"
        replace_string_in_file(test_solution_file, old, new)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Boilderplate to generate workspace for solving problem.\n")
        print("Usage: python crape.py domain problem_id\n\n")
        print("Examples:\n")
        print("\tpython craft.py codeforces 100A")
        print("\tpython craft.py leetcode 217")
        print("\tpython craft.py aoc 2022day2")
        print("\tpython craft.py codejam 2022PunchedCards")
        print("\tpython craft.py dsas _aog_week1_graph_decomposition1_1_finding_exit_from_maze")
        sys.exit(1)
    domain = sys.argv[1]
    problem_id = sys.argv[2]
    if domain == "codeforces":
        GeneratorClass = CodeforcesGenerator
    else:
        GeneratorClass = CodeGenerator
    generator = GeneratorClass(domain, problem_id)
    generator.generate()
