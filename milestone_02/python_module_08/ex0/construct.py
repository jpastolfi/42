import sys
import os
import site


def is_venv() -> bool:
    return sys.prefix != sys.base_prefix


def display_venv() -> None:
    print(f"""MATRIX STATUS: Welcome to the construct

Current Python: {sys.executable}
Virtual Environment: {os.path.basename(sys.prefix)}
Environment Path: {sys.prefix}

SUCCESS: You're in an isolated environment!
Safe to install packages without affecting the global system.

Package installation path: {",".join(site.getsitepackages())}""")


def display_global() -> None:
    print(f"""MATRIX STATUS: You're still plugged in

Current Python: {sys.executable}
Virtual Environment: None detected

WARNING: You're in the global environment!
The machines can see everything you install.
To enter the construct, run:
python3 -m venv matrix_env
source matrix_env/bin/activate # On Unix
matrix_env\\Scripts\\activate # On Windows
Then run this program again.""")


if __name__ == "__main__":
    if is_venv():
        display_venv()
    else:
        display_global()
