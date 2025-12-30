# Module 02: Array - The Foundation

## 1. What is an Array?
If RAM is a giant city, an **Array** is a row of terraced houses (nhà phố liền kề) built on a single street.
* **Contiguous:** All elements live next door to each other in memory.
* **Homogeneous:** Every house looks the same (stores the same data type).
* **Indexed:** You find a house by its house number (0, 1, 2...), not by searching the whole city.

> **Key Feature:** Because we know the start address and the size of each element, we can calculate the address of *any* element instantly. This gives us the superpower of **Random Access**.

---

## 2. Array ADT (The Contract)
As an Abstract Data Type, an Array promises these behaviors:

| Operation | Description | Time Complexity |
| :--- | :--- | :--- |
| **Access(i)** | "Give me the value at index `i`" | $O(1)$ (Instant) |
| **Update(i, val)** | "Change value at index `i` to `val`" | $O(1)$ (Instant) |
| **Insert(i, val)** | "Squeeze `val` into index `i`" | $O(n)$ (Slow - Shifting required) |
| **Delete(i)** | "Remove value at index `i`" | $O(n)$ (Slow - Shifting required) |
| **Size()** | "How many elements do I have?" | $O(1)$ |

---

## 3. Implementation in C

### 3.1. Static Array (The "Fixed" Way)
Allocated at **Compile Time**. The size is set in stone.

```c
#include <stdio.h>

int main() {
    // Declaration: A fixed block for 5 integers
    int scores[5] = {10, 20, 30, 40, 50};

    // Access: Reading the 3rd element (Index 2)
    printf("Score 3: %d\n", scores[2]);

    // Traversal: Visiting every neighbor
    printf("All scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    return 0;
}
```
### 3.2. Dynamic Array (The "Flexible" Way)
Allocated at Runtime (Heap memory). Can grow if needed.

```c
#include <stdio.h>
#include <stdlib.h> // Required for malloc/realloc/free

int main() {
    int capacity = 5;
    
    // 1. Allocation: Request memory from Heap
    int* dynamic_arr = (int*) malloc(capacity * sizeof(int));
    
    // Safety check: Always check if malloc failed!
    if (dynamic_arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // 2. Initialization
    for (int i = 0; i < capacity; i++) {
        dynamic_arr[i] = (i + 1) * 10;
    }

    // 3. Resizing (The tricky part)
    // Scenario: We need more space! Let's double it.
    int new_capacity = capacity * 2;
    
    // Use a temporary pointer to protect original data if realloc fails
    int* temp_ptr = (int*) realloc(dynamic_arr, new_capacity * sizeof(int));
    
    if (temp_ptr == NULL) {
        printf("Resize failed! Keeping old array.\n");
        free(dynamic_arr); // Don't forget to clean up
        return 1;
    }
    
    // Update our main pointer
    dynamic_arr = temp_ptr;
    capacity = new_capacity;

    printf("Array resized successfully to %d elements.\n", capacity);

    // 4. Cleanup (Crucial in C)
    free(dynamic_arr);
    
    return 0;
}
```
My Takeaway: realloc is expensive! It might involve finding a new memory block and copying all old data over. Avoid calling it too often (e.g., inside a loop).

---

## 4. Performance Analysis

### 4.1. Complexity Cheat Sheet

| Operation | Complexity | Why? |
| :--- | :--- | :--- |
| **Access/Read** | $O(1)$ | "Simple math: Base_Addr + (Index * Size)" |
| **Search (Unsorted)** | $O(n)$ | "Must check every element one by one." |
| **Search (Sorted)** | $O(\log n)$ | "Can use **Binary Search**." |
| **Insert/Delete (End)** | $O(1)$ | "No shifting needed (if space exists)." |
| **Insert/Delete (Middle)** | $O(n)$ | "Requires shifting elements to close/open gaps." |

### 4.2. Pros & Cons

| The Good (Pros) | The Bad (Cons) | 
| :--- | :--- | :--- |
| **✅ Blazing Fast Reads:**"Instant access to any index." | **❌ Fixed Size (Static):**"Can't handle unexpected extra data." | 
| **✅ Cache Friendly:**"Elements are neighbors, CPU loves this linear access." | **❌ Slow Writes (Middle):**"nsertion/Deletion is heavy ($O(n)$)." | 
| **✅ Memory Efficient:**"No overhead per element (unlike Linked Lists)." | **❌ Memory Waste:**"If you allocate 1000 slots but use 10." | 



