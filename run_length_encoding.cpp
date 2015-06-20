#include <fstream>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <cstdio>
#include <stdlib.h>
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


string itos(int nr) {
    stringstream s;
    s << nr;
    return s.str();
}

void trim(string &s) {
    int offset = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            offset++;
        else
            s[i - offset] = s[i];

    s = s.substr(0, s.size() - offset);
}

void insert_nr(string &s, int pos, int nr) {
    if (nr < 2) return;
    string str_nr = itos(nr);

    int j = 0;
    for (int i = pos; i < pos + str_nr.size(); i++) {
        s[i] = str_nr[j++];
    }
}

string rle(string s) {
    if (s.size() < 1) return s;

    int i = 0, j = 0;
    while (j < s.size()) {
        while (s[i] == s[j]) {
            if (i != j) s[j] = ' ';
            j++;
        }
        insert_nr(s, i + 1, j - i);
        i = j;
    }

    trim(s);

    return s;
}

int main() {
    assert(rle("aabb") == "a2b2");
    assert(rle("abb") == "ab2");
    assert(rle("a") == "a");
}
