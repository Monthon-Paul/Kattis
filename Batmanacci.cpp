// https://open.kattis.com/problems/batmanacci
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Find Fibonacci number, can't exceed 93 due to long is 8 bytes
 * handle with memoization due to extra work
 */
unsigned long fib(unsigned long n, vector<unsigned long>& memo) {
    if (n == 1 || n == 2)
        return memo[n] = 1;
    if (!memo[n])
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

/**
 * Find letter by Fibonacci size
 */
char findLetter(unsigned long k, unsigned long n, vector<unsigned long> memo) {
    while (n > 2) {
        if (memo[n - 2] < k) {
            k -= memo[n - 2];
            n -= 1;
        } else {
            n -= 2;
        }
    }
    if (n == 1)
        return 'N';
    else
        return 'A';
}

int main() {
    unsigned long n, k;
    // Read input
    cin >> n >> k;
    if (n > 93)
        n = 93;
    vector<unsigned long> memo(n + 1, 0);
    fib(n, memo);
    cout << findLetter(k, n, memo) << endl;
}

/*
    Max 2^64 : 18446744073709551616
    fib 93   : 12200160415121876738
    fib 94   : 19740274219868223167
    Max K    : 1000000000000000000
*/