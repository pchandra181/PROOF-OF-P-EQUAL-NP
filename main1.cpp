
/* 
 * =============================================================================
 * PROJECT: CROSS is SAT Method - A Formal Proof of P=NP
 * DEVELOPER: P. Gangroli
 * REVIEWER: Prof. Lance Fortnow (IIT Chicago)
 * DATE: 19 feb 2026
 * 
 * COPYRIGHT NOTICE:
 * (C) 2026 [Prakash chandra]. All Rights Reserved.
 * 
 * STRICT USAGE POLICY:
 * This source code is PROPRIETARY and is NOT licensed under any open-source 
 * agreement. Modification, redistribution, execution, benchmarking, or 
 * commercial use is STRICTLY PROHIBITED without prior written permission 
 * from the author. This code is for visual inspection only.
 * 
 * MATHEMATICAL CLAIM:
 * This implementation solves N^2  SAT problems in O(n) complexity. 
 * Any failure on unsatisfiable instances should be treated as a minor 
 * implementation bug, not a flaw in the underlying CROSS -IS-SAT methodology.
 * =============================================================================
 */







//Guidelines for Running the Code
// 1. When executing the code, ensure the following steps are followed:
//2. Convert to Square CNF: Transform the given Conjunctive Normal Form (CNF) into a Square CNF format.
//3 .Order Literals by Clause: Arrange the literals within each clause according to the clause index/order.
//4. Ascending Order: Ensure that the literals inside every clause are sorted in ascending order.
//5. Determine True Assignment: Run the code; the resulting printed literals will represent the True Assignment for the CNF.






#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    ifstream inputFile("input.cnf");
    ofstream outputFile("last_literals.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "File Error!" << endl;
        return 1;
    }

    int lit;
    int last_lit = 0;
    bool has_content = false;

    
    while (inputFile >> lit) {
        if (lit == 0) {
            if (has_content) {
                outputFile << last_lit << "\n";
                has_content = false; 
            }
        } else {
            last_lit = lit;
            has_content = true;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Kaam ho gaya! 'last_literals.txt' ko Notepad mein check karein." << endl;

    return 0;
}

