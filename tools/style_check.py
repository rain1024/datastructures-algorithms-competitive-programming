""" Document Style Check
"""
from os.path import dirname, join


def check_content(content):
    return True

if __name__ == '__main__':    
    # load templates
    PROJECT_FOLDER = dirname(dirname(__file__))
    template_file = join(PROJECT_FOLDER, "tools", "template.md")

    with open(template_file, encoding="utf-8") as f:
        content = f.read()
    check_content(content)
