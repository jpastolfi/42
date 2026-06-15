import sys

if __name__ == "__main__":
    index = 1
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    print("No arguments provided!" if len(sys.argv) < 2
          else f"Arguments received: {len(sys.argv) - 1}")
    while index < len(sys.argv):
        print(f"Argument {index}: {sys.argv[index]}")
        index += 1
    print(f"Total arguments: {len(sys.argv)}")
