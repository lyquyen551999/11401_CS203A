# Module 05: Hash Table - The Magic Map

## 1. The Concept: Valet Parking
Imagine a massive parking lot.
* **Array approach:** You drive around looking for an empty spot ($O(n)$).
* **Hash Table approach:** You give your car key to a valet. The valet looks at your license plate, runs a quick calculation, and knows *exactly* which slot (e.g., Slot #42) your car belongs to. No searching required.

> **The Core Idea:** We want the speed of an Array ($O(1)$) but the flexibility to use *any* data type as the index (String, Negative number, Object), not just integers $0 \dots N$.

---

## 2. The Components

### 2.1. The Hash Function (The "Translator")
This is the magic spell. It takes a **Key** (e.g., "Alice") and turns it into an **Integer Index** (e.g., `3`).

$$Index = Hash(Key) \ \% \ TableSize$$

* **Goal:** Spread keys evenly across the array to avoid piling up.
* **Rule:** Same Input must always equal Same Output (Determinism).

### 2.2. Collision Handling (The "Traffic Jam")
What happens if "Alice" and "Bob" both hash to index `3`? This is a **Collision**. Two main ways to fix it:

| Strategy | Analogy | Pros | Cons |
| :--- | :--- | :--- | :--- |
| **Separate Chaining** | **Bunk Beds:** If slot 3 is taken, stack "Bob" on top of "Alice" (Linked List). | Simple deletion. Tolerates high load. | Pointers waste memory. Cache unfriendly. |
| **Open Addressing** | **Next Seat:** If slot 3 is taken, "Bob" looks for slot 4, then 5... (Linear Probing). | No pointers. Fast Cache access. | Deletion is tricky (needs "Tombstones"). Slower if full. |



---

## 3. Implementation: Open Addressing (Linear Probing)
Since C doesn't have built-in Maps (like Python's `dict`), we build one! Here is a clean implementation using **Linear Probing**.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Status flags to handle deletion and empty slots
#define EMPTY 0
#define OCCUPIED 1

typedef struct {
    int key;
    int value;
    int status; // Used to track if slot is taken
} HashItem;

typedef struct {
    HashItem* items;
    int size;
    int capacity;
} HashTable;

// 1. Create the table
HashTable* create_table(int capacity) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->size = 0;
    // Calloc initializes everything to 0 (EMPTY)
    table->items = (HashItem*) calloc(capacity, sizeof(HashItem)); 
    return table;
}

// 2. Simple Hash Function
unsigned int hash_function(int key, int capacity) {
    // Multiply by a prime to scramble bits, then modulo
    return (unsigned int)(key * 2654435761u) % capacity;
}

// 3. Insert (Put)
void hash_insert(HashTable* table, int key, int value) {
    if (table->size >= table->capacity) return; // Table full!

    unsigned int index = hash_function(key, table->capacity);

    // Linear Probing: If occupied, move to next slot
    while (table->items[index].status == OCCUPIED) {
        // Update existing key if found
        if (table->items[index].key == key) {
            table->items[index].value = value;
            return;
        }
        index = (index + 1) % table->capacity; // Wrap around
    }

    // Found empty spot
    table->items[index].key = key;
    table->items[index].value = value;
    table->items[index].status = OCCUPIED;
    table->size++;
}

// 4. Search (Get)
int hash_search(HashTable* table, int key) {
    unsigned int index = hash_function(key, table->capacity);
    int start_index = index;

    while (table->items[index].status != EMPTY) {
        if (table->items[index].key == key && table->items[index].status == OCCUPIED) {
            return table->items[index].value; // Found!
        }
        index = (index + 1) % table->capacity;
        
        // Loop protection: if we circled back to start
        if (index == start_index) break; 
    }
    return -1; // Not found
}
```

**My Take:** Notice the `while` loop in `insert` and `search`. That's the "Probing" part. If the ideal spot is taken, we just keep walking down the street until we find space.

---

## 4. Complexity Analysis

| Operation | Average Case | Worst Case | Why Worst Case? |
| :--- | :--- | :--- | :--- |
| **Insert** | $O(1)$ | $O(n)$ | Collision storm (everyone hashes to same index). |
| **Lookup** | $O(1)$ | $O(n)$ | Same as above. |
| **Delete** | $O(1)$ | $O(n)$ | Same as above. |

* **Load Factor ($\alpha$):**  $\alpha = \frac{\text{Elements}}{\text{Capacity}}$.
* **Rule of Thumb:** Keep $\alpha < 0.7$. If the table gets 70% full, resize it (double the size) to keep operations fast.

---

## 5. The "Killer" Application: Two Sum (Optimized)
We solved this in Module 02 with $O(n^2)$. Now, with a Hash Table, we crush it in $O(n)$.

**Logic:** For every number `x`, we check: "Have I seen `target - x` before?"
* If **Yes:** Solution found!
* If **No:** Add `x` to the Hash Table and continue.
