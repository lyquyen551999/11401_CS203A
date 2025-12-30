# Module 03: Linked List - The Chain

## 1. Concept: The Scavenger Hunt
Remember how Arrays are like houses on a single street? Well, a **Linked List** is like a **Scavenger Hunt** (Trò chơi truy tìm kho báu).
* The items (Nodes) are hidden all over the city (Memory).
* They are **NOT** neighbors.
* To find the next item, you must read the "clue" (Pointer) inside the current item.

> **Key Difference:** In an Array, you calculate the address (`index * size`). In a Linked List, you must *follow the trail* from the Head.



---

## 2. Anatomy of a Node
The transition from Array to Linked List is simply adding a navigation system to the data.

$$\text{Node} = \text{Data} + \text{Address of Next Node}$$

### C Implementation
```c
struct Node {
    int data;           // The value we want to store
    struct Node* next;  // The "clue" pointing to the next node
};
```
---

## 3. Linked List ADT & Operations

The "Contract" of behaviors remains similar to other lists, but the performance characteristics change drastically.

