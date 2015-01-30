#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <set>
#include <ctime>
#include <list>
using namespace std;

int deceitful_war(list<float> naomi, list<float> ken) {
    int points = 0;
    list<float>::iterator it;

    naomi.sort();
    ken.sort();

    while (!naomi.empty()) {
        if (naomi.back() > ken.back()) {
            points++;
            for (it = naomi.begin(); it != naomi.end(); it++)
                if (*it > ken.front()) {
                    naomi.erase(it);
                    ken.pop_front();
                    break;
                }
        } else {
            for (it = ken.begin(); it != ken.end(); it++)
                if (*it > naomi.back()) {
                    ken.erase(it);
                    naomi.pop_front();
                    break;
                }
        }
    }

    return points;
}

int war(list<float> naomi, list<float> ken) {
    int points = 0;
    list<float>::iterator it1;
    list<float>::iterator it2;

    naomi.sort();
    ken.sort();

    for (it1 = naomi.begin(); it1 != naomi.end(); it1++) {
        bool flag = true;
        for (it2 = ken.begin(); it2 != ken.end(); it2++)
            if (*it2 > *it1) {
                flag = false;
                ken.erase(it2);
                break;
            }
        if (flag)
            points++;
    }

    return points;
}

int main() {
    ifstream fin("file.in");
    FILE *fout = fopen("file.out", "w");

    int t, n;
    list<float> naomi, ken;
    float x;

    fin >> t;
    for (int test_nr = 1; test_nr <= t; test_nr++) {
        // Read
        fin >> n;
        for (int i = 1; i <= n; i++) {
            fin >> x;
            naomi.push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            fin >> x;
            ken.push_back(x);
        }

        // Print
        fprintf(fout, "Case #%d: %d %d\n", test_nr, deceitful_war(naomi, ken), war(naomi, ken));
        naomi.clear();
        ken.clear();
    }
}
