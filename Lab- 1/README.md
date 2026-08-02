## DAA Lab — Six C Programs on Algorithm Analysis

This set of programs explores growth rates, recursion, searching, sorting, and probabilistic simulation. Each one is paired with a **GNUplot** visualization, except where noted.

> **Before you run anything:** install a C compiler (GCC works fine — add `-lm` if math functions are used) and make sure **[GNUplot](http://www.gnuplot.org/)** is on your system `PATH`. Two programs don't need it — see below.

---

### 📈 Programs that plot with GNUplot

| Program                  | What it explores                                                                                                   |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------ |
| `growth_functions.c`     | Ranks growth functions like `log2(n)`, `n²`, `2^n`, `3^n` by value at a given `n`, then graphs them on a log scale |
| `bubble_sort_analysis.c` | Pits standard bubble sort against an early-exit optimized version, graphing comparisons vs. array size             |
| `coin_toss_experiment.c` | Tracks a fair coin and a biased coin's running heads-probability, graphing their convergence over many tosses      |
| `hanoi_solver.c`         | Solves Hanoi recursively for growing disk counts, graphing total moves to reveal exponential growth                |

### 🔍 Programs without plotting

| Program                  | What it explores                                                          |
| ------------------------ | ------------------------------------------------------------------------- |
| `binary_switch_search.c` | Binary search to find where a sorted 0/1 array flips from `0` to `1`      |
| `duplicate_detector.c`   | Bucket-array technique to spot duplicate values in a bounded random array |

---

### Details, one at a time

**1 · `growth_functions.c`**
Takes a value `n`, evaluates a batch of standard complexity functions, and prints them in increasing order. A second prompt (max `n`) drives a log-scale plot showing how each function's growth compares over a range.

**2 · `bubble_sort_analysis.c`**
Generates random arrays at increasing sizes, sorts identical copies with both bubble sort variants, and plots comparison counts for each — useful for seeing that random data rarely benefits from the early-exit optimization.

**3 · `coin_toss_experiment.c`**
Runs a fair coin (`p=0.5`) and a user-defined biased coin side by side across many tosses, recording the running observed probability of heads for each, then plots both curves converging toward their expected values.

**4 · `hanoi_solver.c`**
Recursively solves the classic 3-peg puzzle for each disk count from 1 up to a chosen maximum, counting moves at every step, then plots moves vs. disk count — the classic `2^n − 1` curve.

**5 · `binary_switch_search.c`**
A binary-search variant on a sorted array of 0s and 1s: finds the earliest index holding a `1` in `O(log n)` time rather than scanning linearly.

**6 · `duplicate_detector.c`**
Fills an array with random bounded integers, then uses a same-sized "seen" tracker array to flag duplicates as they're encountered — an `O(n)` alternative to nested-loop comparison.

---

### Complexity at a glance

- **O(log n):** `binary_switch_search.c`
- **O(n):** `coin_toss_experiment.c`, `duplicate_detector.c`
- **O(n log n):** `growth_functions.c` (sorting step)
- **O(n²):** `bubble_sort_analysis.c` (worst case)
- **O(2ⁿ):** `hanoi_solver.c`
