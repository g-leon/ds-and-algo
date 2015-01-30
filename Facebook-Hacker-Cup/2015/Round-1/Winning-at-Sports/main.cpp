#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

#define MOD 1000000007

int sf[2002][2002];
int s[2002][2002];

void stress_free() {
    sf[1][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 0; j < i; j++) {
            sf[i + 1][j] = (sf[i + 1][j] + sf[i][j]) % MOD;
            sf[i][j + 1] = (sf[i][j + 1] + sf[i][j]) % MOD;
        }
    }
}

void stressful() {
    s[0][0] = 1;
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            if (j >= i) {
                s[i + 1][j] = (s[i + 1][j] + s[i][j]) % MOD;
                s[i][j + 1] = (s[i][j + 1] + s[i][j]) % MOD;
            } else {
                s[i + 1][j] = (s[i + 1][j] + s[i][j]) % MOD;
            }
        }
    }
}

/***************** MAIN *****************/
int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    stress_free();
    stressful();

    int T;
    fin >> T;
    for (int i = 1; i <= T; i++) {
        int a, b;
        char h;
        fin >> a >> h >> b;
        fout << "Case #" << i << ": " << sf[a][b] << " " << s[a][b] << '\n';
    }
}