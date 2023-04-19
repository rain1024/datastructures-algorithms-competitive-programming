import sys
import unittest
from os import listdir
from os.path import abspath, dirname, join

python_source = dirname(dirname(abspath(__file__)))
sys.path.append(python_source)
from main.solution import Solution

test_data_directory = join(dirname(python_source), 'data')
test_cases = set([data_file.split('.')[0] for data_file in listdir(test_data_directory)])

def read_input(input_file):
    with open(input_file, 'r') as f:
        input = f.readline().strip()
    return input

def read_output(input_file):
    with open(input_file, 'r') as f:
        output = f.readline().strip()
    return output

class TestSequenceMeta(type):
    def __new__(mcs, name, bases, dict):

        def gen_test(input_file, output_file):
            def test(self):
                solution = Solution()
                input = read_input(input_file)
                output = read_output(output_file)
                actual = solution.reverseVowels(input)
                self.assertEqual(actual, output)
            return test

        for test_case in test_cases:
            test_name = f'test_{test_case}'
            input_file = join(test_data_directory, f'{test_case}.in')
            output_file = join(test_data_directory, f'{test_case}.out')
            dict[test_name] = gen_test(input_file, output_file)
        return type.__new__(mcs, name, bases, dict)

class TestSequence(unittest.TestCase, metaclass=TestSequenceMeta):
    pass

if __name__ == '__main__':
    unittest.main()