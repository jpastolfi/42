def input_temperature(temp_str: str) -> int:
    if 0 < int(temp_str) < 40:
        return int(temp_str)
    else:
        raise Exception


def test_temperature() -> None:
    try:
        print("{} degrees looks good to me".format(input_temperature("-50")))
    except Exception:
        print("Oops, something's awry")
    try:
        print("{} degrees looks good to me".format(input_temperature("100")))
    except Exception:
        print("Oops, something's awry")
    try:
        print("{} degrees looks good to me".format(input_temperature("10")))
    except Exception:
        print("Oops, something's awry")

    print("I'm still here")


if (__name__ == "__main__"):
    test_temperature()
