# Dictionary, Hashing & Collisions 🔑

## 1. Dictionary & Key-Value
> **Analogy:** Imagine checking your bag at a supermarket. 🛍️

1.  You give your bag (**Value**).
2.  You get a number tag, e.g., `#05` (**Key**).
3.  To get your bag back, you just show tag `#05`.

This represents a **Key-Value Pair**.

![Supermarket Bag Check Analogy](img_hash.png)
*Concept: Using a unique Key (Tag #05) to retrieve a Value (The Bag).*

---

## 2. Hashing - The Magic Guard 🧙‍♂️
How does a computer know where to put "Alice's" data in a numbered list (Array)?
It uses a **Hash Function**.

* **Input:** "Alice"
* **Magic Formula:** Does some math (like modulo `%`).
* **Output:** Box `#3`.

$\rightarrow$ Alice's data goes into **Box #3**.

> **Goal:** Super fast retrieval ($O(1)$). No searching, just calculating.

---

## 3. Collision - Traffic Jam! 💥
What if "Alex" comes in, and the formula also calculates **Box #3**?
* Box #3 is already occupied by Alice!
* **This is a Collision:** Different keys mapping to the same index.

---

## 4. Solving Collisions - The Strategies 🛠️

### A. Strategy 1: Chaining (The Bunk Bed)
If Box #3 is full, just hang Alex's bag *under* Alice's bag.
* **Method:** Make a chain (**Linked List**) at that slot.
* **Con:** Looking up items in a long chain is slow.

### B. Strategy 2: Open Addressing (Find an Empty Spot)
If Box #3 is full, Alex must find another empty box in the array. How?

#### 1. Linear Probing (Walking) 🚶
* Box 3 full? Try Box 4.
* Box 4 full? Try Box 5.
* **Problem:** **Primary Clustering**. It creates a "crowded neighborhood." If a block is full, newcomers make it even fuller and longer.

#### 2. Quadratic Probing (Leaping) 🐇
* Box 3 full? Jump 1 step ($1^2$).
* Still full? Jump 4 steps ($2^2$).
* Still full? Jump 9 steps ($3^2$).
* **Result:** Spreads data out better than walking.

#### 3. Double Hashing (The Smartest Jump) 🧠
* **Method:** Use a *second* math formula to decide the jump size.
* **Example:** Alice might jump 1 step if blocked, but Alex might jump 5 steps if blocked.
* **Result:** Best distribution, minimizes clustering.

---

### 📝 SUMMARY (RECAP)
> "Hash tables are the fastest way to find data (like looking up words in a dictionary). But the key to success lies in handling 'collision' (**two people wanting to enter the same house**). The best way is to use double hashing or chaining."
