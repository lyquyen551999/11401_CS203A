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
---

## 3. Abstract Data Type (ADT)

### 🧠 The Concept
While a **Data Structure** is the concrete implementation (the code), an **Abstract Data Type (ADT)** is the logical concept.
* **ADT answers:** *What* does it do? (Behavior)
* **Implementation answers:** *How* does it do it? (Coding logic)

> **Analogy:** Think of a **Car**.
> * **ADT (Interface):** Steering wheel, pedals, gear stick. You know how to use them to drive.
> * **Implementation (Hidden):** Engine combustion, transmission belts, fuel injection. You don't need to see these to drive the car.

### 🧩 Components of an ADT
An ADT is defined strictly by:
1.  **Data:** The information being stored.
2.  **Operations:** The valid actions you can perform (e.g., `insert`, `delete`, `search`) without knowing the underlying code.

```mermaid
graph LR
    User((User/Programmer)) -- Calls Operation --> I[Interface / ADT]
    I -- Hides --> Im[Implementation / Code]
    style I fill:#f9f,stroke:#333,stroke-width:2px
    style Im fill:#bbf,stroke:#333,stroke-width:2px,stroke-dasharray: 5 5

