# Graph Theory: The Web of Connections 🕸️

## 1. The Origin: The Seven Bridges Problem 🌉
The story begins in the city of **Königsberg**. There were 7 bridges there, and people challenged each other:
> *"Is there a way to cross all 7 bridges, crossing each one exactly once, and return to the starting point?"*

The mathematician **Euler** solved this by a simple insight: He didn't care if the bridges were curved or straight; he simply redrew them as **dots** and **connecting lines**.
$\rightarrow$ That was the birth of **Graph Theory**!

---

## 2. Graph Anatomy 🧬
Basically, a Graph ($G$) consists of only 2 things:
* **Vertex/Node ($V$):** The dots. *Example: Cities, or Facebook accounts.*
* **Edge ($E$):** The connecting lines. *Example: Roads, or friendships.*

### Types of Paths (Classification):
* **Undirected:** A 2-way street (If A is friends with B, then B is friends with A).
* **Directed:** A 1-way street (A likes B, but B might not like A back - the arrow points one way).
* **Weighted:** Each road has a length (km) or a toll fee. *Google Maps uses this to calculate the fastest route.*

### Concept of Degree:
This is the number of "friends" connected to a node.
* If it is a directed graph, we split it into: **In-degree** (edges pointing in) and **Out-degree** (edges pointing out).

---

## 3. Graph vs. Tree 🌳 vs 🕸️
You have already learned about Trees, so how is a Graph different?

* **Tree:** Very disciplined. No circles allowed (**no cycles**), has a strict hierarchy (parent-child), and is always connected.
* **Graph:** Free and flexible.
    * Can form circles (**Cycle**) (you can walk around and return to the start).
    * Can be broken apart (**Disconnected**) (like separate islands).

---

## 4. Graph Representation (Most important for exams) 💾
Computers can't "see" drawings; they need data. There are 2 main ways to store a graph. Imagine these as 2 ways to manage a phonebook:

### Method 1: Adjacency Matrix - "The Grid"
You draw a square table $V \times V$.
* If A connects to B $\rightarrow$ Write `1` (or the weight).
* If they don't connect $\rightarrow$ Write `0`.

### Method 2: Adjacency List - "The Phonebook"
Each person simply keeps a list of the people they know.
* **A:** connects to `{B, C}`.
* **B:** connects to `{D}`.

### ⚡ Pocket Cheatsheet: Matrix vs. List

| Feature | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Visualization** | Excel Spreadsheet | Phonebook |
| **Check connection (A, B)** | Super fast $O(1)$ | Slower, must scan $O(deg(u))$ |
| **Memory usage** | Very high $O(V^2)$ | Efficient $O(V + E)$ |
| **When to use?** | Dense Graph (many edges) | Sparse Graph (few edges) - Used most in reality |

---

## 5. Walking through the Graph (Graph Traversal) 🚶‍♂️
When lost in a maze (graph), there are 2 tactics to find the way out:

### A. DFS (Depth-First Search)
* **Tactic:** "Once you commit, you keep going." Keep going **deep** until you hit a dead end, then turn back.
* **Tool:** Uses a **Stack** or **Recursion**.

### B. BFS (Breadth-First Search)
* **Tactic:** "Oil spill" (or Ripple effect). Visit all immediate neighbors first, then expand further out.
* **Tool:** Uses a **Queue**.

> **Note:** Since graphs have cycles, we must mark places as **"Visited"** to avoid walking in circles forever.
