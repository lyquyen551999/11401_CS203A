# 📘 Data Structures & Algorithms: Core Concepts

> **Study Note:** This document provides a comprehensive overview of Data Structures (DS), Abstract Data Types (ADT), and Performance Analysis. It is designed to summarize the core concepts needed for efficient software development in C++.

---

## 1. Introduction
### What is a Data Structure?
A **Data Structure (DS)** is a specialized format for organizing, processing, retrieving, and storing data. It ensures data can be used effectively.

* **Real-world Analogy:** Imagine a library.
    * If books are thrown in a pile, finding one takes forever (**Inefficient**).
    * If books are organized by genre and author on shelves, finding one is instant (**Efficient**).

---

## 2. Classification of Data Structures

Data structures are categorized based on memory allocation and data arrangement.

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
