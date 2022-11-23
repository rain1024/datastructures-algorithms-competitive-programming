import os
from os.path import dirname, join
import sys
import shutil

CURRENT_DIR = dirname(__file__)
PROBLEMS_DIR = join(dirname(dirname(CURRENT_DIR)), "problems")
print(PROBLEMS_DIR)

if __name__ == '__main__':
  if len(sys.argv) < 2:
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

  

