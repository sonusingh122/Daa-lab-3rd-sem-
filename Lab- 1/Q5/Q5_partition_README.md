# Q5 — Find the Switch Point (Binary Array Boundary Search)

Program to locate the transition point in a sorted binary array — the index where the sequence switches from `0` to `1` — using binary search instead of a linear scan.

---

## What it does

Given a sorted array containing only `0`s followed by `1`s, the program finds the index of the **first occurrence of `1`** (the "switch point") in `O(log n)` time using a binary search variant, rather than scanning the array linearly.

## Functions Overview

| Function            | Purpose                                                         |
| ------------------- | --------------------------------------------------------------- |
| `find_the_switch()` | Binary search that locates the earliest index containing a `1`. |
| `main()`            | Handles input, invokes the search, and prints the result.       |

## How It Works

**`find_the_switch()`**

- Maintains `start` and `end` pointers, plus a `best_guess` variable that tracks the earliest `1` found so far (starts at `-1`, meaning "not found").
- At each step, the middle element is checked:
  - If it's `1` — this might be the switch point, so it's saved in `best_guess`, and the search continues into the **left half** (`end = mid - 1`) to look for an even earlier `1`.
  - If it's `0` — the switch must lie further right, so the search continues into the **right half** (`start = mid + 1`).
- Returns `best_guess`: the index of the first `1`, or `-1` if the array is entirely `0`s.

**`main()`**

1. Prompts for the array size `n` and declares a variable-length array `arr[n]`.
2. Reads `n` values (expected to be sorted `0`s and `1`s) into the array.
3. Calls `find_the_switch()` to locate the transition index.
4. Prints the index if a `1` was found, or a message indicating the array is all `0`s otherwise.

## How to Run

```powershell
.\find_the_switch.exe
```

You'll be prompted for:

1. **n** — number of elements in the array
2. **n values** — the sorted binary array (0s followed by 1s)

## Why It Matters

This is a classic binary-search pattern used for problems like "find the first `true` in a sorted boolean array" or "find the first occurrence of a target value." It runs in **O(log n)** time, a significant improvement over the **O(n)** cost of a linear scan.

---

**Author:** Sonu Singh | **ID:** B125122
