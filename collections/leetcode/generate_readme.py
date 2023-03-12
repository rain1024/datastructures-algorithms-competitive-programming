import yaml
import os
from os.path import join

wd = os.path.dirname(os.path.realpath(__file__))
# read template file
with open(join(wd, 'README.template.md'), 'r') as f:
    tempalte = f.read()

# read data.yaml
with open(join(wd, 'data.yaml'), 'r') as f:
    data = yaml.load(f, Loader=yaml.FullLoader)

solve_problems = set([int(item['name']) for item in data['problems']])
print(solve_problems)

table = ""
table = "<table>\n<tr>"
for i in range(1, 2589+1):
    if i % 10 == 1 and i > 1:
        table += "<tr>\n"
    if i not in solve_problems:
        table += f"<td>{i}</td>\n"
    else:
        table += f"<td><a href='https://github.com/rain1024/datastructures-algorithms-competitive-programming/tree/main/problems/leetcode{i}/'>{i}</a></td>\n"
table += "</table>"

with open(join(wd, 'README.md'), 'w') as f:
    content = tempalte.replace('<!-- table -->', table)
    f.write(content)
