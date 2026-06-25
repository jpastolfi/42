def secure_archive(
        file_name: str,
        action: str = "r",
        content: str = "Hi there"
        ) -> tuple[bool, str]:
    try:
        with open(file_name, action) as file:
            if action == "r":
                message = file.read()
            else:
                file.write(content)
                message = "Content successfully written to file"
            return (True, message)
    except FileNotFoundError as e:
        return (False, "[Errno {}] {}: '{}'"
                .format(e.errno, e.strerror, e.filename))
    except PermissionError as e:
        return (False, "[Errno {}] {}: '{}'"
                .format(e.errno, e.strerror, e.filename))
    except Exception as e:
        return (False, "Error: {}".format(e))


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    print(secure_archive("nope.txt"))
    print(secure_archive("text.txt"))
    print(secure_archive("a_text.txt"))
    print(secure_archive("a_text.txt", "w"))
