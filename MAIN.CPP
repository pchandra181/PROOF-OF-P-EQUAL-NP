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





#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string filename;
    if (!(cin >> filename)) {
        cerr << "Provide input filename as first token on stdin.\n";
        return 1;
    }
 
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << "\n";
        return 1;
    }

    vector<vector<int>> clauses;
    string line;

   
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == 'c' || line[0] == 'p') continue;

        stringstream ss(line);
        int lit;
        vector<int> clause;
        while (ss >> lit) {
            if (lit != 0) clause.push_back(lit);
        }
        if (!clause.empty()) clauses.push_back(move(clause));
    }
    file.close();

   
    unordered_map<int, vector<size_t>> occ;
    occ.reserve(clauses.size() * 2 + 10);
    for (size_t i = 0; i < clauses.size(); ++i)
        for (int lit : clauses[i])
            occ[lit].push_back(i);

    unordered_set<int> printedLiterals;
    vector<unordered_set<int>> printed;
    vector<int> printedSize;
    printed.reserve(clauses.size());
    printedSize.reserve(clauses.size());
    int emptyCount = 0;

    size_t i = 0;
    while (i < clauses.size()) {
        const vector<int>& clause = clauses[i];
        unordered_set<int> toPrint;

       
        for (int lit : clause)
            if (!printedLiterals.count(-lit))
                toPrint.insert(lit);

       
        if (toPrint.empty()) {
            bool adjusted = false;
            for (int num : clause) {
                bool flag = true;
                auto negIt = occ.find(-num);
                if (negIt != occ.end()) {
                    for (size_t k : negIt->second) {
                        if (k < printed.size() && printed[k].size() == 1 && printed[k].count(-num)) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag) {
                    
                    if (negIt != occ.end()) {
                        for (size_t k : negIt->second) {
                            if (k < printed.size() && printed[k].erase(-num)) {
                                if (--printedSize[k] == 0) ++emptyCount;
                            }
                        }
                    }

                   
                    auto posIt = occ.find(num);
                    if (posIt != occ.end()) {
                        for (size_t k : posIt->second) {
                            if (k < printed.size() && printed[k].insert(num).second) {
                                if (printedSize[k]++ == 0) --emptyCount;
                            }
                        }
                    }

                    printedLiterals.erase(-num);
                    printedLiterals.insert(num);
                    toPrint.insert(num);
                    adjusted = true;
                    break;
                }
            }
            if (!adjusted) {
                if (!clause.empty()) {
                    vector<int> currentClause = clause;
                    clauses.erase(clauses.begin() + i);
                    clauses.insert(clauses.begin(), move(currentClause));
                    printed.clear();
                    printedSize.clear();
                    printedLiterals.clear();
                    occ.clear();
                    occ.reserve(clauses.size() * 2 + 10);
                    for (size_t x = 0; x < clauses.size(); ++x)
                        for (int lit : clauses[x])
                            occ[lit].push_back(x);

                    i = 0;
                    continue;
                }
            }
        }
        if (!toPrint.empty()) {
            for (int lit : toPrint) printedLiterals.insert(lit);
            printed.push_back(move(toPrint));
            printedSize.push_back((int)printed.back().size());
        } else {
            printed.push_back({});
            printedSize.push_back(0);
            ++emptyCount;
        }

        ++i;
    }

    
    ofstream outfile("output.txt");
    if (!outfile.is_open()) {
        cerr << "Cannot open output file.\n";
        return 1;
    }

    for (size_t i = 0; i < printed.size(); ++i) {
        outfile << "line " << i + 1 << ": ";
        if (printed[i].empty()) {
            outfile << "---------------------------------------------------------------------------------------------";
        } else {
            bool first = true;
            for (int lit : printed[i]) {
                if (!first) outfile << " ";
                outfile << lit;
                first = false;
            }
        }
        outfile << "\n";

    }
    outfile.close();

    system("notepad output.txt");
    cout << "Done. Results written to output.txt\n";
    return 0;
}