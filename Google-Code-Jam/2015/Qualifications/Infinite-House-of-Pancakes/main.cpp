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

int second_top(priority_queue<int> &pq) {
    int tmp = pq.top();
    pq.pop();
    int second = pq.top();
    pq.push(tmp);
    return second;
}

int cut(priority_queue<int> &pq) {
    int old_top = pq.top();
    int half = pq.top() % 2 == 1 ? pq.top() / 2 + 1 : pq.top() / 2;
    pq.pop();
    int new_top = pq.size() != 0 ? pq.top() : 0;
    int biggest = max(half, new_top);
    pq.push(old_top);
    return biggest;
}

int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int T, d, x, res;

    fin >> T;
    for (int t = 1; t <= T; t++) {
        fin >> d;

        priority_queue<int> pq;
        for (int i = 0; i < d; i++) {
            fin >> x;
            pq.push(x);
        }

        int time = 0;
        while (1) {
            if (cut(pq) + time + 1 < pq.top() + time) {
                time++;
                int tmp = pq.top();
                pq.pop();
                if (tmp % 2 == 1) {
                    pq.push(tmp / 2 + 1);
                    pq.push(tmp / 2);
                } else {
                    pq.push(tmp / 2);
                    pq.push(tmp / 2);
                }
            } else {
                time += pq.top();
                break;
            }
        }

        fout << "Case #" << t << ": " << time << '\n';
    }
}
