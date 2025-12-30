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

```c
#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count; // Helpful to track size easily
} CircularQueue;

void init_queue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueue(CircularQueue* q, int value) {
    if (q->count == MAX) return; // Full
    
    // Wrap around to 0 if we hit the limit
    q->rear = (q->rear + 1) % MAX; 
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(CircularQueue* q) {
    if (q->count == 0) return -1; // Empty
    
    int value = q->data[q->front];
    // Wrap around to 0 if we hit the limit
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}
```

---

## 4. Complexity Analysis
Both structures are designed for speed.

| Operation | Time Complexity | Why? |
| :--- | :--- | :--- |
| **Push / Enqueue** | $O(1)$ | "Direct index access or pointer update." |
| **Pop / Dequeue** | $O(1)$ | "Direct index access or pointer update." |
| **Peek** | $O(1)$ | "No traversal needed." |
| **Search** | $O(n)$ | "(Not their strong suit!) You must empty them to find items." |

**Note on Space:** > * **Array-based:** Fixed size ($O(C)$). Can waste space or overflow.
* **Linked-List-based:** Dynamic size ($O(n)$). Extra memory for pointers.

---

## 5. Advanced Variations (The "Flavors")

**Deque (Double-Ended Queue):** The rule breaker. You can Push/Pop from both front and back. (Used in Sliding Window algorithms).
**Priority Queue:** Not strictly FIFO. The VIP (Highest Priority) gets dequeued first, regardless of arrival time. (Implemented via Heaps - Spoiler for future modules).
**Monotonic Stack:** Keeps elements sorted inside the stack. Extremely useful for "Next Greater Element" problems.

---

## 6. My Takeaway

* **Stack** is for Backtracking. If you need to reverse your steps (like solving a maze or evaluating math expressions `3 + 4 * 5`), use a Stack.
* **Queue** is for Buffering. If data arrives faster than you can process it (like keyboard strokes or web server requests), put it in a Queue.
* **Never** use a simple array for a Queue (shifting elements is $O(n)$). Always use a **Circular Array** or **Linked List.**

---

**References**
* **Course Material:** Lecture notes on Data Structures.
* **AI Assistance:** Content synthesized and structured with the help of Gemini AI.
