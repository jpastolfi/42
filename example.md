*This project has been created as part of the 42 curriculum by [jcosta-a](https://profile-v3.intra.42.fr/users/jcosta-a).*

# 📚 Libft
![Language](https://img.shields.io/badge/Language-C-blue)
![Norm](https://img.shields.io/badge/Norm-42-black)
![Grade](https://img.shields.io/badge/Grade-100%2F100-brightgreen)
![Pipeline Status](https://gitlab.com/ja-de_42-lisboa/1-common-core/libft/badges/master/pipeline.svg)

This repository contains my implementation of **libft**, the first project of the 42 common core curriculum at **42 Lisboa**, completed in 2026.

---

## 📖 Description

**Libft** is a custom C library built from scratch. The goal is to re-implement a set of standard C library functions — as well as additional utility functions — also relying on `libc`. This project is the foundation of the 42 curriculum: the resulting `libft.a` static library will be reused in virtually every future project.

The library is divided into three parts:

- **Part 1 — Libc functions:** Re-implementations of standard functions from `<string.h>`, `<ctype.h>`, `<stdlib.h>`, and `<strings.h>`, prefixed with `ft_`.
- **Part 2 — Additional functions:** Utility functions not found in libc but useful in everyday C programming (e.g. `ft_substr`, `ft_split`, `ft_itoa`, `ft_putendl_fd`).
- **Part 3 — Linked list functions:** A set of functions to create and manipulate singly linked lists using the `t_list` structure.

---

## 🛠️ Tech Stack & Rules

* **Language:** C
* **Compiler:** `cc` with `-Wall -Wextra -Werror` flags
* **Standard:** All files must follow the **42 Norm**
* **Header:** Every `.c` file includes the mandatory 42 header
* **Authorized Functions:** `malloc`, `free`, `write`
* **No global variables or `for` loops allowed**

---

## 📖 Library Description List

### Part 1 — Libc Functions Re-implementation

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns non-zero if `c` is an alphabetic character. |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns non-zero if `c` is a decimal digit. |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns non-zero if `c` is alphanumeric. |
| `ft_isascii` | `int ft_isascii(int c)` | Returns non-zero if `c` is a 7-bit ASCII character. |
| `ft_isprint` | `int ft_isprint(int c)` | Returns non-zero if `c` is a printable character. |
| `ft_strlen` | `size_t ft_strlen(const char *str)` | Returns the length of the string `str`. |
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills the first `n` bytes of `s` with byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Zeroes the first `n` bytes of `s`. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (non-overlapping). |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (overlap-safe). |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Size-bounded copy of `src` into `dst`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Size-bounded concatenation of `src` onto `dst`. |
| `ft_toupper` | `int ft_toupper(int c)` | Converts `c` to uppercase. |
| `ft_tolower` | `int ft_tolower(int c)` | Converts `c` to lowercase. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Returns a pointer to the first occurrence of `c` in `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Returns a pointer to the last occurrence of `c` in `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares up to `n` bytes of `s1` and `s2`. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Scans `n` bytes of `s` for the first occurrence of `c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares the first `n` bytes of `s1` and `s2`. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Finds `little` inside `big`, searching at most `len` bytes. |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converts the string `nptr` to an integer. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Allocates `nmemb * size` zero-initialised bytes. |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Returns a heap-allocated duplicate of `s`. |

### Part 2 — Additional Functions

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates a substring of `s` starting at `start` with max length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates a new string that is the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates a copy of `s1` with leading/trailing chars from `set` removed. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` on delimiter `c` and returns a NULL-terminated array of strings. |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates a string representation of integer `n`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies `f` to each character of `s` and returns the resulting string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f` in-place to each character of `s`, passing its index. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes character `c` to file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes string `s` to file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes string `s` followed by a newline to file descriptor `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes integer `n` to file descriptor `fd`. |

### Part 3 — Linked-List Functions

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates a new list node with the given `content`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserts `new` at the beginning of the list. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends `new` to the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a single node using `del` on its content. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void*))` | Deletes and frees the entire list. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies function `f` to the content of every node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying `f` to each node's content. |

The `t_list` struct used for the linked lists:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

---

## 🚀 Instructions

### Compilation

Clone the repository and run `make` to compile the library:

```bash
git clone https://gitlab.com/ja-de_42-lisboa/1-common-core/libft
cd libft
make
```

This generates `libft.a` — the static library archive.

### Available Makefile Rules

| Rule | Description |
| :--- | :--- |
| `make` / `make all` | Compiles all functions (Part 1, 2 and 3). |
| `make clean` | Removes object files (`.o`). |
| `make fclean` | Removes object files and the `libft.a` archive. |
| `make re` | Runs `fclean` then `all`. |

### Using the Library in Your Project

To use `libft` in another project, include the header and link the archive:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

Make sure `libft.h` and `libft.a` are accessible from your project's directory (or adjust the `-L` and `-I` paths accordingly).

---

## 📚 Resources

### Documentation & References

- [**man7.org — Linux man pages**](https://man7.org/linux/man-pages/) — Detailed manual pages for every libc function (e.g. `man 3 memcpy`).
- [**42 Norm — norminette**](https://github.com/42School/norminette) — The official 42 coding style enforcer. Every file must pass norminette before submission.

### Video Tutorials & Foundations

A set of video tutorials that helped build a stronger understanding some of the concepts applied in this project:

| Video | Topic |
| :--- | :--- |
| [Compilation Phases in C - Adriano Santos](https://www.youtube.com/watch?v=QbMLHmjEbSY) | How `.c` files go through preprocessing, compilation, assembly, and linking into an executable or archive. |
| [Understanding stack and heap memory — Mike Shah](https://www.youtube.com/watch?v=sXFVaRtobYU&list=PLvv0ScY6vfd8M-Mi_Vyrg7KgISTW3Sklt&index=4) | How stack and heap memory differ, how dynamic allocation works, and why this matters for functions like `malloc` and `free`. |
| [memset, memcpy, strcpy, memmove — Mike Shah](https://www.youtube.com/watch?v=TGlePWhNgY0&list=PLvv0ScY6vfd8M-Mi_Vyrg7KgISTW3Sklt&index=18) | Deep dive into key memory manipulation functions — their differences, use cases, and how to re-implement them safely. |
| [Learn Linked Lists in 13 minutes — Bro Code](https://www.youtube.com/watch?v=N6dOwBde7-M) | Building and traversing singly linked lists — directly applied in the bonus part of this project. |

### AI Usage

AI (Claude & Gemini) was used during this project for the following purposes:

- **Concept clarification:** understanding the exact behaviour of functions such as `ft_strlcat`, `ft_memmove`, and `ft_strnstr` by comparing descriptions from the man pages with alternative explanations.
- **Code review:** checking that implementations matched the expected libc behaviour described in the subject.
- **README writing:** Drafting and structuring this README document.

AI was **not** used to generate or write any C source code submitted as part of this project.

---

Developed by [Jonathan Alves](https://gitlab.com/ja-de_42-lisboa) — 42 Lisboa, 2026