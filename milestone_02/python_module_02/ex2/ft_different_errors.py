def garden_operations(operation_number: int) -> None:
    print("Testing operation {}...".format(operation_number))
    match operation_number:
        case 0:
            print(int("abc"))
        case 1:
            print(1 / 0)
        case 2:
            print(open("not_there.txt"))
        case 3:
            print("1" + 1)
        case _:
            print("Operation completed successfully")

def test_error_types(operation_number: int) -> None:
    print("=== Garden Error Types Demo ===")
    try:
        garden_operations(operation_number)
    except ValueError:
        print("Caught ValueError: invalid literal for int() with base 10: 'abc'")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
    except FileNotFoundError:
        print("Caught FileNotFoundError: [Errno 2] No such file or directory")
    except TypeError:
        print("Caught TypeError: can only concatenate str (not \"int\") to str")        


if (__name__ == "__main__"):
    for i in range(0, 5):
        test_error_types(i)



"""






Operation completed successfully
All error types tested successfully!
"""