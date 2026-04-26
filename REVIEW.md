# libft Review: Differences from Original Functions & Evaluation Prep

---

## Part 1 — Differences and Potential Issues

### ft_memcpy.c
**Behaviour difference:** The null check is:
```c
if (!dest && !src)
    return (NULL);
```
This only returns NULL when **both** pointers are null. The original `memcpy` simply has undefined behaviour when either pointer is null and `n > 0`. The common 42 pattern is accepted by evaluators, but be aware: if only one of the two is null, the function proceeds and will crash. The standard says nothing about returning NULL—it says the result is `dest`.

---

### ft_memmove.c
**Same null check issue as `ft_memcpy`**: `if (!dest && !src)` only guards the case where both are null. The standard guarantees no null check at all—both have undefined behaviour with null pointers.

---

### ft_atoi.c
Three issues:

1. **Dead overflow check:** `total * 10 < INT_MIN` can never be true during the accumulation loop because `total` is always `>= 0` at that point (the sign is applied at the very end with `* signal`). This branch of the condition is unreachable.

2. **Incomplete overflow detection:** The check `total * 10 > INT_MAX` happens *before* the digit is added. A value of `total = 214748364` passes the check (`2147483640 <= INT_MAX = 2147483647`), then adding digit `9` gives `total = 2147483649`, which overflows `int` when cast at the return. The check should cover `total * 10 + digit`.

3. **Wrong overflow return value:** The function returns `0` on detected overflow. The original `atoi` has **undefined behaviour** on overflow—on Linux/glibc it typically wraps/truncates, not returns zero. If an evaluator tests `ft_atoi("9999999999")`, they will get `0` from yours and a wrap-around value from the original.

---

### ft_calloc.c
**Portability issue:** Uses `__SIZE_MAX__`, which is a GCC-specific predefined macro. The standard portable way is to include `<stdint.h>` or `<limits.h>` and use `SIZE_MAX`. On non-GCC compilers this would fail to compile.

---

### ft_strtrim.c
**Bug with empty string input:** When `s1 = ""`, `ft_strlen(s1)` returns `0`. Then:
```c
length = ft_strlen(s1) - 1;  // 0 - 1 with size_t = SIZE_MAX (underflow)
```
`length` is declared as `size_t` (unsigned), so it wraps to `SIZE_MAX`. The second while loop then evaluates `while (SIZE_MAX > 0)` which is `true`, and attempts to read `s1[SIZE_MAX]`—this is a **buffer overread / undefined behaviour**, almost certainly a segfault on a 64-bit system since that address is unmapped.

The case of an all-trimmed non-empty string (e.g., `ft_strtrim("aaa", "a")`) works by coincidence: `ft_substr` is called with `start >= s_len` and returns `ft_strdup("")` before any real damage occurs.

---

### ft_strrchr.c
**Type mismatch:** `ft_strlen` returns `size_t` but the result is assigned to `int len`. If the string length exceeds `INT_MAX`, `len` overflows and the loop breaks immediately with wrong results. In practice strings are never that long, but it is a latent defect.

---

### ft_strncmp.c
The loop structure is unusual and worth being able to explain:
```c
while (s1[index] != '\0')
{
    if (s1[index] == s2[index] && index < n - 1)
        index++;
    else
        break;
}
return ((unsigned char)s1[index] - (unsigned char)s2[index]);
```
The only case the loop does **not** advance is: characters differ, OR we have reached position `n-1`. It then returns the difference. This is functionally equivalent to the standard `strncmp`, but the standard loop normally checks `s2` for `'\0'` explicitly. Here, if `s2` reaches `'\0'` before `s1`, the characters differ (`s1[i] != '\0'` but `s2[i] == '\0'`), so the else branch breaks and the correct positive difference is returned. All known edge cases produce correct results, but be prepared to justify this logic.

---

