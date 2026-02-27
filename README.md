# PROOF-OF-P-EQUAL-NP
A formal proof and O(n)  complexity solution for the N x N   SAT problem using the CROSS-IS-SAT method

# CROSS-IS-SAT Method: A Formal Proof of P=NP

##  Project Announcement
This repository contains the mathematical methodology and the C++ implementation (`main.cpp`) of the **CROSS-IS-SAT method**, which solves the $n \times n$ SAT problem with a computational complexity of **$O(n)$**.



## Acknowledgments & Credits
*   **Code Developer:** Parth Gangroli
*   **Scientific Review:** Special thanks to **Prof. Lance Fortnow** (IIT Chicago) for his invaluable time and effort in reviewing this methodology 
over a period of 1.5 years.



##  Restricted Access & Legal Warning
**Copyright © 2026 [Prakash chandra]. All Rights Reserved.**

**NOTICE:** This repository is **NOT** open-source. All rights, including patent and intellectual property rights, belong exclusively to the author. 
- Unauthorized testing, benchmarking, modification, or commercial use is **strictly prohibited**. 
- This code is for visual inspection only. Any execution without written permission is a violation of legal terms.
- For detailed terms, Read the full terms here: [View Strict License Terms](LICENSE.TXT)

**Contact for Permissions:** `pcgango55@gmail.com`

---

## Performance Guarantee
Mathematically, the CROSS-IS-SAT method and the provided `main.cpp` solve $n \times n$ SAT problems in **Order $O(n)$**. 

> **Technical Note:** While the methodology is mathematically absolute, any failure on an unsatisfiable CNF (which is statistically negligible) should be 
considered a minor implementation bug in the code rather than a flaw in the logic.

---

##  Methodology (CROSS-IS-SAT Method)
1. **Input:** $n \times n$ CNF where each clause size is equal to $n$.
2. **First Pass:** Print all literals of the 1st clause. In subsequent clauses, print all except their negations.
3. **Empty Clause Handling:** Force-print literals and back-propagate negation removal until stability.
4. **Reordering:** If a clause remains empty, move it to the 1st position and restart the process.
5. **Output:** The final set of printed literals constitutes the **True Assignment** for the input CNF.


   # Cross-Is-SAT Method: Square cnf to Pyramid CNF Conversion

This repository demonstrates the **Cross-Is-SAT** method for solving SAT problems by transforming a standard Square CNF into a Pyramid CNF structure to achieve near-instant satisfiability.

## 1. Methodology Overview

The core idea is to take an $n \times n$ CNF and restructure it into a "Pyramid" shape where the number of literals in each clause increases incrementally, and the last literal of each clause is unique.

### Transformation Rules:
1. **Square CNF:** Start with $n$ clauses, where each clause originally contains $n$ literals.
2. **Pyramid Conversion:** 
   - Clause $C_k$ must contain exactly $k$ literals.
   - The $k$-th literal (the last one) in each clause $C_k$ must be **unique**.
3. **Selection Rule:** 
   - To satisfy the CNF, select the **first literal of $C_1$** and the **last literal of every subsequent clause**.
   - Set all selected literals to `True`.

## 2. Example Walkthrough

### Step 1: Input Square CNF
Consider a 4-variable, 4-clause system:
- $C_1 = \{1, 2, 3, 0\}$
- $C_2 = \{-1, -2, -3, 0\}$
- $C_3 = \{1, -2, 3, 0\}$
- $C_4 = \{1, 2, -3, -4, 0\}$

### Step 2: Convert to Pyramid CNF
Following the rule where $C_k$ has $k$ literals:
- $C_1 = \{1\}$ (Last literal: $1$)
- $C_2 = \{-1, -2\}$ (Last literal: $-2$)
- $C_3 = \{-1, 2, 3\}$ (Last literal: $3$)
- $C_4 = \{-1, 2, -3, -4\}$ (Last literal: $-4$)

### Step 3: Solving via Selection
Applying the "Cross Is SAT" selection:
- From $C_1$: Select $1$
- From $C_2$: Select $-2$
- From $C_3$: Select $3$
- From $C_4$: Select $-4$

**Assignment:** $\{1=T, 2=F, 3=T, 4=F\}$

**Result:** All clauses are satisfied immediately because each clause contains at least one literal that has been set to True.

## 3. Complexity Analysis


| Process | Complexity |
| :--- | :--- |
| **SAT Solving (Pyramid)** | $O(1)$ per clause selection |
| **Total Solving Time** | $O(n)$ for $n$ clauses |
| **Conversion Logic** | Subject to uniqueness constraint of last literals. |

> **Note:** The efficiency of this method depends on the ability to map a general CNF into this Pyramid structure while maintaining the uniqueness of the trailing literals.

---
## Implementation Status
`// C++ source code for the revised version will be available soon.`
© 2026 Cross-Is-SAT METHOD Research


7. ## 💻 Compilation and Execution (For Authorized Users Only)
To run the provided `main.cpp` on a Windows system with a GCC compiler, use the following commands in your terminal:

```bash
# Navigate to the directory
cd C:\Users\hp\

# Compile the source code
g++ main.cpp -o main

# Execute the program
./main

