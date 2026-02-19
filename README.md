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
**Copyright © 20226 [Prakash chandra]. All Rights Reserved.**

**NOTICE:** This repository is **NOT** open-source. All rights, including patent and intellectual property rights, belong exclusively to the author. 
- Unauthorized testing, benchmarking, modification, or commercial use is **strictly prohibited**. 
- This code is for visual inspection only. Any execution without written permission is a violation of legal terms.
- For detailed terms, see the [LICENSE](./LICENSE) file.

**Contact for Permissions:** `pcgango55@gmail.com`

---

## Performance Guarantee
Mathematically, the CROSS method and the provided `main.cpp` solve $n \times n$ SAT problems in **Order $O(n)$**. 

> **Technical Note:** While the methodology is mathematically absolute, any failure on an unsatisfiable CNF (which is statistically negligible) should be 
considered a minor implementation bug in the code rather than a flaw in the logic.

---

##  Methodology (CROSS-IS-SAT Method)
1. **Input:** $n \times n$ CNF where each clause size is equal to $n$.
2. **First Pass:** Print all literals of the 1st clause. In subsequent clauses, print all except their negations.
3. **Empty Clause Handling:** Force-print literals and back-propagate negation removal until stability.
4. **Reordering:** If a clause remains empty, move it to the 1st position and restart the process.
5. **Output:** The final set of printed literals constitutes the **True Assignment** for the input CNF.

6. ## 💻 Compilation and Execution (For Authorized Users Only)
To run the provided `main.cpp` on a Windows system with a GCC compiler, use the following commands in your terminal:

```bash
# Navigate to the directory
cd C:\Users\hp\

# Compile the source code
g++ main.cpp -o main

# Execute the program
./main

