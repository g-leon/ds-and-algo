#include <fstream>
#include <iostream>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <climits>
using namespace std;

void compute(char *c, int &smallest, int &biggest) {
    int len = strlen(c);

    smallest = biggest = atoi(c);

    for (int i = 0; i < len; i++)
        for (int j = 0; j < i; j++) {
            if (j == 0 && c[i] == '0') continue;
            swap(c[i], c[j]);
            biggest = max(biggest, atoi(c));
            smallest = min(smallest, atoi(c));
            swap(c[i], c[j]);
        }
}

int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int t;
    char nr[20];

    fin >> t;
    for (int i = 1; i <= t; i++) {
        fin >> nr;

        int smallest, biggest;
        compute(nr, smallest, biggest);
        fout << "Case #" << i << ": " << smallest << " " << biggest << '\n';
    }
}
