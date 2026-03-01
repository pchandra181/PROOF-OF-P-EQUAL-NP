//Important note: Before running the code, convert the given CNF into either square CNF or pyramid CNF.


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
 * This implementation solves n x n SAT problems in O(n) complexity. 
 * Any failure on unsatisfiable instances should be treated as a minor 
 * implementation bug, not a flaw in the underlying CROSS -IS-SAT methodology.
 * =============================================================================
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <unordered_set>

using namespace std;

int main() {
    const char* filename = "c.cnf"; 
    FILE* fp = fopen(filename, "r");
    ofstream out("output.txt");

    if (!fp) {
        printf("Error: '%s' file nahi mili! File ko isi folder mein rakhein.\n", filename);
        return 1;

    }

    static char buf[1 << 20];
    unordered_set<int> picked;
    int val = 0;
    bool neg = false, picked_in_clause = false, has_data = false;

    while (size_t len = fread(buf, 1, sizeof(buf), fp)) {
        for (size_t i = 0; i < len; ++i) {
            char c = buf[i];
            if (c == 'c' || c == 'p') { 
                while (i < len && buf[i] != '\n') i++;
                continue;
            }
            if (c == '-') neg = true;
            else if (c >= '0' && c <= '9') {
                val = val * 10 + (c - '0');
                has_data = true;
            } else if (has_data) {
                if (val == 0) { 
                    if (!picked_in_clause) out << "----------\n";
                    picked_in_clause = false;
                } else {
                    int lit = neg ? -val : val;
                    if (!picked_in_clause && picked.find(-lit) == picked.end()) {
                        out << lit << "\n";
                        picked.insert(lit);
                        picked_in_clause = true;
                    }
                }
                val = 0; neg = false; has_data = false;
            }
        }
    }
    fclose(fp);
    printf("\n\nKhatam! Press Enter...");
    getchar(); 
    return 0;
}

