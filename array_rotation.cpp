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


/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n) {
    int i = 0, j, k, temp, nr = 0;

    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1) {
        k = j + d;
        if (k >= n)
            k = k - n;
        if (k == i) {
            arr[j] = temp;
            i++;
            temp = arr[i];
            j = i;
            continue;
        }
        if (nr == n) {
            break;
        }

        arr[j] = arr[k];
        j = k;
        nr++;
    }

}


void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);

}
