// https://open.kattis.com/problems/loowater
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> knights;
    vector<int> dragondeeznuts;
    int n, m, x;
    while (cin >> n >> m) {
        knights.clear();
        dragondeeznuts.clear();
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> x;
            dragondeeznuts.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            knights.push_back(x);
        }
        if (n > m) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        sort(dragondeeznuts.begin(), dragondeeznuts.end());
        sort(knights.begin(), knights.end());

        int k = 0, d = 0, pay = 0;
        while (d < n && k < m) {
            if (dragondeeznuts[d] <= knights[k]) {
                pay += knights[k];
                d++;
                k++;
            } else {
                k++;
            }
        }
        if (d == n)
            cout << pay << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}