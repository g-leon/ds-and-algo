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


int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int T, s, n;
    char c[1000];

    fin >> T;
    fin.get();

    for (int t = 1; t <= T; t++) {
        int standing = 0;
        int friends = 0;

        fin >> s; fin.get();
        fin.getline(c, 1000);

        n = s + 1;
        for (int i = 0; i < n; i++) {
            if (c[i] - '0' == 0) continue;

            if (i <= standing) {
                standing += c[i] - '0';
            } else {
                friends += (i - standing);
                standing += (i - standing) + c[i] - '0';
            }
        }

        fout << "Case #" << t << ": " << friends << '\n';
    }
}
