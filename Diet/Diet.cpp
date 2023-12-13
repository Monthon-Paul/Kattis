#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int memo[21][6001]; // Assume the max value of calories & the middle of all sum of calories

/**
 * Check the max subset or at least close to mid for day2
 */
int maxsubset(vector<int> calories, int mid, int n) {
    // Base Cases:
    // if the calorie is greater than the mid, it's for day1
    if (calories[n] > mid)
        return memo[n][mid] = 0;
    
    if (n == 0) {
        if (calories[0] <= mid)
            return memo[n][mid] = calories[0];
        else
            return memo[n][mid] = 0;
    }

    // Don't do repeated work
    if (memo[n][mid] != -1)
        return memo[n][mid];

    // Recursive Cases:
    int first = maxsubset(calories, mid, n - 1);
    int second = calories[n] + maxsubset(calories, mid - calories[n], n - 1);
    return memo[n][mid] = max(first, second);
}

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
        memset(memo, -1, sizeof(memo));

        sort(calories.rbegin(), calories.rend());
        int day2 = maxsubset(calories, mid, n - 1);
        cout << sum - day2 << " " << day2 << endl;
    }
    return 0;
}