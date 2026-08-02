# Q2 — Bubble Sort: Standard vs Optimized (Early-Exit)

Program to compare two variants of bubble sort — the plain textbook version and an early-exit optimized version — by counting comparisons across increasing array sizes, and plotting both curves for a visual comparison.

---

## What it does

The program generates random arrays of increasing size, sorts each one using **two different bubble sort implementations**, and records how many comparisons each variant makes. The results are then plotted together using GNUplot so the growth trend of both can be compared side by side.

## Functions Overview

| Function                | Purpose                                                                      |
| ----------------------- | ---------------------------------------------------------------------------- |
| `bubbleSortStandard()`  | Classic bubble sort — always completes all `n-1` passes, no early exit.      |
| `bubbleSortOptimized()` | Bubble sort with a `swapped` flag — exits early if no swaps occur in a pass. |
| `generateRandomArray()` | Fills an array with random integers in the range `[0, 9999]`.                |
| `copyArray()`           | Duplicates an array so both sort variants operate on identical input.        |

## How It Works

1. **Input** — User provides `maxSize` (largest array size to test) and `step` (increment between test sizes).
2. **GNUplot setup** — A pipe to `gnuplot -persistent` is opened, and plot settings (title, axes, grid, legend) are configured.
3. **Experiment loop** — For every array size `n` from `step` to `maxSize`:
   - A random array is generated.
   - Two identical copies are made.
   - Both sort variants run independently, each tracking its own comparison count.
   - Results are printed to the console.
4. **Plotting** — Comparison counts `(size, comparisons)` for both variants are streamed into GNUplot as two separate data series and plotted together.
5. **Cleanup** — The GNUplot pipe and all dynamically allocated arrays are released.

## How to Run

```powershell
.\bubble_sort_comparison.exe
```

You'll be prompted for:

1. **maxSize** — the largest array size to test
2. **step** — the increment in size between each test run

## Output

A graph comparing the number of comparisons made by the standard vs. optimized bubble sort as array size increases — useful for observing that on random (non-sorted) input, the early-exit optimization rarely triggers, so both curves tend to track closely.

---

**Author:** Sonu Singh | **ID:** B125122
