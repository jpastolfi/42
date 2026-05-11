*This project was developed as part of the 42 curriculum by jpastolfi*

# ft_printf
![Language](https://img.shields.io/badge/Language-C-blue)
![Norm](https://img.shields.io/badge/Norm-42-black)

This repository contains my implementation of **ft_printf**, a project from the 42 common core curriculum at **42 Lisboa**, completed in 2026.

---

## Description

**ft_printf** is a custom re-implementation of the standard C `printf` function, built from scratch without relying on it. The goal is to understand how variadic functions work in C and to reproduce the core formatting behaviour of `printf` using only low-level write operations.

The function parses a format string character by character and, whenever it encounters a `%` conversion specifier, retrieves the corresponding argument from the variadic list and prints it in the appropriate format. The total number of characters written is accumulated and returned, mirroring the real `printf`.

### Algorithm & Design Choices

`ft_printf` iterates over the format string one character at a time. When it encounters a `%`, it advances one position and calls `dispatcher`, which reads the specifier character and delegates to the correct output function. Non-specifier characters are written directly via `write_char`.

Helpers have been developed in `utils.c` and `ft_printf.c`. Each one returns the number of bytes it wrote, so the count can be accumulated into `counter` and returned at the end of `ft_printf`.

For the `%p` (pointer) specifier, `write_pointer` handles the full 64-bit address range using internal recursion — printing the `"0x"` prefix only at the deepest recursion level and unwinding digit by digit. This avoids the truncation that would happen if the address were cast to `unsigned int`.

**Supported conversion specifiers:**

| Specifier | Output |
| :--- | :--- |
| `%c` | Single character |
| `%s` | String (`(null)` if pointer is NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%p` | Pointer address (`(nil)` if NULL) |
| `%%` | Literal `%` character |

---

## Tech Stack & Rules

* **Language:** C
* **Compiler:** `cc` with `-Wall -Wextra -Werror` flags
* **Standard:** All files must follow the **42 Norm**
* **Header:** Every `.c` file includes the mandatory 42 header
* **Authorized Functions:** `write`, `va_start`, `va_arg`, `va_end`, `va_copy`
* **No global variables or `for` loops allowed**

---

## Function Reference

### ft_printf

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_printf` | `int ft_printf(const char *string, ...)` | Parses the format string and prints each argument according to its specifier. Returns the total number of characters printed. |

### Output Helpers (`utils.c`)

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `write_char` | `int write_char(int c)` | Writes a single character to stdout. Returns `1`. |
| `write_string` | `int write_string(char *string)` | Writes a string to stdout. Prints `(null)` if pointer is NULL. Returns character count. |
| `write_integer` | `int write_integer(int number)` | Writes a signed decimal integer to stdout. Handles `INT_MIN` explicitly. Returns character count. |
| `write_unsigned_integer` | `int write_unsigned_integer(unsigned int number)` | Writes an unsigned decimal integer to stdout. Returns character count. |
| `write_hexadecimal` | `int write_hexadecimal(unsigned int number, char letter)` | Writes an unsigned integer as hexadecimal to stdout. Pass `'x'` for lowercase or `'X'` for uppercase. Returns character count. |
| `write_pointer` | `int write_pointer(void *pointer)` | Writes a pointer address prefixed with `0x` to stdout using recursive 64-bit-safe hex printing. Prints `(nil)` if NULL. Returns character count. |
| `dispatcher` | `int dispatcher(char formatter, va_list *args)` | Reads the next variadic argument and calls the appropriate output function based on the specifier character. Returns character count. |

---

## Instructions

### Compilation

Clone the repository and run `make` to compile the library:

```bash
git clone <repository-url>
cd ft_printf
make
```

This generates `libftprintf.a` — the static library archive.

### Available Makefile Rules

| Rule | Description |
| :--- | :--- |
| `make` / `make all` | Compiles `ft_printf.c` and `utils.c` and bundles them into `libftprintf.a`. |
| `make clean` | Removes all object files (`.o`). |
| `make fclean` | Removes object files and the `libftprintf.a` archive. |
| `make re` | Runs `fclean` then `all`. |

### Using the Library in Your Project

Include the header and link the archive when compiling:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
./my_program
```

Make sure `ft_printf.h` and `libftprintf.a` are accessible from your project directory, or adjust the `-L` and `-I` paths accordingly.

### Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Characters printed: %d\n", n);
    ft_printf("Pointer: %p\n", &n);
    ft_printf("Hex: %x | %X\n", 255, 255);
    return (0);
}
```

Expected output:

```
Hello, world! You are 42 years old.
Characters printed: 36
Pointer: 0x[address]
Hex: ff | FF
```

---

## Resources

### Documentation & References

- [**man7.org — Linux man pages**](https://man7.org/linux/man-pages/) — Manual pages for `printf`, `stdarg`, and related functions (`man 3 printf`, `man 3 stdarg`).
- [**cppreference — printf**](https://en.cppreference.com/w/c/io/fprintf) — Full specification of `printf` conversion specifiers and return behaviour.
- [**42 Norm — norminette**](https://github.com/42School/norminette) — The official 42 coding style enforcer. Every file must pass norminette before submission.

### Video Tutorials & Foundations

| Video | Topic |
| :--- | :--- |
| [Variadic Functions in C — Jacob Sorber](https://www.youtube.com/watch?v=S-ak715zIIE) | How `va_list`, `va_start`, `va_arg`, and `va_end` work under the hood — the core mechanism behind `ft_printf`. |

### AI Usage

AI was used during this project for the following purposes:

- **Concept clarification:** understanding edge case behaviour such as `%p` with a NULL pointer, the 64-bit truncation issue with pointer addresses, and the exact return value semantics of `printf`.

AI was **not** used to generate or write any C source code submitted as part of this project.

---

Developed by [jastolfi] — 42 Lisboa, 2026
