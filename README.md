# 42 Lisbon — Projects

My project portfolio from the 42 Lisbon software engineering programme. The curriculum is structured around self-paced, peer-evaluated projects that progress through milestones.

---

## Milestone 00 — Foundations

| Project | Description | Skills |
|---------|-------------|--------|
| **[libft](milestone_00/libft/)** | A from-scratch re-implementation of a large subset of the C standard library, split into three parts: libc functions (e.g. `ft_memset`, `ft_strlen`, `ft_atoi`), additional utility functions (e.g. `ft_split`, `ft_itoa`, `ft_strtrim`), and bonus linked list manipulation functions. The resulting library is reused in virtually every subsequent C project. | C, memory management, string manipulation, linked lists, Makefile, static libraries (`.a`) |

---

## Milestone 01 — Core C

| Project | Description | Skills |
|---------|-------------|--------|
| **[ft_printf](milestone_01/printf/)** | Re-implementation of the standard C `printf()` function, supporting the most common conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`). | C, variadic functions (`va_list`, `va_arg`), string formatting, Makefile |
| **[get_next_line](milestone_01/get_next_line/)** | A function that reads and returns one line at a time from a file descriptor, handling multiple file descriptors simultaneously in the bonus part. | C, static variables, file descriptors, buffer management, memory management |
| **[push_swap](milestone_01/push_swap/)** | A group project (2 learners) that sorts a stack of integers using two stacks (A and B) and a strictly limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), with the goal of minimising the total number of moves. Requires implementing and comparing multiple sorting strategies with attention to algorithmic complexity (Big-O). The bonus part adds a `checker` program that validates a sequence of instructions. | C, sorting algorithms, algorithmic complexity (Big-O), stack data structures, algorithm optimisation |

---

## Milestone 02 — Systems & Python

### Systems

| Project | Description | Skills |
|---------|-------------|--------|
| **[Born2beRoot](milestone_02/born2beroot/)** | System administration project focused on setting up a hardened Linux virtual machine from scratch, enforcing strict security policies, configuring services and users, and automating monitoring. | Virtualization (VirtualBox / UTM), Linux (Debian / Rocky), SSH, UFW firewall, sudo policies, LVM partitioning, shell scripting, cron |
| **[A-Maze-ing](milestone_02/a-maze-ing/)** | A maze generator that produces and renders perfect mazes (one unique path between any two points). The generator is configurable via an input file and outputs a visual representation of the result. Closely related to spanning tree algorithms. | Python, graph theory, maze generation algorithms (Prim's / Kruskal's / recursive backtracker), type hints & mypy, flake8, pytest/unittest, pip packaging, file I/O |

### Python for Data Engineering (Modules 00–10)

| Module | Title | Description | Skills |
|--------|-------|-------------|--------|
| **[Module 00](milestone_02/python_module_00/)** | *Growing Code* | Introduction to Python's syntax and semantics through community garden data analysis. Covers expressions, variables, functions, and control flow. | Python basics, expressions, variables, functions, control flow, type annotations |
| **[Module 01](milestone_02/python_module_01/)** | *Code Cultivation* | Building a digital garden ecosystem to explore advanced Python features. Focuses on designing data-driven systems using object-oriented principles. | OOP, classes, encapsulation, constructors, inheritance, class methods, factory pattern |
| **[Module 02](milestone_02/python_module_02/)** | *Garden Guardian* | Building resilient agricultural data pipelines that gracefully handle sensor failures and data anomalies. | Exception handling (`try/except/finally`), custom exception types, data validation, error propagation |
| **[Module 03](milestone_02/python_module_03/)** | *Data Quest* | Mastering Python's built-in data structures while processing game data at scale — inspired by real-world performance challenges such as Twitter's early scaling issues. | Lists, tuples, sets, dictionaries, generators, comprehensions, algorithmic complexity |
| **[Module 04](milestone_02/python_module_04/)** | *Data Archivist* | Mastering file operations to build archival systems that preserve data integrity even under unexpected failures. | File I/O (`open`, `read`, `write`), data streams, context managers (`with`), binary vs. text mode |
| **[Module 05](milestone_02/python_module_05/)** | *Code Nexus* | Building advanced data processing pipelines using polymorphism to handle diverse data stream types within a single unified workflow. | Abstract classes (`ABC`), method overriding, subtype polymorphism, inheritance hierarchies, `@abstractmethod` |
| **[Module 06](milestone_02/python_module_06/)** | *The Codex* | Exploring Python's module and package system through four challenges: package initialization, import pathways, absolute vs. relative imports, and resolving circular dependencies. | Python import system, `__init__.py`, absolute vs. relative imports, package structure, circular dependency resolution |
| **[Module 07](milestone_02/python_module_07/)** | *DataDeck* | Designing a modular card system to master object-oriented design patterns, focusing on abstraction and interface contracts. | Abstract classes, interfaces, factory pattern, design patterns, `@abstractmethod`, multiple inheritance |
| **[Module 08](milestone_02/python_module_08/)** | *The Matrix* | Setting up production-grade Python data environments: isolated virtual environments, dependency management, and environment variable configuration. | `venv`, `pip`, `requirements.txt`, `.env` files, environment variables, data pipeline architecture |
| **[Module 09](milestone_02/python_module_09/)** | *Cosmic Data* | Mastering Pydantic for robust data validation through space-themed exercises, from simple models to complex nested structures with custom validators. | Pydantic v2, data models, field validators, custom validation logic, nested models, type coercion |
| **[Module 10](milestone_02/python_module_10/)** | *FuncMage* | Learning functional programming techniques through five exercises of increasing complexity, covering Python's higher-order function toolkit. | Lambda functions, `map`, `filter`, `reduce`, decorators, closures, lexical scoping, higher-order functions |

---

## Author

**Joao Astolfi** — jpastolfi@gmail.com
