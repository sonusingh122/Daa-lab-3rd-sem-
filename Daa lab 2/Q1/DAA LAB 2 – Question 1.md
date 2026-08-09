# DAA Lab 2 – Question 1: Dictionary Operations

## 📌 Overview

This project implements and analyzes **Dictionary Operations** using different data structures.

The following data structures are considered:

- Sorted Array
- Unsorted Array
- Singly Linked List – Sorted
- Singly Linked List – Unsorted
- Doubly Linked List – Sorted
- Doubly Linked List – Unsorted

The following dictionary operations are analyzed:

- Search
- Insert
- Delete
- Maximum
- Minimum
- Predecessor
- Successor

Each program generates operation-growth data for increasing input sizes, which is saved to the `output/` folder and plotted using **Gnuplot**.

---

## 📂 Files in the Repository

| File                        | Description                                       |
| --------------------------- | ------------------------------------------------- |
| `sorted_array.c`            | C program for sorted array complexity analysis    |
| `unsorted_array.c`          | C program for unsorted array complexity analysis  |
| `singly_linked_sorted.c`    | C program for sorted singly linked list           |
| `singly_linked_unsorted.c`  | C program for unsorted singly linked list         |
| `doubly_linked_sorted.c`    | C program for sorted doubly linked list           |
| `doubly_linked_unsorted.c`  | C program for unsorted doubly linked list         |
| `output/`                   | Folder containing generated data files and graphs |
| `DAA LAB 2 – Question 1.md` | Question/problem statement for this lab           |
| `README.md`                 | Project documentation                             |

---

# 📊 Dictionary Operations

| Operation   | Description                          |
| ----------- | ------------------------------------ |
| Search      | Find a key                           |
| Insert      | Add a key                            |
| Delete      | Remove a key                         |
| Maximum     | Find the largest key                 |
| Minimum     | Find the smallest key                |
| Predecessor | Largest key smaller than a given key |
| Successor   | Smallest key larger than a given key |

---

# ⏱️ Time Complexity Analysis

## 1. Sorted Array

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(log n)   |
| Insert      | O(n)       |
| Delete      | O(n)       |
| Maximum     | O(1)       |
| Minimum     | O(1)       |
| Predecessor | O(log n)   |
| Successor   | O(log n)   |

---

## 2. Unsorted Array

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(n)       |
| Insert      | O(1)       |
| Delete      | O(1)       |
| Maximum     | O(n)       |
| Minimum     | O(n)       |
| Predecessor | O(n)       |
| Successor   | O(n)       |

---

## 3. Singly Linked List – Sorted

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(n)       |
| Insert      | O(n)       |
| Delete      | O(n)       |
| Maximum     | O(n)       |
| Minimum     | O(1)       |
| Predecessor | O(n)       |
| Successor   | O(n)       |

---

## 4. Singly Linked List – Unsorted

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(n)       |
| Insert      | O(1)       |
| Delete      | O(1)       |
| Maximum     | O(n)       |
| Minimum     | O(n)       |
| Predecessor | O(n)       |
| Successor   | O(n)       |

---

## 5. Doubly Linked List – Sorted

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(n)       |
| Insert      | O(n)       |
| Delete      | O(n)       |
| Maximum     | O(1)       |
| Minimum     | O(1)       |
| Predecessor | O(1)       |
| Successor   | O(1)       |

---

## 6. Doubly Linked List – Unsorted

| Operation   | Complexity |
| ----------- | ---------- |
| Search      | O(n)       |
| Insert      | O(1)       |
| Delete      | O(1)       |
| Maximum     | O(n)       |
| Minimum     | O(n)       |
| Predecessor | O(n)       |
| Successor   | O(n)       |

---

# 📋 Overall Comparison

| Data Structure                | Search   | Insert | Delete | Maximum | Minimum | Predecessor | Successor |
| ----------------------------- | -------- | ------ | ------ | ------- | ------- | ----------- | --------- |
| Sorted Array                  | O(log n) | O(n)   | O(n)   | O(1)    | O(1)    | O(log n)    | O(log n)  |
| Unsorted Array                | O(n)     | O(1)   | O(1)   | O(n)    | O(n)    | O(n)        | O(n)      |
| Singly Linked List – Sorted   | O(n)     | O(n)   | O(n)   | O(n)    | O(1)    | O(n)        | O(n)      |
| Singly Linked List – Unsorted | O(n)     | O(1)   | O(1)   | O(n)    | O(n)    | O(n)        | O(n)      |
| Doubly Linked List – Sorted   | O(n)     | O(n)   | O(n)   | O(1)    | O(1)    | O(1)        | O(1)      |
| Doubly Linked List – Unsorted | O(n)     | O(1)   | O(1)   | O(n)    | O(n)    | O(n)        | O(n)      |

---

# 📈 Data Generation

Each `.c` program runs the dictionary operations for increasing input sizes `n` and writes the timing results to a data file inside the `output/` folder, in the format:

```text
n Search Insert Delete Maximum Minimum Predecessor Successor
```

These files are then used to plot the growth of each operation with input size.

---

# 📈 Graph Generation Using Gnuplot

After running a program and generating its data file in `output/`, open Gnuplot and plot directly, for example:

```gnuplot
cd 'output'
plot "sorted_array.txt" using 1:2 with linespoints title "Search", \
     "sorted_array.txt" using 1:3 with linespoints title "Insert", \
     "sorted_array.txt" using 1:4 with linespoints title "Delete", \
     "sorted_array.txt" using 1:5 with linespoints title "Maximum", \
     "sorted_array.txt" using 1:6 with linespoints title "Minimum", \
     "sorted_array.txt" using 1:7 with linespoints title "Predecessor", \
     "sorted_array.txt" using 1:8 with linespoints title "Successor"
```

Repeat this for each generated data file (`unsorted_array.txt`, `singly_linked_sorted.txt`, `singly_linked_unsorted.txt`, `doubly_linked_sorted.txt`, `doubly_linked_unsorted.txt`) to visualize the growth of dictionary operations for each data structure.

---

# 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Gnuplot
- Visual Studio Code
- Git
- GitHub

---

# ▶️ How to Run

### Compile

```bash
gcc sorted_array.c -o sorted_array
gcc unsorted_array.c -o unsorted_array
gcc singly_linked_sorted.c -o singly_linked_sorted
gcc singly_linked_unsorted.c -o singly_linked_unsorted
gcc doubly_linked_sorted.c -o doubly_linked_sorted
gcc doubly_linked_unsorted.c -o doubly_linked_unsorted
```

### Execute

Windows:

```bash
sorted_array.exe
```

Linux/macOS:

```bash
./sorted_array
```

Running each executable generates its corresponding data file inside the `output/` folder.

### Generate Graph

Open Gnuplot in the `output/` folder and plot the generated `.txt` file as shown in the **Graph Generation** section above.

---

# 🎯 Objectives

1. Study dictionary operations.
2. Implement different data structures.
3. Compare their time complexities.
4. Generate experimental data.
5. Visualize growth using Gnuplot.
6. Analyze performance differences among data structures.

---

# 📌 Conclusion

Different data structures offer different trade-offs.

- Sorted arrays provide efficient searching.
- Unsorted arrays provide fast insertion.
- Linked lists allow flexible memory usage.
- Doubly linked lists provide direct predecessor and successor access.
- Graphs help visualize the growth of operations and compare performance.

---

## 👨‍💻 Author

Sonu Singh
B125122

**DAA Lab Project**
**Course:** Design and Analysis of Algorithms (DAA)
**Language:** C
**Tools:** GCC, Gnuplot, VS Code, GitHub
