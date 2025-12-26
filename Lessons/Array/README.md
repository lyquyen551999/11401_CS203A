# Lecture Summary: Data Structures - Arrays

## 1. Definition and Structure
* **Concept:** An Array is a collection of elements stored in a **contiguous block of memory**.
* **Visual Representation:** Elements sit side-by-side in memory, allowing them to be indexed directly (e.g., `Array[0]`, `Array[1]`).
* **Static Nature:** In languages like C, the size of the array is typically fixed and must be defined at the time of declaration.

## 2. Key Operations & Time Complexity
The lecture highlights the performance characteristics of arrays, particularly contrasting them with Linked Lists.

| Operation | Complexity | Description |
| :--- | :--- | :--- |
| **Access (Indexing)** | **$O(1)$** | You can access any element instantly if you know its index because the memory is contiguous. |
| **Search** | **$O(n)$** | Finding an element requires checking items one by one (Linear Search). |
| **Insertion** | **$O(n)$** | Inserting an element (especially in the middle or beginning) is expensive because you must **shift** all subsequent elements to make space. |
| **Deletion** | **$O(n)$** | Similar to insertion, removing an element requires shifting subsequent elements to fill the gap. |

## 3. Advantages (Pros)
* **Fast Access:** Direct access via index is the biggest strength of arrays.
* **Memory Efficiency:** There is **no extra overhead** per element (unlike Linked Lists which need extra memory for pointers).
* **Cache Performance:** Because elements are stored next to each other, arrays have **good spatial locality**, making them cache-friendly.
* **Simplicity:** Easier to implement and use for simple data storage.

## 4. Disadvantages (Cons)
* **Fixed Size:** You often need to know the size in advance. Resizing (in dynamic arrays) can be costly.
* **Inefficient Modification:** Adding or removing elements is slow due to the shifting requirement.
