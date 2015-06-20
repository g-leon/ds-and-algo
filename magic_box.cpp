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

int wishes;

struct trie {
    int cnt;
    trie *son[2];

    trie() {
        cnt = 0;
        memset(son, NULL, sizeof(son));
    }
};

void ins(trie *node, vector<unsigned char> &v, int col_idx) {
    if (col_idx >= v.size()) {
        node->cnt++;
        if (node->cnt > wishes) {
            wishes = node->cnt;
        }
        return;
    }

    if (node->son[v[col_idx]] == NULL) {
        node->son[v[col_idx]] = new trie;
    }

    ins(node->son[v[col_idx]], v, col_idx + 1);
}

void solve(vector<vector<unsigned char> > &mat) {
    trie *tr = new trie;
    wishes = 0;

    // push rows to trie
    for (int i = 0; i < mat.size(); i++)
        ins(tr, mat[i], 0);

    cout << wishes << '\n';
}

int main() {
    ifstream fin("file.in");
    int m, n;
    vector<vector<unsigned char> > mat;

    fin >> m >> n;

    for (int i = 0; i < m; i++) {
        vector<unsigned char> v;
        bool flag = false;

        for (int j = 0; j < n; j++) {
            char c; fin >> c;
            int x = c == 'T' ? 1 : 0;

            if (j == 0 && x) flag = true;

            if (flag)
                v.push_back(!x);
            else
                v.push_back(x);
        }

        mat.push_back(v);
    }

    solve(mat);
}
