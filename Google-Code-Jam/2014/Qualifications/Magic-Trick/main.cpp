#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <map>
#include <set>
#include <ctime>
using namespace std;

int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int t, i, j, r1, r2, nr, magic_nr;
    int m1[5][5], m2[5][5];

    fin >> t;
    for (int test_nr = 1; test_nr <= t; test_nr++) {
        // Read
        fin >> r1;
        for (i = 1; i <= 4; i++)
            for (j = 1; j <=4; j++)
                fin >> m1[i][j];
        fin >> r2;
        for (i = 1; i <= 4; i++)
            for (j = 1; j <=4; j++)
                fin >> m2[i][j];

        // Compute
        nr = 0;
        for (int j1 = 1; j1 <=4; j1++)
            for (int j2 = 1; j2 <=4; j2++)
                if (m1[r1][j1] == m2[r2][j2]) {
                    nr++;
                    magic_nr = m1[r1][j1];
                }

        // Print
        if (nr == 0) {
            fout << "Case #" << test_nr << ": Volunteer cheated!\n";
        } else if (nr == 1) {
            fout << "Case #" << test_nr << ": " << magic_nr <<"\n";
        } else if (nr > 1) {
            fout << "Case #" << test_nr << ": Bad magician!\n";
        }
    }
}
