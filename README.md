*This project has been created as part of the 42 curriculum by legomez & gtomas-m.*

# Push_swap

## Table of Contents

- [Description](#description)
- [Algorithm / Architecture: explanation and justification](#algorithm--architecture-explanation-and-justification)
- [Instructions](#instructions)
- [Team and contributions](#team-and-contributions)
- [Resources](#resources)

## Description

**push_swap** sorts a list of integers using two stacks (`a` and `b`) and a fixed set of 11 operations, aiming to use as few operations as possible. The program prints the sequence of operations needed to leave stack `a` sorted in ascending order and stack `b` empty.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | Swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | Take the top of `b` and put it on `a` / take the top of `a` and put it on `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (the first element becomes the last) |
| `rra` / `rrb` / `rrr` | Rotate `a` / `b` / both down (the last element becomes the first) |

The project implements **three sorting strategies of different complexity** plus an **adaptive mode** that picks one of them based on how disordered the input is. A `--bench` mode reports the disorder, the strategy used and the number of operations of each type.

**Allowed external functions:** `read`, `write`, `malloc`, `free`, `exit`.

### Project Files

<!-- FILES_START -->
```c
checker_aux.c			checker.c	 			ft_compute_disorder.c	ft_linked_list_additions.c	ft_linked_list.c	
ft_parse_input.c	 	ft_push_operations.c	ft_radix_lsd.c	 		ft_reverse_operations.c		ft_rotate_operations.c	
ft_runner.c	 			ft_stack_error.c		ft_swap_operations.c	main.c	 					range_sort.c
small_sort.c			sort_aux.c				turk_sort.c
```
<!-- FILES_END -->

| Area | Files |
|---|---|
| Entry point and mode selection | [`main.c`](main.c), [`ft_runner.c`](ft_runner.c) |
| Input parsing and errors | [`ft_parse_input.c`](ft_parse_input.c), [`ft_stack_error.c`](ft_stack_error.c) |
| Linked list | [`ft_linked_list.c`](ft_linked_list.c), [`ft_linked_list_additions.c`](ft_linked_list_additions.c) |
| Operations (raw, print and count) (`sa`, `pb`, `rr`…) | [`ft_push_operations.c`](ft_push_operations.c), [`ft_swap_operations.c`](ft_swap_operations.c), [`ft_rotate_operations.c`](ft_rotate_operations.c), [`ft_reverse_operations.c`](ft_reverse_operations.c) |
| Disorder metric | [`ft_compute_disorder.c`](ft_compute_disorder.c) |
| Small amount of numbers algorithm (small sort) | [`small_sort.c`](small_sort.c) |
| Simple algorithm (Turk) | [`turk_sort.c`](turk_sort.c), [`sort_aux.c`](sort_aux.c) |
| Medium algorithm (range sort) | [`range_sort.c`](range_sort.c), [`sort_aux.c`](sort_aux.c) |
| Complex algorithm (radix LSD) | [`ft_radix_lsd.c`](ft_radix_lsd.c) |
| Bonus checker | [`checker.c`](checker.c), [`checker_aux.c`](checker_aux.c) |

## Algorithm / Architecture: explanation and justification

### Data structures

Each stack is a **singly linked list** wrapped in a `t_stack`:

```c
typedef struct s_node
{
	int				val;       // original value
	int				norm_val;  // rank of the value: 0 .. n-1
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	size;     // number of nodes, kept up to date by every operation
	size_t	ops[7];   // per-operation counters, used by --bench
	t_node	*head;
}	t_stack;
```

- **Linked list:** push, swap and rotations only touch the first and last nodes, so a list makes them cheap and easy to reason about.
- **`size` stored in the stack:** every algorithm asks for the size many times (half of the stack, distance to the bottom…), so it is kept up to date instead of being recounted.
- **Normalization (`norm_val`):** before sorting, each value is replaced by its rank (the smallest becomes `0`, the largest `n-1`). The algorithms only work with ranks, which makes them independent of the actual values (negatives, big gaps…) and is required by radix, which works on the bits of non-negative (*unsigned*) integers.
- **`t_cost`:** a small struct `{ca, cb}` that holds the number of rotations needed in `a` and `b`. It is returned by value, so no dynamic memory is needed.

### Disorder metric

`compute_disorder` counts, among all pairs `(i, j)` with `i < j`, how many are in the wrong order (inversions), and returns the ratio in hundredths of a percent (`0` = sorted, `10000` = fully reversed). It is used to:
- skip sorting when the input is already sorted;
- choose the strategy in adaptive mode;
- report the disorder in `--bench`.

### Small: small sort (up to 5 numbers)

For very small inputs, a dedicated strategy gives the minimum number of operations. It is used for up to 5-10 numbers, where it beats the other algorithms.

1. While `a` has more than 3 elements: bring the **minimum** of `a` to the top by the shortest path (`ra` or `rra`) and `pb` it.
2. Sort the remaining 3 elements with `sort_three`:
   - if the maximum is on top → `ra`; if it is in the middle → `rra` (the maximum ends at the bottom);
   - then, if the first two are swapped → `sa`.
3. `pa` everything back. The minimums were pushed from smallest to largest, so `b` returns them in the right order: **no rotations are needed on the way back**.

**Worked example** (`a = 5 1 4 2 3`):

| Step | Operations | `a` (top first) | `b` (top first) |
|---|---|---|---|
| Push the minimum (`1`) | `ra` `pb` | `4 2 3 5` | `1` |
| Push the next minimum (`2`) | `ra` `pb` | `3 5 4` | `2 1` |
| `sort_three` | `rra` `sa` | `3 4 5` | |
| Push everything back | `pa` `pa` | `1 2 3 4 5` | |

8 operations.

### Simple: Turk algorithm, O(n²)

A greedy evolution of insertion sort. Stack `b` is always kept **sorted in descending order as a circular list**, and instead of always inserting the top of `a`, we insert the **cheapest** element of `a`.

1. If `a` is already sorted or has fewer than 2 elements, nothing is done.
2. While `a` is not empty:
   - For every element of `a`, compute the rotations needed to bring it to the top of `a` (`ca`) and to bring its insertion point to the top of `b` (`cb`). Each cost is **signed**: positive means `ra`/`rb`, negative means `rra`/`rrb`.
   - Total cost: if both rotations go in the same direction they overlap with `rr`/`rrr` (`max(|ca|, |cb|)`), otherwise they add up (`|ca| + |cb|`).
   - Apply the cheapest move: first the combined `rr`/`rrr` (`rotate_both`), then the remaining single rotations (`rotate_a`, `rotate_b`), then `pb`.
3. Rotate `b` by the shortest path until its maximum is on top.
4. Push everything back to `a` with `pa`: since `b` is sorted in descending order, `a` ends up sorted in ascending order.

### Medium: range sort, O(n√n)

A **range-based strategy** with a sliding window of size `range ≈ 1.3 × √n`. `pushed` is the number of elements already sent to `b`.

**Phase 1 (`a` → `b`)**, looking at the top of `a`:

| Condition | Action |
|---|---|
| `norm_val <= pushed` (below the window) | `pb` + `rb`: goes to the bottom of `b` |
| `norm_val <= pushed + range` (inside the window) | `pb`: stays at the top of `b` |
| otherwise (above the window) | `ra`: kept for later |

The result is a "valley" in `b`: big values at both ends, small values in the middle.

**Phase 2 (`b` → `a`):** repeatedly bring the maximum of `b` to the top by the shortest path and `pa` it.

Because of the valley shape, the maximum is always close to one of the two ends.

**Worked example** (`a = 0 3 4 7 2 9 6 5 1 8`, `range = 3`, values already normalized), first steps:

| Top of `a` | `pushed` | Case | Operations | `b` (top first) |
|---|---|---|---|---|
| 0 | 0 | below | `pb` (no `rb` when `b` has 1 element) | `0` |
| 3 | 1 | inside | `pb` | `3 0` |
| 4 | 2 | inside | `pb` | `4 3 0` |
| 7 | 3 | above | `ra` | `4 3 0` |
| 2 | 3 | below | `pb` `rb` | `4 3 0 2` |

**Why `range ≈ 1.3 × √n`?**

Multiplying `√n` by a constant does not change the complexity, but it changes the number of operations, because the window size affects both phases in opposite ways:

- **A wider window makes phase 1 cheaper:** more elements fall inside it on each lap of `a`, so fewer `ra` are needed.
- **A wider window makes phase 2 more expensive:** `b` ends up less grouped, so the maximum can be further from the ends and needs more rotations.

`1.3` is the balance point between both effects. With plain `√n`, phase 1 does too many laps; with `√n × 2`, phase 2 loses what phase 1 saved, and the result is as bad as plain `√n`.

Measured with 500 random numbers (100 runs per factor):

| `range` | min | avg | max |
|---|---|---|---|
| `√n` | 5101 | 5284 | 5473 |
| **`√n × 1.3`** | **4889** | **5071** | **5221** |
| `√n × 2` | 5036 | 5280 | 5513 |

> `√n` and `√n × 2` give similar results (and `√n × 2` even exceeds the 5500 limit), while `1.3` gives the lowest minimum, average and maximum.

**Why O(n√n):** in each full lap of `a`, every element inside the window is pushed, so each lap pushes at least `range` (≈ √n) elements: at most √n laps of n rotations. In phase 2, the maximum is at a distance of the order of √n, for n extractions.

### Complex: radix sort (LSD, base 2), O(n log n)

Radix sort does not compare elements with each other: it sorts them **bit by bit**, from the least significant bit (LSD) to the most significant one. It works on `norm_val` instead of the original values, because normalization turns any input (negatives, big gaps) into the non-negative integers `0 … n-1`, which need the minimum number of bits.

**One pass per bit:** for every element of `a`, looking at the current bit:

| Bit | Action |
|---|---|
| `0` | `pb`: goes to `b` |
| `1` | `ra`: stays in `a`, rotated to the bottom |

Then everything in `b` is pushed back with `pa`. After the pass, the elements with the bit at `0` are on top of the elements with the bit at `1`, and **within each group the previous relative order is kept**. This stability is what makes LSD radix work: each pass sorts by one more bit without undoing the previous ones. After the last bit, `a` is sorted.

**Worked example** (`a = 3 0 2 1`, 2 bits):

| Pass | Elements (binary) | Operations | `a` after the pass |
|---|---|---|---|
| bit 0 | `3`=11 `0`=00 `2`=10 `1`=01 | `ra` `pb` `pb` `ra` · `pa` `pa` | `0 2 3 1` |
| bit 1 | `0`=00 `2`=10 `3`=11 `1`=01 | `pb` `ra` `ra` `pb` · `pa` `pa` | `0 1 2 3` |

#### Number of operations

Each pass costs one operation per element (`ra` or `pb`) plus one `pa` for every element whose bit is `0`:

> operations = n × bits + (number of `0` bits among all values)

Since the values are always `0 … n-1`, both terms depend only on `n`, not on the order of the input. That is why the count is **exactly the same for every input of the same size** (except an already sorted input, which is detected and costs 0):

| n | bits | n × bits | `pa` | Total |
|---|---|---|---|---|
| 100 | 7 | 700 | 384 | **1084** |
| 500 | 9 | 4500 | 2284 | **6784** |

**Why O(n log n):** the number of bits needed for `n-1` is ⌈log₂ n⌉, and each pass touches every element a constant number of times.

#### Limits and a discarded optimization

Radix does not reach the 700 / 5500 thresholds, and with this approach it cannot: every pass must look at every element at least once, so **with 100 numbers the minimum is 7 × 100 = 700 operations** before a single `pa`.

We tried an optimization: before pushing `b` back, look at the **next** bit of each element. Elements whose next bit is `0` would go back to `b` in the following pass anyway, so they stay in `b` (`rb`) instead of doing `pa` + `pb`. It keeps the sort stable and correct, but it only reduced the count to **913** (100 numbers) and **5765** (500 numbers), still above both thresholds. Since it added complexity without meeting the goal, we kept the original version, which is simpler to read and to defend.

### Adaptive mode

| Disorder | Strategy |
|---|---|
| < 20% | Simple (Turk) |
| 20% – 50% | Medium (range sort) |
| ≥ 50% | Complex (radix) |

### Memory management and performance

- All nodes are allocated during parsing and freed at the end or on any error (`ft_stack_clear`).
- The algorithms only use local variables and the two stacks: no auxiliary arrays.
- Reading the stacks (finding a maximum, an index or a cost) does not cost operations; only the printed moves count. This is why the algorithms first inspect the stacks and then rotate the minimum needed.

### Trade-offs and limitations

- **Turk** produces few moves but computes a cost for every element at every step, which costs CPU time (still fast for 500 numbers).
- **Range sort** depends on the window factor (`1.3`): it was tuned empirically for 100 and 500 numbers.
- **Radix** is simple and predictable, but uses more operations than the other two on random inputs.

## Instructions

### Compilation

```bash
make          # builds push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # rebuilds everything
```

### Usage

```bash
./push_swap [--bench] [--simple | --medium | --complex | --adaptative] <numbers>
```

```bash
./push_swap 3 2 5 1 4                      # adaptive mode by default
./push_swap --medium "3 2 5 1 4"           # numbers can also be passed in one string
./push_swap --medium "3 2 5 " 1 4          # can also be passed by strings and arguments
./push_swap --bench --simple 3 2 5 1 4     # bench report is written to stderr

ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l                   # number of operations
./push_swap $ARG | ./checker $ARG          # OK / KO
```

On invalid input (non-numeric values, duplicates, values out of the `int` range) the program prints `Error` and exits.

### Testing

**Edge cases checked:**

| Input | Example | Expected |
|---|---|---|
| No arguments | `./push_swap` | Returns the control to user |
| No arguments + flags | `./push_swap --simple ` | Returns the control to user |
| Empty string | `./push_swap ""` | Returns the control to user |
| Empty string + flags | `./push_swap --simple ""` | Returns the control to user |
| Only one value | `./push_swap 1` | 0 operations |
| 2 or more values | `./push_swap 1 6 3` | Runs until the stack `a` is sorted |
| Already sorted | `./push_swap 1 2 3 4 5` | 0 operations |
| Duplicated values | `./push_swap 1 2 2` | `Error` |
| Non-numeric | `./push_swap 1 a --3 +` | `Error` |
| Out of `int` range | `./push_swap 2147483648 -2147483649` | `Error` |
| 100 random numbers | `ARG=$(shuf -i 0-9999 -n 100 \| tr '\n' ' ') ; ./push_swap $ARG` | Runs until the stack `a` is sorted |
| 100 random numbers with `checker` | `ARG=$(shuf -i 0-9999 -n 100 \| tr '\n' ' ') ; ./push_swap $ARG \| ./checker $ARG` | `OK` |

**Tools:**
- `show_stack.c`
   - `show_stack()` is a function for manually viewing the contents of the stack.
   - `check_order()` is a manual checker function.
- `test.sh`: runs N random inputs and reports the minimum, average and maximum number of operations for each algorithm.
- `check_sort.sh`: runs N calls with random inputs and reports how many `OK` and `KO` returns the selected algorithm.
- Our `checker` (bonus) and the official `checker_linux`.
- `valgrind --leak-check=full` for memory leaks, also on error paths.
- `norminette`.

<details>
<summary>show_stack.c</summary>

```c
#include "push_swap.h"

/* Prints the stack values */
void	show_stack(t_stack *stack, char name)
{
	t_node	*curr;

	curr = stack->head;
	ft_printf("%c: ", name);
	while (curr)
	{
		ft_printf("%d ", curr->val);
		curr = curr->next;
	}
	ft_printf("\n");
}

/* Checks if the stacks are in the correct order */
void	check_order(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return ;
	if (compute_disorder(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
```

</details>

<details>
<summary>test.sh</summary>

```bash
#!/bin/bash

x=${1:-${x:-9999}}          # shuf unsigned number  [ 99 | 499 ] (def 9999)
n=${2:-${n:-50}}            # iter unsigned number  [ 1 | 10 | 50 | 100 ] (def 50)
f=${3:-${f:-"adaptative"}}  # flag for algorithm    [ simple | medium | complex | adaptative | all ] (def "adaptative")

min=""                      # min operations count
max=0                       # max operations count
media=0                     # averge operations count

if [ "$f" != "all" ]; then
    echo "Test from 0-$x $n time(s) with $f algorithm"
    for ((i=1; i<=n; i++)); do
        shuf -i 0-${x} -n 500 > args.txt
        val=$(./push_swap --bench --$f $(cat args.txt) | wc -l)
        echo ""

        total=$((total + val))

        if [[ -z "$min" || $val -lt $min ]]; then
            min=$val
        fi

        if [[ $val -gt $max ]]; then
            max=$val
        fi
    done
    media=$(awk "BEGIN {printf \"%d\", $total / $n}")
    echo "min = $min - media = ~$media - max = $max"
else
    media=0
    echo "Test from 0-$x $n time(s) with simple algorithm"
    for ((i=1; i<=n; i++)); do
        shuf -i 0-${x} -n 500 > args.txt
        val=$(./push_swap --bench --simple $(cat args.txt) | wc -l)
        echo ""

        total=$((total + val))

        if [[ -z "$min" || $val -lt $min ]]; then
            min=$val
        fi        

        if [[ $val -gt $max ]]; then
            max=$val
        fi
    done
    media=$(awk "BEGIN {printf \"%d\", $total / $n}")
    echo "min = $min - media = ~$media - max = $max"
    echo "---"

    echo ""
    echo "Test from 0-$x $n time(s) with medium algorithm"
    for ((i=1; i<=n; i++)); do
        shuf -i 0-${x} -n 500 > args.txt
        val=$(./push_swap --bench --medium $(cat args.txt) | wc -l)
        echo ""

        total=$((total + val))

        if [[ -z "$min" || $val -lt $min ]]; then
            min=$val
        fi

        if [[ $val -gt $max ]]; then
            max=$val
        fi
    done
    media=$(awk "BEGIN {printf \"%d\", $total / $n}")
    echo "min = $min - media = ~$media - max = $max"
    echo "---"

    echo ""
    echo "Test from 0-$x $n time(s) with complex algorithm"
    for ((i=1; i<=n; i++)); do
        shuf -i 0-${x} -n 500 > args.txt
        val=$(./push_swap --bench --complex $(cat args.txt) | wc -l)
        echo ""

        total=$((total + val))

        if [[ -z "$min" || $val -lt $min ]]; then
            min=$val
        fi

        if [[ $val -gt $max ]]; then
            max=$val
        fi
    done
    media=$(awk "BEGIN {printf \"%d\", $total / $n}")
    echo "min = $min - media = ~$media - max = $max"
    echo "---"

    echo ""
    echo "Test from 0-$x $n time(s) with adaptative algorithm"
    for ((i=1; i<=n; i++)); do
        shuf -i 0-${x} -n 500 > args.txt
        val=$(./push_swap --bench --adaptative $(cat args.txt) | wc -l)
        echo ""

        total=$((total + val))

        if [[ -z "$min" || $val -lt $min ]]; then
            min=$val
        fi

        if [[ $val -gt $max ]]; then
            max=$val
        fi
    done
    media=$(awk "BEGIN {printf \"%d\", $total / $n}")
    echo "min = $min - media = ~$media - max = $max"
fi
```

</details>

<details>
<summary>check_sort.sh</summary>

```bash
#!/bin/bash

x=${1:-${x:-100}}             # Exec number (def 100)

f=${2:-${f:-"adaptative"}}    # flag for algorithm    [ simple | medium | complex | adaptative ] (def "adaptative")

ok_count=0
ko_count=0

echo "Executing $x tests..."

for ((i=1; i<=x; i++)); do
    # -i 0-9999 for 500 unique numbers)
    shuf -i 0-9999 -n 500 > args.txt

	echo "Exec $i de $(cat args.txt | wc -l) args:"
    result=$(./push_swap --bench --$f $(cat args.txt) | ./checker $(cat args.txt))

    if [ "$result" == "OK" ]; then
        ((ok_count++))
    else
        ((ko_count++))
        echo "KO in the $i iteration"
		exit 1
    fi
done

echo "-----------------------------------"
echo "Results after $x iterations:"
echo "OK: $ok_count"
echo "KO: $ko_count"

```

</details>

### Performance

Measured on random inputs (number of runs between parentheses).

| Algorithm | 100 numbers: min / avg / max | 500 numbers: min / avg / max |
|---|---|---|
| Simple (Turk) | `492` / `558` / `607` (100 times) | `4885` / `5195` / `5551` (30 times) |
| Medium (range sort) | `539` / `576` / `633` (100 times) | `4953` / `5093` / `5283` (30 times) |
| Complex (radix) | `1084` / `1084` / `1084` (100 times) | `6784` / `6784` / `6784` (30 times) |

## Team and contributions

| Task | legomez | gtomas-m | Notes |
|---|:---:|:---:|---|
| Own libraries (`libft`, `ft_printf`, `get_next_line`) | ✔ | | Adapted GNL reads byte by byte (no static buffer) for the checker, and `ft_printferr` sends errors and `--bench` output to `stderr` |
| Project structure and Makefile | ✔ | ✔ | |
| Linked list and stack utilities | ✔ | ✔ | |
| Input parsing and error handling | | ✔ | |
| Normalization (`norm_val`) | | ✔ | |
| Basic operations and wrappers | | ✔ | |
| Disorder metric (`compute_disorder`) | | ✔ | |
| Small amount of numbers (small_sort) | ✔ | | |
| Simple algorithm (Turk) | ✔ | | |
| Medium algorithm (range sort) | ✔ | | |
| Complex algorithm (radix LSD) | | ✔ | |
| Adaptive mode and `--bench` | | ✔ | |
| Bonus: checker | ✔ | ✔ | Built separately with `make bonus`. Reads instructions with the adapted GNL and accepts surrounding spaces in the input |
| Testing scripts and benchmarks | ✔ | | Testing tools are not necessary, but useful for multiple checks |
| Norminette, leaks and debugging | ✔ | ✔ | |
| README | ✔ | | |

## Resources

- [Push Swap — A journey to find most efficient sorting algorithm (A. Yigit Ogun)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97): origin of the Turk algorithm.
- [Insertion sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Bucket sort — Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)): basis of the disorder metric.
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)

### Use of AI

<!-- Review and adjust this section so it describes exactly how each member used AI. -->

- **Tool:** Claude (Anthropic).
- **Algorithm study:** used as a tutor to understand the different sort algorithms. 
- **Complexity:** helped explain why each algorithm has its complexity class.
- **Code review:** helped locate bugs (wrong indices, infinite loops, unsigned arithmetic, memory leaks) and explained why they happened. The fixes and updates were developed applied by the team.
- **Not used for:** The decomposition into functions and pseudocode, and paper traces to check them. The C code was written by the team, and the debugging part and bugs.
