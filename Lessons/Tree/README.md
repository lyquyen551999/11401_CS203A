# Module 06: Tree - The Hierarchy

## 1. Welcome to the 2nd Dimension
So far, we've lived in a flat world. Arrays and Linked Lists are linear lines ($1 \to 2 \to 3$).
**The Tree** introduces a new dimension: **Hierarchy**.

* **Analogy:** Think of a **Company Org Chart**.
    * **Root:** The CEO (No boss).
    * **Internal Nodes:** Managers (Has a boss, has employees).
    * **Leaves:** Interns (Has a boss, no employees).
    * **Subtree:** A department within the company.

> **The Shift:** In a Linked List, a node knows its "Next" neighbor. In a Tree, a node knows its "Children".

---

## 2. Terminology & Anatomy
Understanding the vocab is half the battle.

* **Node:** The individual entity (contains Data + Pointers).
* **Edge:** The link connecting two nodes.
* **Root:** The top-most node (Entry point).
* **Leaf:** A node with no children (The end of the line).
* **Height:** The length of the longest path from Root to a Leaf.
* **Depth:** The distance from the Root to the current node.

---

## 3. The Binary Search Tree (BST)
While there are many types of trees, the **Binary Search Tree** is the superstar of this course.

### 3.1. The Golden Rules
1.  **Binary:** Each node has at most **2 children** (Left & Right).
2.  **Ordered:**
    * **Left Child** < Parent
    * **Right Child** > Parent
    * No duplicate values (usually).



![Binary Search Tree](./images/BST_Structure.png)


### 3.2. C Implementation
Here is how we build a BST node and insert data recursively.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert logic (Recursive)
Node* insert(Node* root, int value) {
    // 1. Base Case: If tree is empty, new node becomes root
    if (root == NULL) {
        return create_node(value);
    }
    
    // 2. Recursive Step: Go Left or Right?
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // If value == root->data, do nothing (no duplicates)
    
    return root;
}
```

---

## 4. Tree Traversals (Walking the Tree)
Unlike an array where you iterate `0` to `n`, there are multiple ways to visit every node in a tree.

### 4.1. Depth-First Search (DFS)
We dive deep before we go wide. Used heavily in recursion.

| Type | Order | Mnemonic | Use Case |
| :--- | :--- | :--- | :--- |
| **Pre-order** | Root $\to$ Left $\to$ Right | "Me First" | Copying a tree structure. |
| **In-order** | Left $\to$ Root $\to$ Right | "Bottom Up" | **Getting sorted data** from a BST. |
| **Post-order** | Left $\to$ Right $\to$ Root | "Me Last" | Deleting a tree (Free children first). |

### 4.2. Code: The Magic of Recursion

```c
// In-order Traversal: Left -> Root -> Right
void inorder_traversal(Node* root) {
    if (root == NULL) return; // Base case
    
    inorder_traversal(root->left);  // 1. Go Left
    printf("%d ", root->data);      // 2. Visit Root
    inorder_traversal(root->right); // 3. Go Right
}
```

**My Take:** Notice how short the code is? That's the power of recursion. If you tried to do this with loops (iteratively), you'd need a Stack and 20+ lines of code!
