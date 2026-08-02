# Q6 — Duplicate Finder (Counting/Bucket Approach)

Program to detect duplicate values in a randomly generated array of bounded-range integers, using a counting/bucket technique instead of a naive nested-loop comparison.

---

## What it does

The program generates `n` random integers within a bounded range `[0, range)`, then identifies which values occur more than once — printing each duplicate exactly once — using an `O(n)` counting approach rather than an `O(n²)` pairwise comparison.

## Functions Overview

| Component | Purpose                                                                                                                                 |
| --------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| `arr`     | Holds the `n` generated random numbers.                                                                                                 |
| `seen`    | A tracker array of size `range`, used as a lookup table: `0` = not seen, `1` = seen once, `2` = seen and already reported as duplicate. |
| `main()`  | Handles input, generation, duplicate detection, and output.                                                                             |

## How It Works

1. **Input** — User provides `n` (how many random numbers to generate) and `range` (the upper bound; numbers fall in `[0, range)`).
2. **Allocation** — Two arrays are set up:
   - `arr`, sized `n`, to hold the generated numbers.
   - `seen`, sized `range`, to act as a direct-index lookup/tracker for each possible value.
3. **Number generation** — `n` random values in `[0, range - 1]` are generated, stored in `arr`, and printed.
4. **Duplicate detection** — The array is scanned once. For each value:
   - If `seen[value] == 1` (already seen before) → it's a duplicate. It's printed, a `found` flag is set, and `seen[value]` is bumped to `2` so the same value isn't printed again on later repeats.
   - If `seen[value] == 0` (first occurrence) → it's marked as `1`.
5. **Result output** — If no duplicates were found, the program prints `None` along with a message confirming all elements are unique. Otherwise, it lists each duplicate value once and confirms duplicates exist.
6. **Cleanup** — Both dynamically allocated arrays are freed.

## How to Run

```powershell
.\duplicate_finder.exe
```

You'll be prompted for:

1. **n** — number of random values to generate
2. **range** — the upper bound for generated values (exclusive)

## Why It Matters

Because `seen[value]` is used as a direct index — only possible since values are bounded by `range` — duplicates can be found in **O(n)** time instead of the **O(n²)** cost of a naive nested-loop comparison, trading a small amount of extra memory (the `seen` array) for a significant speed gain.

---

**Author:** Sonu Singh | **ID:** B125122
