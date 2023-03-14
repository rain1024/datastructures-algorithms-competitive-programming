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

problems = {}
solved_problems = set()
for item in data['problems']:
    id = item['name']
    problems[id] = item
    solved_problems.add(id)
print(f"Solve {len(solved_problems)} problems")

table = ""
table = "<table>\n<tr>"
for i in range(1, 1804):
    table += "<tr>\n"
    tr = "<tr>\n"
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
    tr += "</tr>\n"
    table += tr
    
table += "</table>"

with open(join(wd, 'README.md'), 'w') as f:
    content = tempalte.replace('<!-- table -->', table)
    f.write(content)
