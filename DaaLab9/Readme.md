# DAA Lab-09: Greedy Algorithms

**Course:** Design and Analysis of Algorithms (DAA)  
**Programme:** B.Tech. (CS-B and CE), 3rd Semester  
**Lab Date:** October 6, 2026  
**Instructor:** Dr. Ajaya Kumar Dash

## Overview

This repository contains C implementations and complexity analysis for the ten problems in DAA Lab-09, which focuses on the **Greedy Design Paradigm**.

A greedy algorithm makes a locally optimal choice at each step with the aim of building a good or optimal overall solution. Each program should use a suitable input representation, display its result, and be tested with appropriate sample cases.

## Questions Covered

1. **Fractional Knapsack with Deterioration Rate**  
   Determine the scheduling order and fractional item choices that maximise total value when each item's value density decreases over time.

2. **Huffman Coding**  
   Build a minimum-expected-length prefix-free code from symbol frequencies and output a canonical Huffman codebook ordered by code length.

3. **Minimum Initial Fuel (Reverse Greedy)**  
   Find the minimum number of refuelling stops needed to reach a target distance, given the fuel available at stations along the route.

4. **Minimum Cost to Connect Sticks**  
   Connect all sticks into one while minimising the total cost, where joining sticks of lengths `x` and `y` costs `x + y`.

5. **Candy Distribution Problem (Bi-directional Slope Greedy)**  
   Give every child at least one candy and ensure children with higher ratings than their immediate neighbours receive more candies, while minimising the total.

6. **Reorganise String with K-Distance Apart**  
   Rearrange a string so identical characters are at least distance `K` apart. If no valid arrangement exists, return an empty result.

7. **Minimise Deviation in Array (Two-Way Greedy with Max-Heap)**  
   Minimise `max(A) - min(A)` by repeatedly applying the permitted operations: multiply an odd element by 2 or divide an even element by 2.

8. **Minimum Number of Meeting Rooms**  
   Given meeting start and end times, calculate the minimum number of conference rooms required so that overlapping meetings can take place.

9. **Hu-Tucker Greedy Simulation**  
   Given an ordered sequence of weights, construct an optimal alphabetic binary tree or merge pattern that preserves the order of the indices while minimising the weighted path length, `sum(w[i] * depth(i))`.

10. **Greedy Superstring Conjecture (Open Problem in the Lab Sheet)**  
    Given a set of strings, find a short string containing every input string as a substring. The classic greedy approach repeatedly merges the pair with the greatest overlap. The lab sheet discusses the conjecture and a reported September 2026 preprint; treat the research-status statement as described in the sheet rather than as independently verified here.

## Suggested Project Structure

Use filenames that clearly identify each question. Adjust these names to match the files in your repository.

```text
DAA-Lab-09/
├── README.md
├── Q1_Fractional_Knapsack.c
├── Q2_Huffman_Coding.c
├── Q3_Minimum_Refuelling_Stops.c
├── Q4_Connect_Sticks.c
├── Q5_Candy_Distribution.c
├── Q6_Reorganise_String.c
├── Q7_Minimise_Deviation.c
├── Q8_Meeting_Rooms.c
├── Q9_Hu_Tucker_Simulation.c
└── Q10_Greedy_Superstring.c
```

## Requirements

- A C compiler such as GCC
- A terminal or command prompt
- Basic knowledge of arrays, sorting, greedy strategies, and algorithm analysis

## Compile and Run

Compile a question's C file using GCC. For example:

```bash
gcc Q4_Connect_Sticks.c -o Q4
```

Run it on Linux/macOS:

```bash
./Q4
```

On Windows using MinGW:

```bash
Q4.exe
```

Repeat the same process for the other questions, changing the source filename and executable name as needed. If your compiler requires the C standard to be specified, you can use:

```bash
gcc -std=c11 Q4_Connect_Sticks.c -o Q4
```

## Complexity Analysis

For each question, document the following:

- **Input representation:** How the problem data is stored.
- **Greedy choice:** The local choice made at each step.
- **Time complexity:** How running time grows with input size.
- **Space complexity:** Additional memory required.
- **Correctness or limitations:** Explain why the method works, or state any assumptions and limitations.
- **Testing:** Include normal, boundary, and impossible-case inputs where applicable.

The exact complexity depends on the implementation and data structures used, so report the complexity of the code actually submitted rather than assuming one fixed bound for every implementation.

## Learning Outcomes

After completing this lab, students should be able to:

- Identify problems that can be approached using greedy strategies.
- Choose suitable data structures for each problem.
- Implement and test algorithms in C.
- Analyse time and auxiliary-space complexity.
- Explain the greedy choice and its effect on the final solution.
- Recognise the difference between a practical greedy heuristic and a proven optimal algorithm.

## Note

This README summarises the ten questions in the **DAA Lab-09 problem sheet dated October 6, 2026**. The source sheet requests a C program and complexity analysis for each question. The suggested filenames and repository structure are examples; change them to match the actual files in your submission.
