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
    FILE *fout = fopen("file.out", "w");

    int t;
    double cookies_per_sec, elapsed_time, best_time, time;
    double C, F, X;

    fin >> t;
    for (int test_nr = 1; test_nr <= t; test_nr++) {
        // Read
        fin >> C >> F >> X;

        // Compute
        cookies_per_sec = 2.0;
        elapsed_time = 0;
        best_time = X / cookies_per_sec;

        while (1) {
            elapsed_time += C / cookies_per_sec;
            cookies_per_sec += F;
            time = elapsed_time + X / cookies_per_sec;

            if (best_time < time)
                break;
            else
                best_time = time;
        }

        // Print
        fprintf(fout, " Case #%d: %.7f\n", test_nr, best_time);
    }
}
