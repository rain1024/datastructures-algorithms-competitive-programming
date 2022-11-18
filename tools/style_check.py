""" Document Style Check
"""
import sys
from os.path import dirname, join
import yaml
import re


def check_content(file, rules):
    with open(file, encoding="utf-8") as f:
        content = f.read(f)

    for rule in rules:
        search = rule['search']
        result = re.search(search, content)
        if not result:
            message = f"[❌] {rule['name']}\n{rule}"
            raise Exception(message)

if __name__ == '__main__':
    PROJECT_FOLDER = dirname(dirname(__file__))
    template_file = join(PROJECT_FOLDER, "tools", "template.md")
    rules_file = join(PROJECT_FOLDER, "tools", "rules.yaml")

    with open(rules_file, 'r', encoding='utf-8') as f:
        rules = yaml.safe_load(f)

    check_content(template_file, rules)
    print("✅ Check template file")
