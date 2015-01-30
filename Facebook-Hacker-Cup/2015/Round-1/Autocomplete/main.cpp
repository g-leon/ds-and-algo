#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

#define CH (*s - 'a')

struct Trie {
    Trie *fiu[26];
    int fiu_val[26];

    Trie() {
        memset(fiu_val, 0, sizeof(fiu_val));
        memset(fiu, NULL, sizeof(fiu));
    }
}*T;

void ins(Trie *nod, char *s) {
    if (*s == '\n' || *s == '\0') return;

    if (nod->fiu[CH] == NULL) {
        nod->fiu[CH] = new Trie;
    }

    nod->fiu_val[CH]++;
    ins(nod->fiu[CH], s + 1);
}

int autocomp(Trie *nod, char *s, int nr) {
    if (*s == '\n' || *s == '\0') return nr - 1;

    if (nod->fiu_val[CH] == 1)
        return nr;
    else
        return autocomp(nod->fiu[CH], s + 1, nr + 1);
}

/***************** MAIN *****************/
int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int t;
    fin >> t;
    for (int i = 1; i <= t; i++) {
        T = new Trie;
        char *c = new char[1000005];
        int nr_words;
        int result = 0;

        fin >> nr_words;
        fin.getline(c, 10);

        for (int j = 1; j <= nr_words; j++) {
            fin.getline(c, 1000005);
            ins(T, c);
            result += autocomp(T, c, 1);
        }

        fout << "Case #" << i << ": " << result << '\n';

        delete T;
        delete[] c;
    }
}
