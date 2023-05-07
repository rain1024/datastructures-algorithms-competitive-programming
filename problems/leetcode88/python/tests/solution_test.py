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
        nums1 = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
        m = int(f.readline().strip())
        nums2 = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
        n = int(f.readline().strip())
    return nums1, m, nums2, n

def read_output(output_file):
    with open(output_file, 'r') as f:
        nums1 = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
        return nums1

class TestSequenceMeta(type):
    def __new__(mcs, name, bases, dict):

        def gen_test(input_file, output_file):
            def test(self):
                solution = Solution()
                nums1, m, nums2, n = read_input(input_file)
                expected_nums1 = read_output(output_file)
                solution.merge(nums1, m, nums2, n)
                self.assertEqual(nums1, expected_nums1)
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