# Lecture Summary: Data Structures - Linked Lists (Chapter 4)

## 1. Motivation: The Limitation of Arrays
To understand why we use Linked Lists, we first look at the drawbacks of Arrays:
* **Inefficient Insertion/Deletion:** Inserting or deleting an element in an array (especially in the middle) is expensive because it requires **shifting** all subsequent elements to maintain contiguous memory.
* **Time Complexity:** This shifting results in **O(n)** complexity, which is slow for large datasets.
* **The Solution:** Linked Lists solve this by using "linkers" (pointers) to connect elements, allowing easier manipulation of order without moving data in memory.

## 2. Definition and Structure
* **Definition:** A Linked List is a linear data structure where elements (Nodes) are stored in **non-contiguous** memory locations.
* **Analogy:** It acts like a **train** coupled together; you can add/remove cars by changing the couplers.
* **Node Structure:** Each node consists of two parts:
    1.  **Data:** The value stored (e.g., integer).
    2.  **Pointer (Next):** A reference to the next node in the sequence.

### Implementation (C vs. C++)
The lecture contrasted the syntax for defining nodes:
* **C Style:** Uses `struct` with a pointer to the same struct type.
* **C++ Style:** Uses `class` with a constructor to initialize data and set `next` to `nullptr`.

## 3. Variations of Linked Lists
Different types of lists exist to solve specific navigation problems:
1.  **Singly Linked List:** Standard form. Navigation is forward only (Head $\rightarrow$ Tail).
2.  **Doubly Linked List:** Each node has a `prev` and `next` pointer. Allows bidirectional traversal but consumes more memory.
3.  **Circular Linked List:** The last node points back to the **Head** instead of `NULL`. Useful for continuous loops.

## 4. Key Operations & Logic
The lecture emphasized that Linked List operations focus on pointer manipulation rather than data movement.

| Operation | Logic | Complexity |
| :--- | :--- | :--- |
| **Insert (Front)** | Create node, point it to Head, update Head. | **O(1)** |
| **Insert (End)** | Traverse to the last node, link it to the new node. | **O(n)** |
| **Delete (Front)** | Move Head to `Head->next`, free old head. | **O(1)** |
| **Delete (Target)** | Traverse to find target, bypass it (`Prev->next = Target->next`), free memory. | **O(n)** |

## 5. Advanced Operation: `MoveTo` (Pointer Manipulation)
A critical skill is rearranging nodes without moving data (e.g., moving a node to the front).
* **The Risk:** Simply moving a node without connecting its neighbors first creates **dangling nodes** (broken chain).
* **The Correct Algorithm:**
    1.  **Identify:** Locate `Prev`, `Target` (the node to move), and `Head`.
    2.  **Detach:** Link `Prev->next` to `Target->next` to close the gap.
    3.  **Attach:** Point `Target->next` to the current `Head`.
    4.  **Update:** Set `Head` to `Target`.

## 6. Application: Sorting (Selection Sort)
Sorting a Linked List demonstrates the difference between swapping values and swapping pointers.
* **Swap Value:** Simple code, but inefficient if data size is large.
* **Swap Pointer:** Complex logic (uses `MoveTo`), but efficient for large data objects.
* **Stability:** Selection Sort on a linked list is a **stable** sorting algorithm (preserves relative order of equal elements).

## 7. Grand Comparison: Array vs. Linked List


| Feature | Array | Linked List |
| :--- | :--- | :--- |
| **Memory Allocation** | Contiguous (Block) | Non-contiguous (Scattered) |
| **Access (Indexing)** | **O(1)** (Fast) | **O(n)** (Slow - must traverse) |
| **Insertion/Deletion** | **O(n)** (Slow - requires shifting) | **O(1)** (Fast - if pointer is known) |
| **Memory Efficiency** | No overhead | Overhead (extra memory for pointers) |
| **Cache Performance** | **Good** (Spatial Locality) | **Poor** (Jumping addresses) |
| **Flexibility** | Fixed size (usually) | Dynamic size (Grow/Shrink) |
