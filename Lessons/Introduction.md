# 🚀 Data Structures: Core Concepts

> **Note:** This is a comprehensive summary of introductory data structures, focusing on how data is organized to optimize program efficiency.

## 1. What is a Data Structure?
In simple terms, a **Data Structure (DS)** is a specialized format for organizing, processing, retrieving, and storing data.
* **Analogy:** If data represents books, a Data Structure is the library shelving system. A messy pile of books makes finding a specific title impossible (inefficient), whereas a categorized shelf system makes retrieval instant (efficient).

---

## 2. Classification of Data Structures

Instead of a plain list, we can visualize the hierarchy of data structures as follows:

```mermaid
graph TD
    DS[Data Structures] --> P[Primitive]
    DS --> NP[Non-Primitive]
    
    P --> Int[Integer]
    P --> Fl[Float]
    P --> Ch[Char]
    P --> Pt[Pointer]
    
    NP --> L[Linear]
    NP --> NL[Non-Linear]
    
    L --> Arr[Array]
    L --> LL[Linked List]
    L --> St[Stack]
    L --> Q[Queue]
    
    NL --> Tr[Tree]
    NL --> Gr[Graph]
    NL --> Tb[Hash Table]
