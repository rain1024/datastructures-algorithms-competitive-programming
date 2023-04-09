import sys
import unittest
from os import listdir
from os.path import abspath, dirname, join

python_source = dirname(dirname(abspath(__file__)))
sys.path.append(python_source)
from main.solution import Solution

test_data_directory = join(dirname(python_source), 'data')
test_cases = set([data_file.split('.')[0] for data_file in listdir(test_data_directory)])

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def read_input(input_file):
    with open(input_file, 'r') as f:
        nums = [int(num) if num != '_' else None for num in f.readline().strip().strip('][').split(',') ]
        val = int(f.readline().strip())
        current = head = ListNode(0)
        loop_node = None
        for i, num in enumerate(nums):
            current.next = ListNode(num)
            current = current.next
            if i == val:
                loop_node = current
        if loop_node is not None:
            current.next = loop_node
    return head.next, val

def read_output(output_file):
    with open(output_file, 'r') as f:
        k = f.readline().strip()
        k = False if k == 'false' else True
        return k

class TestSequenceMeta(type):
    def __new__(mcs, name, bases, dict):

        def gen_test(input_file, output_file):
            def test(self):
                solution = Solution()
                head, val = read_input(input_file)
                expected_k = read_output(output_file)
                actual_k = solution.hasCycle(head)
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