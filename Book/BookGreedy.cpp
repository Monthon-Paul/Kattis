// https://open.kattis.com/problems/bokhyllor
#include <iostream>
using namespace std;
/* did it Greedy lol */
int main() {
    int b1, b2, b3, shelf;
    cin >> b1 >> b2 >> b3 >> shelf;
    int count = 0, current_shelf = 0;
    for (int i = 0; i < b3; i++) {
        if (b2 > 1 && shelf - current_shelf == 4) {
            count++;
            b2 -= 2;
            current_shelf = 3;
        } else if (b1 > 3 && shelf - current_shelf == 4) {
            count++;
            b1 -= 4;
            current_shelf = 3;
        } else if (b2 > 0 && shelf - current_shelf == 2) {
            count++;
            b2--;
            current_shelf = 3;
        } else if (b1 > 1 && shelf - current_shelf == 2) {
            count++;
            b1 -= 2;
            current_shelf = 3;
        } else if (b1 > 0 && shelf - current_shelf == 1) {
            count++;
            b1--;
            current_shelf = 3;
        } else if (current_shelf + 3 > shelf) {
            count++;
            current_shelf = 3;
        } else {
            current_shelf += 3;
        }
    }
    for (int i = 0; i < b2; i++) {
        if (b1 > 0 && shelf - current_shelf == 1) {
            count++;
            b1--;
            current_shelf = 2;
        } else if (current_shelf + 2 > shelf) {
            count++;
            current_shelf = 2;
        } else {
            current_shelf += 2;
        }
    }
    for (int i = 0; i < b1; i++) {
        if (current_shelf + 1 > shelf) {
            count++;
            current_shelf = 1;
        } else {
            current_shelf++;
        }
    }
    if (current_shelf > 0)
        count++;

    cout << count << endl;
    return 0;
}