import os
from os.path import join

import yaml

wd = os.path.dirname(os.path.realpath(__file__))
# read template file
with open(join(wd, 'README.template.md'), 'r', encoding='utf-8') as f:
    template = f.read()

# read data.yaml
with open(join(wd, 'data.yaml'), 'r') as f:
    data = yaml.load(f, Loader=yaml.FullLoader)

problems = {}
solved_problems = set()
for item in data['problems']:
    id = int(item['name'])
    problems[id] = item
    solved_problems.add(id)
print(f"Leetcode: {len(solved_problems)} problems solved.")

table = ""
table = "<table>\n<tr>"
for i in range(1, 3000+1):
    if i % 10 == 1 and i > 1:
        table += "<tr>\n"
    if i not in solved_problems:
        table += f"<td>{i}</td>\n"
    else:
        td = "<td>"
        if 'level' in problems[i] and problems[i]['level'] == 'easy':
            td += "🟢&nbsp;"
        elif 'level' in problems[i] and problems[i]['level'] == 'medium':
            td += "🟡&nbsp;"
        elif 'level' in problems[i] and problems[i]['level'] == 'hard':
            td += "🔴&nbsp;"
        td += f"<a href='https://github.com/rain1024/datastructures-algorithms-competitive-programming/tree/main/problems/leetcode{i}'>{i}</a>"
        td += "</td>\n"
        table += td
table += "</table>"

with open(join(wd, 'README.md'), 'w', encoding='utf-8') as f:
    content = template.replace('<!-- table -->', table)
    f.write(content)
