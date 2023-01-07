""" Document Style Check
"""
from os.path import dirname, join
import re
import glob
import yaml


def check_content(file, rules):
    with open(file, encoding="utf-8") as f:
        content = f.read()

    for rule in rules:
        search = rule['search']
        result = re.search(search, content, re.UNICODE | re.MULTILINE | re.DOTALL)
        if not result:
            print(f"File: {file}")
            message = f"[❌] {rule['name']}\n{rule}"
            raise Exception(message)

if __name__ == '__main__':
    PROJECT_FOLDER = dirname(dirname(__file__))

    rules_file = join(PROJECT_FOLDER, "tools", "rules.yaml")
    with open(rules_file, 'r', encoding='utf-8') as f:
        rules = yaml.safe_load(f)

    template_file = join(PROJECT_FOLDER, "tools", "template.md")
    check_content(template_file, rules)
    print("✅ Check template file")

    content_files = glob.glob("concepts/**/*.md")
    for content_file in content_files:
        check_content(content_file, rules)
    print("✅ All checks were successful.")
