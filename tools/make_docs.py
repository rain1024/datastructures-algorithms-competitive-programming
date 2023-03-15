import os
from os.path import join, dirname, abspath

# read concepts_data.yaml

import yaml

cwd = dirname(abspath(__file__))
workspace_dir = dirname(cwd)
readme_dir = join(workspace_dir, "readme")

data = yaml.safe_load(open(join(cwd, "concepts_data.yaml")))
print(data)

# write file in readme_dir
programming_languages = [
    "abstract",
    "javascript",
    "python",
    "java",
    "nodejs",
    "typescript",
    "csharp",
    "cpp",
    "php",
    "c",
    "go",
    "kotlin",
    "rust",
    "ruby",
]

# read template from README.md
with open(join(workspace_dir, "README.md"), "r") as f:
    template = f.read()

for programing_language in programming_languages:
    with open(join(readme_dir, programing_language, "README.md"), "w") as f:
        content = template
        f.write(content)
