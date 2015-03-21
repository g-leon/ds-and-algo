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


int len(int nr) {
    if (nr < 0) return len(-1 * nr);
    if (nr == 0) return 0;

    short c = 0;
    while (nr) {
        nr /= 10;
        c++;
    }

    return c;
}

int new_int(string s) {
    if (s.empty()) return INT_MIN;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 10 + (s[i] - '0');

    return res;
}

float str_to_nonscien(string s) {
    if (s.empty()) return 0;
    if (s[0] == '-') return -str_to_nonscien(s.substr(1));

    int idx_dot = s.find('.');
    if (idx_dot != string::npos) {
        int whole_part = new_int(s.substr(0, idx_dot));
        int dec_part = new_int(s.substr(idx_dot + 1));
        return whole_part +
               dec_part * pow(10, -len(dec_part));
    } else {
        return (float) new_int(s);
    }
}

void trim(string &s) {
    if (s.empty()) return;

    int offset = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            offset++;
        else
            s[i - offset] = s[i];

    s = s.substr(0, s.size() - offset);
}

float str_to_scien(string s) {
    if (s.empty()) return 0;

    trim(s);

    int idx_e = s.find('e');
    if (idx_e == string::npos)
        idx_e = s.find('E');

    if (idx_e == string::npos) {
        return str_to_nonscien(s);
    } else {
        return str_to_nonscien(s.substr(0, idx_e)) *
               pow(10, str_to_nonscien(s.substr(idx_e + 1)));
    }
}

int main() {
    float f = 3.2e-10;
    assert(str_to_scien("3.2e-10") == f);

    f = 3.2;
    assert(str_to_scien("3.2") == f);

    f = 3;
    assert(str_to_scien("3") == f);

    f = 3.2e-10;
    assert(str_to_scien(" 3 . 2 e - 1 0 ") == f);
}
