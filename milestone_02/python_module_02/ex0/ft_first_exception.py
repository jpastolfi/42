def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    try:
        print("{} degrees looks good to me".format(input_temperature("25")))
    except Exception:
        print("Oops, something's awry")

    try:
        print("{} degrees looks good to me".format(input_temperature("abc")))
    except Exception:
        print("Oops, something's awry")

    print("I'm still here")


if (__name__ == "__main__"):
    test_temperature()
