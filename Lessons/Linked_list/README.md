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

| Operation | Description | The "Catch" |
| :--- | :--- | :--- |
| **Insert (Head)** | "Add new node at the start" | "Super Fast $O(1)$. Just update one pointer." |
| **Insert (Tail)** | "Add new node at the end" | "Slow $O(n)$ unless you keep a tail pointer." |
| **Delete (Node)** | "Remove a specific node" | "Fast $O(1)$ if you already stand at the previous node." |
| **Search/Access** | "Find a value or index" | "Slow $O(n)$. No random access allowed!"|

---

## 4. Basic Implementation (Singly Linked List)
Here is a simple C implementation to demonstrate the dynamic nature of Linked Lists.

```c
#include <stdio.h>
#include <stdlib.h>

// 1. Define the blueprint
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper: Create a new node
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    // 2. Initialize the Head (The first clue)
    Node* head = create_node(10);
    
    // 3. Link more nodes manually (for demonstration)
    Node* second = create_node(20);
    Node* third = create_node(30);
    
    head->next = second; // Link 1st -> 2nd
    second->next = third; // Link 2nd -> 3rd
    
    // 4. Traversal: Walk through the list
    Node* current = head;
    printf("Linked List Chain: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next; // Move to the next address
    }
    printf("NULL\n");

    // 5. Cleanup (Free memory is mandatory!)
    // Note: In real projects, use a loop to free all nodes.
    free(third);
    free(second);
    free(head);
    
    return 0;
}
```
**Critical Rule:** Never lose the head pointer. If you lose head, you lose the entire list (Memory Leak).


