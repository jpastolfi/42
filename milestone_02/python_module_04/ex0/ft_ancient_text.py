import sys

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("Usage: ft_ancient_text.py <file>")
    else:
        file_name = sys.argv[1]
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
        finally:
            file.close()
            print("File '{}' closed.".format(file_name))
