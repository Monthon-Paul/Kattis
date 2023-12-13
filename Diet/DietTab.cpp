// https://open.kattis.com/problems/balanceddiet
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n, v, sum = 0;
    while (cin >> n && n != 0) {
        sum = 0;
        vector<int> calories(n);
        for (int i = 0; i < n; i++) {
            cin >> v;
            sum += v;
            calories[i] = v;
        }
        int mid = sum / 2;
        int tab[n + 1][mid + 1];
        memset(tab, 0, sizeof(tab));
        sort(calories.rbegin(), calories.rend());

        // Initialize tabulation
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= mid; j++) {
                if (i == 0 || j == 0)
                    tab[i][j] = 0;
                else if (calories[i - 1] <= j)
                    tab[i][j] = max(calories[i - 1] + tab[i - 1][j - calories[i - 1]], tab[i - 1][j]);
                else
                    tab[i][j] = tab[i - 1][j];
            }
        }

        int day2 = tab[n][mid];
        cout << sum - day2 << " " << day2 << endl;
    }
    return 0;
}
