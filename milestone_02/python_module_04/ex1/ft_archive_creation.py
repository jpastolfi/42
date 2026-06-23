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
            print("Error opening file '{}': {}".format(file_name, e))
        except PermissionError as e:
            print("Error opening file '{}': {}".format(file_name, e))
        except Exception as e:
            print("Error opening file '{}': {}".format(file_name, e))
        finally:
            if file is not None:
                file.close()
                print("File '{}' closed.".format(file_name), end="\n\n")

        if file is not None:
            try:
                file = None
                file = open(file_name, 'r+')
                lines: list[str] = list()
                print("Transform data:")
                print("---")
                for line in file.readlines():
                    if line.endswith("\n"):
                        lines.append(line.rstrip() + "#\n")
                    else:
                        lines.append(line.rstrip() + "#")
                for line in lines:
                    print(line, end="")
                print("\n---")
                new_file_name = input("Enter new file name (or empty): ")
                if (new_file_name == file_name):
                    file.seek(0)
                    file.truncate()
                    file.writelines(lines)
                elif new_file_name == "":
                    print("Not saving data")
                else:
                    file.close()
                    file = open(new_file_name, 'w')
                    file.writelines(lines)
            except Exception as e:
                print("Error opening file '{}': {}".format(file_name, e))
            finally:
                if file is not None:
                    file.close()
                if new_file_name != "":
                    print("Data saved in file '{}'.".format(new_file_name))
