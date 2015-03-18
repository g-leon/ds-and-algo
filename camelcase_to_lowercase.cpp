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

/*
Design a function that converts a camel-case string to a lowercase string.
*/

string camel_to_lower(string& s) {
    string res;

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]) && isupper(s[i]))
            res.push_back(tolower(s[i]));
        else
            res.push_back(s[i]);
    }

    return res;
}

int main() {
    string s = "AbC";
    assert(camel_to_lower(s) == "abc");

    s = "";
    assert(camel_to_lower(s) == "");

    s = "1A";
    assert(camel_to_lower(s) == "1a");
}
