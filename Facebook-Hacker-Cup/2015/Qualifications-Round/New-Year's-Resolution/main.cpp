#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

struct food {
    int prot, carb, fat;

    food(): prot(0), carb(0), fat(0) {};
}fa[20];

int N, PROT, CARB, FAT;

food eat(int r, food f) {
    f.prot += fa[r].prot;
    f.carb += fa[r].carb;
    f.fat += fa[r].fat;
    return f;
}

bool enough(food f) {
    return f.prot == PROT && f.carb == CARB && f.fat == FAT;
}

bool ok(int r, food f) {
    if (r > N) return false;

    if (enough(f)) return true;

    return ok(r + 1, f) || ok(r + 1, eat(r, f));
}

/***************** MAIN *****************/
int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int t;
    fin >> t;
    for (int i = 1; i <= t; i++) {
        fin >> PROT >> CARB >> FAT;
        fin >> N;
        for (int j = 0; j < N; j++)
            fin >> fa[j].prot >> fa[j].carb >> fa[j].fat;

        food f;
        if (ok(0, f))
            fout << "Case " << "#" << i << ": yes" << '\n';
        else
            fout << "Case " << "#" << i << ": no" << '\n';
    }
}
