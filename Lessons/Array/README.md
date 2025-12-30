# 📦 Data Structure: Array Implementation

> **Study Note:** Arrays are the foundational building blocks of data structures. They offer fast access but rigid structural constraints.

---

## 1. Concept & Memory Layout

An **Array** is a collection of elements of the same type stored in **contiguous memory locations**.
* **Key Feature:** Random Access. You can calculate the exact memory address of any element instantly.
* **The Math:** $Address(i) = BaseAddress + (i \times SizeOfElement)$

### 🧠 Visualization (Memory Model)
Instead of a black box, visualize how an array looks in RAM:

```mermaid
graph LR
    subgraph Memory Block
    A[Index 0 <br> Addr: 1000] --- B[Index 1 <br> Addr: 1004]
    B --- C[Index 2 <br> Addr: 1008]
    C --- D[Index 3 <br> Addr: 1012]
    D --- E[Index 4 <br> Addr: 1016]
    end
    style A fill:#f9f,stroke:#333
    style B fill:#f9f,stroke:#333
    style C fill:#f9f,stroke:#333
    style D fill:#f9f,stroke:#333
    style E fill:#f9f,stroke:#333
