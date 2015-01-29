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
using namespace std;

struct special_nr {
    unsigned val;
    bool not_prime;
} sn[10000001];

void generate_primes() {
    for (int i = 2; i <= 10000000; i++)
        if (sn[i].not_prime == false) {
            sn[i].val++;
            for (int j = i + i; j <= 10000000; j += i) {
                sn[j].not_prime = true;
                sn[j].val++;
            }
        }
}

int compute(int a, int b, int k) {
    unsigned result = 0;
    for (int i = a; i <= b; i++)
        if (sn[i].val == k)
            result++;
    return result;
}

/***************** MAIN *****************/
int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    generate_primes();

    int T;
    fin >> T;
    for ( int i = 1; i <= T; i++) {
        int A, B, K;
        fin >> A >> B >> K;
        fout << "Case #" << i << ": " << compute(A, B, K) << '\n';
    }
}