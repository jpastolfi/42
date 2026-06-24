import sys

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("Usage: ft_ancient_text.py <file>")
    else:
        file_name = sys.argv[1]
        new_file_name: str = ""
        file = None
        try:
            print("=== Cyber Archives Recovery ===")
            print("Accessing file '{}'".format(file_name))
            file = open(file_name, 'r')
            content = file.read()
            print("---")
            print(content)
            print("---")
        except FileNotFoundError as e:
            sys.stderr.write(
                "[STDERR] Error opening file '{}': {}".format(file_name, e)
                )
        except PermissionError as e:
            sys.stderr.write(
                "[STDERR] Error opening file '{}': {}".format(file_name, e)
                )
        except Exception as e:
            sys.stderr.write(
                "[STDERR] Error opening file '{}': {}".format(file_name, e)
                )
        finally:
            if file is not None:
                file.close()
                print("File '{}' closed.".format(file_name), end="\n\n")

        if file is not None:
            try:
                i: int = 0
                file = None
                file = open(file_name, 'r+')
                lines: list[str] = list()
                print("Transform data:")
                print("---")
                lines = file.read().split("\n")
                for line in lines:
                    print(line + "#")
                print("---")
                print("Enter new file name (or empty): ", end="")
                sys.stdout.flush()
                new_file_name = sys.stdin.readline().strip()
                if new_file_name == "":
                    print("Not saving data")
                else:
                    file.close()
                    file = open(new_file_name, 'w')
                    for line in lines:
                        file.write(line + "#")
                        i += 1
                        if len(lines) != i:
                            file.write("\n")

            except Exception as e:
                sys.stderr.write(
                    "[STDERR] Error opening file '{}': {}".format(file_name, e)
                    )
            finally:
                if file is not None:
                    file.close()
                if new_file_name != "":
                    print("Data saved in file '{}'.".format(new_file_name))
