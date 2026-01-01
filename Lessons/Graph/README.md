# Module 08: Graph - The Web of Connections

## 1. The Concept: Social Networks
If Trees are hierarchical (Boss -> Employee), **Graphs** are messy networks where anyone can connect to anyone.
* **Undirected Graph:** Think **Facebook Friends**. If A is friend with B, B is friend with A. (Mutual).
* **Directed Graph (Digraph):** Think **Instagram/Twitter**. You (A) follow Celebrity (B), but B doesn't follow you back. (One-way).

> **Definition:** A Graph $G = (V, E)$ is a set of **Vertices** (Nodes) connected by **Edges** (Links).



---

## 2. The Math: Handshaking Lemma
Don't let the name scare you. Imagine a party.
* Every time two people shake hands, **2 hands** are involved.
* **Theorem:** The sum of degrees (connections) of all vertices is always **Twice** the number of edges.
* **Fun Fact:** The number of people who shook hands an **odd** number of times must be **even**. (Try checking this at your next party!).

---

## 3. Representations: Matrix vs. List
How do we store this mess in code? Two main ways:

### 3.1. Adjacency Matrix (The Grid)
A 2D Array `A[i][j]`.
* `1` means "Yes, connected".
* `0` means "No connection".

| . | A | B | C |
|---|---|---|---|
| **A** | 0 | 1 | 0 |
| **B** | 1 | 0 | 1 |
| **C** | 0 | 1 | 0 |

* **Pros:** Checking connection is instant $O(1)$.
* **Cons:** Wastes huge space $O(V^2)$ if connections are sparse.

### 3.2. Adjacency List (The Rolodex)
An Array of Linked Lists. Each node keeps a list of its friends.
* `A: [B]`
* `B: [A, C]`
* `C: [B]`

* **Pros:** Saves space $O(V + E)$. Standard for algorithms.
* **Cons:** Checking connection is slower (have to walk the list).



---

## 4. C Implementation (Adjacency Matrix)
We will implement an Undirected Graph using the Matrix method because it's easier to visualize.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// 1. Initialize the Graph (All 0s)
void init_graph(Graph* g) {
    g->numVertices = MAX_VERTICES;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// 2. Add Edge (Undirected = Symmetric)
void add_edge(Graph* g, int start, int end) {
    // Connect Start -> End
    g->adjMatrix[start][end] = 1;
    // Connect End -> Start (Remove this line for Directed Graph)
    g->adjMatrix[end][start] = 1; 
}

// 3. Print the Matrix
void print_graph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g);

    // Creating connections: 0-1, 0-2, 1-2
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);

    print_graph(&g);
    return 0;
}
```

---

## 5. Graph Traversals
Just like Trees have DFS/BFS, Graphs do too.

| Algo | Full Name | Strategy | Data Structure |
|---|---|---|---|
| **BFS** | Breadth-First Search | **"The Wave":** Visit all immediate neighbors first. | **Queue** |
| **DFS** | Depth-First Search | **"The Maze Solver":** Go as deep as possible, then backtrack. | **Stack** (or Recursion) |

---

## 6. Performance Analysis

| Operation | Adjacency Matrix | Adjacency List | 
|---|---|---|
| **Space** | $O(V^2)$ (Heavy) | $O(V + E)$ (Light) | 
| **Add Edge** | $O(1)$ | $O(1)$ | 
| **Check Edge** | $O(1)$ | $O(degree)$ | 
| **BFS/DFS** | $O(V^2)$ | $O(V + E)$ | 

**My Takeaway:**
   * Use **Matrix** for dense graphs (lots of edges) or small graphs.
   * Use **List** for sparse graphs (few edges) - This is what you'll use 90% of the time in real world.

---

## 7. Variations

* **Weighted Graph:** Edges have "Cost" (e.g., Distance between cities). Matrix stores weights instead of `1`.
* **DAG (Directed Acyclic Graph):** A directed graph with NO loops. Critical for scheduling tasks (Project Management).
* **Complete Graph ($K_n$):** Everyone is connected to everyone.

---

**References**
* **Course Material:** Lecture notes on Data Structures.
* **AI Assistance:** Content synthesized and structured with the help of Gemini AI.
