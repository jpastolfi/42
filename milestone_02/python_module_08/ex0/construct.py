import sys

def is_venv() -> bool:
    return (sys.prefix == sys.base_prefix)

venv_text = {
    "status": "Welcome to the construct",
    "v_env": "None detected"
}

global_text = {
    "status": "You're still plugged in",
    "v_env": "None detected"
}

if __name__ == "__main__":
    print("Current Python: {}"
        .format(sys.prefix))
    print(sys.prefix)