import sys
import unittest
from os import listdir
from os.path import abspath, dirname, join

python_source = dirname(dirname(abspath(__file__)))
sys.path.append(python_source)
from main.solution import Solution, TreeNode

test_data_directory = join(dirname(python_source), 'data')
test_cases = set([data_file.split('.')[0] for data_file in listdir(test_data_directory)])

def read_input(input_file):
    with open(input_file, 'r') as f:
        nums1 = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
        nums2 = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
    return nums1, nums2

def read_output(output_file):
    with open(output_file, 'r') as f:
        k = True if f.readline().strip() == 'true' else False
        return k

class TestSequenceMeta(type):
    def __new__(mcs, name, bases, dict):

        def list_to_tree(nums):
            if not nums:
                return None
            mid = len(nums) // 2
            root = TreeNode(nums[mid])
            root.left = list_to_tree(nums[:mid])
            root.right = list_to_tree(nums[mid+1:])
            return root

        def gen_test(input_file, output_file):
            def test(self):
                solution = Solution()
                nums1, nums2 = read_input(input_file)
                first_tree = list_to_tree(nums=nums1)
                second_tree = list_to_tree(nums=nums2)
                expected_k = read_output(output_file)
                actual_k = solution.isSameTree(first_tree, second_tree)
                self.assertEqual(actual_k, expected_k)
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