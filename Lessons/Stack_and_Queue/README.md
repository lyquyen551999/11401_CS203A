# Module 04: Stack & Queue - The Disciplined Lists

## 1. Introduction: Law and Order
Unlike Arrays and Linked Lists which act like "free-for-all" storage, **Stacks** and **Queues** are strict disciplinarians. They enforce specific rules on how data enters and leaves.

| Feature | 🥞 Stack | 🎫 Queue |
| :--- | :--- | :--- |
| **Rule** | **LIFO** (Last In, First Out) | **FIFO** (First In, First Out) |
| **Analogy** | A tube of Pringles chips. | A line at a Bubble Tea shop. |
| **Action** | Insert Top, Remove Top. | Insert Rear, Remove Front. |
| **Real World** | Undo button (Ctrl+Z), Browser Back button. | Printer jobs, CPU task scheduling. |

---

## 2. Visualization & Operations

### 2.1. Stack ( The "Vertical" View)
Input and Output happen at the **same end** (Top).


* **Push:** Add to Top.
* **Pop:** Remove from Top.
* **Peek:** Look at Top (don't remove).

### 2.2. Queue (The "Horizontal" View)
Input and Output happen at **opposite ends**.


* **Enqueue:** Add to Rear.
* **Dequeue:** Remove from Front.

---

## 3. Implementation Strategies
How do we build these using what we already know (Arrays/Linked Lists)?

### 3.1. Stack Implementation (Array-based)
Using an Array is the fastest way. We just track the `top` index.

```c
#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init_stack(Stack* s) {
    s->top = -1; // Empty state
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1) return; // Overflow check
    s->data[++(s->top)] = value;   // Increment then store
}

int pop(Stack* s) {
    if (s->top == -1) return -1;   // Underflow check
    return s->data[(s->top)--];    // Return then decrement
}
```
### 3.2. Queue Implementation (The "Circular" Trick)

**The Problem:** If we use a normal array, removing items from the front leaves empty, unusable space at the start. 
**The Solution:** Circular Buffer (Ring Buffer). When we reach the end of the array, we loop back to index 0.

**Key Formula:** `next_index = (current_index + 1) % CAPACITY`