### ft_lstmap.c
**Memory leak on allocation failure:** When `ft_lstnew(new_content)` fails:
```c
new_content = f(lst->content);   // allocates memory
new_node = ft_lstnew(new_content);
if (!new_node)
{
    // new_content is never freed here — it is leaked
    ft_lstclear(&result, del);
    return (NULL);
}
```
If `f` allocates memory (as the commented example with `ft_strdup` does), that allocation is lost. The correct cleanup requires calling `del(new_content)` before calling `ft_lstclear`. This is a genuine memory leak that any memory checker (valgrind) will catch.

---

### ft_striteri.c
**Unnecessary suppression:** Line 21 has `(void)f;`, which silences an "unused variable" warning—but `f` **is** used on line 25. The cast is harmless but incorrect and confusing.

---

### ft_strnstr.c
**Minor:** The inner loop guards against exceeding `len` with `index + inner_index < len` but does **not** explicitly check `big[index + inner_index] != '\0'`. In practice this is safe: when the outer string's null terminator is reached, it simply mismatches the needle (unless the needle also ends, in which case a correct match is returned). No memory outside the string is read because the null terminator is a valid part of the array. Behaviour is correct, but the logic is subtler than the standard reference implementation.

---

### Return values of is*() functions
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isprint`, `ft_isascii` all return `0` or `1` (from a boolean expression). The C standard only requires a **non-zero** value for true, so `1` is fully compliant. However, older glibc versions returned values from an internal table (e.g., 8 for `isupper`). This difference is irrelevant for 42 evaluation.

---

## Part 2 — Concepts and Questions for the Evaluation

### Memory and Pointers

**Q: Why do memory functions (`ft_memcpy`, `ft_memset`, etc.) cast the pointer to `unsigned char *` internally?**
A: Because `void *` cannot be dereferenced or incremented. `unsigned char *` is used specifically because the C standard guarantees it has no padding, it can alias any type, and one `unsigned char` is exactly one byte. Using `char *` would work on most systems but introduces signed/unsigned comparison subtleties.

**Q: What is the difference between `memcpy` and `memmove`?**
A: `memcpy` has undefined behaviour when the source and destination memory regions overlap. `memmove` is safe for overlapping regions because it checks the relative positions of the pointers and copies backward when `dest > src` (so already-written bytes aren't read from before being overwritten).

**Q: What does `void *` mean as a return type?**
A: A generic pointer with no type information. It can be implicitly cast to or from any other pointer type in C (not in C++). It is used when a function should work with any data type, like `malloc` or `memset`.

**Q: What is `size_t` and why is it used for sizes?**
A: `size_t` is the unsigned integer type returned by `sizeof`. It is guaranteed to be large enough to represent the size of the largest possible object on the platform (32-bit on 32-bit systems, 64-bit on 64-bit systems). It is used for sizes and counts to avoid negative values and to match platform width.

**Q: What is a null pointer and what happens if you dereference one?**
A: A null pointer is a pointer with the value `0` (or `NULL`). Dereferencing it is **undefined behaviour**—on most systems it causes a segmentation fault because address 0 is not mapped.

---

### Strings

**Q: Why does `ft_strchr` (and `ft_strrchr`) compare using `(unsigned char)c`?**
A: The `int c` parameter must be cast to `unsigned char` for comparison against `char` values because `char` may be signed, which means characters with values above 127 would be represented as negative numbers. The cast ensures consistent comparison using the raw byte value, matching the behaviour of the standard library.

**Q: What does `ft_strlcpy` return, and why?**
A: It returns the length of `src` (not the number of bytes written). This allows the caller to detect truncation: if the return value is `>= size`, the destination was too small and the string was truncated.

**Q: What does `ft_strlcat` return when `dst_len >= size`?**
A: It returns `size + strlen(src)`. This still indicates the total length that the fully concatenated string would have had, letting the caller detect truncation.

**Q: Why must strings in C be null-terminated?**
A: Because there is no length stored with the string. Functions like `strlen` simply scan forward until they find a `'\0'` byte. Without it, they would read past the array into undefined memory.

**Q: What is the difference between `strncmp` and `strcmp`?**
A: `strcmp` compares until a null terminator or a difference is found, with no limit. `strncmp` stops after at most `n` characters, which is useful for comparing prefixes without risking reading past a known boundary.

---

### Numbers and Overflow

**Q: Why is `INT_MIN` a special case in `ft_itoa` and `ft_putnbr_fd`?**
A: On two's complement systems (all modern CPUs), `INT_MIN = -2147483648` and `INT_MAX = 2147483647`. Negating `INT_MIN` would give `2147483648`, which **overflows** `int`. That is why `ft_itoa` casts to `long` before negating, and `ft_putnbr_fd` hardcodes the string `"-2147483648"`.

**Q: What is integer overflow and is it defined behaviour?**
A: Signed integer overflow is **undefined behaviour** in C. The compiler is allowed to assume it never happens and may optimise accordingly. Unsigned integer overflow is **defined**—it wraps modulo `2^N` (e.g., `SIZE_MAX + 1 == 0` for `size_t`).

**Q: What does `atoi` do with a number larger than INT_MAX?**
A: The standard says the behaviour is **undefined**. In practice on Linux/glibc it wraps. Your `ft_atoi` returns `0` in some overflow cases, which differs from the original.

---

### Memory Allocation

**Q: What is the difference between `malloc` and `calloc`?**
A: Both allocate memory on the heap. `calloc(n, size)` allocates `n * size` bytes and **zero-initialises** them. `malloc(n)` allocates `n` bytes and leaves the content **uninitialised** (garbage).

**Q: What does `malloc` return on failure?**
A: It returns `NULL`. Every allocation must be checked before use.

**Q: What is a memory leak?**
A: Memory that was `malloc`-ed but never `free`-d before the pointer to it is lost. The memory remains reserved for the process until it exits. In long-running programs, leaks accumulate and eventually exhaust available memory.

**Q: In `ft_calloc`, what is the overflow check `SIZE_MAX / nmemb < size` protecting against?**
A: If `nmemb * size` would overflow `size_t` (giving a small result), the allocation would succeed with a tiny buffer that is later written to as if it were large. The division check detects this before multiplication: if `SIZE_MAX / nmemb < size`, then `nmemb * size > SIZE_MAX`.

---

### File Descriptors and System Calls

**Q: What are file descriptors 0, 1, and 2?**
A: 0 is `stdin` (standard input), 1 is `stdout` (standard output), 2 is `stderr` (standard error). The `write` system call writes `n` bytes from a buffer to the given file descriptor.

**Q: Why use `write` instead of `printf` in `ft_putchar_fd`?**
A: `printf` writes to `stdout` only (via `FILE *`) and uses buffering. `write` is a raw system call that works on any file descriptor and is unbuffered, which is required for writing to `stderr` or arbitrary fds.

---

### Linked Lists

**Q: What is the `t_list` structure?**
A:
```c
typedef struct s_list {
    void            *content;   // pointer to any data
    struct s_list   *next;      // pointer to the next node
} t_list;
```
It is a singly-linked list. `content` is `void *` so it can hold a pointer to any type.

**Q: Why does `ft_lstadd_front` take a `t_list **` (double pointer)?**
A: Because it needs to modify the caller's pointer to the head of the list. If it only took `t_list *`, changes to the local copy would not propagate back. The double pointer lets the function write to `*lst`, updating the head.

**Q: What does `ft_lstclear` do and what is the `del` function for?**
A: It frees every node in the list and sets the head pointer to `NULL`. The `del` function is called on each node's `content` before the node itself is freed, because `ft_lstclear` does not know how to free the content (it is `void *`). The caller provides the appropriate destructor.

**Q: In `ft_lstmap`, what should happen if `ft_lstnew` fails mid-way?**
A: All nodes created so far must be freed (via `ft_lstclear`), and the content that was just produced by `f` but not yet attached to any node must also be freed via `del`. The current implementation **misses** the `del(new_content)` call, causing a memory leak.

---

### Function Pointers

**Q: What is a function pointer?**
A: A variable that holds the address of a function, allowing it to be called indirectly or passed as an argument. Example:
```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```
Here `f` is a pointer to a function that takes `unsigned int` and `char *` and returns `void`.

**Q: What is the difference between `ft_strmapi` and `ft_striteri`?**
A: `ft_strmapi` returns a **new** allocated string where each character is the result of `f(index, char)`. `ft_striteri` modifies the string **in place** by passing a pointer to each character to `f`. `ft_strmapi` creates; `ft_striteri` mutates.

---

### C Language Concepts

**Q: What does `static` mean on a function in C?**
A: It limits the function's linkage to the current translation unit (the `.c` file). The function is not visible to other `.c` files and cannot be called from outside. Used for helper functions that are implementation details.

**Q: What is the difference between `char` and `unsigned char`?**
A: `char` signedness is **implementation-defined** (signed on most x86 platforms, unsigned on ARM by default). `unsigned char` is always 0–255. When doing byte-level arithmetic or comparisons with values > 127, `unsigned char` must be used to avoid sign extension producing negative numbers.

**Q: What is `const` and why are many parameters declared `const char *`?**
A: `const` tells the compiler (and the reader) that the function will not modify the data through that pointer. It allows passing string literals (which are read-only) safely, and it documents intent. Modifying a `const`-qualified object is undefined behaviour.

**Q: What is undefined behaviour (UB)?**
A: Any operation whose result the C standard leaves unspecified. The compiler may generate any code, including code that seems to "work", crashes, or silently corrupts data. Examples in this project: dereferencing NULL, signed integer overflow, reading past the end of an array (e.g., the empty-string bug in `ft_strtrim`).

**Q: Why does `ft_bzero` exist when `memset(s, 0, n)` does the same thing?**
A: `bzero` is a POSIX legacy function (originally from BSD). It is deprecated in modern POSIX (2008+) because `memset` is the standard equivalent. `libft` reimplements it because older code and some 42 projects still reference it.

---

## Part 3 — Makefile Issues

### Duplicate entries in FILES

The `FILES` variable in the Makefile lists the following source files **twice**:

```
ft_substr.c  ft_strjoin.c  ft_strtrim.c  ft_split.c   ft_itoa.c
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c
ft_putendl_fd.c ft_putnbr_fd.c
```

Each duplicate produces a second `.o` file that gets archived into `libft.a` a second time. The linker silently takes the first definition it finds, so behaviour is correct — but it wastes compile time and slightly bloats the archive. Fix: remove the second block of duplicates.

---

### Missing `bonus` Makefile rule

The standard 42 libft subject requires a separate `bonus` rule that compiles only the linked-list (`ft_lst*`) functions. The current Makefile compiles everything — including bonus functions — under `all`. This means:

- `make` will compile the bonus functions even when the evaluator only tests Part 1 and Part 2.
- If the evaluator explicitly runs `make bonus`, it will fail (no such target).

Fix: add a `bonus` target that compiles only `ft_lst*.c` and archives them separately (or appends to `libft.a`).

---

### `re` target does not use `$(MAKE)`

```make
re:
	fclean
	all
```

This calls `fclean` and `all` as sub-targets of the current make invocation, which works correctly for sequential execution. However, the 42 Norm and common convention expect either:

```make
re: fclean all
```

(prerequisites, which make handles natively) or:

```make
re:
	$(MAKE) fclean
	$(MAKE) all
```

(recursive make, preserves flags passed on the command line). The current form is functionally equivalent in practice but looks like it was meant to be written as dependencies. Using `re: fclean all` is the idiomatic way.

---

### No `CC` variable

The compile rule uses `cc` directly:

```make
%.o:%.c
	cc  -c ${FLAGS} $< -o $@
```

Convention is to define `CC = cc` at the top and use `$(CC)` in rules, making it trivial to swap compilers. Minor, but inconsistent with how `FLAGS` is already abstracted. Also note the double space between `cc` and `-c` — harmless but untidy.
