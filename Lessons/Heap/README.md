# Lecture Summary: Data Structures - Heaps

## 1. Definition and Core Properties
A **Heap** is a specialized data structure defined as a **complete binary tree** that satisfies the **heap-order property**.

It relies on two fundamental properties:
* **Shape Property (Structure):**
    * The tree must be a **complete binary tree**, meaning every level is completely filled, except possibly the last level.
    * Nodes in the last level are filled from **left to right**.
    * *Significance:* This structure allows the heap to be stored efficiently in an **array** without any gaps.
* **Heap-Order Property (Ordering):**
    * This defines the relationship between parent and child nodes to establish priority.

## 2. Types of Heaps
There are two main types of heaps based on the ordering rule:

| Type | Rule | Root Node |
| :--- | :--- | :--- |
| **Max Heap** | Parent key $\ge$ Children keys | Contains the **Maximum** element |
| **Min Heap** | Parent key $\le$ Children keys | Contains the **Minimum** element |

**Note:** Heaps are primarily used to implement **Priority Queues** and for **Heap Sort algorithms**.

## 3. The Concept of Priority
In a heap, the "Order" directly translates to "Priority".
* The **Key Value** (number, weight, time) represents the priority.
* The **Root Node** always holds the element with the highest priority.

**Real-world examples of Priority:**
* **Emergency Room:** Triage level (High priority treated first).
* **Operating System:** Shortest job remaining (High priority).
* **Networking:** Packets with high QoS levels.

## 4. Key Operations and Algorithms
The heap must always maintain both the **Shape** and **Order** properties. Operations usually occur at the last leaf position to preserve the shape, followed by "sifting" to fix the order.

### A. Insertion (`insert(x)`)
1.  **Place:** Insert the new node at the **leftmost empty position** on the last level (preserves Shape).
2.  **Sift-Up:** Compare the new node with its parent. If the order is violated (e.g., child > parent in Max Heap), **swap** them.
3.  **Repeat:** Continue swapping upwards until the property holds or the root is reached.
    * *Visual Example:* Inserting 200 into a Max Heap involves swapping it up from the bottom leaf to the root.

### B. Extract Root (`extract_max` or `extract_min`)
1.  **Replace:** Remove the root and replace it with the element from the **last leaf** (preserves Shape).
2.  **Sift-Down:** Compare the new root with its children. Swap it with the larger child (in Max Heap) or smaller child (in Min Heap) if the order is violated.
3.  **Repeat:** Continue swapping downwards until the property holds or a leaf is reached.
    * *Visual Example:* Extracting 200 causes 30 (the last leaf) to move to the root, which then sifts down to its correct position.

## 5. Time Complexity Analysis
Heap operations are highly efficient due to the tree structure.

| Operation | Time Complexity | Why? |
| :--- | :--- | :--- |
| **peek_root** | **O(1)** | The highest priority element is always at index 0. |
| **insert** | **O(log n)** | Worst case involves sifting up along the height of the tree. |
| **extract_root** | **O(log n)** | Worst case involves sifting down along the height of the tree. |
| **heapify(i)** | **O(log n)** | Restores property at a specific node. |
| **build_heap** | **O(n)** | Converts an entire array to a heap using Floyd’s algorithm (more efficient than n insertions). |
| **heapsort** | **O(n log n)** | Involves *n* extract-max operations. |
