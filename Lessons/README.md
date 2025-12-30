# Module 01: The Fundamentals of Data Structures

## 1. What is a Data Structure?
Simply put, a Data Structure (DS) is a specialized format for organizing, processing, and retrieving data. 
> **My Take:** Think of it as a container. If coding is cooking, the Data Structure is not the food itself, but the specific bowl, plate, or shelf we use to store ingredients so we can grab them efficiently when needed.

---

## 2. Memory Allocation Strategies
Instead of just "Classification", let's look at how they handle memory:

| Type | Memory Size | Flexibility | Analogy |
| :--- | :--- | :--- | :--- |
| **Static** | Fixed at compile-time | Low (Hard to resize) | A parking lot with a fixed number of slots. |
| **Dynamic** | Changes at runtime | High (Grows/Shrinks) | A train that can attach or detach wagons as needed. |

---

## 3. The Lifecycle of Data (Operations)
Every data structure generally supports a set of operations. I categorize them into four main phases:

### Phase 1: Manipulation (CRUD)
* **Create/Initialize:** Allocating resources (e.g., `new Node()`).
* **Insert:** Injecting data (Push, Enqueue, Add).
* **Read/Access:** Peeking at data without touching it.
* **Update:** Changing the value of an existing node.
* **Delete:** Removing data and freeing memory.

### Phase 2: Navigation & Search
* **Search:** finding the index or address of a specific value.
* **Traverse:** Walking through *every* element (e.g., `for` loop over an array).

### Phase 3: Maintenance (Housekeeping)
* **Sort:** Ordering elements (Ascending/Descending).
* **Merge/Split:** Combining structures or breaking them apart.
* **Resize:** (Dynamic only) Expanding capacity when full.
* **Clear:** Resetting the structure to empty.

### Phase 4: Status Checks (Boolean Flags)
These are usually `O(1)` operations to prevent errors:
* `isEmpty()`: Is there anything here?
* `isFull()`: Can I add more?
* `isValid()` / `isSorted()`: Does it meet the rules?

---

## 4. Taxonomy: The Family Tree
A visual breakdown of how data structures are related:

* **Primitive** (Built-in, single value):
    * `int`, `char`, `float`, `pointer`...
* **Non-Primitive** (Complex, holds multiple values):
    * **Linear** (Sequential, 1-to-1 relationship):
        * *Examples:* Arrays, Linked Lists, Stacks, Queues.
    * **Non-Linear** (Hierarchical/Network, 1-to-Many or Many-to-Many):
        * *Examples:* Trees, Graphs, Hash Tables.

---

## 5. Performance Metrics (Big-O)
How do we measure "efficiency"? We don't measure seconds (too hardware-dependent). We measure **Growth Rate**.

### 5.1. The "Big Three" Notations
These describe how the algorithm behaves as input $n$ approaches infinity.

1.  **Big-O ($O$) - The Pessimist (Worst Case):**
    * The upper bound. The code will never be slower than this.
    * *Math:* $f(n) = O(g(n))$ if $f(n) \leq C \cdot g(n)$ for large $n$.
2.  **Omega ($\Omega$) - The Optimist (Best Case):**
    * The lower bound. The code will never be faster than this.
    * *Math:* $f(n) = \Omega(g(n))$ if $f(n) \geq C \cdot g(n)$ for large $n$.
3.  **Theta ($\Theta$) - The Realist (Average/Tight Case):**
    * The precise bound.
    * *Math:* $f(n) = \Theta(g(n))$ covers both upper and lower bounds.

### 5.2. Complexity Cheat Sheet
Ranking from **Fastest** to **Slowest**:

| Complexity | Name | Common Scenario |
| :--- | :--- | :--- |
| $O(1)$ | Constant | Accessing Array Index `arr[5]` |
| $O(\log n)$ | Logarithmic | Binary Search (Cutting problem in half) |
| $O(n)$ | Linear | Simple Loop (Reading a book page by page) |
| $O(n \log n)$ | Linearithmic | Efficient Sorting (Merge Sort, Heap Sort) |
| $O(n^2)$ | Quadratic | Nested Loops (Bubble Sort) |
| $O(2^n)$ | Exponential | Recursive Fibonacci (Try to avoid this!) |

> **Note to self:** Always aim for $O(n \log n)$ or better for large datasets.

