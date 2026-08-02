# Q4 — Tower of Hanoi: Move Count Analysis

Program to solve the classic Tower of Hanoi puzzle recursively for increasing disk counts, track the number of moves required each time, and plot how the move count grows with the number of disks.

---

## What it does

The program recursively solves Tower of Hanoi for every disk count from `1` up to a user-specified maximum `d`, counting the total moves needed at each step. The results are plotted to visually confirm the puzzle's well-known exponential growth pattern.

## Functions Overview

| Function | Purpose                                                                                                                                                                                                                                                                                                                                |
| -------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `TOH()`  | Recursive solver using three pegs — `L` (source), `R` (destination), `M` (auxiliary). Base case moves a single disk directly; otherwise it recursively shifts `n-1` disks out of the way, moves the largest disk, then recursively shifts the `n-1` disks onto the destination. A global `moveCount` accumulates the total moves made. |
| `main()` | Handles input, GNUplot setup, the simulation loop, and plotting.                                                                                                                                                                                                                                                                       |

## How It Works

1. **Input** — User provides `d`, the maximum number of disks to simulate.
2. **GNUplot setup** — A pipe to `gnuplot -persistent` is opened, with title, axis labels, and grid configured.
3. **Simulation loop** — For each disk count `n` from `1` to `d`:
   - `moveCount` is reset to `0`.
   - `TOH(n, 'L', 'R', 'M')` is called to solve the puzzle for `n` disks.
   - The pair `(n, moveCount)` is written to the GNUplot pipe.
4. **Finish plotting** — The inline data block is terminated and the GNUplot pipe is closed.

## How to Run

```powershell
.\tower_of_hanoi.exe
```

You'll be prompted for:

1. **d** — the maximum number of disks to simulate

## Output

A graph of moves required vs. number of disks, illustrating that the move count follows **2ⁿ − 1**, confirming the puzzle's exponential time complexity.

---

**Author:** Sonu Singh | **ID:** B125122
