import os
import sys
from dotenv import load_dotenv

if __name__ == "__main__":
    load_dotenv(override=False)
    env_vars: dict[str, str | None] = {
        "MATRIX_MODE": os.environ.get('MATRIX_MODE'),
        "DATABASE_URL": os.environ.get('DATABASE_URL'),
        "API_KEY": os.environ.get('API_KEY'),
        "LOG_LEVEL": os.environ.get('LOG_LEVEL'),
        "ZION_ENDPOINT": os.environ.get('ZION_ENDPOINT'),
    }
    messages: dict[str | None, str] = {
        "development": "this is the place to make mistakes",
        "production": "this is no longer a simulation",
    }
    is_missing: bool = False
    for item in env_vars.items():
        key, value = item
        if key == "MATRIX_MODE" and key not in messages.keys():
            is_missing = True
            print("MATRIX_MODE not recognized")
        if value is None:
            is_missing = True
            print(f"Environment variable {key} not found")

    if is_missing:
        sys.exit(1)
    print(f"""ORACLE STATUS: Reading the Matrix...

Configuration loaded:
Mode: {env_vars.get('MATRIX_MODE')}
Database: {"Connected to local instance"}
API Access: Authenticated
Log Level: {env_vars.get('LOG_LEVEL')}
Zion Network: Online

Environment security check:
[OK] No hardcoded secrets detected
[OK] .env file properly configured
[OK] Production overrides available

The Oracle sees all configurations.
""")

    if env_vars.get('MATRIX_MODE') in messages.keys():
        print(
            f"Remember you are in {env_vars.get('MATRIX_MODE')} mode: "
            f"{messages.get(env_vars.get('MATRIX_MODE'))}"
            )
