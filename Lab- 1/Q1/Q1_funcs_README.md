# Q1 — Growth Rate Analysis of Functions

Program to determine the increasing order of common time-complexity functions for a given `n`, and to plot them for visual comparison.

---

## What it does

Given a value of `n`, the program evaluates a set of standard functions (constant, logarithmic, polynomial, exponential, etc.) and prints them sorted in increasing order of growth. It also generates a plot comparing their growth up to a user-specified `n`.

## Functions Compared

| Category         | Example(s)                 |
| ---------------- | -------------------------- |
| Constant         | `1/n`                      |
| Logarithmic      | `log2(n)`                  |
| Sub-linear power | `n^0.51`                   |
| Linear (scaled)  | `12√n`, `50√n`             |
| Linearithmic     | `n·log2(n)`                |
| Quadratic        | `n^2 - 324`, `100n^2 + 6n` |
| Cubic            | `2n^3`                     |
| Exponential      | `2^32·n`, `3^n`            |
| Quasi-polynomial | `n^(log2 n)`               |

## How to Run

```powershell
.\Q1_funcs.exe
```

You'll be prompted for:

1. **n** — to compute and display the sorted order of function values
2. **max n (for plotting)** — to generate a growth comparison graph

## Sample Run

> **Note:** For small plotting ranges, gnuplot may show a `y axis range undefined` warning — this is harmless and just means the axis auto-scaled to the available data.

## Output

Running the program generates a plot (saved to the `output/` folder) comparing all functions' growth rates over the chosen range of `n`.

---

**Author:** Sonu Singh | **ID:** B125122
