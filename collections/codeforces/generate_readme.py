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

def get_level(problem):
    return "🟢&nbsp"

table = ""
table = "<table>\n<tr>"
for i in range(1, 1804):
    table += "<tr>\n"
    tr = "<tr>\n"
    for j in ['A', 'B', 'C', 'D', 'E', 'F', 'G']:
        id = f"{i}{j}"
        if id not in solved_problems:
            tr += f"<td>{id}</td>\n"
        else:
            td = "<td>"
            td += get_level(problems[id])
            td += f"<a href='https://github.com/rain1024/datastructures-algorithms-competitive-programming/tree/main/problems/codeforces{id}'>{id}</a>"
            td += "</td>\n"
            tr += td
    tr += "</tr>\n"
    table += tr
    
table += "</table>"

with open(join(wd, 'README.md'), 'w') as f:
    content = tempalte.replace('<!-- table -->', table)
    f.write(content)
