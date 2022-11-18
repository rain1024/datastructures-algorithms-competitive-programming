""" Document Style Check
"""
import sys
from os.path import dirname, join


def check_content(content):
    # Must have line "From wikipedia"
    print("Rule: Must have line \"From wikipedia\"")
    rule_valid = False
    for line in content.splitlines():
        print(line)
        if line.strip() == "From wikipedia":
            rule_valid = True
    if not rule_valid:
        raise Exception("Style Check Error")
        sys.exit(-1)


if __name__ == '__main__':  
    # load templates
    PROJECT_FOLDER = dirname(dirname(__file__))
    template_file = join(PROJECT_FOLDER, "tools", "template.md")

    with open(template_file, encoding="utf-8") as f:
        content = f.read()
    check_content(content)
