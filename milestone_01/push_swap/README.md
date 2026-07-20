*This project has been created as part of the 42 curriculum by jcosta-a, jastolfi.*

# push_swap

![Language](https://img.shields.io/badge/Language-C-blue)
![Norm](https://img.shields.io/badge/Norm-42-black)
![Grade](https://img.shields.io/badge/Grade-100%2F100-brightgreen)

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers stored in **Stack A** using a limited set of stack operations and the fewest moves possible. A second auxiliary stack (**Stack B**) is available as temporary storage.

The project enforces a deep understanding of algorithmic complexity by requiring the implementation of **four distinct sorting strategies**, each targeting a specific complexity class. The program selects the most appropriate strategy at runtime — either automatically based on a disorder metric or manually via a flag.

---

## Instructions

### Compilation

```bash
make        # build push_swap
make re     # clean rebuild
make clean  # remove object files
make fclean # remove objects and binary
```

### Execution

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <integers>
```

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Selection Sort adaptation | O(n²) |
| `--medium` | Bucket Sort adaptation | O(n√n) |
| `--complex` | Radix Sort — LSD bitwise | O(n log n) |
| `--adaptive` | Disorder-based auto-selection | varies |

> If no flag is given, `--adaptive` is used by default.

### Optional Benchmark Mode

Append `--bench` to display performance metrics on `stderr` after sorting:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Output includes:
- Computed disorder (% with 2 decimals)
- Strategy name and complexity class
- Total number of operations
- Count per operation type (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)

### Usage Examples

```bash
# Sort 3 numbers using simple strategy
./push_swap --simple 3 1 2

# Count operations for 5 random numbers
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# Benchmark with 500 random numbers
shuf -i 0-9999 -n 500 > args.txt && ./push_swap --bench $(cat args.txt) 2> bench.txt | wc -l
```

### Error Handling

The program prints `Error` to `stderr` and exits in the following cases:
- Non-integer arguments
- Values outside the `int` range
- Duplicate values
- Invalid flags

```bash
./push_swap --adaptive 0 one 2 3   # Error
./push_swap --simple 3 2 3         # Error (duplicate)
```
---
## Data Structure: Circular Buffer

To achieve maximum efficiency, the stacks in this project are implemented as **Circular Buffers** using static arrays. Instead of physically shifting every element in memory during `rotate` (`ra`/`rb`) or `reverse rotate` (`rra`/`rrb`) operations — which would cost O(n) time — we simply move the logical pointers in O(1) time.

[![Circular-Buffer-Example.png](https://i.postimg.cc/tgw3yWkY/Circular-Buffer-Example.png)](https://postimg.cc/wt5yQtSp)

**How it works:**
* **Capacity & Size:** The physical array has a fixed `data->capacity` (e.g., 10 slots), while `data->size` tracks the active number of elements (e.g., 5).
* **Logical Pointers (`HEAD` & `TAIL`):** The `HEAD` marks the logical top of the stack, and the `TAIL` marks the bottom.
* **Physical Wrap-Around:** When the data reaches the physical boundary of the array (e.g., index 9), the logic seamlessly wraps back to the beginning (index 0).
* **Circular Index Calculation:** To read or write the *i*-th logical element in the stack, we map the logical index to the physical memory using modulo arithmetic:
    ```c
    Physical Index = (HEAD + i) % data->capacity
    ```

**Example (based on the diagram):**
If `HEAD` is at physical index `7` and we want to access the 3rd logical element (`i = 3`):
1. `HEAD + i` = `7 + 3` = `10`
2. `10 % capacity (10)` = `0`
3. The formula maps logical index 3 to **physical index 0**, where the value is `99`.

---

## Algorithms

### Disorder Metric

Before selecting a strategy, the adaptive mode measures how disordered the stack is using an **inversion count ratio**:

```
disorder = number of inverted pairs / total pairs
```

- `0.0` → perfectly sorted
- `1.0` → fully reversed

```c
for i from 0 to size-1:
    for j from i+1 to size-1:
        if a[i] > a[j]:
            mistakes++
        total_pairs++
return mistakes / total_pairs
```

---

### Simple — Selection Sort O(n²)

**Used when:** `disorder < 0.2` (adaptive) or `--simple` flag.

Repeatedly finds the minimum element in Stack A, rotates it to the top (choosing the shortest rotation direction), and pushes it to Stack B. Once Stack A is empty, all elements are pushed back from B to A in ascending order.

**Complexity:**
- Time: O(n²) — for each of the n elements, up to n/2 rotations are needed
- Space: O(n) — one auxiliary stack

---

### Medium — Bucket Sort O(n√n)

**Used when:** `0.2 ≤ disorder < 0.5` (adaptive) or `--medium` flag.

Divides the sorted value range into **√n buckets**. For each bucket, elements falling within the bucket's `[min, max]` range are rotated to the top of Stack A (using shortest path) and pushed to Stack B. After all buckets are processed, Stack B is sorted in descending order by pulling the largest element to the top each time and pushing it back to Stack A.

**Complexity:**
- Time: O(n√n) — √n passes over n elements each
- Space: O(n) — one auxiliary stack

---

### Complex — Radix Sort LSD O(n log n)

**Used when:** `disorder ≥ 0.5` (adaptive) or `--complex` flag.

Applies **indexation** first — each value is replaced by its rank index in the sorted order (0 to n-1). Then a **Least Significant Bit (LSD) Radix Sort** is performed:

- For each bit from least to most significant (log₂(n) passes total):
  - If the current top element's bit is `0` → push to Stack B
  - If the bit is `1` → rotate to the back of Stack A
  - After processing all n elements, pull everything back from B to A

Each pass costs O(n) operations. With log₂(n) passes, total cost is O(n log n).

**Complexity:**
- Time: O(n log n) — log₂(n) passes × n operations each
- Space: O(n) — one auxiliary stack

---

### Adaptive — Disorder-Based Auto-Selection

Measures disorder before any moves, then delegates to the appropriate strategy:

| Disorder | Strategy used | Complexity |
|----------|---------------|------------|
| `< 0.2` | Simple (Selection Sort) | O(n²) |
| `0.2 – 0.5` | Medium (Bucket Sort) | O(n√n) |
| `≥ 0.5` | Complex (Radix LSD) | O(n log n) |

Stacks with 5 or fewer elements are always handled by a dedicated hardcoded small-stack sorter, bypassing disorder measurement entirely.

**Threshold justification:** The thresholds 0.2 and 0.5 were chosen empirically. At low disorder, simple in-place rotations are cheap and avoid the overhead of chunking or indexation. At medium disorder, bucket partitioning amortizes rotation costs across √n groups. At high disorder, the input is chaotic enough that the consistent O(n log n) cost of Radix sort outperforms both alternatives.

---

## Performance Targets

### Expected Performance

| Input size | Pass (min) | Good | Excellent |
|------------|-----------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

### Our Performance

| Strategy | 100 numbers | 500 numbers | 
|------------|-----------|-----------|
| Simple | 1407 ops | 3500 ops |
| Medium | 974 ops | 4469 ops |
| Complex | 1284 ops | 6784 ops |

---

## Resources

### Video Tutorials & Foundations
 
| Video | Topic |
| :--- | :--- |
| [Buffer circulares e ponteiros de função — Rodrigo Maximiano Antunes de Almeida](https://www.youtube.com/watch?v=zakK-FckMZE) | Conceitos e implementação de buffers circulares e o uso de ponteiros de função em C. |
| [Bucket Sort Algorithm: A Step-by-Step Visualization — Quoc Dat Phung](https://www.youtube.com/watch?v=xeT31rm3bN0) | Visualização passo a passo de como a lógica do algoritmo Bucket Sort opera. |
| [Algoritmo de ordenação Bucketsort (ordenação por baldes) — Aulas de Computação](https://www.youtube.com/watch?v=Nc9W_WGYzBc&t=5s) | Explicação teórica e funcionamento detalhado do algoritmo de ordenação por baldes. |
| [Pilha (stack) em Linguagem C (Aula Completa) — Prof. Gustavo Kikee, PhD](https://www.youtube.com/watch?v=Hnm_ma6KZ8A) | Aula completa sobre os fundamentos, operações e a implementação da estrutura de Pilhas (Stacks) em C. |### Video Tutorials & Foundations
 

### AI Usage

AI was used throughout this project for the following tasks:
- **Code comments:** generating inline documentation for strategy functions following a consistent format
- **Algorithm explanations:** clarifying the mechanics of LSD Radix sort and its adaptation to the stack model
- **README drafting:** structuring and writing sections of this document based on the project PDF requirements

All AI-generated content was reviewed, tested, and validated by both team members before being included in the project.

---

## Development History & Last Changes

**Phase 1: Project Setup & Parsing**
- [x] 🟣 Project initialization and initial data structure setup
- [x] 🟣 Implemented parsing logic, flags struct (`t_flags`), and edge case validation (e.g., `-`, `+`, `--adap`)
- [x] 🟢 Fixed syntax errors (`ft_strlen` brace) and refactored string/number conversion using `printf_fd` and a custom `atol`

**Phase 2: Stack Operations Implementation**
- [x] 🔵 Implemented `push` (`pa`, `pb`) operations and integrated `capacity` into data structures
- [x] 🟢 Implemented `swap` operations with static functions for cleaner code
- [x] 🟣 Implemented `rotate` and `reverse rotate` operations
- [x] 🔵 Added detailed comments to all stack operations

**Phase 3: Dispatcher & Simple Algorithm (Selection Sort & Small Stacks)**
- [x] 🔵 Created the dispatcher logic to route algorithms based on stack size
- [x] 🔵 Developed the `strategy_utils` for small stack sorting (2 to 5 numbers)
- [x] 🟣 Built the initial logic, merged selection sort concepts, and finished the `strategy_simple` algorithm
- [x] 🟢 Set up the testing environment for small stacks and performance checks (100/500 numbers)

**Phase 4: Medium Algorithm (Bucket Sort)**
- [x] 🟢 Added custom `ft_sqrt` function to `libft` for dynamic chunk size calculations
- [x] 🔵 Drafted initial logic for chunk sorting within `strategy_medium.c`
- [x] 🟢 Refactored `strategy_medium` and implemented move-reduction logic to improve the overall number of steps
- [x] 🔵 Created and fixed functions to calculate stack disorder and adjusted return types
- [x] 🟢 Added detailed comments to all `strategy_medium` operations
- [x] 🔵 Fixed Norminette issues across the algorithm logic
- [x] 🟢 Refactored logic of min and max from strategy_medium to and array of integers with two numbers, so it is correct with the norm about limit parameters on function

**Phase 5: Complex Algorithm (Radix Sort)**
- [x] 🟢 Implemented `indexation` (Coordinate Compression) specifically for the Radix complex algorithm
- [x] 🟢 Fixed norminette and summarized README for better project tracking and understanding
- [x] 🟢 Implemented new function get_max_bits
- [x] 🔵 Refactored `push_swap.c` and main execution flow to prepare integration with complex and adaptive strategies
- [x] 🟢 Continued Radix Sort groundwork by implementing bit-count calculation (`get_max_bits`) and integrating the required structures for bitwise processing

**Phase 6: Adaptive Algorithm**
- [x] 🔵 Created function to calculate the disorder of the array
- [x] 🔵 Expanded adaptive strategy logic and improved algorithm selection preparation based on stack disorder analysis
- [x] 🟢 Refactored adaptive strategy implementation and fixed Norminette issues across related files

**Phase 7: Benchmark Functionality**
- [x] 🟣 Implemented main logic for benchmark functionality. Changed operations logic and created struct to keep track of operations count
- [x] 🟣 Implemented new function on libft to print also float numbers
- [x] 🟣 Finished benchmark main implemetation
- [x] 🟢 Fixed norminette in all of the files, also replaced some variables names
- [x] 🔵 Change ops logic to hide functions when bench is off
- [x] 🔵 Removed redundant bench flag 

**Phase 8: Project Finalization**
- [x] 🟢 Implement makefile using also makefile from auxiliar libft library
- [x] 🟢 Removed unused variables
- [x] 🔵 Checked and corrected norminette on all files
- [x] 🔵 Fixed bug when calculating the disorder and small tweaks to increase performance
- [x] 🔵 README creation with strategies description and logic behind the project.
- [x] 🟣 Test final program on project official testers
- [x] 🟣 Check all files: names, comments and norminette

## Authors & Contributions

| | Login | Role |
|--|-------|------|
| 🟢 | **jalves** | [Jonathan Alves - Github](https://github.com/jalves-de) |
| 🔵 | **jastolfi** | [João Astolfi - Github](https://github.com/jpastolfi) |
| 🟣 | Both | Pair programming sessions |

*Programming Students @ 42*
