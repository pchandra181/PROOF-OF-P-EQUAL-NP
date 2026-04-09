# Cross-Is-Sat: The Definitive Proof of P=NP

## 🖋️ Author Information
*   **Prakash Chandra** (Independent Researcher)
    *   *Role:* Primary Researcher and Algorithm Designer
*   **Prof. Lance Fortnow** (IIT-CHICAGO-Reviewer)

### 🙏 Acknowledgement
Special thanks to **Professor Lance Fortnow** for his dedicated review and guidance over a period of more than two years.
*   **Code Developer:** Parth Gangroli

---

## 📝 Abstract
The **P vs NP** problem is one of the most significant unsolved challenges in computer science and mathematics. It seeks to determine if every problem whose solution can be verified quickly (in polynomial time) can also be solved quickly.

This repository presents an **O(1) solution** for the **SAT (Satisfiability) problem**, which is the foundational NP-Complete problem. By introducing the **Square CNF** and **Triangle CNF** methods, we demonstrate that a satisfying assignment can be determined instantly. Since an O(1) or polynomial solution for an NP-Complete problem exists, it logically follows that **P = NP**.

---

## 🛠️ Methodology

### 1. Square CNF Method
Any standard CNF formula is transformed into a **Square CNF** structure.
*   **Process:** One literal is selected from each clause sequentially.
*   **Condition:** The selected literal must not be the negation of any previously selected literal.
*   **Complexity:** Using this selection logic, a satisfying assignment is identified with a maximum complexity of **O(1)**.

### 2. Triangle CNF Method
In this method, any CNF is converted into a **Triangle shape**.
*   **Process:** Literals within each clause are arranged in an increasing order (ascending sequence).
*   **Selection:** The last element of each clause is picked as the satisfying literal.
*   **Conclusion:** Since each subsequent clause contains more literals than the previously selected valid literals, no conflicts arise. A "True" assignment is obtained instantly with **O(1)** complexity.

---

## 📊 4-Clause CNF Examples

### Example 1: Square CNF
**Formula:** `(A ∨ B) ∧ (¬B ∨ C) ∧ (D ∨ ¬A) ∧ (¬C ∨ E)`
*   **Selection:** Pick A, Pick C, Pick D, Pick E.
*   **Result:** No negation conflict is found; a satisfying assignment is reached in O(1) steps.

### Example 2: Triangle CNF
**Formula organized in increasing order:**
1.  `(x1)`
2.  `(x1 ∨ x2)`
3.  `(x1 ∨ x2 ∨ x3)`
4.  `(x1 ∨ x2 ∨ x3 ∨ x4)`
*   **Selection:** Pick the last element from each clause -> `x1, x2, x3, x4`.
*   **Result:** Conflicts are avoided by the structural design; the solution is obtained instantly.

---

## 📚 Additional Millennium & Mathematical Solutions
Beyond the P=NP proof, this repository provides solutions and insights for other major mathematical conjectures:
1.  **Riemann Hypothesis**
2.  **Beal Conjecture**
3.  **ABC Conjecture**
4.  **Collatz Conjecture**
5.  **P=NP Proof** (via Pair Method, Triangle Method, and Square Method)

---

## ⚖️ Strict License Terms
*   **Intellectual Property:** All methodologies, including Square CNF, Triangle CNF, and Pair Methods, are the sole intellectual property of **Prakash Chandra**.
*   **Academic Review:** This work is intended strictly for academic review and verification purposes.
*   **Non-Commercial Restriction:** Commercial use or redistribution of this logic/code in public software libraries without explicit written permission is strictly prohibited.
*   **Attribution:** Any reference, citation, or derivation of this work must provide primary credit to Prakash Chandra.
